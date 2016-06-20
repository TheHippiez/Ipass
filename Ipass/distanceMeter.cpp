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
//       File      : distanceMeter.cpp                                                                +
//       Part of   : Application for a HC-SR04 Sonar Sensor & Nokia 5510 LCD                          +
//                                                                                                    +
//       Distributed under the Boost Software License, Version 1.0.                                   +
//       (See accompanying file LICENSE_1_0.txt or copy at                                            +
//       http://www.boost.org/LICENSE_1_0.txt)                                                        +
//                                                                                                    +
//                                                                                                    +
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "distanceMeter.hpp"
#include "hwlib.hpp"


distanceMeter::distanceMeter(sonarSensor & p_sens,lcdScreen & p_lcd, hwlib::target::pin_in & button):
    sens(p_sens),
    lcd(p_lcd),
    button(button)
    {}


                              
    

void distanceMeter::NmbrSeparator(int number, int & FirstNmbr,int & SecondNmbr,int & ThirdNmbr,int & FourthNmbr,int & FifthNmbr,int & SixthNmbr,int & SeventhNmbr){
    
/* For the comma*/      FirstNmbr = 0;  SecondNmbr = 0;   ThirdNmbr = 0;  FourthNmbr = 0;  FifthNmbr =0; 
/* Behind the comma */     SixthNmbr = 0;  SeventhNmbr = 0; 
SeventhNmbr = number%10;
    if(SeventhNmbr <= 0){
        SeventhNmbr=0;
    }
SixthNmbr = ((number%100)-SeventhNmbr)/10;
    if(SixthNmbr <= 0){
        SixthNmbr=0;
    }
FifthNmbr = ((number%1000)-number%100)/100;
    if(FifthNmbr <= 0){
        FifthNmbr=0;
    }
FourthNmbr = ((number%10000)-(number%1000))/1000;
    if(FourthNmbr <= 0){
        FourthNmbr=0;
    }
ThirdNmbr = ((number%100000)-(number%10000))/10000;
    if(ThirdNmbr <= 0){
        ThirdNmbr=0;
    }
SecondNmbr = ((number%1000000)-number%100000)/100000;
    if(SecondNmbr <= 0){
        SecondNmbr=0;
    }
FirstNmbr = ((number%10000000)-number%1000000)/1000000;
    if(FirstNmbr <= 0){
        FirstNmbr=0;
    }
   
}




