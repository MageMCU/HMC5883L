//
// Carpenter Software
// File: HMC5883L.h
// Source: Honeywell HMC5883L Datasheet
// Used Device Board: (1) Parallax Compass Module 3-Axis HMC5883L (#29133)
//                    (2) Others pending...
//
// Purpose: Public Github Account - MageMCU
// Repository: HMC5993L
// Date Created: 20230221
// Folder: Code
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
// The code can be easily compared along with the Honeywell HMC5883L Datasheet...
// Keep it simple...
//
// Note: (1) The Parallax Compass Module 3-Axis HMC5883L (#29133) may not be functioning
//           properly... Setting up an experiment to obtain data. Pending allocation from
//           other board manufacturers to be used in a comparative test. Project on hold.
//       (2) Looking for other HMC5883L boards...
//
// Code was extracted from various websites and sources and then simplified as shown below... 
// The code is under development...
//
// Experiment design - csv file - headings as a function of angles H(a).
// (1) Draw two lines perpendicular 90 degrees 
// (1a) Draw two lines perpendicular offset to (1) giving 8 - 45 degree angles
// (2) Use these 8 lines to measure the headings... 
// (3) Should give an approximate angle offset relative to the given angles
// (4) Use both the actual and the readings into comma separated values (csv) file
// (5) Use spreadsheet to plot data... 
//

#ifndef Parallax_HMC5883L_h
#define Parallax_HMC5883L_h

#include "Arduino.h"
#include "Wire.h"
#include "MiscMath.h"

namespace par
{
    template <typename real>
    class HMC5883L
    {
    private:
        uint8_t m_deviceAddr;
        real m_x;
        real m_y;
        real m_z;
        real m_heading;

    public:
        // Constructor
        HMC5883L() = default;
        HMC5883L(uint8_t deviceAddress);
        ~HMC5883L() = default;

        // Arduino setup()
        void BeginRegA(uint8_t bits);
        void BeginRegB(uint8_t bits);
        void BeginModeReg(uint8_t bits);

        // Arduino loop()
        void Update();
        real Heading();
        String GetString();
    };

    template <typename real>
    HMC5883L<real>::HMC5883L(uint8_t deviceAddress)
    {
        m_deviceAddr = deviceAddress;
        m_heading = (real)0;
    }


    template <typename real>
    void HMC5883L<real>::BeginRegA(uint8_t bits /* 0b00010000 Default */)
    {
        // See Honeywell HMC5883L Datasheet
        Wire.beginTransmission(m_deviceAddr);

        // Configuration Register-A - hexidecimal
        Wire.write(byte(0x00));      

        // Reg A binary data
        // CRA0 through CRA7 indicate bit locations
        //    bits          bit-values     description
        // CRA7             0bX-------    X-bit-locations
        //                  0b0-------    reserved for future function.
        //
        // CRA6 to CRA5     0b-XX-----    X-bit-locations
        //                  0b-00-----    1 - samples averaged - Default    
        //                  0b-01-----    2 - samples averaged    
        //                  0b-10-----    4 - samples averaged    
        //                  0b-11-----    8 - samples averaged    
        //
        // CRA4 to CRA2     0b---XXX--    X-bit-locations
        //                  0b---000--    0.75 Hz - Data Output
        //                  0b---001--    1.5  Hz
        //                  0b---010--    3    Hz
        //                  0b---011--    7.5  Hz
        //                  0b---100--    15   Hz - Default
        //                  0b---101--    30   Hz
        //                  0b---110--    75   Hz
        //                  0b---111--    Reserved
        //
        // CRA1 to CRA0     0b------XX    X-bit-locations
        //                  0b------00    Measurement - No Bias.
        //                  0b------01    Measurement - Positive Bias.
        //                  0b------10    Measurement - Negative Bias.
        //                  0b------11    Reserved
        Wire.write(byte(bits));
        Wire.endTransmission();

        delay(5);
    }

