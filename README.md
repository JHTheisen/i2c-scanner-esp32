# i2c-scanner-esp32
A sketch for an esp32 to detect i2c devices

# ESP32 I2C Debug Sketches

This repository contains simple Arduino/ESP32 sketches used to debug I2C communication issues with various sensors.

## Purpose

I was having trouble getting certain I2C devices to respond on ESP32 boards. This repo is a collection of small test sketches used to isolate the problem.

## What Works

- I2C scanner detects devices
- OLED display (I2C) works correctly
- Read/write communication works with known-good devices

## What Does NOT Work (Current Issue)

- AS5600 magnetic encoder not detected
- BNO085 sensors not detected
- Tested across multiple ESP32 boards with same result

## Hardware Used

- ESP32 (DevKit, C3, etc.)
- AS5600 encoder
- BNO085 sensor
- I2C OLED display (working reference)


## Goal

Identify why some I2C devices are detected and others are not, despite working wiring and bus activity.

## If You Have Suggestions

Feel free to comment or suggest things to try. This is an active debugging process.