void distanceMeter::HardCodedText(){ 
    int start = 0;
    int distance_is_matrix[8][84]=
    {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
    {0,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    lcd.draw(distance_is_matrix,start);
}
    
void distanceMeter::MeasureDist(bool enableMm){
    int start = 2;
    HardCodedText();
    while(1){
        if(!button.get()){
        int x[8][84]=
        {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        };
    
        int FirstNmbr; int SecondNmbr; int ThirdNmbr; int FourthNmbr; int FifthNmbr;
        int SixthNmbr; int SeventhNmbr;
        const int period = 10;
        const int CMorMM = 11; 
        int RawDist = sens.MsDistance();
        NmbrSeparator(RawDist,FirstNmbr,SecondNmbr,ThirdNmbr,FourthNmbr,FifthNmbr,SixthNmbr,SeventhNmbr);
        int array1[9] = {0,0,0,0,0,0,0,0,0};
        int array2[12]= {0,1,2,3,4,5,6,7,8,9,10,11};
        if(!enableMm){
            int arrayCM1[9] = {FirstNmbr,SecondNmbr,ThirdNmbr,FourthNmbr,FifthNmbr,period,SixthNmbr,SeventhNmbr,CMorMM};
            for(int element =0; element<9;element++){
                array1[element] = arrayCM1[element];
            }
        }
        if(enableMm){
            int arrayMM1[9] = {FirstNmbr,SecondNmbr,ThirdNmbr,FourthNmbr,FifthNmbr,SixthNmbr,period,SeventhNmbr,CMorMM};
            for(int element =0; element<9;element++){
                array1[element] = arrayMM1[element];
            }

        }
        int counter = 0;
        for(int j = 0; j<9 ; j++){
            counter++;
            for(int i = 0; i<12 ;i++){
                if( array1[j] == array2[i]){

                    int padding= (7*counter);
                    if(i == CMorMM){
                        if(!enableMm){
                            x[2][3+padding]=1; x[2][4+padding]=1; x[2][5+padding]=1; x[2][6+padding]=1; 
                            x[3][2+padding]=1;
                            x[4][1+padding]=1;
                            x[5][1+padding]=1;
                            x[6][2+padding]=1;
                            x[7][3+padding]=1; x[7][4+padding]=1; x[7][5+padding]=1; x[7][6+padding]=1; 
                            
                            x[2][8+padding]=1; x[2][12+padding]=1;
                            x[3][8+padding]=1; x[3][9+padding]=1 ; x[3][11+padding]=1; x[3][12+padding]=1;
                            x[4][8+padding]=1; x[4][10+padding]=1; x[4][12+padding]=1;
                            x[5][8+padding]=1; x[5][12+padding]=1;
                            x[6][8+padding]=1; x[6][12+padding]=1;
                            x[7][8+padding]=1; x[7][12+padding]=1;

                        }
                        if(enableMm){
                            x[2][1+padding]=1; x[2][5+padding]=1;        
                            x[3][1+padding]=1; x[3][2+padding]=1; x[3][4+padding]=1; x[3][5+padding]=1;
                            x[4][1+padding]=1; x[4][3+padding]=1; x[4][5+padding]=1;
                            x[5][1+padding]=1; x[5][5+padding]=1;
                            x[6][1+padding]=1; x[6][5+padding]=1;
                            x[7][1+padding]=1; x[7][5+padding]=1;
                            
                            x[2][7+padding]=1; x[2][11+padding]=1;
                            x[3][7+padding]=1; x[3][8+padding]=1; x[3][10+padding]=1; x[3][11+padding]=1;
                            x[4][7+padding]=1; x[4][9+padding]=1; x[4][11+padding]=1;
                            x[5][7+padding]=1; x[5][11+padding]=1;
                            x[6][7+padding]=1; x[6][11+padding]=1;
                            x[7][7+padding]=1; x[7][11+padding]=1;
                        }
                        
                    }
                    if(i == period ){
                        x[7][(1+padding)]=0; x[7][(2+padding)]=0; x[7][(3+padding)]=1; x[7][(4+padding)]=1; x[7][(5+padding)]=0; x[7][(6+padding)]=0;
                    }
                    if(i == 0 ){ 
                        x[0][(1+padding)]=1; x[0][(2+padding)]=1; x[0][(3+padding)]=1; x[0][(4+padding)]=1; x[0][(5+padding)]=1; x[0][(6+padding)]=1;
                        x[1][(1+padding)]=1; x[1][(6+padding)]=1;
                        x[2][(1+padding)]=1; x[2][(6+padding)]=1;
                        x[3][(1+padding)]=1; x[3][(6+padding)]=1;
                        x[4][(1+padding)]=1; x[4][(6+padding)]=1;
                        x[5][(1+padding)]=1; x[5][(6+padding)]=1;
                        x[6][(1+padding)]=1; x[6][(6+padding)]=1;
                        x[7][(1+padding)]=1; x[7][(2+padding)]=1; x[7][(3+padding)]=1; x[7][(4+padding)]=1; x[7][(5+padding)]=1; x[7][(6+padding)]=1;
                    }        

                    if(i == 1 ){
                        x[0][3+padding]=1; x[0][4+padding]=1;
                        x[1][2+padding]=1; x[1][3+padding]=1; x[1][4+padding]=1;
                        x[2][4+padding]=1;
                        x[3][4+padding]=1;
                        x[4][4+padding]=1;
                        x[5][4+padding]=1;
                        x[6][4+padding]=1;
                        x[7][2+padding]=1; x[7][3+padding]=1; x[7][4+padding]=1; x[7][5+padding]=1;
                    }
        
                    if(i == 2 ){
                        x[0][2+padding]=1; x[0][3+padding]=1; x[0][4+padding]=1;
                        x[1][1+padding]=1; x[1][5+padding]=1;
                        x[2][6+padding]=1;
                        x[3][5+padding]=1;
                        x[4][4+padding]=1;
                        x[5][3+padding]=1;
                        x[6][2+padding]=1;
                        x[7][1+padding]=1; x[7][2+padding]=1; x[7][3+padding]=1; x[7][4+padding]=1; x[7][5+padding]=1; x[7][6+padding]=1;
                    }    
                    if(i == 3 ){
                        x[0][2+padding]=1; x[0][3+padding]=1; x[0][4+padding]=1;
                        x[1][1+padding]=1; x[1][5+padding]=1;
                        x[2][5+padding]=1;
                        x[3][4+padding]=1;
                        x[4][5+padding]=1;
                        x[5][6+padding]=1;
                        x[6][1+padding]=1; x[6][6+padding]=1;
                        x[7][2+padding]=1; x[7][3+padding]=1; x[7][4+padding]=1; x[7][5+padding]=1;
                    }    
                    if(i == 4 ){
                        x[0][1+padding]=1; x[0][6+padding]=1;
                        x[1][1+padding]=1; x[1][6+padding]=1;
                        x[2][1+padding]=1; x[2][6+padding]=1;
                        x[3][1+padding]=1; x[3][6+padding]=1;
                        x[4][1+padding]=1; x[4][2+padding]=1; x[4][3+padding]=1; x[4][4+padding]=1; x[4][5+padding]=1; x[4][6+padding]=1;
                        x[5][6+padding]=1;
                        x[6][6+padding]=1;
                        x[7][6+padding]=1;
                    }    
                    if(i == 5 ){
                        x[0][1+padding]=1; x[0][2+padding]=1; x[0][3+padding]=1; x[0][4+padding]=1; x[0][5+padding]=1;
                        x[1][1+padding]=1;
                        x[2][1+padding]=1;
                        x[3][1+padding]=1; x[3][2+padding]=1; x[3][3+padding]=1; x[3][4+padding]=1; x[3][5+padding]=1;
                        x[4][6+padding]=1;
                        x[5][6+padding]=1;
                        x[6][6+padding]=1;
                        x[7][1+padding]=1; x[7][2+padding]=1; x[7][3+padding]=1; x[7][4+padding]=1; x[7][5+padding]=1;
                    }       
                    if(i == 6 ){
                        x[0][1+padding]=1; x[0][2+padding]=1;x[0][3+padding]=1;x[0][4+padding]=1;x[0][5+padding]=1;x[0][6+padding]=1;
                        x[1][1+padding]=1;
                        x[2][1+padding]=1;
                        x[3][1+padding]=1;
                        x[4][1+padding]=1; x[4][2+padding]=1; x[4][3+padding]=1; x[4][4+padding]=1; x[4][5+padding]=1; x[4][6+padding]=1;
                        x[5][1+padding]=1; x[5][6+padding]=1;
                        x[6][1+padding]=1; x[6][6+padding]=1;
                        x[7][1+padding]=1; x[7][2+padding]=1; x[7][3+padding]=1; x[7][4+padding]=1; x[7][5+padding]=1; x[7][6+padding]=1;
                    }    
                    if(i == 7 ){
                        x[0][1+padding]=1; x[0][2+padding]=1; x[0][3+padding]=1; x[0][4+padding]=1; x[0][5+padding]=1; x[0][6+padding]=1;
                        x[1][6+padding]=1;
                        x[2][6+padding]=1;
                        x[3][5+padding]=1;
                        x[4][4+padding]=1;
                        x[5][3+padding]=1;
                        x[6][2+padding]=1;
                        x[7][1+padding]=1;
                    }    
                    if(i == 8 ){
                        x[0][1+padding]=1; x[0][2+padding]=1; x[0][3+padding]=1; x[0][4+padding]=1; x[0][5+padding]=1; x[0][6+padding]=1;
                        x[1][1+padding]=1; x[1][6+padding]=1;
                        x[2][1+padding]=1; x[2][6+padding]=1;
                        x[3][1+padding]=1; x[3][2+padding]=1; x[3][3+padding]=1; x[3][4+padding]=1; x[3][5+padding]=1; x[3][6+padding]=1;
                        x[4][1+padding]=1; x[4][6+padding]=1;
                        x[5][1+padding]=1; x[5][6+padding]=1;
                        x[6][1+padding]=1; x[6][6+padding]=1;
                        x[7][1+padding]=1; x[7][2+padding]=1; x[7][3+padding]=1; x[7][4+padding]=1; x[7][5+padding]=1; x[7][6+padding]=1;
                    }    
                    if(i == 9 ){
                        x[0][1+padding]=1; x[0][2+padding]=1; x[0][3+padding]=1; x[0][4+padding]=1; x[0][5+padding]=1; x[0][6+padding]=1;
                        x[1][1+padding]=1; x[1][6+padding]=1;
                        x[2][1+padding]=1; x[2][6+padding]=1;
                        x[3][1+padding]=1; x[3][2+padding]=1; x[3][3+padding]=1; x[3][4+padding]=1; x[3][5+padding]=1; x[3][6+padding]=1;
                        x[4][6+padding]=1;
                        x[5][6+padding]=1;
                        x[6][6+padding]=1;
                        x[7][1+padding]=1; x[7][2+padding]=1; x[7][3+padding]=1; x[7][4+padding]=1; x[7][5+padding]=1; x[7][6+padding]=1;
                    } 
                }
            }
        }
        lcd.draw(x,start);
        hwlib::wait_ms(1000);
        
        }
    }
}

