/**
   Leader Code
   Using Teensey 3.2
**/

#include <Firmata.h>

//uncomment to debug
#define DEBUG

#define HWSONE Serial1 //Serial com with follower 1
#define HWSTWO Serial2 //Serial com with follower 1
#define HWSTHREE Serial3 //Serial com with follower 1
#define HWSFOUR Serial4 //Serial com with follower 1

#define ledPin 13



//enable pins for rs485 com set to low to receive data
int enablePins [] = {2, 3, 11, 12};
int followerValues [] = {0, 0, 0, 0, 0};
int followerStates [] = {LOW, LOW, LOW, LOW, LOW};

void setup() {

  Firmata.setFirmwareVersion(FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);
  Firmata.attach(DIGITAL_MESSAGE, digitalWriteCallback);
  Firmata.begin(57600);

#ifdef DEBUG
  Serial.begin(9600);
  Serial.println("Leader Booted");
#endif

  //start com with followers
  HWSONE.begin(9600);
  HWSTWO.begin(9600);
  HWSTHREE.begin(9600);
  HWSFOUR.begin(9600);


  //assign pins
  for (int i = 0; i < 4; i++) {
    pinMode(enablePins[i], OUTPUT);
  }

  for (int i = 0; i < 4; i++) {
    digitalWrite(enablePins[i], LOW);
  }

  //led boy
  pinMode(ledPin, OUTPUT);
}

void loop() {
  followerOne();
  followerTwo();
  followerThree();
  followerFour();
}

void followerOne() {
  while (HWSONE.available()) {
    followerValues[0] = HWSONE.read();
    if (followerValues[0] == 1) {
      digitalWrite(ledPin, HIGH);
      if (followerStates[0] == LOW) {
        //firmata goes here
#ifdef DEBUG
        Serial.println("send data to computer world from follower One A");
#endif
        followerStates[0] = HIGH;
      }
    } else {
      digitalWrite(ledPin, LOW);
      if (followerStates[0] == HIGH) {
        followerStates[0] = LOW;
      }
    }
  }

  while (HWSONE.available()) {
    followerValues[1] = HWSONE.read();
    if (followerValues[1] == 2) {
      digitalWrite(ledPin, HIGH);
      if (followerStates[1] == LOW) {
        //firmata goes here
#ifdef DEBUG
        Serial.println("send data to computer world from follower One B");
#endif
        followerStates[1] = HIGH;
      }
    } else {
      digitalWrite(ledPin, LOW);
      if (followerStates[1] == HIGH) {
        followerStates[1] = LOW;
      }
    }
  }
}

void followerTwo() {
  while (HWSTWO.available()) {
    followerValues[2] = HWSTWO.read();
    if (followerValues[2] == HIGH) {
      digitalWrite(ledPin, HIGH);
      if (followerStates[2] == LOW) {
        //firmata goes here
#ifdef DEBUG
        Serial.println("send data to computer world from follower two");
#endif
        followerStates[2] = HIGH;
      }
    } else {
      digitalWrite(ledPin, LOW);
      if (followerStates[2] == HIGH) {
        followerStates[2] = LOW;
      }
    }
  }
}

void followerThree() {
  while (HWSTHREE.available()) {
    followerValues[3] = HWSTHREE.read();
    if (followerValues[3] == HIGH) {
      digitalWrite(ledPin, HIGH);
      if (followerStates[3] == LOW) {
        //firmata goes here
#ifdef DEBUG
        Serial.println("send data to computer world from follower three");
#endif
        followerStates[3] = HIGH;
      }
    } else {
      digitalWrite(ledPin, LOW);
      if (followerStates[3] == HIGH) {
        followerStates[3] = LOW;
      }
    }
  }
}

void followerFour() {
  while (HWSFOUR.available()) {
    followerValues[4] = HWSFOUR.read();
    if (followerValues[4] == HIGH) {
      digitalWrite(ledPin, HIGH);
      if (followerStates[4] == LOW) {
        //firmata goes here
#ifdef DEBUG
        Serial.println("send data to computer world from follower four");
#endif
        followerStates[4] = HIGH;
      }
    } else {
      digitalWrite(ledPin, LOW);
      if (followerStates[4] == HIGH) {
        followerStates[4] = LOW;
      }
    }
  }
}
