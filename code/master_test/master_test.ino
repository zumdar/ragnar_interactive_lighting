//Master (Arduino UNO):

//Master code (Arduino UNO)
//Serial Communication Between Arduino using RS-485

#define HWSERIAL Serial1

int enablePin = 2;
int potPin = 0 ;
int led = 13;


void setup()
{
  Serial.begin(9600);            // initialize serial at baudrate 9600:
  HWSERIAL.begin(9600);
  pinMode(enablePin, OUTPUT);
  pinMode(potPin, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(enablePin, HIGH);  //  (always high as Master Writes data to Slave)
  digitalWrite(led, HIGH);  //  (always high as Master Writes data to Slave)
}
void loop()
{
  int potval = analogRead(potPin);
  int convert = map(potval, 0, 1023, 0, 255); //Map those value from (0-1023) to (0-255)
  analogWrite(led, convert);              //PWM write to LED
  Serial.println(potval);          //Serial Write POTval to RS-485 Bus
  HWSERIAL.println(potval);

}
