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
//       File      : sonarSensor.hpp                                                                  +
//       Part of   : library for a HC-SR04 Sonar Sensor                                               +
//                                                                                                    +
//       Distributed under the Boost Software License, Version 1.0.                                   +
//       (See accompanying file LICENSE_1_0.txt or copy at                                            +
//       http://www.boost.org/LICENSE_1_0.txt)                                                        +
//                                                                                                    +
//                                                                                                    +
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef SONARSENSOR_HPP
#define SONARSENSOR_HPP
#include "hwlib.hpp"
#include "distanceSensors.hpp"

/// sonarSensor class 
//
/// This class is used to initialize HC-SR04 sonar sensors. It may also be used by any similair sensor with the same pins and workings as the HC-SR04. 
/// The following is a short summary of the 3 functions this class provides: 
/// MsDistance(); : A function that measures the distance in Cm and returns an integer that is a 100 times larger for a more accurate number. 
/// Trigger(); : A function that returns a boolean value if it measures an object or being between two given values, it can be set to repeat. 
/// TriggerInRange(); : A function that returns the value of a measurement inbetween two given values. It can also return a percentage int.  

class sonarSensor:public distanceSensors{
private:
    hwlib::target::pin_out & trigger;
    hwlib::target::pin_in & echo;
public:
    sonarSensor(hwlib::target::pin_out & p_trigger, hwlib::target::pin_in & p_echo);
    int MsDistance();
    bool Trigger(int MinimalDistance, int MaximumDistance,bool SetConstantTrigger = 0);
    int  TriggerInRange(int MinimalDistance, int MaximumDistance,bool PercentageEnable = 0);
};
#endif 