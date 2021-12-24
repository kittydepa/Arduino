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
//
//// Variables will change (?)
//int ledState = LOW;                     // ledState used to set the LED
//
//// This is for setting up the LEDs so that they can 'blink without delay'
//unsigned long previousMillis = 0;     // will store last time LED was updated
//const long interval = 300;          // interval at which to blink (in milliseconds)
//

ezOutput led1(GREEN_LED);
ezOutput led2(RED_LED);

// ------------------------------------------------------- Setup -------------------------------------------------------
void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
//  pinMode(GREEN_LED, OUTPUT);
//  pinMode(RED_LED, OUTPUT);
  led1.blink(500, 250);
  led2.blink(1000, 500);
   
}


// ------------------------------------------------------- Main loop -------------------------------------------------------
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
//
//    // check to see if it's time for the LED to blink, if the diff. between the current and last time the LED blink 
//  // is greater than the interval at which you want it to blink.
//  unsigned long currentMillis = millis();
//  
//  if (currentMillis - previousMillis >= interval) {
//    // save the last time the LED blinked
//    previousMillis = currentMillis;
//
//    // if the LED is off turn it on, and vice-versa:
//    if (ledState == LOW) {
//      ledState = HIGH;
//    } else {
//      ledState = LOW;
//    }
//
//    // set the LED with the ledState of the variable
//    digitalWrite(GREEN_LED, ledState);
//    
//    if (GREEN_LED == HIGH) {
//    digitalWrite(RED_LED, ledState);
//  }
//  }
  led1.loop();
  led2.loop();
 }
 
}
