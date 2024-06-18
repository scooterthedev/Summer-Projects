//LCD pins and layout taken from Paul McWhorter
//My dad helped with the issue where the input would go rapid
//fire if held on edge
#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int sensorPin1 = A0; 
int sensorPin2 = A1;

int ledPin = 13; 

int sensorValue1 = 0;  
int sensorValue2 = 0; 

void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  lcd.begin(16,2);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Pushups Done:");

}

int pushupsDone = 0;
int middle = 380;
bool in_the_middle = true;
void loop() {

  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  Serial.println(sensorValue1);
  Serial.println(sensorValue2);

  if (abs(sensorValue1 - middle) > 100 || abs(sensorValue2 - middle) > 100) {
    if (in_the_middle) {
      pushupsDone++;
      in_the_middle = false;
      lcd.setCursor(0, 1);
      lcd.print(pushupsDone);
    }
  } 
  else{
    in_the_middle = true;
  }
}
