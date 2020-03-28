// This program demonstrates using a texture atlas 
// to display an animated clock.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int IMAGE_INDEX   = 1;
const int FRAME_WIDTH   = 240;
const int FRAME_HEIGHT  = 240;
const int FRAME_COUNT   = 8;
const int SPRITE_INDEX  = 1;
const float SPRITE_X = SCREEN_WIDTH / 2 - FRAME_WIDTH / 2;
const float SPRITE_Y = SCREEN_HEIGHT / 2 - FRAME_HEIGHT / 2;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Clock Texture Atlas");

   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Load the texture atlas.
   agk::LoadImage(IMAGE_INDEX, "ClockTextureAtlas.png");

   // Create the sprite using the texture atlas as the image.
   agk::CreateSprite(SPRITE_INDEX, IMAGE_INDEX);

   // Set the sprite animation.
   agk::SetSpriteAnimation(SPRITE_INDEX, FRAME_WIDTH, 
                           FRAME_HEIGHT, FRAME_COUNT);

   // Set the sprite's position.
   agk::SetSpritePosition(SPRITE_INDEX, SPRITE_X, SPRITE_Y);

   // Play the clock animation.
   agk::PlaySprite(SPRITE_INDEX);
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Refresh the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
