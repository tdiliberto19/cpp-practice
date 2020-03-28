// This program demonstrates a virtual joystick.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int SPRITE_INDEX  = 1;
const int JOY_INDEX     = 1;
const float JOY_SIZE    = 100.0;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Virtual Joystick");

   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Create the sprite.
   agk::CreateSprite(SPRITE_INDEX, "fish.png");

   // Calculate the position of the virtual joystick.
   float joyX = SCREEN_WIDTH / 2;
   float joyY = SCREEN_HEIGHT - JOY_SIZE / 2;

   // Add the virtual joystick.
   agk::AddVirtualJoystick(JOY_INDEX, joyX, joyY, JOY_SIZE);
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Get the joystick input.
   float joystickX = agk::GetVirtualJoystickX(JOY_INDEX);
   float joystickY = agk::GetVirtualJoystickY(JOY_INDEX);

   // Get the sprite position.
   float spriteX = agk::GetSpriteX(SPRITE_INDEX);
   float spriteY = agk::GetSpriteY(SPRITE_INDEX);

   // Calculate how far the sprite will move.
   float moveX = spriteX + joystickX;
   float moveY = spriteY + joystickY;

   // Set the sprite position.
   agk::SetSpritePosition(SPRITE_INDEX, moveX, moveY);

   // Refresh the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
