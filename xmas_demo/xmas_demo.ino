/*
* scrollingHelloWorld
* Author: Darrell Little
* Date: 10/15/2019
* This code example shows how to scroll a line of text
* across the screen on an Arduboy.
* The OLED screen dimensions are 128 x 60 pixels (width x height)
*/
#include <Arduboy2.h>
#include <Arduboy2Core.h>
 
Arduboy2 arduboy;

#define RGB_ON LOW
#define RGB_OFF HIGH

// Create the variables needed
int x;
int y;
char* myGreeting = ("Merry Christmas!!! <3 <3 ~ Kitty");


void static digitalWriteRGB(uint8_t red,
                            uint8_t green,
                            uint8_t blue
                               );

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.digitalWriteRGB(RGB_OFF, RGB_OFF, RGB_OFF);
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;
  
  // Set the coordinates to start at the right edge of the screen
  // and midway down on the Y-axis
  x = 127;
  y = 30;
  
  // In the for() loop, use the screen width x 2
  // this allows the entire message to scroll across
  // before starting over
  for(int i = 0; i < 256; i++) {

  arduboy.clear();
  arduboy.setCursor(x, y);
  arduboy.print(myGreeting);
  arduboy.display();
  delay(75);
  
  x--;

  digitalWriteRGB(RGB_ON, RGB_OFF, RGB_OFF); // Turn on red LED
  delay(3000);   // Wait for 3 seconds
  digitalWriteRGB(RGB_OFF, RGB_OFF, RGB_OFF); // Turn off red LED
  delay(3000); // Wait for 3 seconds

  digitalWriteRGB(RGB_OFF, RGB_ON, RGB_OFF);  // Turn on green LED
  delay(3000);   // Wait for 3 seconds
  digitalWriteRGB(RGB_OFF, RGB_ON, RGB_OFF); // Turn off green LED
  delay(3000); // Wait for 3 seconds

  }
}
