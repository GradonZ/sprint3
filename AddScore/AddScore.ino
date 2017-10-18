#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2); 

int fsrAnalogPin = 0; // FSR is connected to analog 0
int fsrReading;      // The analog reading from the pin that the FSR is connected to
int counterState = 0;
int prevCounterState = 0;
long counter = 0;

void setup() {
  Serial.begin(9600);
  lcd.init(); //initialises the LCD screen so i can actually use it later
}

void loop() {
  fsrReading = analogRead(fsrAnalogPin);

  //Serial.println(fsrReading);
  //delay(100);
  counterState = fsrReading;
  if (counterState < 100 && prevCounterState > 100)
  {
    counter = counter +15000;
    Serial.println(counter);
  }
  prevCounterState = counterState;
   //lcd.clear(); //clears all remaining numbers/ letter on screen because otherwise they'll stay there
   lcd.backlight(); //enables the LCD screen's backlight
   lcd.setCursor(3,0); //3 spaces in on the first row
   lcd.print("Score:");
   lcd.setCursor(3,3); //2 spaces in on the third row
   lcd.print(counter);
}


/* 
Add points when the pressure went above the threshhold, but also went back to either underneath it/ completely natural (0) 
if pressure exceeds 500 and previous pressure state was < 500, points need to be counted BUT ONLY ONCE

*/
