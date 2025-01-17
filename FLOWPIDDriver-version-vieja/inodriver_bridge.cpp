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


#include "inodriver_bridge.h"

SerialCommand sCmd;

void ok() {
  Serial.println("OK");
}

void error(const char* msg) {
  Serial.print("ERROR: ");
  Serial.println(msg);
}

void error_i(int errno) {
  Serial.print("ERROR: ");
  Serial.println(errno);
}

void bridge_loop() {
  while (Serial.available() > 0) {
    sCmd.readSerial();
  }
}

void bridge_setup() {
  //// Setup callbacks for SerialCommand commands

  // All commands might return
  //    ERROR: <error message>

  // All set commands return 
  //    OK 
  // if the operation is successfull

  // All parameters are ascii encoded strings
  sCmd.addCommand("INFO?", getInfo); 

  sCmd.setDefaultHandler(unrecognized); 


  // flow_value
  // <F> float as string 

  // Getter:
  //   Flow_value? 
  // Returns: <F> 
  sCmd.addCommand("Flow_value?", wrapperGet_Flow_value); 

  // Setter:
  //   Flow_value <F> 
  // Returns: OK or ERROR    
  sCmd.addCommand("Flow_value", wrapperSet_Flow_value); 

  // pump_flow
  // <F> float as string 
  // <I> int as string 

  // Getter:
  //   Pump_Flow? <I>
  // Returns: <F> 
  sCmd.addCommand("Pump_Flow?", wrapperGet_Pump_Flow); 

  // Setter:
  //   Pump_Flow <I> <F>
  // Returns: OK or ERROR    
  sCmd.addCommand("Pump_Flow", wrapperSet_Pump_Flow); 

  // control_loop_enabled
  // <B> bool as string: True as "1", False as "0" 

  // Getter:
  //   Control_Loop_enabled? 
  // Returns: <B> 
  sCmd.addCommand("Control_Loop_enabled?", wrapperGet_Control_Loop_enabled); 

  // Setter:
  //   Control_Loop_enabled <B> 
  // Returns: OK or ERROR    
  sCmd.addCommand("Control_Loop_enabled", wrapperSet_Control_Loop_enabled); 

  // Ki
  // <F> float as string 

  // Getter:
  //   Ki? 
  // Returns: <F> 
  sCmd.addCommand("Ki?", wrapperGet_Ki); 

  // Setter:
  //   Ki <F> 
  // Returns: OK or ERROR    
  sCmd.addCommand("Ki", wrapperSet_Ki); 

  // set_point
  // <F> float as string 

  // Getter:
  //   Set_Point? 
  // Returns: <F> 
  sCmd.addCommand("Set_Point?", wrapperGet_Set_Point); 

  // Setter:
  //   Set_Point <F> 
  // Returns: OK or ERROR    
  sCmd.addCommand("Set_Point", wrapperSet_Set_Point); 

  // Kd
  // <F> float as string 

  // Getter:
  //   Kd? 
  // Returns: <F> 
  sCmd.addCommand("Kd?", wrapperGet_Kd); 

  // Setter:
  //   Kd <F> 
  // Returns: OK or ERROR    
  sCmd.addCommand("Kd", wrapperSet_Kd); 

  // Kp
  // <F> float as string 

  // Getter:
  //   Kp? 
  // Returns: <F> 
  sCmd.addCommand("Kp?", wrapperGet_Kp); 

  // Setter:
  //   Kp <F> 
  // Returns: OK or ERROR    
  sCmd.addCommand("Kp", wrapperSet_Kp); 
}

//// Code 

void getInfo() {
  Serial.print("FLOWPIDDriver,");
  Serial.println(COMPILE_DATE_TIME);
}

void unrecognized(const char *command) {
  error("Unknown command");
}
//// Auto generated Feat and DictFeat Code
// COMMAND: Flow_value, FEAT: flow_value

void wrapperGet_Flow_value() { 
  Serial.println(get_Flow_value()); 
}; 


void wrapperSet_Flow_value() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  int err = set_Flow_value(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: Pump_Flow, FEAT: pump_flow

void wrapperGet_Pump_Flow() { 
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  int key = atoi(arg);


  Serial.println(get_Pump_Flow(key)); 
}; 


void wrapperSet_Pump_Flow() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  int key = atoi(arg);

  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  
  int err = set_Pump_Flow(key, value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: Control_Loop_enabled, FEAT: control_loop_enabled

void wrapperGet_Control_Loop_enabled() { 
  Serial.println(get_Control_Loop_enabled()); 
}; 


void wrapperSet_Control_Loop_enabled() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  int value = atoi(arg);

  int err = set_Control_Loop_enabled(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: Ki, FEAT: Ki

void wrapperGet_Ki() { 
  Serial.println(get_Ki()); 
}; 


void wrapperSet_Ki() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  int err = set_Ki(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: Set_Point, FEAT: set_point

void wrapperGet_Set_Point() { 
  Serial.println(get_Set_Point()); 
}; 


void wrapperSet_Set_Point() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  int err = set_Set_Point(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: Kd, FEAT: Kd

void wrapperGet_Kd() { 
  Serial.println(get_Kd()); 
}; 


void wrapperSet_Kd() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  int err = set_Kd(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: Kp, FEAT: Kp

void wrapperGet_Kp() { 
  Serial.println(get_Kp()); 
}; 


void wrapperSet_Kp() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  int err = set_Kp(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



