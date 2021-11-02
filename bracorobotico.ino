#include <SoftwareSerial.h> 
#include <Servo.h> 

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
int bluetoothTx = 10; 
int bluetoothRx = 11;
int starts1, starts2, starts3, starts4, starts5;
 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
 
void setup()
{
  myservo1.attach(9);
  myservo2.attach(8);
  myservo3.attach(7);
  myservo4.attach(6);
  myservo5.attach(5);
  Serial.begin(9600);
  bluetooth.begin(9600);

  starts1 = 90;
  myservo1.write(starts1);
  starts2 = 90;
  myservo2.write(starts2);
  starts3 = 90;
  myservo3.write(starts3);
  starts4 = 90;
  myservo4.write(starts4);
  starts5 = 90;
  myservo5.write(starts5);
} 
void loop()
{
  if(bluetooth.available()> 0 ) 
  {
    int servopos = bluetooth.read(); 
    Serial.print("recebido do bluetooth ");
    Serial.println(servopos);
    
    if(servopos <=42 && servopos >=1){
    int servopos1 = servopos;
    servopos1 = map(servopos1, 1, 42, 17, 100);
    Serial.print("variação servo1 ");
    Serial.println(servopos1); 
    myservo1.write(servopos1);
    delay(1);
    }
    if(servopos >=43 && servopos <=84){
    int servopos2 = servopos;
    servopos2 = map(servopos2, 43, 84, 0, 180);
    Serial.print("variação servo2 ");
    Serial.println(servopos2); 
    myservo2.write(servopos2);
    delay(1);
    }
    if(servopos >=85 && servopos <=126){
    int servopos3 = servopos;
    servopos3 = map(servopos3, 85, 126, 0, 180);
    Serial.print("variação servo3 ");
    Serial.println(servopos3); 
    myservo3.write(servopos3);
    delay(1);
    }
    if(servopos >=127 && servopos <=168){
    int servopos4 = servopos;
    servopos4 = map(servopos4, 127, 168, 0, 180);
    Serial.print("variação servo4 ");
    Serial.println(servopos4); 
    myservo4.write(servopos4);
    delay(1);
    }
    if(servopos >=169 && servopos <=210){
    int servopos5 = servopos;
    servopos5 = map(servopos5, 169, 210, 0, 180);
    Serial.print("variação servo5 ");
    Serial.println(servopos5); 
    myservo5.write(servopos5);
    delay(1);
    }
  }
}
