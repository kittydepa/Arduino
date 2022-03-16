/* From community.arduboy user crait
 Make your own... pt 6 - adding graphics 
 https://community.arduboy.com/t/make-your-own-arduboy-game-part-6-graphics/7929
 */


// Libraries to include
#include <Arduboy2.h>


// Setting up variables
Arduboy2 arduboy;

const unsigned char PROGMEM background[] = {
  // width, height
  8, 8,
  0x81, 0x00, 0x12, 0x40, 0x04, 0x11, 0x00, 0x04,
};

/*
   - Explanation of the images: they need to be converted into a byte array.
   - 'const' is used to set a variable that cannot be changed
   - 'unsigned' is used because we cannot use negative values (?)
   - The arrays are given the names 'background' and 'player'
   - [] are used to create a character array
   - {} are used for what is actually part of the array
   - PROGMEM is a macro, that indicates where to store the array in memory
*/

const unsigned char PROGMEM player[] = {
  //width, height
  16, 16,
  0xfe, 0x01, 0x3d, 0x25, 0x25, 0x3d, 0x01, 0x01, 0xc1, 0x01, 0x3d, 0x25, 0x25, 0x3d, 0x01, 0xfe, 
  0x7f, 0x80, 0x9c, 0xbc, 0xb0, 0xb0, 0xb2, 0xb2, 0xb3, 0xb0, 0xb0, 0xb0, 0xbc, 0x9c, 0x80, 0x7f, 
};


/*-------------------------------------------------------------------------------------*/


void setup() {
  arduboy.begin();
  arduboy.clear();
}


/*-------------------------------------------------------------------------------------*/


void loop() {
  arduboy.clear();
  Sprites::drawOverwrite(5, 10, player, 0); // The first 2 parameters are X, Y coordinates for where to render the image, what to draw, and what 'frame' to draw
  arduboy.display();
}
