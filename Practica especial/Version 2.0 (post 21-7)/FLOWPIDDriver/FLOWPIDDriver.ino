//// ****** THIS FILE IS AUTOGENERATED ******
////
////          >>>> DO NOT CHANGE <<<<
////
/// 
///  Filename; D:\Documentos\Licenciatura en Física\Laboratorios\Instrumentacion\Instrumentacion\Practica especial\Version 2.0 (post 21-7)\PIDDRIVER.py
///  Source class: FLOWPIDDriver
///  Generation timestamp: 2019-07-21T17:08:12.206695
///  Class code hash: b4513fff6bb16d2ee86ec4e6995533d4e153bd09
///
/////////////////////////////////////////////////////////////



// Import libraries
#include <Arduino.h>

#include "inodriver_bridge.h"
#include "inodriver_user.h"

#define BAUD_RATE 9600

void setup() {
  bridge_setup();
  
  user_setup();

  Serial.begin(BAUD_RATE);
}

void loop() {
  
  bridge_loop();
  
  user_loop();
}
