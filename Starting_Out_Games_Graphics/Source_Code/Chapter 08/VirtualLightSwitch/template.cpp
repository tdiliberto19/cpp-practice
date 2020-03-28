// This program demonstrates a virtual light switch.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

const int ROOM    = 1;
const int SWITCH  = 2;
const int ON      = 1;
const int OFF     = 2;

// Global variable for the light switch state.
bool g_lightOn = true;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Virtual Light Switch");

   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Load the images.
   agk::LoadImage(ON, "light_switch_on.png");
   agk::LoadImage(OFF, "light_switch_off.png");

   // Create the sprites.
   agk::CreateSprite(ROOM, "room.png");
   agk::CreateSprite(SWITCH, ON);
   agk::SetSpriteScale(SWITCH, 0.15f, 0.15f);
   agk::SetSpritePosition(SWITCH, 50, 50);
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Determine if the left mouse button was pressed.
   if(agk::GetRawMouseLeftPressed())
   {
      // Get the mouse coordinates.
      float mouseX = agk::GetRawMouseX();
      float mouseY = agk::GetRawMouseY();

      // Determine if the mouse hit the sprite.
      if (agk::GetSpriteHit(mouseX, mouseY) == SWITCH)
      {
         // Determine if the light is already on.
         if(g_lightOn)
         {
            // Turn the light switch off.
            agk::SetSpriteColor(ROOM, 64, 64, 64, 255);
            agk::SetSpriteColor(SWITCH, 64, 64, 64, 255);
            agk::SetSpriteImage(SWITCH, OFF);

            g_lightOn = false;   // Set the state to false.
         }
         else
         {
            // Turn the light switch on.
            agk::SetSpriteColor(ROOM, 255, 255, 255, 255);
            agk::SetSpriteColor(SWITCH, 255, 255, 255, 255);
            agk::SetSpriteImage(SWITCH, ON);

            g_lightOn = true; // Set the state to true.
         }
      }
   }

   // Refresh the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
