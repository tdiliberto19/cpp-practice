// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Constants for the frame rate and refresh mode.
const float FRAME_RATE = 5;
const int REFRESH_MODE = 1;

// Constants for the sprite indices
const int HOUSE_INDEX = 1;
const int GHOST_INDEX = 2;

// Constants for the ghost's minimum and maximum alpha.
const int MIN_ALPHA = 50;
const int MAX_ALPHA = 255;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Create the haunted house sprite for the background.
   agk::CreateSprite(HOUSE_INDEX,
         "HauntedHouse/haunted_house.png");

   // Create the ghost sprite.
   agk::CreateSprite(GHOST_INDEX,
         "HauntedHouse/ghost.png");

   // Set the frame rate.
   agk::SetSyncRate(FRAME_RATE, REFRESH_MODE);
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Variables for the ghost's location and alpha value
   int ghostX, ghostY, ghostAlpha;

   // Get random coordinates.
   ghostX = agk::Random(0, SCREEN_WIDTH);
   ghostY = agk::Random(0, SCREEN_HEIGHT);

   // Get a random value for the ghost's alpha.
   ghostAlpha = agk::Random(MIN_ALPHA, MAX_ALPHA);

   // Set the ghost's position.
   agk::SetSpritePosition(GHOST_INDEX, ghostX, ghostY);

   // Set the ghost's alpha value.
   agk::SetSpriteColorAlpha(GHOST_INDEX, ghostAlpha);

   // Display the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
