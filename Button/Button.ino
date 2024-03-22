#include "modbtn.h"
 Btn btn_mode = Btn(12,"Alarm",false);
 void setup() {
       Serial.begin(9600);
       delay(2000);
  }

void loop() {
    
     if(btn_mode.isbuttonClicked() && btn_mode.btnClick == true){
         btn_mode.debbuger();
     }
     
} 
