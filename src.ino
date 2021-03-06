#include <LiquidCrystal.h>

// Initalizes LCD values
LiquidCrystal lcd(12, 11, 0, 1, A2, 13);
const int displayPin = 10;
const int displayContrast = 10;
int prevValue = 0;

// Info for the potentiometers
const int sensorPin = A0;
const int sensorPin2 = A1;
int sensorVal = 0;
int sensorVal2 = 0;

// LED pin variables
const int ones = 9;
const int twos = 8;
const int fours = 7;
const int eights = 6;
const int sixteens = 5;
const int thirtytwos = 4;
const int sixtyfours = 3;
const int onetwentyeights = 2;

void setup() {
  // Starts the LCD
  lcd.begin(16, 2);
  analogWrite(displayPin, displayContrast);
  
  // Initalizes LED pins
  pinMode(ones, OUTPUT);
  pinMode(twos, OUTPUT);
  pinMode(fours, OUTPUT);
  pinMode(eights, OUTPUT);
  pinMode(sixteens, OUTPUT);
  pinMode(thirtytwos, OUTPUT);
  pinMode(sixtyfours, OUTPUT);
  pinMode(onetwentyeights, OUTPUT);
}

void loop() {
  // Reads potentiometer values and converts them into useable data
  sensorVal = analogRead(sensorPin);
  sensorVal = ((sensorVal-20)/64);
  sensorVal2 = analogRead(sensorPin2);
  sensorVal2 = ((sensorVal2-20)/64) * pow(2, 4);
  delay(5);

  // Reads values from potentiometer #1 and lights last four LEDs
  digitalWrite(ones, bitRead(sensorVal, 0));
  digitalWrite(twos, bitRead(sensorVal, 1));
  digitalWrite(fours, bitRead(sensorVal, 2));
  digitalWrite(eights, bitRead(sensorVal, 3));

  // Reads values from potentiometer #2 and lights first four LEDs
  digitalWrite(sixteens, bitRead(sensorVal2, 4));
  digitalWrite(thirtytwos, bitRead(sensorVal2, 5));
  digitalWrite(sixtyfours, bitRead(sensorVal2, 6));
  digitalWrite(onetwentyeights, bitRead(sensorVal2, 7));

  // Writes to the LCD
  if((sensorVal + sensorVal2) != prevValue) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Value:");
    lcd.setCursor(0, 1);
    lcd.print(sensorVal + sensorVal2);
  }
  prevValue = sensorVal + sensorVal2;

}
