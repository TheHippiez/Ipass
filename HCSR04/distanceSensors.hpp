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
//       File      : DistanceSensor.hpp                                                               +
//       Part of   : library for a HC-SR04 Sonar Sensor                                               +
//                                                                                                    +
//       Distributed under the Boost Software License, Version 1.0.                                   +
//       (See accompanying file LICENSE_1_0.txt or copy at                                            +
//       http://www.boost.org/LICENSE_1_0.txt)                                                        +
//                                                                                                    +
//                                                                                                    +
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "hwlib.hpp"

/// distanceSensors Class
//
/// The super class for sensors, handy if there are more sensors added in the future. 
class distanceSensors {
protected:
    distanceSensors( )
    {}   
    virtual int MsDistance();
};
