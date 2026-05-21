/*
 * variant.h
 * Copyright (C) 2023 Seeed K.K.
 * MIT License
 */

#pragma once

#include "WVariant.h"

////////////////////////////////////////////////////////////////////////////////
// Low frequency clock source

#define USE_LFXO    // 32.768 kHz crystal oscillator
// #define USE_LFRC    // 32.768 kHz RC oscillator

////////////////////////////////////////////////////////////////////////////////
// Number of pins

#define PINS_COUNT              (48)

////////////////////////////////////////////////////////////////////////////////
// Digital pin definition

#define NUM_DIGITAL_PINS        (12)

#define D0                      (13)            // Grove - Digital0 (P1)
#define D1                      (14)            // Grove - Digital0 (P2)
#define D2                      (15)            // Grove - Digital1 (P1)
#define D3                      (16)            // Grove - Digital1 (P2)
#define D4                      (30)            // Grove - Digital2 (P1)
#define D5                      (31)            // Grove - Digital2 (P2)
#define D6                      (28)            // Grove - Analog (P1)
#define D7                      (29)            // Grove - Analog (P2)
#define D8                      (24)            // Grove - UART (P1)
#define D9                      (25)            // Grove - UART (P2)
#define D10                     (4)             // Grove - I2C (P1)
#define D11                     (5)             // Grove - I2C (P2)

////////////////////////////////////////////////////////////////////////////////
// Analog pin definition

#define NUM_ANALOG_INPUTS       (6)
#define NUM_ANALOG_OUTPUTS      (0)

#define A0                      (28)            // Grove - Analog (P1)
#define A1                      (29)            // Grove - Analog (P2)
#define A2                      (30)            // Grove - Digital2 (P1)
#define A3                      (31)            // Grove - Digital2 (P2)
#define A4                      (4)             // Grove - I2C (P1)
#define A5                      (5)             // Grove - I2C (P2)

////////////////////////////////////////////////////////////////////////////////
// UART pin definition

#define PIN_SERIAL1_RX          (24)             // Serial1 / Grove - UART (P1)
#define PIN_SERIAL1_TX          (25)             // Serial1 / Grove - UART (P2)

////////////////////////////////////////////////////////////////////////////////
// I2C pin definition

#define WIRE_INTERFACES_COUNT   (1)

#define PIN_WIRE_SDA            (5)             // Wire / Grove - I2C (P2)
#define PIN_WIRE_SCL            (4)             // Wire / Grove - I2C (P1)

////////////////////////////////////////////////////////////////////////////////
// SPI pin definition

#define SPI_INTERFACES_COUNT    (1)

#define PIN_SPI_MISO            (PINS_COUNT)    // No connection
#define PIN_SPI_MOSI            (PINS_COUNT)    // No connection
#define PIN_SPI_SCK             (PINS_COUNT)    // No connection

static const uint8_t SS = PINS_COUNT;           // No connection

////////////////////////////////////////////////////////////////////////////////
// On-board QSPI Flash

#define PIN_QSPI_SCK            (19)
#define PIN_QSPI_CS             (20)
#define PIN_QSPI_IO0            (17)
#define PIN_QSPI_IO1            (22)
#define PIN_QSPI_IO2            (23)
#define PIN_QSPI_IO3            (21)

#define EXTERNAL_FLASH_DEVICES  (P25Q16H)
#define EXTERNAL_FLASH_USE_QSPI

////////////////////////////////////////////////////////////////////////////////
// Builtin LEDs

#define LED_BUILTIN             (6)
#define LED_RED                 (LED_BUILTIN)
#define LED_BLUE                (PINS_COUNT)    // No connection

#define LED_STATE_ON            (0)             // 1:HIGH, 0:LOW

////////////////////////////////////////////////////////////////////////////////
// Builtin buttons

#define PIN_BUTTON1             (34)            // BOOT Button

////////////////////////////////////////////////////////////////////////////////
// MISC

#define PIN_LR1110_IRQ          (2)             // WM1110 LR_DIO9
#define PIN_GNSS_LNA            (37)
#define PIN_POWER_SUPPLY_GROVE  (33)

#define PIN_LIS3DHTR_INT1       (35)
#define PIN_LIS3DHTR_INT2       (36)
