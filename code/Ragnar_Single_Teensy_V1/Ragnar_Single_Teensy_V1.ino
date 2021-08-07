#include <Bounce.h>

int ledPin = 13;
int inputPins [] = {2, 3, 4, 5, 6};
int outPins[] = {18, 19, 20, 21, 22};
int inputStates [] = {LOW, LOW, LOW, LOW, LOW};
int inputVal [] = {0, 0, 0, 0, 0};

const int debounceTime = 1000;

Bounce bounceSensor1 = Bounce(inputPins[0], debounceTime);
Bounce bounceSensor2 = Bounce(inputPins[1], debounceTime);
Bounce bounceSensor3 = Bounce(inputPins[2], debounceTime);
Bounce bounceSensor4 = Bounce(inputPins[3], debounceTime);
Bounce bounceSensor5 = Bounce(inputPins[4], debounceTime);


void setup() {
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Teensy Boot");

  for (int i = 0; i < 5; i++) {
    pinMode(outPins[i], OUTPUT);
  }

  for (int i = 0; i < 5; i++) {
    pinMode(inputPins[i], INPUT_PULLDOWN);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor1();
  sensor2();
  sensor3();
  sensor4();
  sensor5();
}

void sensor1() {
  bounceSensor1.update();
  inputVal[0] = bounceSensor1.read();

  if (inputVal[0] == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (inputStates[0] == LOW) {
      Serial.println("Sensor 1 motion detected");
      digitalWrite(outPins[0], HIGH);
      Serial.println(digitalRead(outPins[0]));
      inputStates[0] = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (inputStates[0] == HIGH) {
      Serial.println("Sensor 1 motion ended");
      digitalWrite(outPins[0], LOW);
      Serial.println(digitalRead(outPins[0]));
      inputStates[0] = LOW;
    }
  }
}

void sensor2() {
  bounceSensor2.update();
  inputVal[1] = bounceSensor2.read();

  if (inputVal[1] == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (inputStates[1] == LOW) {
      Serial.println("Sensor 2 motion detected");
      digitalWrite(outPins[1], HIGH);
      Serial.println(digitalRead(outPins[1]));
      inputStates[1] = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (inputStates[1] == HIGH) {
      Serial.println("Sensor 2 motion ended");
      digitalWrite(outPins[1], LOW);
      Serial.println(digitalRead(outPins[1]));
      inputStates[1] = LOW;
    }
  }
}

void sensor3() {
  bounceSensor3.update();
  inputVal[2] = bounceSensor3.read();

  if (inputVal[2] == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (inputStates[2] == LOW) {
      Serial.println("Sensor 3 motion detected");
      digitalWrite(outPins[2], HIGH);
      Serial.println(digitalRead(outPins[2]));
      inputStates[2] = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (inputStates[2] == HIGH) {
      Serial.println("Sensor 3 motion ended");
      digitalWrite(outPins[2], LOW);
      Serial.println(digitalRead(outPins[2]));
      inputStates[2] = LOW;
    }
  }
}

void sensor4() {
  bounceSensor4.update();
  inputVal[3] = bounceSensor4.read();

  if (inputVal[3] == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (inputStates[3] == LOW) {
      Serial.println("Sensor 4 motion detected");
      digitalWrite(outPins[3], HIGH);
      Serial.println(digitalRead(outPins[3]));
      inputStates[3] = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (inputStates[3] == HIGH) {
      Serial.println("Sensor 4 motion ended");
      digitalWrite(outPins[3], LOW);
      Serial.println(digitalRead(outPins[3]));
      inputStates[3] = LOW;
    }
  }
}

void sensor5() {
  bounceSensor5.update();
  inputVal[4] = bounceSensor5.read();

  if (inputVal[4] == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (inputStates[4] == LOW) {
      Serial.println("Sensor 5 motion detected");
      digitalWrite(outPins[4], HIGH);
      Serial.println(digitalRead(outPins[4]));
      inputStates[4] = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (inputStates[4] == HIGH) {
      Serial.println("Sensor 5 motion ended");
      digitalWrite(outPins[4], LOW);
      Serial.println(digitalRead(outPins[4]));
      inputStates[4] = LOW;
    }
  }
}
