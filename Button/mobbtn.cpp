#include "modbtn.h"
 Btn::Btn(byte pin,String bname){
     this->pin = pin;
     this->btnname = bname;
     lastReading = LOW;
     
     init();
     }
   
     void Btn::init(){
       pinMode(pin,INPUT_PULLUP);
       btnUpdate();
      }
     void Btn::btnUpdate()
      {
       
        byte newReading = digitalRead(this->pin);
        
          if(newReading != lastReading){
                 lastDebounceTime =millis();
            }
          if((millis() - lastDebounceTime) > debounceDelay){
                  state = newReading;
            }
       lastReading = newReading;
      
     }
     byte Btn::getState(){
        btnUpdate();
        return state;
     }
     bool Btn::getStikyKey(){
      return this->stikyKey; 
     }
     void Btn::setStikyKey(bool key){
       this->stikyKey = key;  
     }
     bool Btn::isBtnPressed(){
       return (getState() == HIGH);
        
     }
     String Btn::getBtnname(){
      return this->btnname;
    
    }

   void Btn::debbuger(){
        bool sbtn  = getState();
        String btnstate = String(sbtn ? "Pressed":"Released");
        Serial<<"Button module\n"<<"Name:"<< btnname<<endl;
        Serial<<"Status:"<<btnstate<<"\nValue:"<<sbtn<<endl;
        Serial<<"Stiky key:"<<getStikyKey()<<"\n\n"<<endl;
        }
