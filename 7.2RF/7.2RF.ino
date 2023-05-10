//BY-VANSH GABA
#include <VirtualWire.h>
#define LM1 2//(orange) //+ve(out1)
#define LM2 3//(yellow)
#define RM1 4//(red)  //+ve(out3)
#define RM2 5//(green)

#define leftspeedcontrol 9
#define rightspeedcontrol 10

void setup() 
{
  // put your setup code here, to run once:
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  Serial.begin(9600);
  vw_set_rx_pin(2);
  vw_setup (2000);
  pinMode(2,INPUT);
  vw_rx_start();
analogWrite(leftspeedcontrol,200);
analogWrite(rightspeedcontrol,200);
}
void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen=VW_MAX_MESSAGE_LEN;
  Serial.println(buf[0]);
if (vw_get_message(buf,&buflen)) {
    switch (buf[0]) {
      case 'F':
        forward();
        break;
      case 'B':
       back();
        break;
      case 'L':
       left();
        break;
      case 'R':
      right(); 
        break;
      case'S':
        stop();
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
void left()
{   digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);

}
void right()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
}