    template <typename real>
    void HMC5883L<real>::BeginRegB(uint8_t bits /* 0b00100000 Default */)
    {
        // See Honeywell HMC5883L Datasheet
        Wire.beginTransmission(m_deviceAddr);

        // Configuration Register-B - hexidecimal
        Wire.write(byte(0x01));

        // Reg B binary data
        // CRB0 through CRB7 indicate bit locations
        //    bits          bit-values     description
        // CRB7 to CRB5    0bXXX-----    X-bit-locations
        //                 0b000-----    ± 0.88 Ga - Gain Bits.
        //                 0b001-----    ± 1.3  Ga - Gain Bits. - Default
        //                 0b010-----    ± 1.9  Ga - Gain Bits.
        //                 0b011-----    ± 2.5  Ga - Gain Bits.
        //                 0b100-----    ± 4.0  Ga - Gain Bits.
        //                 0b101-----    ± 4.7  Ga - Gain Bits.
        //                 0b110-----    ± 5.6  Ga - Gain Bits.
        //                 0b111-----    ± 8.1  Ga - Gain Bits.
        //
        // CRB4 to CRB0    0b---XXXXX    X-bit-locations
        //                 0b---00000    cleared for correct operation.
        Wire.write(byte(bits)); 
        Wire.endTransmission();

        delay(5);
    }

    template <typename real>
    void HMC5883L<real>::BeginModeReg(uint8_t bits /* 0b00000000 Default */)
    {
        // See Honeywell HMC5883L Datasheet
        Wire.beginTransmission(m_deviceAddr);

        // Mode Reg hex
        Wire.write(byte(0x02));

        // Mode Reg binary data 
        // MR0 through MR7 indicate bit locations
        //    bits       bit-values     description
        // MR7 to MR2    0bXXXXXX--   X-bit-locations
        //               0b000000--   Please read datasheet.
        //
        // MR1 to MR0    0b------XX   X-bit-locations
        //               0b------00   Continuous-Measurement Mode. - Default
        //               0b------01   Single-Measurement Mode.
        //               0b------10   Idle Mode.
        //               0b------11   Idle Mode.


        Wire.write(byte(bits));
        Wire.endTransmission();

        delay(5);
    }

    template <typename real>
    void HMC5883L<real>::Update()
    {

        // Initiate communications with compass
        Wire.beginTransmission(m_deviceAddr);
        // Send request to Data Output X MSB Register
        // starting at 0x03 Address Location page 11 of
        // Honeywell datasheet.
        Wire.write(byte(0x03));
        Wire.endTransmission();

        Wire.requestFrom(m_deviceAddr, (byte)6); // Request 6 bytes; 2 bytes per axis
        if (Wire.available() == 6)
        {
            m_x = Wire.read() << 8 | Wire.read();
            m_y = Wire.read() << 8 | Wire.read();
            m_z = Wire.read() << 8 | Wire.read();
        }

        // Interested in the heading only...
        // Headings (board orientation - place arrows accordingly)
        // board placement for example XY horizontal to earth's surface...
        // axes XY where Z points-up: first test (Questionable) --------------------- FAILED 
        // axes YZ where X points-up: not tested yet
        // axes ZX where Y points-up: not tested yet

        // Results - Axes XY test data distribution as a function of the angle was not linear...

        // Functions MiscMath.h
        // m_heading = nmr::AngleRadian<float>(m_x, m_y) * (float)RAD_TO_DEG;
        m_heading = nmr::Angle2Radian<float>(m_x, m_y) * (float)RAD_TO_DEG;

        // Pending - Setup an experiment to obtain data... Project on hold
    }

    template <typename real>
    real HMC5883L<real>::Heading()
    {
        return m_heading;
    }

    template <typename real>
    String HMC5883L<real>::GetString()
    {
        String str = "Heading: ";
        str += String(m_heading, 2);
        return str;
    }

}

#endif