/*
 * variant.cpp
 * Copyright (C) 2023 Seeed K.K.
 * MIT License
 */

#include "variant.h"
#include "wiring_constants.h"
#include "wiring_digital.h"

const uint32_t g_ADigitalPinMap[PINS_COUNT + 1] =
{
  0,  // P0.00,XL1
  1,  // P0.01,XL2
  2,  // P0.02,AIN0           (SD,LF)
  3,  // P0.03,AIN1           (SD,LF)
  4,  // P0.04,AIN2
  5,  // P0.05,AIN3
  6,  // P0.06
  7,  // P0.07,TRACECLK
  8,  // P0.08
  9,  // P0.09,NFC1           (SD,LF)
  10, // P0.10,NFC2           (SD,LF)
  11, // P0.11,TRACEDATA2
  12, // P0.12,TRACEDATA1
  13, // P0.13
  14, // P0.14
  15, // P0.15
  16, // P0.16
  17, // P0.17
  18, // P0.18,nRESET
  19, // P0.19
  20, // P0.20
  21, // P0.21
  22, // P0.22
  23, // P0.23
  24, // P0.24
  25, // P0.25
  26, // P0.26
  27, // P0.27
  28, // P0.28,AIN4           (SD,LF)
  29, // P0.29,AIN5           (SD,LF)
  30, // P0.30,AIN6           (SD,LF)
  31, // P0.31,AIN7           (SD,LF)
  32, // P1.00,TRACEDATA0,SWO
  33, // P1.01                (SD,LF)
  34, // P1.02                (SD,LF)
  35, // P1.03                (SD,LF)
  36, // P1.04                (SD,LF)
  37, // P1.05                (SD,LF)
  38, // P1.06                (SD,LF)
  39, // P1.07                (SD,LF)
  40, // P1.08
  41, // P1.09,TRACEDATA3
  42, // P1.10                (SD,LF)
  43, // P1.11                (SD,LF)
  44, // P1.12                (SD,LF)
  45, // P1.13                (SD,LF)
  46, // P1.14                (SD,LF)
  47, // P1.15                (SD,LF)
  255,  // NRFX_SPIM_PIN_NOT_USED
};

void initVariant()
{
  // All pins output HIGH by default.
  // https://github.com/Seeed-Studio/Adafruit_nRF52_Arduino/blob/fab7d30a997a1dfeef9d1d59bfb549adda73815a/cores/nRF5/wiring.c#L65-L69

  digitalWrite(PIN_GNSS_LNA, LOW);
  pinMode(PIN_GNSS_LNA, OUTPUT);

#if defined(POWER_SUPPLY_GROVE) && POWER_SUPPLY_GROVE == 1
  digitalWrite(PIN_POWER_SUPPLY_GROVE, HIGH);
#else
  digitalWrite(PIN_POWER_SUPPLY_GROVE, LOW);
#endif
  pinMode(PIN_POWER_SUPPLY_GROVE, OUTPUT);

  ledOff(LED_BUILTIN);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(PIN_BUTTON1, INPUT);
}
