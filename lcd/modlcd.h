#ifndef MOD_LCD_H
#define MOD_LCD_H
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Streaming.h>
class Lcd  {
  
  private:
    
    byte rs, en,d4,d5,d6,d7;
    String debug_msg;
    bool error_flag = false;
    int  lcd_row,lcd_col;
    void error_menu(LiquidCrystal l,String msg,String code);
    
  public:  
    void writeRow(LiquidCrystal l, int col , int row, String data);
    void writeString(LiquidCrystal l, int col , int row, String cdata);
    void scrollText(LiquidCrystal l, int col , int row, String sdata);
  public:
    Lcd(byte rs,byte en,byte d4,byte d5,byte d6,byte d7);
    LiquidCrystal init(int col,int row);
    void welcome(LiquidCrystal l);
    };

#endif
