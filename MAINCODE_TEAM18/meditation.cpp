#include <M5Core2.h>
#include <Wire.h>


void meditation() {


    while (2) {


      M5.Lcd.clear(WHITE);


      M5.Lcd.setTextSize(10);
      M5.Lcd.setCursor(25, 96);
      M5.Lcd.setTextColor(TFT_BLUE, TFT_WHITE);
      M5.Lcd.println("Breathe in");
      M5.Axp.SetLDOEnable(3, true);  //Open the vibration.   
      delay (2000);


      M5.Lcd.clear(WHITE);
      M5.Lcd.setTextSize(10);
      M5.Lcd.setCursor(23, 96);
      M5.Lcd.setTextColor(TFT_RED, TFT_WHITE);
      M5.Lcd.println("Breathe out");
      M5.Axp.SetLDOEnable(3, false);  //Open the vibration.  
      delay (4000);


      M5.update();


      if (M5.BtnA.wasReleasefor(700)) {
        break;
      }
    }


      M5.Axp.DeepSleep(SLEEP_SEC(
        1));


}
