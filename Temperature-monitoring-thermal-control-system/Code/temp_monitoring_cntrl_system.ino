#include "LiquidCrystal.h"

LiquidCrystal lcd(8,7,6,5,4,3);

int sensorPin = A0;
int fanPin = 9;

int greenLED = 10;
int yellowLED = 11;
int redLED = 12;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);

  pinMode(fanPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  lcd.setCursor(0,0);
  lcd.print("Thermal Control");

  lcd.setCursor(0,1);
  lcd.print("System Starting");

  delay(2000);   // show message for 2 seconds

  lcd.clear();   // clear screen before main loop
}

void loop()
{
  int reading = analogRead(sensorPin);

  float voltage = reading * (5.0 / 1024.0);
  float temperatureC = (voltage - 0.5) * 100;

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print(" C   ");

  lcd.setCursor(0,1);

  if(temperatureC < 25)
  {
    digitalWrite(fanPin, LOW);

    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    lcd.print("Fan: OFF|SAFE ");
  }

  else if(temperatureC >= 25 && temperatureC <= 50)
  {
    digitalWrite(fanPin, HIGH);

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    lcd.print("Fan: ON|NORMAL");
  }

  else
  {
    digitalWrite(fanPin, HIGH);

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    lcd.print("Fan: ON|OVERHT");
  }

  delay(500);
}
