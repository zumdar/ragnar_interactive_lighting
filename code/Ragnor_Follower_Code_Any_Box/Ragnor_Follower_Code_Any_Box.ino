/**
   Follower Code
   Using Teensey 3.2
**/

//uncomment to debug
#define DEBUG

#define HWSERIAL Serial2 //communicate to leader

#define enablePin 6 //High to send data low to receive data change to 8 for teensey3.2
#define ledPin 13 //visual indication 
#define dataPinOne 14 //collects data to send to leader
#define dataPinTwo 15 //collects data to send to leader 

byte valPirOne = 0; // pir value
int pirStateOne = LOW; //state of pir sensor

byte valPirTwo = 0;
int pirStateTwo = LOW;

void setup() {

#ifdef DEBUG
  Serial.begin(9600);
  Serial.println("Teensey Booted");
#endif

  HWSERIAL.begin(9600);

  //rs485 communicatino protocol
  pinMode(enablePin, OUTPUT); //IO pin configuration
  digitalWrite(enablePin, HIGH); //Always high because we send data constantly

  pinMode(ledPin, OUTPUT); //led pin configuration
  pinMode(dataPinOne, INPUT_PULLDOWN); //input pin for pir sensor
  pinMode(dataPinTwo, INPUT_PULLDOWN);

}

void loop() {
  pirDetection();
}

void pirDetection() {
  valPirOne = digitalRead(dataPinOne);
  valPirTwo = digitalRead(dataPinTwo);

  //sensor 1 motion detected
  if (valPirOne == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (pirStateOne == LOW) {
      HWSERIAL.write(2);
#ifdef DEBUG
      Serial.println("motion detected sensor 1 sending value");
#endif
      pirStateOne = HIGH;
    }
  }
  //sensor motion capture over
  if (valPirOne == LOW) {
    digitalWrite(ledPin, LOW);
    if (pirStateOne == HIGH) {
      HWSERIAL.write(0);
#ifdef DEBUG
      Serial.println("motion ended sensor 1"); //takes 3 seconds to reset
#endif
      pirStateOne = LOW;
    }
  }
  //sensor 2
  if (valPirTwo == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (pirStateTwo == LOW) {
      HWSERIAL.write(3);
#ifdef DEBUG
      Serial.println("motion detected sensor 2 sending value");
#endif
      pirStateTwo = HIGH;
    }
  }

  if (valPirTwo == LOW) {
    digitalWrite(ledPin, LOW);
    if (pirStateTwo == HIGH) {
      HWSERIAL.write(1);
#ifdef DEBUG
      Serial.println("motion ended sensor 2"); //takes 3 seconds to reset
#endif
      pirStateTwo = LOW;
    }
  }
}
