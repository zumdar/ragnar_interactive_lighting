#include <EasyTransfer.h>


//SLAVE CODE: (Arduino NANO):

//Slave code (Arduino NANO)
//Serial Communication Between Two Arduinos using RS-485
//Circuit Digest

#define HWSERIAL Serial1

int enablePin = 2;
int ledpin = 13;


void setup()
{
  Serial1.begin(9600);                   // initialize serial at baudrate 9600:
  HWSERIAL.begin(9600);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);        //  (Pin 8 always LOW to receive value from Master)

}

void loop()

{
  while (Serial1.available())                   //While have data at Serial port this loop executes
  {
    int pwmval = Serial1.parseInt();            //Receive INTEGER value from Master throught RS-485
    int convert = map(pwmval, 0, 1023, 0, 255); //Map those value from (0-1023) to (0-255)
    analogWrite(ledpin, convert);              //PWM write to LED
    Serial.println(pwmval);

  }
}
