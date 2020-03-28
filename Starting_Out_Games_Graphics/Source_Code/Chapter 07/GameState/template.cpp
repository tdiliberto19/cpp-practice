// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Global constants for screen resolution 
const int   SCREEN_WIDTH = 640;  // Screen width
const int   SCREEN_HEIGHT = 480; // Screen height

// Global constants for the ghost sprite
const int   GHOST_INDEX = 1;     // Ghost sprite index
const float GHOST_START_X = 0;   // Ghost's starting X
const float GHOST_START_Y = 150; // Ghost's starting Y
const float GHOST_END_X = 540;   // Ghost's ending X
const int   INCREMENT = 10;      // Amount to move the ghost

// Global constants for the game state
const int   MOVING_RIGHT = 0;
const int   MOVING_LEFT  = 1;

// Global variable for game state
int g_gameState = MOVING_RIGHT;

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

   // Is the sprite moving to the right side of the screen?
   if (g_gameState == MOVING_RIGHT)
   {
      // The sprite is moving right. Has it reached the
      // edge of the screen?
      if (ghostX < GHOST_END_X)
      {
         // Not at the edge yet, so keep moving right.
         agk::SetSpriteX(GHOST_INDEX, ghostX + INCREMENT);
      }
      else
      {
         // The sprite is at the right edge of the screen.
         // Change the game state to reverse directions.
         g_gameState = MOVING_LEFT;
      }
   }
   else
   {
      // The sprite is moving to the left.
      // Has it reached the edge of the screen?
      if (ghostX > GHOST_START_X)
      {
         // Not at the edge yet, so keep moving left.
         agk::SetSpriteX(GHOST_INDEX, ghostX - INCREMENT);
      }
      else
      {
         // The sprite is at the left edge of the screen.
         // Change the game state to reverse directions.
         g_gameState = MOVING_RIGHT;
      }
   }

   // Display the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
