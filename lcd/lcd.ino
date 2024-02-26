#include "modlcd.h"
#define ROW 4
#define COL 20
#define LCD_RS 2
#define LCD_EN 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7
Lcd mod_lcd(LCD_RS,LCD_EN,LCD_D4,LCD_D5,LCD_D6,LCD_D7);
LiquidCrystal lcd_helper = mod_lcd.init(COL,ROW);

void setup() {
     mod_lcd.welcome(lcd_helper);
     delay(5000);
     lcd_helper.clear();
    }

void loop() {
    String data  = "LCD OOP";
    mod_lcd.scrollText(lcd_helper, 0 , 0,data);
    }
