

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
const int LeftButton = 10;
const int RightButton = 11;
const int EnterButton = 12;
const int AnalogIn = 0;

int main_menu = 1;
int LeftButtonFlag = 0;
int RightButtonFlag = 0;
int EnterButtonFlag = 0;
float vin = 0.0;
float vout = 0.0; 
float R1 = 100380.0; // actual resistance of R1 (100K) default
float R2 = 9940.0; // actual resistance of R2 (10K) default
int value = 0;
int mins = 0;
void setup() {
  pinMode(LeftButton,INPUT_PULLUP);
  pinMode(RightButton,INPUT_PULLUP);
  pinMode(EnterButton,INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
 scroll_msg("Welcome");
 delay(1000);
 lcd.clear();
}

void loop() {
check_buttons();
read_analog_in();
main_display();
check_voltage();

 }


void read_analog_in() { // read the value at analog input

       value = analogRead(AnalogIn);
       vout = ((value) * 5.0) / 1024.0; 
       vin = vout / (R2/(R1+R2)); 
       
       Serial.println("Value:"); 
       Serial.println(value); 
       Serial.println("Vout:");
       Serial.println(vout); 
       if (vin<0.09) {
        vin=0.0;//statement to junk undesired reading !
        
          }
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
    lcd_display("Voltage Reading:",0,0);
    lcd.setCursor(3,1);
    lcd.print("V = ");
    lcd.print(vin);
    Serial.println(vin);
    break;
  case 2:
    lcd.clear();
    lcd_display("30s Timer",5,0);
    timer();
    break;

  case 3:
    lcd.clear();
    lcd_display("SW Version 1.1",0,0);
    break;  
}
}

void timer() {
  for (int count = 0; count < 61; count++) {
    
    lcd.setCursor(6,1);
    lcd.print("00");
    lcd.setCursor(8,1);
    
    lcd.print(":");
    lcd.print(count);
    Serial.println(count);
    delay(1000);
  }
  mins = mins+1;
  lcd.setCursor(7,1);
  lcd.print(mins);
  for (int z = 0; z  < 20; z++) {
  tone(3,1000,150);
  delay(250);
  tone(3,1100,250);
  delay(250);
  tone(3,1200,150);
  delay(250);
  tone(3,1500,250);
  }
}

void check_voltage() {
if (vin > 24.0) {
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Over Voltage!");
  Serial.println("Over Voltage");
  lcd.setCursor(3,1);
  lcd.print("V = ");
  lcd.print(vin);
  
  tone(3,1000,150);
  delay(250);
  tone(3,1100,250);
  delay(250);
  tone(3,1200,150);
  delay(250);
  tone(3,1500,250);
 
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

