// This program demonstrates playing sounds
// when a sprite is clicked by the mouse.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int GUITAR_SPRITE = 1;
const int DRUM_SPRITE   = 2;
const int HORN_SPRITE   = 3;
const int GUITAR_SOUND  = 1;
const int DRUM_SOUND    = 2;
const int HORN_SOUND    = 3;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Sprite Sounds");

   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Load the sounds.
   agk::LoadSound(GUITAR_SOUND, "guitar.wav");
   agk::LoadSound(DRUM_SOUND, "drum.wav");
   agk::LoadSound(HORN_SOUND, "horn.wav");

   // Create the sprites.
   agk::CreateSprite(GUITAR_SPRITE, "guitar.png");
   agk::CreateSprite(DRUM_SPRITE, "drum.png");
   agk::CreateSprite(HORN_SPRITE, "horn.png");

   // Position the sprites.
   agk::SetSpritePosition(GUITAR_SPRITE, 0.0, 0.0);
   agk::SetSpritePosition(DRUM_SPRITE, 200.0, 200.0);
   agk::SetSpritePosition(HORN_SPRITE, 300.0, 300.0);
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Get the mouse coordinates.
   float mouseX = agk::GetRawMouseX();
   float mouseY = agk::GetRawMouseY();

   // Determine if the left mouse button was pressed.
   if(agk::GetRawMouseLeftPressed())
   {
      // Get the index number of the sprite that the mouse
      // is pointing at.
      int spriteIndex = agk::GetSpriteHit(mouseX, mouseY);

      // Determine if the sound is already playing.
      if(agk::GetSoundsPlaying(spriteIndex))
         // Stop the sound.
         agk::StopSound(spriteIndex);
      else
         // Play the sound.
         agk::PlaySound(spriteIndex);
   }

   // Refresh the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
