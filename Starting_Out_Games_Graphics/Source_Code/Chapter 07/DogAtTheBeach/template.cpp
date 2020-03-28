// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Constants for the beach background
const int BEACH_SPRITE_INDEX = 1;

// Constants for the Dog image and sprite
const int DOG_IMAGE_INDEX = 1;
const int DOG_SPRITE_INDEX = 2;
const int BLACK_TRANSPARENT = 1;
const int DOG_X = 100;
const int DOG_Y = 240;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Create the beach sprite.
   agk::CreateSprite(BEACH_SPRITE_INDEX, "Beach.png");

   // Load the dog image with black pixels transparent.
   agk::LoadImage(DOG_IMAGE_INDEX, "Dog.png", 
                 BLACK_TRANSPARENT);

   // Create the dog sprite from the dog image.
   agk::CreateSprite(DOG_SPRITE_INDEX, DOG_IMAGE_INDEX);

   // Set the dog sprite's position.
   agk::SetSpritePosition(DOG_SPRITE_INDEX, DOG_X, DOG_Y);
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
