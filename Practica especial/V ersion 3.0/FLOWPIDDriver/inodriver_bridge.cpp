//// ****** THIS FILE IS AUTOGENERATED ******
////
////          >>>> DO NOT CHANGE <<<<
////
/// 
///  Filename; D:\Documentos\Licenciatura en Física\Laboratorios\Instrumentacion\Instrumentacion\Practica especial\V ersion 3.0\PIDDRIVER.py
///  Source class: FLOWPIDDriver
///  Generation timestamp: 2019-07-25T19:30:32.518211
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


  // pumpflowvalue1
  // <F> float as string 

  // Getter:
  //   PF1? 
  // Returns: <F> 
  sCmd.addCommand("PF1?", wrapperGet_PF1); 

  // Setter:
  //   PF1 <F> 
  // Returns: OK or ERROR    
  sCmd.addCommand("PF1", wrapperSet_PF1); 

  // pumpflowvalue2
  // <F> float as string 

  // Getter:
  //   PF2? 
  // Returns: <F> 
  sCmd.addCommand("PF2?", wrapperGet_PF2); 

  // Setter:
  //   PF2 <F> 
  // Returns: OK or ERROR    
  sCmd.addCommand("PF2", wrapperSet_PF2); 

  // kd
  // <F> float as string 

  // Getter:
  //   KD? 
  // Returns: <F> 
  sCmd.addCommand("KD?", wrapperGet_KD); 

  // Setter:
  //   KD <F> 
  // Returns: OK or ERROR    
  sCmd.addCommand("KD", wrapperSet_KD); 

  // flowvalue
  // <F> float as string 

  // Getter:
  //   FV? 
  // Returns: <F> 
  sCmd.addCommand("FV?", wrapperGet_FV); 

  // setpoint
  // <F> float as string 

  // Getter:
  //   SP? 
  // Returns: <F> 
  sCmd.addCommand("SP?", wrapperGet_SP); 

  // Setter:
  //   SP <F> 
  // Returns: OK or ERROR    
  sCmd.addCommand("SP", wrapperSet_SP); 

  // CLENABLE
  // <B> bool as string: True as "1", False as "0" 

  // Getter:
  //   CLENABLE? 
  // Returns: <B> 
  sCmd.addCommand("CLENABLE?", wrapperGet_CLENABLE); 

  // Setter:
  //   CLENABLE <B> 
  // Returns: OK or ERROR    
  sCmd.addCommand("CLENABLE", wrapperSet_CLENABLE); 

  // kp
  // <F> float as string 

  // Getter:
  //   KP? 
  // Returns: <F> 
  sCmd.addCommand("KP?", wrapperGet_KP); 

  // Setter:
  //   KP <F> 
  // Returns: OK or ERROR    
  sCmd.addCommand("KP", wrapperSet_KP); 

  // ki
  // <F> float as string 

  // Getter:
  //   LI? 
  // Returns: <F> 
  sCmd.addCommand("LI?", wrapperGet_LI); 

  // Setter:
  //   LI <F> 
  // Returns: OK or ERROR    
  sCmd.addCommand("LI", wrapperSet_LI); 
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
// COMMAND: PF1, FEAT: pumpflowvalue1

void wrapperGet_PF1() { 
  Serial.println(get_PF1()); 
}; 


void wrapperSet_PF1() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  int err = set_PF1(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: PF2, FEAT: pumpflowvalue2

void wrapperGet_PF2() { 
  Serial.println(get_PF2()); 
}; 


void wrapperSet_PF2() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  int err = set_PF2(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: KD, FEAT: kd

void wrapperGet_KD() { 
  Serial.println(get_KD()); 
}; 


void wrapperSet_KD() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  int err = set_KD(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: FV, FEAT: flowvalue

void wrapperGet_FV() { 
  Serial.println(get_FV()); 
}; 



// COMMAND: SP, FEAT: setpoint

void wrapperGet_SP() { 
  Serial.println(get_SP()); 
}; 


void wrapperSet_SP() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  int err = set_SP(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: CLENABLE, FEAT: CLENABLE

void wrapperGet_CLENABLE() { 
  Serial.println(get_CLENABLE()); 
}; 


void wrapperSet_CLENABLE() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  int value = atoi(arg);

  int err = set_CLENABLE(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: KP, FEAT: kp

void wrapperGet_KP() { 
  Serial.println(get_KP()); 
}; 


void wrapperSet_KP() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  int err = set_KP(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



// COMMAND: LI, FEAT: ki

void wrapperGet_LI() { 
  Serial.println(get_LI()); 
}; 


void wrapperSet_LI() {
  char *arg;
  
  arg = sCmd.next();
  if (arg == NULL) {
    error("No value stated");
    return;
  }
  float value = atof(arg);

  int err = set_LI(value);
  if (err == 0) {
    ok();
  } else {
    error_i(err);
  }
};



