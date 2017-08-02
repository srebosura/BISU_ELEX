

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);


void setup() {
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(2,0);
  lcd.print("HELLO WORLD");
  lcd.setCursor(2,1);
  lcd.print("ELECTRONICS");
  delay(1000);
}

void loop() {
 
 
 }







void scroll (String msg) {
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print(msg);
  delay(500);
    // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(250);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(250);
  }

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(250);
  }

  // delay at the end of the full loop:
  delay(500);
  
}

