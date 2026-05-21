/*
 * variant.cpp
 * Copyright (C) 2025 Seeed K.K.
 * MIT License
 */

#include "variant.h"
#include "wiring_constants.h"
#include "wiring_digital.h"

const uint32_t g_ADigitalPinMap[PINS_COUNT + 1] =
{
  0,   // P0.00 XL1
  1,   // P0.01 XL2
  2,   // P0.02 Analog input, Baterry level dectect
  3,   // P0.03 Red LED IO
  4,   // P0.04 Analog input, VCC voltage dectect
  5,   // P0.05 Analog input, Charger insert dectect, must be configured as no pullup or pulldown
  6,   // P0.06 Key IO, must be configured as input_pulldown
  7,   // P0.07 LR1110 BUSY
  8,   // P0.08 AG3335 VRTC EN
  9,   // P0.09 NFC input
  10,  // P0.10 NFC input
  11,  // P0.11 SPI SCK
  12,  // P0.12 SPI CS
  13,  // P0.13 UART1 TX For AG3335
  14,  // P0.14 UART1 RX For AG3335
  15,  // P0.15 AG3335 RTC Interrupt
  16,  // P0.16 UART2 TX For debug
  17,  // P0.17 UART2 RX For debug
  18,  // P0.18 Reset
  19,  // P0.19 QSPI Clock for FLASH
  20,  // P0.20 QSPI CS for FLASH
  21,  // P0.21 QSPI IO0 for FLASH
  22,  // P0.22 QSPI IO1 for FLASH
  23,  // P0.23 QSPI IO2 for FLASH
  24,  // P0.24 Green LED IO
  25,  // P0.25 Buzzer PWM
  26,  // P0.26 I2C SDA
  27,  // P0.27 I2C SCL
  28,  // P0.28 Analog input
  29,  // P0.29 Analog input, Light Sensor ADC input
  30,  // P0.30 Analog input
  31,  // P0.31 Analog input, Temperature Sensor ADC input
  32,  // P1.00 QSPI IO3 for FLASH
  33,  // P1.01 LR1110 DIO9
  34,  // P1.02 Accelerator Interrupt
  35,  // P1.03 Charger State
  36,  // P1.04 Charger Done
  37,  // P1.05 Buzzer Enable
  38,  // P1.06 Sensor VCC Enable
  39,  // P1.07 Accelerator Enable
  40,  // P1.08 SPI MISO
  41,  // P1.09 SPI MOSI
  42,  // P1.10 LR1110 RESET
  43,  // P1.11 AG3335 PWR EN
  44,  // P1.12 AG3335 SLEEP Interrupt
  45,  // P1.13 Flash Enable
  46,  // P1.14 AG3335 RESETB OUT
  47,  // P1.15 AG3335 Reset
  255, // NRFX_SPIM_PIN_NOT_USED
};

void initVariant()
{
  // All pins output HIGH by default.
  // https://github.com/Seeed-Studio/Adafruit_nRF52_Arduino/blob/fab7d30a997a1dfeef9d1d59bfb549adda73815a/cores/nRF5/wiring.c#L65-L69

  ledOff(LED_RED);
  pinMode(LED_RED, OUTPUT);
  ledOff(LED_GREEN);
  pinMode(LED_GREEN, OUTPUT);

  pinMode(PIN_BUTTON1, INPUT);
}
