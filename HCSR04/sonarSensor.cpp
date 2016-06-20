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
//       Part of   : library for a HC-SR04 Sonar Sensor                                               +
//                                                                                                    +
//       Distributed under the Boost Software License, Version 1.0.                                   +
//       (See accompanying file LICENSE_1_0.txt or copy at                                            +
//       http://www.boost.org/LICENSE_1_0.txt)                                                        +
//                                                                                                    +
//                                                                                                    +
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include "hwlib.hpp"
#include "sonarSensor.hpp"
/// sonarSensor Constructor
//
/// This constructor consists of 2 pins. 
/// Trigger: This pin is the signal that goes from the Arduino to the HC-SR04. It triggers the sensor to start a measurment cycle.
/// Echo: This pin is the signal that goes from the HC-SR04 to the Arduino, the time it returns a high voltage can be translated into distance. 
/// It also includes the constructor from its super class. 
sonarSensor::sonarSensor(hwlib::target::pin_out & p_trigger, hwlib::target::pin_in & p_echo):
    distanceSensors(),
    trigger(p_trigger),
    echo(p_echo)
        {}   

/// MsDistacne; int
//
/// Parameters: None.
/// Variables: 
/// Counter     =   Starts at 0, is used to measure the time that has passed. 
/// RawDistance =   The return variabel. Is the distance in Cm*100. 
/// This function makes the HC-SR04 start a measurement cycle. It starts the cycle and adds 1 to the counter for every microsecond echo is high. 
/// It returns an int, which consist of the measured time echo was high divided by an amount that was based on real life testing. It is multiplied times 100 to
/// make sure there is more accuracy in the measurement.

int sonarSensor::MsDistance(){
    int counter=0;
    
    trigger.set(0);
    hwlib::wait_us(1);
    trigger.set(1);
    hwlib::wait_us(10);
    trigger.set(0);

    while(!echo.get()){
      hwlib::wait_us(1);  
    }
    while(echo.get()){
        counter++;
        hwlib::wait_us(1);
    }
    int RawDistance = (counter/13.10)*100;
    hwlib::wait_ms(2);
    return RawDistance;
}

/// TriggerInRange; int
//
/// Parameters: MinimalDistance; int. MaximumDistance; int. PercentageEnable; int. 
/// MinimalDistance,MaximumDistance: Both in Cm. Gives us the range which to work with.
/// PercentageEnable: Enables the return in percentages. 
//
/// Variables: 
/// max,min = Both are simply the parameters *100, because MsDistance returns Cm * 100. Keeping one standard helps with the math.
/// RawDistance =  The return of MsDistance. Is the distance in Cm*100.    
//
/// This function was mostly made for its percentage return making it very usefull for controls in games and other applications.
/// The function returns a percentage within the trigger range with minimaldistance as baseline.   

int sonarSensor::TriggerInRange(int MinimalDistance, int MaximumDistance, bool PercentageEnable){
    int min = MinimalDistance*100;
    int max = MaximumDistance*100;
    int RawDistance=MsDistance();
    int z=(RawDistance);
    
    if((z >= min  ) && (z <= max)){
        if(!PercentageEnable){
            int x=z-min;
            return x; 
        }
        if(PercentageEnable){
           int x=z-min;
           int y=max-min;
           return ((x*100)/y); 
        }
    }
    return 0;
}


/// Trigger; boolean
//
/// Parameters: MinimalDistance, MaximumDistance, SetConstantTrigger
/// MinimalDistance,MaximumDistance: Both in Cm. Gives us the range which to work with.
/// SetConstantTrigger: Enables the while loop for constant measuring. 
//
/// Variables:
/// max,min = Both are simply the parameters *100, because MsDistance returns Cm * 100. Keeping one standard helps with the math.  
/// RawDistance =   The return variabel from MsDistance(). Is the distance in Cm*100. 
//
/// Simple trigger returning 1 when triggered. Build-in while loop if needed. 

bool sonarSensor::Trigger(int MinimalDistance, int MaximumDistance, bool SetConstantTrigger){
    int min = MinimalDistance*100;
    int max = MaximumDistance*100;
    int RawDistance=MsDistance();
    if(SetConstantTrigger){
            while(1){
                int RawDistance=MsDistance();
                if(min<=RawDistance && RawDistance <= max){
                    return 1;
                }
            }
    }
    if(min<=RawDistance && RawDistance <= max){
        return 1;
    }
    return 0;
}







