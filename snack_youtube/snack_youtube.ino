#include <Arduboy.h>

Arduboy arduboy;
const int8_t GRID_SIZE =4;

int8_t snake[256][2];
int8_t snakeDirection = 0;
int16_t snakeSpeed = 0;
int16_t snakeLength = 1;

int8_t appleX;
int8_t appleY;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.initRandomSeed();

  snake[0][0] = 2;
  snake[0][1] = 2;

 

}

void loop() {
  tick();
  render();


}

void tick() {
  
  if(arduboy.pressed(UP_BUTTON) && snakeDirection != 2){
    snakeDirection = 0;
  }
  else if(arduboy.pressed(RIGHT_BUTTON) && snakeDirection != 3){
    snakeDirection = 1;
  }
  else if(arduboy.pressed(DOWN_BUTTON) && snakeDirection != 0){
    snakeDirection = 2;
  }
  else if(arduboy.pressed(LEFT_BUTTON) && snakeDirection != 1){
    snakeDirection = 3;
  }

  
  snakeSpeed++;
  if (snakeSpeed >= 100) {
      switch (snakeDirection) {
      case 0:
      snake[0][1]--;
      if (snake[0][1] == -1) {
        snake[0][1] = 15;  
      }
      break;
      case 1:
      snake[0][0]++;
       if (snake[0][0] == 32) {
        snake[0][0] = 0;  
      }
      break;
      case 2:
      snake[0][1]++;
       if (snake[0][1] == 16) {
        snake[0][1] = 0;  
      }
      break;
      case 3:
      snake[0][0]--;
       if (snake[0][0] == -1) {
        snake[0][0] = 31;  
      }
      break;
    }
  snakeSpeed = 0;
    
  }

  
}

void render() {
  arduboy.clear();

  for (int i = 0; i < snakeLength; i++) {
    arduboy.fillRect(snake[i][0] * GRID_SIZE, snake[i][1] * GRID_SIZE, 4, 4, 1);
    }

  arduboy.display();  
}


void spawnApple() {
 do {
  appleX = arduboy.random(0, 32);
  appleX = arduboy.random(0, 16); 
 } while (false);
}
