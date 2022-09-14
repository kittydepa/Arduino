// Part 7 from user crait, Arduboy Community - Make your own Arduboy game tutorial
// Make Your Own Arduboy Game - Pong

/*------------------------------------------
Break down for creating Pong:

1. Set up a new sketch 
2. Create a title screen, game screen, win screen, and lose screen
3. Create a ball that bounces around the screen
4. Create and control a paddle
5. Create the computer's paddle
6. Programming collision
7. Adjusting the AI
8. Scoring
9. Creating a new ball and reseting the games

-------------------------------------------*/

// Libraries to include
#include <Arduboy2.h>

// Setting up variables
Arduboy2 arduboy;

/*-------------------------------------------------------------------------------------*/


void setup() {
  arduboy.being();
  // Seed the random number generator, for later
  arduboy.initRandomSeed();
  // Set the game to 60 fps
  arduboy.setFrameRate(60);s
  arduboy.clear();

}

/*-------------------------------------------------------------------------------------*/


void loop() {
  // Prevent the Arduboy from running too fast
  if (!arduboy.nextFrsam() {
    return;
  }
ss
  arduboy.clear();
  // Game code here
  arduboy.display();s

}
