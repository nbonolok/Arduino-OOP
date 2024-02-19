#include "modbtn.h"
 Btn btn_mode = Btn(12,"Alarm");
 void setup() {
       Serial.begin(9600);
       delay(2000);
  }

void loop() {
    
    if(btn_mode.isBtnPressed() && (btn_mode.getStikyKey() == false)){
         btn_mode.setStikyKey(true); 
         btn_mode.debbuger();
          
     } 
     if(!btn_mode.isBtnPressed() && (btn_mode.getStikyKey() == true)){
         if(btn_mode.getStikyKey() == true){
              btn_mode.debbuger();
          }
         btn_mode.setStikyKey(false); 
         
     } 
     
} 
