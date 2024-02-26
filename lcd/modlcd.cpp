#include "modlcd.h"
Lcd::Lcd(byte rs,byte en,byte d4,byte d5,byte d6,byte d7) {
  this->rs = rs;
  this->en = en;
  this->d4 = d4;
  this->d5 = d5;
  this->d6 = d6;
  this->d7 = d7;
  this->error_flag = false;
  
 }
   LiquidCrystal Lcd::init(int col, int row) 
     {
        this->lcd_col = col;
        this->lcd_row = row;
        LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
        lcd.begin(this->lcd_col,this->lcd_row);
       return lcd;
    }
    void Lcd::writeRow(LiquidCrystal l, int col , int row, String data){
          l.setCursor(0,row);
          l<<"                    ";
          l.setCursor(col,row);  
          l<<data;
          this->debug_msg = __func__;
      }
      
      void Lcd::writeString(LiquidCrystal l, int col, int row, String cdata){
        int data_length = cdata.length();
        String space =  " ";
        String str;
        for(int i = 0; i < data_length; i++){
               str+= space;
          }
         l.setCursor(col,row);
         l<<str;
         
         l.setCursor(col,row);
          l<<cdata;
          this->debug_msg = __func__;
       } 
       
     void Lcd::welcome(LiquidCrystal l)
         {
           l.clear();
           this->writeRow(l,1,0,"LCD Library module");
           this->writeRow(l,5,1,"OOP Design");
           this->writeRow(l,8,2,"BY"); 
           this->writeRow(l,3,3,"Bonolo K Nyoni");   
           this->debug_msg =__func__;
         }
      void Lcd::scrollText(LiquidCrystal l, int col , int row, String sdata){
             int ldata   = sdata.length();
             l.setCursor(col,row);
             while(true){
               
               int screenText  = col+ldata;
               this->writeString(l,col,row,sdata);
               delay(200);
               l.clear();
               col = col + 1;
                  if(screenText >= this->lcd_col){
                      row = row + 1;
                      col = 0;
                      }
                  if(row > ( this->lcd_row -1)){
                      col = 0;
                      row = 0;
                    }  
                  }
              }   
   
    
  
