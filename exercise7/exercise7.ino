

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
  delay(3000);
}

void loop() {
  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("Thank You");
  delay(500);
    // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(250);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(250);
  }

 delay(1000);
 lcd.clear();
 lcd.begin(16,2);
 lcd.setCursor(2,2);
 lcd.print("Goodbye");
 delay(2000);
 
 }


