// This program demonstrates how sprite
// collisions can be detected.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

// Constant for the image index numbers.
const int BALL1_IMAGE = 1;
const int BALL2_IMAGE = 2;

// Constant for the sprite index numbers.
const int BALL1_SPRITE = 1;
const int BALL2_SPRITE = 2;

// Constant for ball 1's intitial X position.
const float BALL1_X = 0;

// Constant for ball 2's intitial Y position.
const float BALL2_X = 511;

// Constant for the Y position of both sprites.
const float BALL_Y = 175;

// Constant for the distance to move each frame.
const float DISTANCE = 1;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Set the window title.
   agk::SetWindowTitle("Sprite Collision");

   // Load the images.
   agk::LoadImage(BALL1_IMAGE, "BowlingBall1.png");
   agk::LoadImage(BALL2_IMAGE, "BowlingBall2.png");

   // Create the sprites.
   agk::CreateSprite(BALL1_SPRITE, BALL1_IMAGE);
   agk::CreateSprite(BALL2_SPRITE, BALL2_IMAGE);

   // Set the position of each sprite.
   agk::SetSpritePosition(BALL1_SPRITE, BALL1_X, BALL_Y);
   agk::SetSpritePosition(BALL2_SPRITE, BALL2_X, BALL_Y);
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Get the X coordinate of each sprite.
   float ball1x = agk::GetSpriteX(BALL1_SPRITE);
   float ball2x = agk::GetSpriteX(BALL2_SPRITE);

   // Determine if the two sprites have collided.
   if (agk::GetSpriteCollision(BALL1_SPRITE, BALL2_SPRITE))
   {
      // Reset the sprites to their original locations.
      agk::SetSpriteX(BALL1_SPRITE, BALL1_X);
      agk::SetSpriteX(BALL2_SPRITE, BALL2_X);
   }
   else
   {
      // Move ball 2 to the right.
      agk::SetSpriteX(BALL1_SPRITE, ball1x + DISTANCE);

      // Move ball 1 to the left.
      agk::SetSpriteX(BALL2_SPRITE, ball2x - DISTANCE);
   }

   // Refresh the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
