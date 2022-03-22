# Schorschis Periodic Table

## Summary

- Use LCD Keypad Shield with 6 buttons.
- Show a part of a period table.
- move the window with buttons.

## Ingrediants

- LCD 1602 Display Keypad Shield HD44780
- Arduino Uno (ATmega328)
- Cable
- micro USB -> TypeC converter cable 
- Macbook Pro

------------------------------------------
## Trial 1.
### Goal
- Write a code with library.
- Upload the code to Arduino
- Run the code
  + Initialize LCD
  + Show 'Periodic Table' on the LCD

### Import library
Tools -> Manage Library

### Check syntax
"v"

### Upload program
"->"

### Select Device
- Tools -> Ports -> (Select that looks likely)


### Code
'''
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

//this sketch is for 1602A with shield (buttons)

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Periodic Table!");

}

'''

------------------------------------------
## Trial 2.
### Goal
- Use keypad to move the window
  (=move the text)

### Goal


## Reference
1. http://physics.cocolog-nifty.com/weblog/2018/07/arduino18lcd-8c.html
2. https://picavr.uunyan.com/avr_m2_dds_fg_ctrl.html
3. https://forum.arduino.cc/t/a-true-array-of-strings-heres-how-i-did-it-using-pointers/319474/2
4. https://www.arduino.cc/en/Reference/LiquidCrystal