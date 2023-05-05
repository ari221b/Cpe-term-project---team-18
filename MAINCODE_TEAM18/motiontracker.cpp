#include "motiontracker.h"
#include <M5Core2.h>
#include <Wire.h>


float prevGyroX = 0.0;  // Initialize previous gyroZ value
int movementCount = 0;  // Initialize movement counter


void record() {


  M5.IMU.Init();  // Initialize the gyroscope
  Serial.begin(9600);  // Start serial communication


  float gyroX, gyroY, gyroZ;


  M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);  // Get gyroscope data
 
  float gyroXDiff = gyroX - prevGyroX;  // Calculate difference in gyroZ values
  if (gyroXDiff > 400 || gyroXDiff < -400) {  // Check if movement threshold is exceeded
    movementCount++;  // Increment movement counter
  }


  prevGyroX = gyroX;  // Store current gyroZ value for next loop iteration
 
  delay(100);  // Delay for stability


}


// print results
void results() {
 
  M5.Lcd.setTextColor(TFT_BLACK, TFT_WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(10, 85);
  M5.Lcd.printf("Movement count: %d", movementCount);


  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(10, 100);
  if (movementCount > 60){
    M5.Lcd.println("You're an insomniac.");
    M5.Lcd.setCursor(10, 120);
    M5.Lcd.println("Try our meditation program!");
  }
  else if (movementCount > 35 && movementCount < 50){
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(10, 100);
    M5.Lcd.println("Congrats! You have healthy sleep habits.");
  }
  else if (movementCount < 35){
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(10, 100);
    M5.Lcd.println("You're a hypersomniac.");
    M5.Lcd.setCursor(10, 120);
    M5.Lcd.println("Try our sleep timer!");
  }


}
