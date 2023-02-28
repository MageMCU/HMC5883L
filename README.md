# Honeywell HMC5883L

- namespace ***par***

## Boards

- Parallax Compass Module 3-Axis HMC5883L (#29133)
- Other boards pending...

## IC Magnetic Sensors

A magnetometer, IC magnetic sensor, is a device that measures magnetic field. Different types of magnetometers measure the direction, strength, or relative change of a magnetic field at a particular location. A compass is one such device, one that measures the direction of an ambient magnetic field, in this case, the Earth's magnetic field....

- **The Earth's magnetic field** - [(Wikipedia)](https://en.wikipedia.org/wiki/Earth%27s_magnetic_field)

## Testing Platform

This MCU chip **Atmega328P** is well known and the price is affordable as well as most of the robotic hardware that is described here. The Arduino Uno board comes with a removable MCU.

**PlatformIO** is a cross-platform, cross-architecture, multiple framework, professional tool for embedded systems engineers and for software developers who write applications for embedded products. 

**Visual Studio Code** is a streamlined code editor and it runs on macOS, Linux, and Windows. The best thing about VSCode, it is free.

## Issues - PlatformIO - Arduino - Arduino Uno - Arduino.h - Wire.h Libs...

- Uncovered Parallax HMC5883L failure.
    - Integer data-type conversion two's compliment BUG
    - Read the  **Bug Report** titled: VSCode PlatformIO Wire.read() Issue.txt
        - File is located in Bug-Report folder...
        - Uploaded a supplemental bug report in the same folder (PDF). 20230228...
    - **New data:** Pololu LSM303D Compass testing shows that the previous bug about the HMC5883L Arduino's Wire.h was erroneously concluded prematurely without having the adequate information. The LSM303D testing shows that the code here for the HMC5883L needs further work.
  
## In Development

- This project is on hold until a resolution is determined...

## Disclaimer and Terms

Please follow the ***Disclaimer*** and ***Terms*** in the ***HMC5883L*** Repository.
