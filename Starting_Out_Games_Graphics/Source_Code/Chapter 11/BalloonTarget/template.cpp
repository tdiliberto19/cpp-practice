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
   string imageFile;   // The name of the image file
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
   float getSpriteHeight() const;
   float getSpriteWidth() const;

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

// The getSpriteHeight member function returns
// the sprite's height.
float Sprite::getSpriteHeight() const
{
   return agk::GetSpriteHeight(spriteIndex);
}

// The getSpriteWidth member function returns
// the sprite's height.
float Sprite::getSpriteWidth() const
{
   return agk::GetSpriteWidth(spriteIndex);
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

   // Move the sprite at its new location.
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

   // Move the sprite at its new location.
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

   // Move the sprite at its new location.
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

   // Move the sprite at its new location.
   setX(x);
}

// Function prototypes
void restartDart();
void restartBalloon();
void moveBalloon();
void moveDart();
void checkForCollision();

// Constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Constants for sprites and sound
const int BALLOON_INDEX    = 1;  // Balloon sprite index
const int DART_INDEX       = 2;  // Dart sprite index
const int DART_DIST        = 10; // Dart moving distance
const int MAX_BALLOON_DIST = 14; // Maximum balloon distance
const int LASER_SOUND      = 1;  // Sound number

// Variable to indicate whether the dart has been launched
bool g_dartLaunched = false;

// Create MoveableSprite objects for the balloon and dart.
MoveableSprite balloon(BALLOON_INDEX, 
              "BalloonTarget/balloon.png", 0);

MoveableSprite dart(DART_INDEX, 
              "BalloonTarget/dart.png", DART_DIST);

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Set the text in the window title bar.
   agk::SetWindowTitle("Balloon Target");

   // Load the laser sound.
   agk::LoadSound(LASER_SOUND, "BalloonTarget/laser.wav");

   // Create the balloon and dart sprites on the screen.
   balloon.createSprite();
   dart.createSprite();

   // Position the dart and balloon.
   restartDart();
   restartBalloon();
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Move the balloon.
   moveBalloon();

   // Determine whether the spacebar is being pressed.
   if (agk::GetRawKeyState(AGK_KEY_SPACE))
   {
      g_dartLaunched = true;
   }

   // If the dart is launched, move it.
   if (g_dartLaunched)
   {
      moveDart();
   }

   // Check for collisions.
   checkForCollision();
   
   // Display the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}

// The restartBalloon function restarts the balloon along
// the left edge of the screen, with a random moving distance.
void restartBalloon()
{
   // We want to keep the balloon in the top
   // two-thirds of the screen. Calculate the
   // greatest Y coordinate for the balloon.
   int maxY = SCREEN_HEIGHT * 0.66;

   // Get a random value for the Y coordinate.
   int y = agk::Random(0, maxY);

   // Display the balloon at its new location
   // along the left edge of the screen.
   balloon.setPosition( 0, y );

   // Generate a random value for the balloon's
   // moving distance.
   int dist = agk::Random(1, MAX_BALLOON_DIST);

   // Set the balloon's moving distance.
   balloon.setDistance(dist);
}

// The restartDart function repositions the dart sprite
// at the bottom center of the screen.
void restartDart()
{
   // Calculate the dart's X coordinate so it is
   // centered horizontally on the screen.
   int x = ( SCREEN_WIDTH / 2 ) - 
         ( dart.getSpriteWidth()  / 2);

   // Set the dart's Y coordinate so it is at the
   // bottom of the screen.
   int y = SCREEN_HEIGHT - dart.getSpriteHeight();

   // Position the dart at its new location.
   dart.setPosition( x, y );
}

// The moveBalloon function moves the balloon to the
// right. If it is at the right edge of the screen,
// it restarts the balloon.
void moveBalloon()
{
   if (balloon.getX() < SCREEN_WIDTH)
   {
      balloon.moveRight();
   }
   else
   {
      restartBalloon();
   }
}

// The moveDart function updates the dart's position.
// If the dart has been launched, it is moved up.
// If the dart has reached the top of the screen,
// it is restarted and the dartLaunched flag is
// set to false.
void moveDart()
{
    // If the dart has been launched, move it up.
    if (g_dartLaunched)
    {
        dart.moveUp();
    }

    // If the dart has reached the top of the screen,
    // restart it.
    if ( dart.getY() < 0 )
    {
        // Restart the dart.
        restartDart();

        // Reset the dartLaunched flag.
        g_dartLaunched = false;
    }
}

 
// The checkForCollision function determines whether
// the dart and the balloon have collided. If so, a 
// laser sound is played and the objects are reset.                     
void checkForCollision()
{
   // Determine whether the dart and the balloon
   // have collided.
   if ( agk::GetSpriteCollision( dart.getSpriteIndex(), 
                      balloon.getSpriteIndex() ) )
   {
      // Play the laser sound.
      agk::PlaySound(LASER_SOUND);

      // Restart the balloon.
      restartBalloon();

      // Restart the dart.
      restartDart();

      // Reset the g_dartLaunched flag.
      g_dartLaunched = false;
   }
}
