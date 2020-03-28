// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Constants for the sprite index
const int GHOST_INDEX = 1;

// Constant for the amount to rotate
const float ROTATION = 10;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Create the ghost sprite.
   agk::CreateSprite(GHOST_INDEX, "ghost.png");
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Get the ghost's angle.
   float ghostAngle = agk::GetSpriteAngle(GHOST_INDEX);

   // Rotate the ghost.
   agk::SetSpriteAngle(GHOST_INDEX, ghostAngle + ROTATION);

   // Display the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
