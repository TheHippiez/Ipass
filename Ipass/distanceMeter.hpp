//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                 ______                     _           _           _        _                      +
//                | ___ \                   (_)         | |         | |      (_)                      +
//                | |_/ /__  __ _  ___ ___   _ _ __   __| |_   _ ___| |_ _ __ _  ___  ___             +
//                |  __/ _ \/ _` |/ __/ _ \ | | '_ \ / _` | | | / __| __| '__| |/ _ \/ __|            +
//                | | |  __/ (_| | (_|  __/ | | | | | (_| | |_| \__ \ |_| |  | |  __/\__ \            +
//                \_|  \___|\__,_|\___\___| |_|_| |_|\__,_|\__,_|___/\__|_|  |_|\___||___/            +
//                                                                                                    +
//                                _                                                                   +
//                                  .         _____|___                                               +
//                                 .      ___/  o o o  \___                                           +
//                                 .     /    ---------    \                                          +
//                                  .   |     ---------     |                                         +
//                                    8-=\_________________/                                          +
//                                                                                                    +
//                                                                                                    +
//                                                                                                    +
//       Author    : L. Roovers                                                                       +
//       File      : distanceMeter.hpp                                                                +
//       Part of   : Application for a HC-SR04 Sonar Sensor & Nokia 5510 LCD                          +
//                                                                                                    +
//       Distributed under the Boost Software License, Version 1.0.                                   +
//       (See accompanying file LICENSE_1_0.txt or copy at                                            +
//       http://www.boost.org/LICENSE_1_0.txt)                                                        +
//                                                                                                    +
//                                                                                                    +
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef DISTANCEMETER_HPP
#define DISTANCEMETER_HPP
#include "hwlib.hpp"
#include "sonarSensor.hpp"
#include "lcdScreen.hpp"


class distanceMeter{
private:
    sonarSensor & sens;
    lcdScreen & lcd;
    hwlib::target::pin_in & button;
    
public:
    distanceMeter(sonarSensor & sens,lcdScreen & lcd,  hwlib::target::pin_in & button);
    void MeasureDist(bool enableMm = 0);
    void HardCodedText();
    void NmbrSeparator(int number, int & FirstNmbr,int & SecondNmbr,int & ThirdNmbr,int & FourthNmbr,int & FifthNmbr,int & SixthNmbr,int & SeventhNmbr);
};
#endif 

