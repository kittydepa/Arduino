/*
* scrollingHelloWorld
* Author: Darrell Little
* Date: 10/15/2019
* This code example shows how to scroll a line of text
* across the screen on an Arduboy.
* The OLED screen dimensions are 128 x 60 pixels (width x height)
*/
#include <Arduboy2.h>
 
Arduboy2 arduboy;


// Color array index
enum class Color {
  RED,
  GREEN,
  BLUE,
  COUNT
};

// Map LED color index to LED name
const byte LEDpin[(byte)(Color::COUNT)] = {
  RED_LED,
  GREEN_LED,
  BLUE_LED
};


// Create the variables needed
int x;
int y;
char* myGreeting = ("Merry Christmas!!! I love you so much <3 ~ Kitty");

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
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
  
  }
}
