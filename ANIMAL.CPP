#include <SoftwareSerial.h>

SoftwareSerial gsm(2, 3);

int trigPin = 9;
int echoPin = 10;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  gsm.begin(9600);
  delay(2000);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance < 50) {
    gsm.println("ATD+91XXXXXXXXXX;");
    delay(20000);
    gsm.println("ATH");
  }

  delay(2000);
}
