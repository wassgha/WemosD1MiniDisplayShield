#include <Wire.h>  // Include Wire if you're using I2C
#include <SPI.h>  // Include SPI if you're using SPI
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library

//////////////////////////
// MicroOLED Definition //
//////////////////////////

#define PIN_RESET 255  //
#define DC_JUMPER 0  // I2C Addres: 0 - 0x3C, 1 - 0x3D

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////

MicroOLED oled(PIN_RESET, DC_JUMPER);  // I2C Example

void setup()
{
  Serial.begin(115200); 
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.display();  // Display what's in the buffer (splashscreen)
  delay(1000);     // Delay 1000 ms
  oled.clear(PAGE); // Clear the buffer.


  oled.setFontType(1);  // Set font to type 1
  oled.clear(PAGE);     // Clear the page
  oled.setCursor(0, 0); // Set cursor to top-left
}

void textExamples()
{
  if (Serial.available() > 0) {
    int byteRecieved = Serial.read();
    if (byteRecieved == 95)
      {
        oled.clear(PAGE);     // Clear the page
        oled.setCursor(0, 0); // Set cursor to top-left
        oled.display();
      } else {
        //oled.print(byteRecieved);
        oled.write(byteRecieved);
        oled.display();
      }
  }
}

void loop()
{
  textExamples();  // Finally the text example
}
