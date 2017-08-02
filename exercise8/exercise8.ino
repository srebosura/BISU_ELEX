

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
const int LeftButton = 10;
const int RightButton = 11;
const int EnterButton = 12;
int main_menu = 1;
int LeftButtonFlag = 0;
int RightButtonFlag = 0;
int EnterButtonFlag = 0;
 

void setup() {
  pinMode(LeftButton,INPUT_PULLUP);
  pinMode(RightButton,INPUT_PULLUP);
  pinMode(EnterButton,INPUT_PULLUP);
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
 scroll_msg("Welcome");
 delay(1000);
 lcd.clear();
}

void loop() {
check_buttons();
main_display();

 }

void check_buttons() {
  
int readleft = digitalRead(LeftButton);
    if (readleft != 1) {
      main_menu = 1; 
    }
  delay(150);
int readright = digitalRead(RightButton);
    if(readright != 1) {
      main_menu = 2;  
    }
  delay(150);
int read_enter = digitalRead(EnterButton);
    if(read_enter != 1) {
      main_menu = 3;  
    }
  delay (150);
}



void main_display() {
  

switch (main_menu) {
  case 1:
    lcd.clear();
    lcd_display("Press Enter To",0,0);
    lcd_display("Start",5,1);
    break;
  case 2:
     lcd.clear();
    lcd_display("SETTINGS",5,0);
    lcd_display("ENTER to SAVE",2,1);
    break;

  case 3:
    lcd.clear();
    lcd_display("SW Version 1.1",0,0);
    break;  
}
}

void lcd_display(String msg,int x,int y) {
  lcd.setCursor(x,y);
  lcd.print(msg);
}

void scroll_msg (String msg) {
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(msg);
  delay(250);
    // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
}

