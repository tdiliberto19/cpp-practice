// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Constants for the sprite indices
const int HOUSE_INDEX = 1;
const int GHOST_INDEX = 2;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Create the ghost sprite.
   agk::CreateSprite(GHOST_INDEX, "ghost.png");

   // Create the haunted house sprite for the background.
   agk::CreateSprite(HOUSE_INDEX, "haunted_house.png");

   // Set the sprite depth values so the ghost is always
   // drawn in front of the haunted house.
   agk::SetSpriteDepth(GHOST_INDEX, 0);
   agk::SetSpriteDepth(HOUSE_INDEX, 1000);
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


