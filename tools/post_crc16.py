# -*- coding: utf-8 -*-
"""
PlatformIO post-build CRC16 helper for dual-bank bootloader.

Usage (PlatformIO):
  Add to platformio.ini:
    extra_scripts = post:tools/post_crc16.py

Usage (CLI):
  python post_crc16.py <firmware.bin> [--addr 0xF0000] [--bank 0|1]

Outputs:
  - Prints SIZE and CRC16 compatible with Nordic's crc16_compute (poly 0x1021, init 0xFFFF).
  - Writes tools/last_build_crc.json with details.
"""
from __future__ import print_function
import os, sys, json, argparse

# CRC-16/CCITT-FALSE: poly 0x1021, init 0xFFFF, no reflect, xorout 0x0000
def crc16_ccitt(data, init=0xFFFF):
    crc = init & 0xFFFF
    for b in data:
        crc ^= (b << 8) & 0xFFFF
        for _ in range(8):
            if (crc & 0x8000):
                crc = ((crc << 1) ^ 0x1021) & 0xFFFF
            else:
                crc = (crc << 1) & 0xFFFF
    return crc & 0xFFFF

def compute_for_file(bin_path):
    with open(bin_path, "rb") as f:
        blob = f.read()
    size = len(blob)
    crc = crc16_ccitt(blob, 0xFFFF)
    return size, crc

def _post_action(env):
    # PlatformIO post action entry
    try:
        build_dir = env.get("BUILD_DIR")
        progname  = env.get("PROGNAME")
        bin_path  = os.path.join(build_dir, progname + ".bin")
        bank      = env.get("BUILD_BANK", None)  # comes from build_flags -DBUILD_BANK=0/1 (optional)
        # Try to infer from build_flags if not set
        if bank is None:
            bank = env.get("CPPDEFINES", [])
        size, crc = compute_for_file(bin_path)
        info = {
            "bin": bin_path,
            "size": size,
            "crc16": crc,
            "hex_crc16": "0x%04X" % crc,
            "bank": bank
        }
        # Persist
        out_json = os.path.join(os.path.dirname(__file__), "last_build_crc.json")
        with open(out_json, "w") as f:
            json.dump(info, f, indent=2)
        print("\n=== Dual-Bank CRC16 ===")
        print("BIN : %s" % bin_path)
        print("SIZE: %d bytes" % size)
        print("CRC : 0x%04X" % crc)
        print("=======================\n")
    except Exception as e:
        print("CRC16 post step failed:", e)

def main():
    # If invoked by PlatformIO, SCons will import this file and call env.AddPostAction.
    # If invoked directly, act as a CLI.
    if len(sys.argv) >= 2 and sys.argv[1].endswith(".bin"):
        ap = argparse.ArgumentParser()
        ap.add_argument("bin", help="Path to firmware .bin")
        ap.add_argument("--addr", help="BANK_SETTINGS_ADDR (for reference/printing)", default=None)
        ap.add_argument("--bank", help="Target bank number (0 or 1)", default=None)
        args = ap.parse_args()
        size, crc = compute_for_file(args.bin)
        print("BIN : %s" % args.bin)
        print("SIZE: %d bytes" % size)
        print("CRC : 0x%04X" % crc)
        if args.addr:
            print("Write these into bank settings at %s" % args.addr)
        if args.bank is not None:
            print("Bank : %s" % args.bank)
        # Also dump JSON next to script
        info = {"bin": args.bin, "size": size, "crc16": crc, "hex_crc16": "0x%04X" % crc, "bank": args.bank, "addr": args.addr}
        out_json = os.path.join(os.path.dirname(__file__), "last_build_crc.json")
        with open(out_json, "w") as f:
            json.dump(info, f, indent=2)
        return 0
    # If imported into PlatformIO
    try:
        Import("env")  # type: ignore # provided by PlatformIO
        env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", _post_action)  # type: ignore
    except Exception as e:
        # Not running inside PlatformIO
        if __name__ == "__main__":
            print("Note: not running inside PlatformIO; use CLI mode.")
    return 0

if __name__ == "__main__":
    sys.exit(main())
