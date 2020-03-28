// This program demonstrates cel animation.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int FIRST_IMAGE   = 1;
const int LAST_IMAGE    = 8;
const int SPRITE_INDEX  = 1;
const float FPS         = 8;
const int MODE          = 0;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Cel Animation");

   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Set the frame rate and mode.
   agk::SetSyncRate(FPS, MODE);

   // Load the walking man images.
   agk::LoadImage(1, "WalkingMan1.png", 1);
   agk::LoadImage(2, "WalkingMan2.png", 1);
   agk::LoadImage(3, "WalkingMan3.png", 1);
   agk::LoadImage(4, "WalkingMan4.png", 1);
   agk::LoadImage(5, "WalkingMan5.png", 1);
   agk::LoadImage(6, "WalkingMan6.png", 1);
   agk::LoadImage(7, "WalkingMan7.png", 1);
   agk::LoadImage(8, "WalkingMan8.png", 1);

   // Create the sprite using the first frame of animation.
   agk::CreateSprite(SPRITE_INDEX, FIRST_IMAGE);

   // Calculate the sprite's position.
   float spriteWidth = agk::GetSpriteWidth(SPRITE_INDEX);
   float spriteHeight = agk::GetSpriteHeight(SPRITE_INDEX);
   float spriteX = SCREEN_WIDTH / 2 - spriteWidth / 2;
   float spriteY = SCREEN_HEIGHT / 2 - spriteHeight / 2;

   // Set the sprite's position.
   agk::SetSpritePosition(SPRITE_INDEX, spriteX, spriteY);
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Get the sprite's image number.
   int currentImage = agk::GetSpriteImageID(SPRITE_INDEX);

   // Update the sprite's image number.
   if (currentImage == LAST_IMAGE)
      currentImage = FIRST_IMAGE;
   else
      currentImage++;

   // Set the sprite's image number.
   agk::SetSpriteImage(SPRITE_INDEX, currentImage);

   // Refresh the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
