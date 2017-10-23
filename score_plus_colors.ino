#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>
#define PIN 7
LiquidCrystal_I2C lcd(0x3F,16,2); 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

int fsrAnalogPin = 0; // FSR is connected to analog 0
int fsrReading;      // The analog reading from the pin that the FSR is connected to
int counterState = 0;
int prevCounterState = 0;
long counter = 0;

void setup() {
  Serial.begin(9600);
  lcd.init(); //initialises the LCD screen so i can actually use it later
  strip.begin();
  strip.setBrightness(80);
}

void loop() {
  fsrReading = analogRead(fsrAnalogPin);

  //Serial.println(fsrReading);
  //delay(100);
  counterState = fsrReading;
  if (counterState < 100 && prevCounterState > 100)
  {
    counter = counter +1;
    Serial.println(counter);
  }
  prevCounterState = counterState;
   //lcd.clear(); //clears all remaining numbers/ letter on screen because otherwise they'll stay there
   lcd.backlight(); //enables the LCD screen's backlight
   lcd.setCursor(3,0); //3 spaces in on the first row
   lcd.print("Score:");
   lcd.setCursor(3,3); //2 spaces in on the third row
   lcd.print(counter);
   
   pixelring();
}

void pixelring(){
  if(counter<3){                           //color level 1
    for(int x=0; x<12; x++){
      strip.setPixelColor(x, 0, 210, 20);   //set color green
    }
  }
  else if(3<=counter<6){                     //color level 2
    for(int x=0; x<12; x++){
      strip.setPixelColor(x, 255, 210, 0);    //set color yellow
    }
  }
  else if(6<=counter){                        //color level 3
    for(int x=0; x<12; x++){
      strip.setPixelColor(x, 255, 75, 0);      //set color orange
    }
  }


}

