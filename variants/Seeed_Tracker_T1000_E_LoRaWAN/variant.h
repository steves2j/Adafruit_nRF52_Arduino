/*
 * variant.h
 * Copyright (C) 2025 Seeed K.K.
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

#define NUM_DIGITAL_PINS        (0)

////////////////////////////////////////////////////////////////////////////////
// Analog pin definition

#define NUM_ANALOG_INPUTS       (5)
#define NUM_ANALOG_OUTPUTS      (0)

#define A0                      (2)             // Baterry level dectect
#define A1                      (4)             // VCC voltage dectect
#define A2                      (5)             // Charger insert dectect
#define A3                      (29)            // Light sensor
#define A4                      (31)            // Temperature sensor

#define NTC_ANALOG_INPUT        (A4)
#define LUX_ANALOG_INPUT        (A3)
#define BAT_ANALOG_INPUT        (A0)

////////////////////////////////////////////////////////////////////////////////
// UART pin definition

#define PIN_SERIAL1_RX          (17)             // Serial1 / Debug - UART
#define PIN_SERIAL1_TX          (16)             // Serial1 / Debug - UART
#define PIN_SERIAL2_RX          (14)             // Serial2 / AG3335 - UART
#define PIN_SERIAL2_TX          (13)             // Serial2 / AG3335 - UART

////////////////////////////////////////////////////////////////////////////////
// I2C pin definition

#define WIRE_INTERFACES_COUNT   (1)

#define PIN_WIRE_SDA            (26)
#define PIN_WIRE_SCL            (27)

////////////////////////////////////////////////////////////////////////////////
// SPI pin definition

#define SPI_INTERFACES_COUNT    (1)

#define PIN_SPI_MISO            (40)
#define PIN_SPI_MOSI            (41)
#define PIN_SPI_SCK             (11)
#define PIN_SPI_CS              (12)

////////////////////////////////////////////////////////////////////////////////
// On-board QSPI Flash

#define PIN_QSPI_SCK            (19)
#define PIN_QSPI_CS             (20)
#define PIN_QSPI_IO0            (21)
#define PIN_QSPI_IO1            (22)
#define PIN_QSPI_IO2            (23)
#define PIN_QSPI_IO3            (33)

#define EXTERNAL_FLASH_DEVICES  (P25Q16H)
#define EXTERNAL_FLASH_USE_QSPI

////////////////////////////////////////////////////////////////////////////////
// Builtin LEDs

#define LED_RED                 (3)
#define LED_GREEN               (24)
#define LED_BUILTIN             (LED_RED)
#define LED_BLUE                (PINS_COUNT)    // No connection

#define LED_STATE_ON            (1)

////////////////////////////////////////////////////////////////////////////////
// Builtin buttons

#define PIN_BUTTON1             (6)

////////////////////////////////////////////////////////////////////////////////
// MISC

#define PIN_BUZZER_EN           (37)
#define PIN_BUZZER_PWM          (25)
#define PIN_SENSE_POWER_EN      (38)
#define PIN_ACC_POWER_EN        (39)
#define PIN_ACC_INTERRUPT       (34)
#define PIN_GNSS_POWER_EN       (43)
#define PIN_GNSS_VRTC_EN        (8)
#define PIN_GNSS_RESET          (47)
#define PIN_GNSS_RESETB         (46)
#define PIN_GNSS_SLEEP_INT      (44)
#define PIN_GNSS_RTC_INT        (15)
#define PIN_LR1110_IRQ          (33)
