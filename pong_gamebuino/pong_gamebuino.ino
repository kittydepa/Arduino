#include <Arduboy2.h>

Arduboy2 arduboy;

void setup() {
  // put your setup code here, to run once:
  // See official Arduboy2 library docs.
  
 arduboy.begin(); // must be called at the beginning of every game
 
}


void loop() {
  // put your main code here, to run repeatedly:

  while(!arduboy.update());
  arduboy.display.clear();

  // This is where most of the program takes place
  arduboy.display.print("hello, world");

  
}
