#include "DHT.h"

#define DHTTYPE DHT11

int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;

struct SensorSuhu {
  int pin;
  float suhuCelcius;
  char namaZona[10];
};

SensorSuhu zona1 = {A5, 0.0, "Zona 1"};
SensorSuhu zona2 = {A4, 0.0, "Zona 2"};

DHT dht1(zona1.pin, DHTTYPE);
DHT dht2(zona2.pin, DHTTYPE);

void bacaSuhu(SensorSuhu &s, DHT &sensor) {
  s.suhuCelcius = sensor.readTemperature();
}

void setup() {
  Serial.begin(9600);
  dht1.begin();
  dht2.begin();

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  Serial.println("Sistem Pemantau");
  Serial.println("Suhu Multi-zona");
  delay(2000);
}

void loop() {
  bacaSuhu(zona1, dht1);
  bacaSuhu(zona2, dht2);

  float suhuMaks = zona1.suhuCelcius;
  if (zona2.suhuCelcius > suhuMaks) {
    suhuMaks = zona2.suhuCelcius;
  }

  Serial.print(zona1.namaZona);
  Serial.print(" : ");
  Serial.print(zona1.suhuCelcius);
  Serial.print(" C | ");
  Serial.print(zona2.namaZona);
  Serial.print(" : ");
  Serial.print(zona2.suhuCelcius);
  Serial.println(" C");

  if (suhuMaks > 40.0) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    Serial.println("STATUS : BAHAYA");
  } else if (suhuMaks >= 30.0 && suhuMaks <= 40.0) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    Serial.println("STATUS : WASPADA");
  } else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    Serial.println("STATUS : NORMAL");
  }

  delay(2000);
}