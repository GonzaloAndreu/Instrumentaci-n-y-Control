//// ****** THIS FILE IS AUTOGENERATED ******
////
////          >>>> DO NOT CHANGE <<<<
////
/// 
///  Filename; D:\Insturmentacion 1C2019\Instrumentacion\Practica especial\PIDDRIVER.py
///  Source class: FLOWPIDDriver
///  Generation timestamp: 2019-06-18T17:00:01.426857
///  Class code hash: b4513fff6bb16d2ee86ec4e6995533d4e153bd09
///
/////////////////////////////////////////////////////////////

#ifndef inodriver_bridge_h
#define inodriver_bridge_h

#include <Arduino.h>

#include "SerialCommand.h"

#include "inodriver_user.h"

const char COMPILE_DATE_TIME[] = __DATE__ " " __TIME__;

void ok();
void error(const char*);
void error_i(int);
void bridge_loop();
void bridge_setup();

void getInfo();
void unrecognized(const char *);
void wrapperGet_Flow_value(); 
void wrapperSet_Flow_value(); 
void wrapperGet_Pump_Flow(); 
void wrapperSet_Pump_Flow(); 
void wrapperGet_Control_Loop_enabled(); 
void wrapperSet_Control_Loop_enabled(); 
void wrapperGet_Ki(); 
void wrapperSet_Ki(); 
void wrapperGet_Set_Point(); 
void wrapperSet_Set_Point(); 
void wrapperGet_Kd(); 
void wrapperSet_Kd(); 
void wrapperGet_Kp(); 
void wrapperSet_Kp(); 


#endif // inodriver_bridge_h
