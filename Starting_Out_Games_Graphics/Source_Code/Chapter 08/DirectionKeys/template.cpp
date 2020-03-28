// This program demonstrates direction keys.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants
const int SCREEN_WIDTH     = 640;
const int SCREEN_HEIGHT    = 480;
const int SPRITE_INDEX     = 1;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Direction Keys");

   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Create the sprite.
   agk::CreateSprite(SPRITE_INDEX, "fish.png");
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Get the direction as input from the keyboard.
   float directionX = agk::GetDirectionX();
   float directionY = agk::GetDirectionY();

   // Get the sprite position.
   float spriteX = agk::GetSpriteX(SPRITE_INDEX);
   float spriteY = agk::GetSpriteY(SPRITE_INDEX);

   // Calculate how far the sprite will move.
   float moveX = spriteX + directionX;
   float moveY = spriteY + directionY;

   // Set the sprite position.
   agk::SetSpritePosition(SPRITE_INDEX, moveX, moveY);

   // Refresh the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
