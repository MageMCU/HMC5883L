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

## Issues

- Uncovered Parallax HMC5883L failure.
    - Integer data-type conversion two's compliment BUG
    - Read the  **Bug Report** titled: VSCode PlatformIO Wire.read() Issue.txt
        - File is located in Bug-Report folder...
        - Uploaded a supplemental bug report in the same folder (PDF). 20230228...
    - **New data:** Pololu LSM303D Compass testing shows that the previous bug about the HMC5883L Arduino's Wire.h was erroneously concluded prematurely without having the adequate information. The LSM303D testing shows that the code here for the HMC5883L needs further work. 20230228
  
## In Development

- While programming and testing multiple magnetometers, HMC5883L and LSM303D, they seem to have similar functional characteristics when it comes to programming (which I hope will solve some of the issues with the HMC5883L). 
    - There are no technical or application notes to suplement information other than the incomplete HMC5883L datasheet from Honeywell.
    - On the other hand, the STMicroelectronics LSM303D datasheet is simiular to the Honeywell, but I did find an application note AN3192.
        - Application Note - AN3192
            - Using LSM303DLH for tilt compensated electronic compass
        - With this information and the further attempt to contact Honeywell, I might get their compass up and working...
    - Additional information was found for QMC5883L and HMC5883L sensors from National Library of Medicine (NIH) website from their Journal list - PLoS - PMC9307166 - published online 2022 Jul 22 titled ***Integration and evaluation of magnetic stimulation in physiology setups***. This article can be downloaded as a PDF file.
        - This article has an extensive reference section to other sources... It seems like the authors of this article could not get anything from Honeywell either except their datasheet...
    - Xtrinsic MAG3110 Three-Axis, Digital Magnetometer (Pending)
        - Application Note - AN4246
            - Calibrating an eCompass in the Presense of Hard- and Soft-Iron Interferance
        - Application Note - AN4247
            - Layout Recommendations for PCBs using a Magnetometer Sensor
                - Has more mathematically...
        - Application Note - AN4248
            - Implementing a Tilt-Compensated eCompass using Accelerometer and Magnetometer Sensors

## Disclaimer and Terms

Please follow the ***Disclaimer*** and ***Terms*** in the ***HMC5883L*** Repository.
