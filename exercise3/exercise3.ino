void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT_PULLUP);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
delay(1000);
digitalWrite(3,HIGH);

delay(1000);

digitalWrite(3,LOW);

}
