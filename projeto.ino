#include <Arduino.h>
#include "User_Setup.h"

int trigPin = 9;
int echoPin = 2;
int ledVermelho = 12;
int ledVerde = 10;
int ledAmarelo = 11;
int ledBranco = 3;
int ledPin = 4;
int ldrPin = 0;
int ldrValor = 0;
double duration, cm;


// Declaração de Funções

void acenderLed(int corLed, double distanciaIncial, double distanciaFinal){

    (cm > distanciaIncial and cm < distanciaFinal) ? digitalWrite(corLed, LOW) : digitalWrite(corLed, HIGH);
}

void setup() {

    Serial.begin(9600);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(ledAmarelo, OUTPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(ledBranco, OUTPUT);

}

void loop(){
    ldrValor = analogRead(ldrPin);


    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(15);
    digitalWrite(trigPin, LOW);

    pinMode(echoPin, INPUT);

    duration = pulseIn(echoPin, HIGH);

    cm = (duration/2) / 29.1;

//    (ldrValor < 250 && cm < 10) ? digitalWrite(ledBranco, HIGH) : digitalWrite(ledBranco, LOW)

    analogWrite(ledBranco, cm);

    acenderLed(ledVermelho, 11, 15);
    acenderLed(ledAmarelo, 16, 30);
    acenderLed(ledVerde, 31, 50);

    Serial.print("\nValor LDR: ");
    Serial.print(ldrValor);
    Serial.print("\nDistancia: ");
    Serial.print(cm);

    delay(50);
}