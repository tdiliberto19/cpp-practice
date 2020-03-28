// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Constants for the sprite index
const int GHOST_INDEX = 1;

// Constants for the ghost's starting position
const float GHOST_START_X = 0;
const float GHOST_START_Y = 150;

// Constant for the ghost's ending X coordinate
const float GHOST_END_X = 540;

// Constant for the amount to increment the
// ghost's X coordinate
const int INCREMENT = 10;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Create the ghost sprite.
   agk::CreateSprite(GHOST_INDEX, "ghost.png");

   // Set the ghost's position.
   agk::SetSpritePosition(GHOST_INDEX, 
                GHOST_START_X, GHOST_START_Y);
}

// Main loop, called every frame
void app::Loop( void )
{
   // Get the ghost's current X coordinate.
   float ghostX = agk::GetSpriteX(GHOST_INDEX);

   if (ghostX < GHOST_END_X)
   {
      agk::SetSpriteX(GHOST_INDEX, ghostX + INCREMENT);
   }
   else
   {
      agk::SetSpriteX(GHOST_INDEX, GHOST_START_X);
   }

   // Display the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
