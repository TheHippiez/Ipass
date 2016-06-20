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
//       File      : sonarSensor.cpp                                                                  +
//       Part of   : library for a Nokia 5510 LCD screen                                              +
//                                                                                                    +
//       Distributed under the Boost Software License, Version 1.0.                                   +
//       (See accompanying file LICENSE_1_0.txt or copy at                                            +
//       http://www.boost.org/LICENSE_1_0.txt)                                                        +
//                                                                                                    +
//                                                                                                    +
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef LCDSCREEN_HPP
#define LCDSCREEN_HPP

#include "hwlib.hpp"

/// lcdScreen class 
//
/// This class is used to initialize 5510 screens. It may also be used by any similair LCD screen with the same pins and workings as the Nokia 5510 ( Screen sizes might require some changes in the libary) . 
/// The following is a short summary of the 6 functions this class provides: 
/// clear();    : A function that sets every pixel on the screen to zero. 
/// setup();    : A function that issues commands to the LCD screen, setting it up to receive data.
/// command();  : A function that sends the array to the LCD screen.
/// draw();     : A function that draws a [8][84] matrix on the screen!
/// drawBIG();  : A function that draws a [48][84] matrix on the screen!.  
 

class lcdScreen{
    private:
        hwlib::target::pin_out & enable;
        hwlib::target::pin_out & datacommand;
        hwlib::target::pin_out & clock;
        hwlib::target::pin_out & datain;
        hwlib::target::pin_out & reset;
    public:
        lcdScreen(hwlib::target::pin_out & enable,hwlib::target::pin_out & datacommand,hwlib::target::pin_out & clock, hwlib::target::pin_out & datain, hwlib::target::pin_out & reset);
        void clear();
        void setup(int StartMatrix);
        void command(int x[]);
        void draw(int matrix[8][84],int StartMatrix);
        void drawBIG(int array[48][84]);
};

#endif 