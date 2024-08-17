#include <LiquidCrystal.h> 
#include "DHT.h"

#define TYPE DHT11

int sensePin = 2;

DHT HT(sensePin, TYPE);

float humidity;
float tempC;
float tempF;

int rs = 7; 
int en = 8; 
int d4 = 9; 
int d5 = 10; 
int d6 = 11; 
int d7 = 12; 

float num1; 
float num2; 
float result;

int setTime = 500;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  HT.begin();
  delay(setTime);
}

void loop() {
    humidity = HT.readHumidity();
    tempC = HT.readTemperature();
    tempF = HT.readTemperature(true);

    lcd.setCursor(0, 0);
    lcd.print("Humidity:");
    lcd.print(humidity);
    delay(3000);
    lcd.clear();

    lcd.print("Temperature (C):");
    lcd.setCursor(0, 1);
    lcd.print(tempC);
    lcd.print(" C");
    delay(5000);
    lcd.clear();

    lcd.print("Temperature (F):");
    lcd.setCursor(0, 1);
    lcd.print(tempF);
    lcd.print(" F");
    delay(5000);
    lcd.clear();

  }



