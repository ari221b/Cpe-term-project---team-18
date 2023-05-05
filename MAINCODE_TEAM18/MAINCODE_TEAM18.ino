#include <M5Core2.h>
#include <Wire.h>
#include "alarmclock.h"
#include "motiontracker.h"
#include "meditation.h"
#include <Time.h>
#include <Arduino.h>




void setup() {


  M5.begin();
  M5.Lcd.fillScreen(TFT_WHITE);
  M5.Lcd.setTextColor(TFT_GREEN, TFT_WHITE);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(46, 40);
  M5.Lcd.println("Dream Capture");


  M5.Lcd.setTextSize(2.5);
  M5.Lcd.setCursor(10, 100);
  M5.Lcd.setTextColor(TFT_BLACK, TFT_WHITE);
  M5.Lcd.println("Choose your service: ");
  M5.Lcd.println(" ");
  M5.Lcd.println("1) Motion Tracking");
  M5.Lcd.println(" ");
  M5.Lcd.println("2) Meditation program");
  M5.Lcd.println(" ");
  M5.Lcd.println("3) Alarm Clock");
}


void loop() {
  M5.update();
  // Motion Tracking
  if (M5.BtnA.wasReleasefor(1000)) {
   
      M5.Lcd.clear(BLACK);
      M5.Lcd.setTextColor(TFT_WHITE, TFT_WHITE);
      M5.Lcd.setTextSize(2);
      M5.Lcd.setCursor(10, 110);
      M5.Lcd.println("Recording!");
      delay(1000);
      M5.Lcd.clear(BLACK);


    while(1) {
      record();


      M5.update();


      if (M5.BtnA.wasReleasefor(700)) {
        M5.Lcd.clear(WHITE);
        break;
      }
    }


    while(2) {
      results();
       
      M5.update();


      if (M5.BtnB.wasReleasefor(700)) {
        break;
      }
    }


      M5.Axp.DeepSleep(SLEEP_SEC(
      1));
   
  }


  // meditation
  if (M5.BtnB.wasReleasefor(1000)) {


    meditation();


  }


  // Sleep timer
  if (M5.BtnC.wasReleasefor(1000)) {
   
    while(1) {
      M5.update();


      timesetting();


    if (M5.BtnB.wasReleasefor(700)) {
      break;
    }
  }
    while(2) {
      alarmring();


      break;    
    }


    M5.Axp.DeepSleep(SLEEP_SEC(
      1));
  }
}
