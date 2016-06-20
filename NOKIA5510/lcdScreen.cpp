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
//       File      : lcdScreen.hpp                                                                    +
//       Part of   : library for a Nokia 5510 LCD screen                                              +
//                                                                                                    +
//       Distributed under the Boost Software License, Version 1.0.                                   +
//       (See accompanying file LICENSE_1_0.txt or copy at                                            +
//       http://www.boost.org/LICENSE_1_0.txt)                                                        +
//                                                                                                    +
//                                                                                                    +
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "lcdScreen.hpp"
#include "hwlib.hpp"


/// lcdScreen Constructor
//
/// This constructor consists of 5 pins. 
/// enable(p_enable):           This pin must be set to 0 ( active low ) for any other operation to take place.
/// datacommand(p_datacommand): This pin is set to 0 to send commands to the screen, set it to 1 for data.
/// clock(p_clock):             This pin is the clock. 
/// datain(p_datain):           This pin is the data pin, all the 1's  and 0's go through this. 
/// reset(p_reset):             This pin is the reset. 

lcdScreen::lcdScreen(hwlib::target::pin_out & p_enable, hwlib::target::pin_out & p_datacommand, hwlib::target::pin_out & p_clock, hwlib::target::pin_out & p_datain, hwlib::target::pin_out & p_reset):
    enable(p_enable),
    datacommand(p_datacommand),
    clock(p_clock),
    datain(p_datain),
    reset(p_reset)
    {clear();}



/// command; void. 
//
/// Parameters: 
/// Int x[] :  Array filled with the command data.
/// Variables: 
///  - 
/// Simple for loop puts the data from the array on the datain pin. 
void lcdScreen::command(int x[]){
    datacommand.set(0);
    enable.set(0);
        for(int i=0; i<8 ; i++){
            datain.set(x[i]);
            clock.set(1);
            hwlib::wait_us(10);
            clock.set(0);
        }
    enable.set(1);
}



/// Setup; void.
//
/// Parameters:
/// StartMatrix : Where do you want to start drawing? 0 to 5. 
/// Variables:
///   A through f : All these arrays are needed to iniate the screen.
/// Setup for the screen. Standard command to initalize it, extra commands included for drawing positions. 
void lcdScreen::setup(int StartMatrix ){

    clock.set(0);
    enable.set(1);
    reset.set(0);
    hwlib::wait_us(10);
    reset.set(0.5);

    int command1[8] = {0,0,1,0,0,0,0,1}; /// selecting extended instructions  
    int command2[8] = {1,1,0,0,1,0,0,0}; /// Vop = 110000b  
    int command3[8] = {0,0,0,0,0,1,1,0}; /// TCx = 00b
    int command4[8] = {0,0,1,0,0,0,0,0}; /// Funcion set PD = 0 and V = 0
    int command5[8] = {0,0,0,1,0,0,1,1}; /// BSx = 100b 
    int command6[8] = {0,0,0,0,1,1,0,0}; /// normal mode
  
    command(command1);
    command(command2);
    command(command3);
    command(command4);
    command(command5);
    command(command6);
    
    if(StartMatrix == 0){
        int ystart[8] = {0,1,0,0,0,0,0,0};  
        int xstart[8] = {1,0,0,0,0,0,0,0}; 
        command(ystart);
        command(xstart);  
    }
    if(StartMatrix == 1){
        int ystart[8] = {0,1,0,0,0,0,0,1};  
        int xstart[8] = {1,0,0,0,0,0,0,1}; 
        command(ystart);
        command(xstart); 
    }
    if(StartMatrix == 2){
        int ystart[8] = {0,1,0,0,0,0,1,0};  
        int xstart[8] = {1,0,0,0,0,0,1,0};  
        command(ystart);
        command(xstart); 
    }
    if(StartMatrix == 3){
        int ystart[8] = {0,1,0,0,0,0,1,1};  
        int xstart[8] = {1,0,0,0,0,0,1,1};     
        command(ystart);
        command(xstart); 
    }
    if(StartMatrix == 4){
        int ystart[8] = {0,1,0,0,0,1,0,0};  
        int xstart[8] = {1,0,0,0,0,1,0,0};  
        command(ystart);
        command(xstart); 
    }
    if(StartMatrix == 5){
        int ystart[8] = {0,1,0,0,0,1,0,1};  
        int xstart[8] = {1,0,0,0,0,1,0,1}; 
        command(ystart);
        command(xstart);  
    }

    
}



   
/// clear; void.
//
/// Parameters:
///     - 
/// Variables:
///   matrix = empty matrix.
/// Calls on the draw function and empties the screen. 
void lcdScreen::clear(){
    int matrix[48][84]={0};
    drawBIG(matrix);
}


/// draw; void.
//
/// Parameters:
///     Matrix : Matrix you give to the function. This is a [8[ bij [84], which means 1 row on the screen. Which means this is the function to draw 1 line of text to the screen.
/// Variables:
///   matrix[8][84] : 
///   StartMatrix   :
/// Function to Draw 1 row on the screen. The way the screen works is that the screen is divied in 6 matrixen of 8 vertically and 84 horzizontally. You draw on it
/// by drawing rows of 8 vertically. So like this : 
/// 1 1
/// 2 2
/// 3 3
/// 4 4
/// 5 5 
/// 6 6

void lcdScreen::draw(int matrix[8][84],int StartMatrix){
    setup(StartMatrix);
    datacommand.set(1);
    int j = 8;
    enable.set(0);
    for(int d=0; d<8; d+= 8){               // the forloop that runs through the 6 matrixen that divide the screen ( in this case the 0-7 matrix, which is matrix number 0 ) 
        for (int y = 0; y < 84;y++ ){       // the forloop that runs (-->) horizontally along the screen 
            for(int x = d+j; x > d; x--){   // The forloop that draws rows of 8. 
                datain.set(matrix[x-1][y]);
                clock.set(1);
                hwlib::wait_us(10);
                clock.set(0);
            }
        }
    }
    enable.set(1);
}

/// DrawBIG; void.
//
/// Parameters:
///     - 
/// Variables:
/// Matrix[48][84] : Huge matrix
/// Works the same as Draw, but this one draws on the whole screen in one go. 
void lcdScreen::drawBIG(int matrix[48][84]){
    setup(0);
    datacommand.set(1);
    int j = 8;
    enable.set(0);
    for(int d=0; d<48; d+= 8){
        for (int y = 0; y < 84;y++ ){
            for(int x = d+j; x > d; x--){
                datain.set(matrix[x-1][y]);
                clock.set(1);
                hwlib::wait_us(10);
                clock.set(0);
            }
        }
    }
    enable.set(1);
}