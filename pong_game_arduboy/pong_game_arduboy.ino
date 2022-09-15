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
int gamestate = 0;

// Declare the balls, location, and their size
int ballx = 62;
int bally = 0;
int ballsize = 4;

// Declare for vertical and horizontal direction on the screen
int ballright = 1;
int balldown = 1;

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

  arduboy.clear();

  // Game code here
  switch (gamestate) {

    case 0:
      // Title screen
      arduboy.setCursor(0,0);
      arduboy.print("Title Screen");
      if (arduboy.justPressed(A_BUTTON)) {
        gamestate = 1;
      }
      break;

    case 1:
      // Gameplay screen
      arduboy.setCursor(0,0);
      arduboy.print("Gameplay");
      if (arduboy.justPressed(A_BUTTON)) {
        gamestate = 2;
      }
      break;

    case 2:
      // Win screen
      arduboy.setCursor(0,0);
      arduboy.print("Win Screen");
      if (arduboy.justPressed(A_BUTTON)) {
        gamestate = 3;
      }
      break;

    case 3:
      // Game over screen
      arduboy.setCursor(0,0);
      arduboy.print("Game Over Screen");
      if (arduboy.justPressed(A_BUTTON)) {
        gamestate = 0;
      }
      break;
  }

  arduboy.display();

}
