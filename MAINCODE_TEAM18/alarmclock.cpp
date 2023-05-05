#include <M5Core2.h>
#include <Wire.h>
#include "alarmclock.h"
#include <Time.h>


int minute = 0;
int second = 0;


void timesetting() {
  // Print time
  if (M5.BtnC.wasPressed()) {
      M5.Lcd.clear(WHITE);
      M5.Lcd.setTextColor(TFT_BLACK, TFT_WHITE);
      M5.Lcd.setTextSize(4);
      M5.Lcd.setCursor(51, 45);
      M5.Lcd.print("Amount of");
      M5.Lcd.setCursor(91, 95);
      M5.Lcd.print ("sleep: ");
      M5.Lcd.setTextSize(4);
      M5.Lcd.setCursor(105, 150);
      if (minute < 10) {
          M5.Lcd.print("0");
        }
        M5.Lcd.print(minute);
        M5.Lcd.print(":");
        if (second < 10) {
          M5.Lcd.print("0");
        }
        M5.Lcd.print(second);
    }
      // Increase minute
      if (M5.BtnA.wasReleased()) {
        minute++;
        M5.Lcd.clear(WHITE);
      M5.Lcd.setTextColor(TFT_BLACK, TFT_WHITE);
      M5.Lcd.setTextSize(4);
      M5.Lcd.setCursor(51, 45);
      M5.Lcd.print("Amount of");
      M5.Lcd.setCursor(91, 95);
      M5.Lcd.print ("sleep: ");
      M5.Lcd.setTextSize(4);
      M5.Lcd.setCursor(105, 150);
      if (minute < 10) {
          M5.Lcd.print("0");
        }
        M5.Lcd.print(minute);
        M5.Lcd.print(":");
        if (second < 10) {
          M5.Lcd.print("0");
        }
        M5.Lcd.print(second);
      }
       // increase seconds
      if (M5.BtnC.wasReleased()) {
        second++;
        M5.Lcd.clear(WHITE);
      M5.Lcd.setTextColor(TFT_BLACK, TFT_WHITE);
      M5.Lcd.setTextSize(4);
      M5.Lcd.setCursor(51, 45);
      M5.Lcd.print("Amount of");
      M5.Lcd.setCursor(91, 95);
      M5.Lcd.print ("sleep: ");
      M5.Lcd.setTextSize(4);
      M5.Lcd.setCursor(105, 150);
      if (minute < 10) {
          M5.Lcd.print("0");
        }
        M5.Lcd.print(minute);
        M5.Lcd.print(":");
        if (second < 10) {
          M5.Lcd.print("0");
        }
        M5.Lcd.print(second);
      }
}


void alarmring() {
 
    int amount = (minute * 60000) + (second * 1000);
   
    M5.Lcd.clear(BLACK);
    delay(2000);
    M5.Rtc.clearIRQ();
    M5.Rtc.SetAlarmIRQ(amount/1000);
    M5.Lcd.clear(BLACK);


    delay(amount);


    // Ring alarm after amount of input time
    M5.update();
    while (!M5.BtnB.wasReleasefor(700)) {
      M5.Lcd.fillScreen(TFT_WHITE);
    M5.Lcd.setTextColor(TFT_RED, TFT_WHITE);
    M5.Lcd.setTextSize(10);
    M5.Lcd.setCursor(43, 90);
    M5.Lcd.print("ALARM!");


    M5.Spk.begin();
    M5.Axp.SetLDOVoltage(100, 100);
    M5.Axp.SetLDOEnable(3, true);  //Open the vibration.  
    delay(200);
    M5.Spk.DingDong();
    M5.Axp.SetLDOEnable(3, false);  //Open the vibration.     
delay(200);
    M5.Spk.DingDong();
    M5.update();
   
    // exit loop
    if (M5.BtnB.wasReleasefor(700)) {
        break;
      }


  }  
 
}
