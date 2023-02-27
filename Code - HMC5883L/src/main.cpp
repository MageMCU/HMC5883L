//
// Carpenter Software
// File: main.cpp
//
// Purpose: Public Github Account - MageMCU
// Repository: HMC5883L 
// Date Created: 20230225
// Folder: Code-HMC5883L
//
// Author: Jesse Carpenter (carpentersoftware.com)
// Email:carpenterhesse@gmail.com
//
// Testing Platform:
//  * MCU:Atmega328P
//  * Editor: VSCode
//  * VSCode Extension: Microsoft C/C++ IntelliSense, debugging, and code browsing.
//  * VSCode Extension:PlatformIO
// 
// Revised Header-Comment 20230219
//
// MIT LICENSE
//

#include <Arduino.h>

#include "HMC5883L.h"
#include "Timer.h"

// Parallax
par::HMC5883L<float> compass;
// Timer
nmr::Timer loopTimer;

void setup() {
  Serial.begin(9600);
  while (!Serial){}
  
  Wire.begin();

  // Address of HMC5883L is 0x1E (hexidecimal)
  compass = par::HMC5883L<float>(0x1E);
  // More info in class file (binary bits)
  compass.BeginRegA(0b01110000);
  compass.BeginRegB(0b00100000);
  compass.BeginModeReg(0b00000000);

  // timer
  loopTimer = nmr::Timer();
}

void loop() {
  // 1-second timer
  if (loopTimer.isTimer(1000))
  {
    compass.Update();
    Serial.println(compass.GetRawZ());
  }
}