int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int sw1 = 2;

void setup() {
  // put your setup code here, to run once:
pinMode(sw1,INPUT_PULLUP);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);

}

void led_control(int a,int b,int c,int d) {

digitalWrite(led1,a);
digitalWrite(led2,b);
digitalWrite(led3,c);
digitalWrite(led4,d);
}

void loop() {
  // put your main code here, to run repeatedly:
led_control(1,0,0,0);
delay(500);
led_control(0,1,0,0);
delay(500);
led_control(0,0,1,0);
delay(500);
led_control(0,0,0,1);
delay(500);
}
