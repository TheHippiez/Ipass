#include "hwlib.hpp"
#include "sonarSensor.hpp"
#include "guardObject.hpp"
#include "lcdScreen.hpp"
#include "distanceMeter.hpp"
#include "radar.hpp"



int main(int argc, char **argv)
{
    WDT->WDT_MR = WDT_MR_WDDIS;
/////////////////////////////////////////////////////////////////////////////////////////// Raw distance

//    hwlib::wait_ms(1000);
//
//    auto trigger1   =  hwlib::target::pin_out(  hwlib::target::pins::d2 );
//    auto echo1      =  hwlib::target::pin_in(  hwlib::target::pins::d11 );
//    
//    sonarSensor Sensor1 (trigger1,echo1);
//    
//    int x = Sensor1.MsDistance();
//    hwlib::cout<<x;
//    }
    

////////////////////////////////////////////////////////////////////////////////////////// Distance Meter

//    hwlib::wait_ms(1000);
//
//    auto reset       =  hwlib::target::pin_out(  hwlib::target::pins::d21 );
//    auto enable      =  hwlib::target::pin_out(  hwlib::target::pins::d20 );
//    auto datacommand =  hwlib::target::pin_out(  hwlib::target::pins::d19 );
//    auto clock       =  hwlib::target::pin_out(  hwlib::target::pins::d17 );
//    auto datain      =  hwlib::target::pin_out(  hwlib::target::pins::d18 );
//
//    auto button      =  hwlib::target::pin_in(  hwlib::target::pins::d8 );
//
//    auto trigger1   =  hwlib::target::pin_out(  hwlib::target::pins::d2 );
//    auto echo1      =  hwlib::target::pin_in(  hwlib::target::pins::d11 );

//    lcdScreen myScreen (enable,datacommand,clock,datain,reset)  ;  
//    sonarSensor Sensor1 (trigger1,echo1);
//    
//    
//    distanceMeter meter (Sensor1,myScreen,button);
//    meter.MeasureDist(0);

    
///////////////////////////////////////////////////////////////////////////////////////////////Radar
    hwlib::wait_ms(1000);

    auto reset       =  hwlib::target::pin_out(  hwlib::target::pins::d21 );
    auto enable      =  hwlib::target::pin_out(  hwlib::target::pins::d20 );
    auto datacommand =  hwlib::target::pin_out(  hwlib::target::pins::d19 );
    auto clock       =  hwlib::target::pin_out(  hwlib::target::pins::d17 );
    auto datain      =  hwlib::target::pin_out(  hwlib::target::pins::d18 );

    auto button      =  hwlib::target::pin_in(  hwlib::target::pins::d8 );

    auto trigger1   =  hwlib::target::pin_out(  hwlib::target::pins::d2 );
    auto echo1      =  hwlib::target::pin_in(  hwlib::target::pins::d11 );
    
    auto trigger2   =  hwlib::target::pin_out(  hwlib::target::pins::d3 );
    auto echo2      =  hwlib::target::pin_in(  hwlib::target::pins::d10 );
    
    auto trigger3   =  hwlib::target::pin_out(  hwlib::target::pins::d4 );
    auto echo3      =  hwlib::target::pin_in(  hwlib::target::pins::d7 );
    
    auto trigger4   =  hwlib::target::pin_out(  hwlib::target::pins::d5 );
    auto echo4      =  hwlib::target::pin_in(  hwlib::target::pins::d6 );
    
    lcdScreen myScreen (enable,datacommand,clock,datain,reset)  ;  
    
    sonarSensor Sensor1 (trigger1,echo1);
    sonarSensor Sensor2 (trigger2,echo2);
    sonarSensor Sensor3 (trigger3,echo3);
    sonarSensor Sensor4 (trigger4,echo4);
    
    radar TestRadar (Sensor1, Sensor2, Sensor3, Sensor4, myScreen, button );
    TestRadar.sonarRadar(3,30);
    
    
    
//////////////////////////////////////////////////////////////////////////////////////////////Guard object
//    hwlib::wait_ms(1000);
//
//    auto reset       =  hwlib::target::pin_out(  hwlib::target::pins::d21 );
//    auto enable      =  hwlib::target::pin_out(  hwlib::target::pins::d20 );
//    auto datacommand =  hwlib::target::pin_out(  hwlib::target::pins::d19 );
//    auto clock       =  hwlib::target::pin_out(  hwlib::target::pins::d17 );
//    auto datain      =  hwlib::target::pin_out(  hwlib::target::pins::d18 );
//
//
//    auto trigger1   =  hwlib::target::pin_out(  hwlib::target::pins::d2 );
//    auto echo1      =  hwlib::target::pin_in(  hwlib::target::pins::d11 );
//    
//    lcdScreen myScreen (enable,datacommand,clock,datain,reset);  
//    sonarSensor Sensor1 (trigger1,echo1);
//    GuardObject Gaurd (Sensor1,myScreen,100 );
//    
//    Gaurd.Guard();
// 
//    }
//    hwlib::wait_ms(1000);
//
//    auto reset       =  hwlib::target::pin_out(  hwlib::target::pins::d21 );
//    auto enable      =  hwlib::target::pin_out(  hwlib::target::pins::d20 );
//    auto datacommand =  hwlib::target::pin_out(  hwlib::target::pins::d19 );
//    auto clock       =  hwlib::target::pin_out(  hwlib::target::pins::d17 );
//    auto datain      =  hwlib::target::pin_out(  hwlib::target::pins::d18 );
//
//    auto button      =  hwlib::target::pin_in(  hwlib::target::pins::d8 );
//
//    auto trigger1   =  hwlib::target::pin_out(  hwlib::target::pins::d2 );
//    auto echo1      =  hwlib::target::pin_in(  hwlib::target::pins::d11 );
//    lcdScreen myScreen (enable,datacommand,clock,datain,reset)  ;  
//    sonarSensor Sensor1 (trigger1,echo1);
//    
//    HWLIB_TRACE;
//    distanceMeter meter (Sensor1,myScreen,button);
//    meter.MeasureDist(0);
//    HWLIB_TRACE;


 
    
}
    

