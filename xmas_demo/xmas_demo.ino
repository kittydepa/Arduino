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


// Create the variables needed
int x;
int y;
char* myGreeting = ("Merry Christmas!!! <3 <3 ~ Kitty");

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
//  arduboy.digitalWriteRGB(RGB_OFF, RGB_OFF, RGB_OFF);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
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

  digitalWrite(GREEN_LED, LOW); // turn on green LED
  digitalWrite(RED_LED, HIGH); // turn off red LED
  delay(1000);
  digitalWrite(GREEN_LED, HIGH); // turn off green LED
  digitalWrite(RED_LED, LOW); // turn on red LED
  delay(1000);
  

  }
}
