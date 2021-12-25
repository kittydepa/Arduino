/*
* Originally from: scrollingHelloWorld
* Original Author: Darrell Little
* Original Date: 10/15/2019
* This code was originally an example shows how to scroll a line of text
* across the screen on an Arduboy.
* The OLED screen dimensions are 128 x 60 pixels (width x height)
* It has since been modified by myself as a small Xmas exercise for my own learning.
*/
#include <Arduboy2.h>
 
Arduboy2 arduboy;

// Set the coordinates to start at the right edge of the screen
int16_t x = 127;

// The counter variable
int16_t step = 0;

// The type of 'myGreeting' is inferred by the compiler
constexpr char * myGreeting = ("Merry Christmas!!! <3 <3 ~ Kitty");

// The brightness at which to flash the LED
constexpr uint8_t brightness = 30;

// Setup
void setup()
{
  arduboy.begin();

  // Initialise the analogue LED control with the setRGBled function
  arduboy.setRGBled(0, 0, 0);
}

// Track the state of the LEDs
bool greenLightOn = false;
bool redLightOn = false;

// Main loop
void loop()
{
  if (!arduboy.nextFrame())
    return;

  arduboy.clear();
  arduboy.setCursor(x, 30);
  arduboy.print(myGreeting);
  arduboy.display();
  
  // Every 1/2 a second (when the Arduboy is at 60FPS - the default)
  if(arduboy.everyXFrames(60))
  {
    // If green light is on
    if(greenLightOn)
    {
      // Turn green light off
      arduboy.setRGBled(GREEN_LED, 0);
      greenLightOn = false;
    }
    // If green light is off
    else
    {
      // Turn green light on
      arduboy.setRGBled(GREEN_LED, brightness);
      greenLightOn = true;
    }
  }
  
  // Every 2 seconds (when the Arduboy is at 60FPS - the default)
  if(arduboy.everyXFrames(120))
  {
    // If red light is on
    if(redLightOn)
    {
      // Turn red light off
      arduboy.setRGBled(RED_LED, 0);
      redLightOn = false;
    }
    // If red light is off
    else
    {
      // Turn red light on
      arduboy.setRGBled(RED_LED, brightness);
      redLightOn = true;
    }
  }
  
  if(step < 256)
  {
    ++step;
    --x;
  }
  else
  {
    step = 0;
    x = 127;
  }
}
