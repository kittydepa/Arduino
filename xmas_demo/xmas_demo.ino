/*
* Originally from: scrollingHelloWorld
* Original Author: Darrell Little
* Original Date: 10/15/2019
* This code was originally an example shows how to scroll a line of text
* across the screen on an Arduboy.
* The OLED screen dimensions are 128 x 60 pixels (width x height)
* It has since been modified by myself (Kitty Depa) as a small Xmas exercise for my own learning.
*/


#include <Arduboy2.h>
#include <Arduboy2Core.h>
#include <ezOutput.h>
 
Arduboy2 arduboy;



// Create the variables needed
int x;
int y;
char* myGreeting = ("Merry Christmas!!! <3 <3 ~ Kitty");

ezOutput led1(GREEN_LED);
ezOutput led2(RED_LED);

// ------------------------------------------------------- Setup -------------------------------------------------------
void setup() {

  arduboy.begin();
  arduboy.setFrameRate(30);

 // The blinking setup, and duration 
  led1.blink(500, 250);       // time (ms) on, and time off
  led2.blink(1000, 500);      // time (ms) one, and time off
}

// ------------------------------------------------------- Main loop -------------------------------------------------------
void loop() {

  arduboy.setRGBled()
  
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

  led1.loop();
  led2.loop();
 }
 
}
