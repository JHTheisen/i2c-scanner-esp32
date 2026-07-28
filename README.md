# ESP32 I2C Debug Sketch

A simple ESP32 I2C scanner used to troubleshoot devices that are not being detected.

## Purpose

I am having trouble getting certain I2C devices to respond on ESP32 boards. This repository contains a test sketch used to isolate the problem.

## What Works

- The I2C scanner detects a 1602 I2C LCD display
- I can successfully write text to the 1602 LCD display

## Current Problem

- AS5600 magnetic encoder is not detected
- BNO085 sensors are not detected
- The same behavior occurs with multiple ESP32 boards and an Arduino board

## Hardware Tested

- ESP32 DevKit V1
- ESP32-C3 SuperMini
- Arduino UNO R4 WiFi
- AS5600 magnetic encoder
- BNO085 sensor
- 1602 I2C LCD display as a known-working reference device

## Troubleshooting Performed

- Verified the wiring multiple times
- Tested multiple ESP32 boards
- Tested an Arduino UNO R4 WiFi
- Measured unusual voltages on the SDA and SCL lines when the AS5600 and BNO085 sensors were connected
- Added external pull-up resistors from SDA and SCL to 3.3 V
- Rechecked the SDA and SCL voltages with the pull-up resistors installed and found that the resistors had no apparent effect on the measured voltages
- The same boards and scanner reliably detect and communicate with the 1602 I2C LCD
## Goal

Determine why the 1602 I2C LCD is detected and communicates successfully while the AS5600 and BNO085 devices are not detected.

## Suggestions

Suggestions for additional tests or possible causes are welcome. This is an active debugging project.
