#ifndef MOD_BTN_H
#define MOD_BTN_H
#include <Arduino.h>
#include <Streaming.h>
class Btn {
private:
    byte pin;
    byte state;
    byte lastReading;
    String btnname;
    bool  stikyKey = false;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 50;
    
 public:
           Btn(byte pin,String bname); 
           void init();
           void btnUpdate();
           byte getState();
           bool isBtnPressed();
           bool getStikyKey();
           void setStikyKey(bool key);
public: 
         String getBtnname();
         void debbuger();
};
#endif
