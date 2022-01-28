// Part 5 of Make Your Own Arduboy Game Tutorial (from user: crait)
// Guessing game
// A number guessing game where Arduboy picks a random number and the player has X attempts to guess the number.
// After each guess, the Arduboy will tell the player a hint. If the player guesses right, they win!




// Libraries to include
#include <Arduboy2.h>

// Setting up variables
Arduboy2 arduboy;
int playerwin;
int attempts;
int guessednumber;
int randomnumber;
int lastguess;


void setup() {
  arduboy.begin();
  arduboy.clear();

  playerwin = 0;
  attempts = 0;
  guessednumber = 0;
  arduboy.initRandomSeed();
  randomnumber = random(1, 21);
  

}


void loop() {
  arduboy.clear();
  arduboy.pollButtons();
  
  // Game code goes here
  if (playerwin == 0) {
    // Ask the player for a number and play the game
 
    if (attempts == 4) {
      // Game Over
      arduboy.setCursor(0, 0);
      arduboy.print("You lost!");
      arduboy.print("\n");
      arduboy.print("Correct number: ");
      arduboy.print(randomnumber);
      arduboy.print("\n");
    arduboy.print("Press A to play again!");
      
      if (arduboy.justPressed(A_BUTTON)) {
        randomnumber = random(1, 21);
        attempts = 0;
        playerwin = 0;
      }
    }
    
    else { // Player has more attempts
      if (arduboy.justPressed(UP_BUTTON)) {
        guessednumber = guessednumber + 1;
      }

      if (arduboy.justPressed(DOWN_BUTTON)) {
        guessednumber = guessednumber - 1;
      }

      if (arduboy.justPressed(A_BUTTON)) {
        // Guess number
        if (guessednumber == randomnumber) {
          playerwin = 1;
        }

        else {
          attempts = attempts + 1;
                     lastguess = guessednumber;
        }
      }
      
    arduboy.setCursor(0, 0);
    arduboy.print("Guess the number \n");
    arduboy.print("between 1-20.\n");
    arduboy.print("Press A to submit. \n");
    arduboy.print("\n");
    arduboy.print("\n");
    arduboy.print("Attempt: ");
    arduboy.print(attempts);
    arduboy.print("\n");
    arduboy.print("Number to guess: ");
    arduboy.print(guessednumber);
    arduboy.print("\n");
    if (attempts == 0) {
      arduboy.print("Good luck!");
    }
    else {
      arduboy.print(lastguess);
      if (lastguess > randomnumber) {
        arduboy.print(" is too high!");
      }
      if (lastguess < randomnumber) {
        arduboy.print(" is too low!");
      }
    } 
  }
  }

  else { 
    // Tell the player that they won!
    arduboy.setCursor(0, 0);
    arduboy.print("You won!");
    arduboy.print("\n");
    arduboy.print("Correct Number: ");
    arduboy.print(randomnumber);
    arduboy.print("\n\n\n");
    arduboy.print("Press A to play again!");
    
    if (arduboy.justPressed(A_BUTTON)) {
        randomnumber = random(1, 21);
        attempts = 0;
        playerwin = 0;
      }
  }

  arduboy.display();
}
