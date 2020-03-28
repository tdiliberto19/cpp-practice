// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Constant for the sprite index
const int SPRITE_INDEX = 1;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Create the beach sprite.
   agk::CreateSprite(SPRITE_INDEX, "beach.png");
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Display the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
