#include <VirtualWire.h> 
#define LM1 4
#define LM2 5
#define RM1 6
#define RM2 7

#define ENA 9
#define ENB 10
char command;
char *data;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  Serial.begin(9600);
  vw_set_tx_pin (2);
  vw_setup (2000);
analogWrite(ENA,200);
analogWrite(ENB,200);
}
void loop() {
if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);
    switch (command) {
      case 'F':{
        data="F";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      forward();}
        break;
      case 'B':{
        data="B";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      back();
      }
        break;
      case 'L':{
        data="L";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      left();
      }
        break;
      case 'R':{
        data="R";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      right(); 
      }
       break;
      case'S':
      {
        data="S";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
        stop();
      }
        break;
}
}
}
void stop(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
}
void forward()
{
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
}
void back()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);

}
void right()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
}  void left()
{   digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
}