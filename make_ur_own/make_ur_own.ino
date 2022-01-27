// Tutorial from Arduboy Community user: crait 


// Including necessary libraries
#include <Arduboy2.h>


// Initializing variables 
Arduboy2 arduboy;
int counter;


void setup() {
  arduboy.begin();
  arduboy.clear();
  counter = 0;


}

void loop() {
  arduboy.clear();
  
  if ( arduboy.pressed(UP_BUTTON) ){
    // Increase counter
    counter = counter + 1;
  }

  if ( arduboy.pressed(DOWN_BUTTON ) ){
    // Decrease counter
    counter = counter - 1;
  }

  // Check if counter is equal to 36
  if ( counter == 36 ){
    arduboy.setCursor(30, 30);
    arduboy.print("Yay!");
  }
  
  arduboy.setCursor(0,0);
  arduboy.print(counter);
  arduboy.display();

}
