// Includes, namespace and prototypes
#include "template.h"
#include <string>      // Needed for the string class
using namespace std;   // Needed for the string class
using namespace AGK;
app App;

class Sprite
{
private:
   int spriteIndex;  // The sprite index
   string imageFile; // The name of the image file
public:
   // Constructors
   Sprite();
   Sprite(int, string);

   // Mutators
   void createSprite();
   void createSprite(int, string);
   void setPosition(float, float);
   void setX(float);
   void setY(float);

   // Accessors
   int getSpriteIndex() const;
   string getImageFile() const;
   float getX() const;
   float getY() const;

   // Destructor
   ~Sprite();
};

// This is the default constructor for the Sprite
// class. It sets index to 1 and imageFile to
// an empty string.
Sprite::Sprite()
{
   spriteIndex = 1;
   imageFile = "";
}

// This Sprite class constructor accepts as arguments
// the sprite index and the name of the image file,
// and initializes the member variables.
Sprite::Sprite(int index, string filename)
{
   spriteIndex = index;
   imageFile = filename;
}

// The Sprite::createSprite member function 
void Sprite::createSprite()
{
   // If the sprite does not already exist,
   // then create it.
   if (!agk::GetSpriteExists(spriteIndex))
   {
      agk::CreateSprite(spriteIndex, imageFile.c_str());
   }
}

// The Sprite::createSprite member function 
void Sprite::createSprite(int index, string filename)
{
   // Set the member variables.
   spriteIndex = index;
   imageFile = filename;

   // If the sprite does not already exist,
   // then create it.
   if (!agk::GetSpriteExists(spriteIndex))
   {
      agk::CreateSprite(spriteIndex, imageFile.c_str());
   }
}

// The Sprite::setPosition member function sets the
// sprite's position.
void Sprite::setPosition(float x, float y)
{
   agk::SetSpritePosition(spriteIndex, x, y);
}

// The Sprite::setX member function sets the
// sprite's X coordinate.
void Sprite::setX(float x)
{
   agk::SetSpriteX(spriteIndex, x);
}

// The Sprite::setY member function sets the
// sprite's Y coordinate.
void Sprite::setY(float y)
{
   agk::SetSpriteY(spriteIndex, y);
}

// The Sprite::getSpriteIndex member function
// returns the sprite's index.
int Sprite::getSpriteIndex() const
{
   return spriteIndex;
}

// The Sprite::getImageFile member function
// returns the name of the image file used to 
// create this sprite.
string Sprite::getImageFile() const
{
   return imageFile;
}

// The Sprite::getX member function returns the
// sprite's X coordinate.
float Sprite::getX() const
{
   return agk::GetSpriteX(spriteIndex);
}

// The Sprite::getY member function returns the
// sprite's Y coordinate.
float Sprite::getY() const
{
   return agk::GetSpriteY(spriteIndex);
}

// The Sprite class destructor deletes the
// sprite from memory.
Sprite::~Sprite()
{
   agk::DeleteSprite(spriteIndex);
}

// MoveableSprite declaration
class MoveableSprite : public Sprite
{
private:
   int distance;
public:
   // Constructors
   MoveableSprite();
   MoveableSprite(int, string, int);

   // Mutators and accessors
   void setDistance(int);
   int getDistance() const;

   // Functions to move the sprite
   void moveUp();
   void moveDown();
   void moveLeft();
   void moveRight();
};

// Default constructor
MoveableSprite::MoveableSprite() : Sprite()
{
   distance = 0;
}

// This constructor accepts arguments for the sprite
// index, image file name, and distance to move.
MoveableSprite::MoveableSprite(int index, string filename,
               int dist) : Sprite(index, filename)
{
   distance = dist;
}

// The setDistance member function sets
// the moving distance.
void MoveableSprite::setDistance(int dist)
{
   distance = dist;
}

// The getDistance member function returns the
// sprite's moving distance.
int MoveableSprite::getDistance() const
{
   return distance;
}

// The moveUp member function moves the sprite up.
void MoveableSprite::moveUp()
{
   // Get the sprite's current coordinates.
   int x = getX();
   int y = getY();

   // Decrease y.
   y -= distance;

   // Move the sprite to its new location.
   setY(y);
}

// The moveDown member function moves the sprite down.
void MoveableSprite::moveDown()
{
   // Get the sprite's current coordinates.
   int x = getX();
   int y = getY();

   // Increase y.
   y += distance;

   // Move the sprite to its new location.
   setY(y);
}

// The moveLeft member function moves the sprite left.
void MoveableSprite::moveLeft()
{
   // Get the sprite's current coordinates.
   int x = getX();
   int y = getY();

   // Decrease x.
   x -= distance;

   // Move the sprite to its new location.
   setX(x);
}

// The moveRight member function moves the sprite right.
void MoveableSprite::moveRight()
{
   // Get the sprite's current coordinates.
   int x = getX();
   int y = getY();

   // Increase x.
   x += distance;

   // Move the sprite to its new location.
   setX(x);
}

// Function prototype for the updateSprite function
void updateSprite(MoveableSprite &);

// Constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Constant for the sprite index
const int SPRITE_INDEX = 1;

// Constant for the moving distance
const int MOVING_DISTANCE = 10;

// Declare an instance of the MoveableSprite class
MoveableSprite spaceship(SPRITE_INDEX, 
   "Space/spaceship.png", MOVING_DISTANCE);

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Create the sprite on the screen.
   spaceship.createSprite();

   // Position the sprite at the center of the screen.
   spaceship.setPosition(SCREEN_WIDTH / 2 - 105,
                         SCREEN_HEIGHT / 2 - 26);
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Update the sprite position.
   updateSprite(spaceship);

   // Display the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}

// The updateSprite function checks for arrow key
// presses and moves the argument accordingly.
void updateSprite(MoveableSprite &sprite)
{
   // Get the direction as input from the keyboard.
   float directionX = agk::GetDirectionX();
   float directionY = agk::GetDirectionY();

   // Check for left/right arrow keys.
   if (directionX < 0)
   {
      sprite.moveLeft();
   }
   else if (directionX > 0)
   {
      sprite.moveRight();
   }

   // Check for up/down arrow keys.
   if (directionY < 0)
   {
      sprite.moveUp();
   }
   else if (directionY > 0)
   {
      sprite.moveDown();
   }
}
