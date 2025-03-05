/**********************************************************************
  Description : Read battery voltage.
  Auther      : www.adeept.com
  Modification: 2023/05/27
**********************************************************************/
#include "Adeept_Battery_For_ESP32.h"
#include <Wire.h>
#include <SSD1306Wire.h>

// OLED pin definition.
#define SDA   13
#define SCL   14
SSD1306Wire OLED_display(0x3c, SDA, SCL);

void setup() {
  Serial.begin(115200);                     //Set the Serial Baud rate
  OLED_display.init(); // Initialize the OLED.
  OLED_display.flipScreenVertically();  // The screen flips 180° to display.
}

void loop() {
  Serial.print("Battery ADC : ");
  Serial.println(Get_Battery_Voltage_ADC());//Gets the battery ADC value
  Serial.print("Battery Voltage : ");
  Serial.print(Get_Battery_Voltage());      //Get the battery voltage value
  Serial.println("V");

    OLED_display.clear();  // clear screen.
    OLED_display.setFont(ArialMT_Plain_16);  // set font size 10,16,24.
    OLED_display.drawString(20, 10, "ESP32 Car");
    OLED_display.setFont(ArialMT_Plain_16);
    OLED_display.drawString(20,30,"Batt " + String (Get_Battery_Voltage()) + " V" );
    OLED_display.setFont(ArialMT_Plain_10);
    OLED_display.drawString(20,50,"www.adeept.com");
    OLED_display.display(); // display characters.
  
  delay(300);
}
