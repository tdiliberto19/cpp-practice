// This program demonstrates virtual buttons.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants
const int SCREEN_WIDTH      = 640;
const int SCREEN_HEIGHT     = 480;
const int SPRITE_INDEX      = 1;
const int SHOW_BUTTON_INDEX = 1;
const int HIDE_BUTTON_INDEX = 2;
const float BUTTON_SIZE     = 100.0;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Virtual Buttons");

   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Create the sprite.
   agk::CreateSprite(SPRITE_INDEX, "frog.png");

   // Calculate the position of the sprite.
   float spriteWidth = agk::GetSpriteWidth(SPRITE_INDEX);
   float spriteX = SCREEN_WIDTH / 2 - spriteWidth / 2;
   float spriteY = 0.0;

   // Set the position of the sprite.
   agk::SetSpritePosition(SPRITE_INDEX, spriteX, spriteY);

   // Calculate the position of the virtual "show" button.
   float showButtonX = SCREEN_WIDTH / 2 - BUTTON_SIZE;
   float showButtonY = SCREEN_HEIGHT - BUTTON_SIZE;

   // Calculate the position of the virtual "hide" button.
   float hideButtonX = SCREEN_WIDTH / 2 + BUTTON_SIZE;
   float hideButtonY = SCREEN_HEIGHT - BUTTON_SIZE;

   // Add the virtual buttons.
   agk::AddVirtualButton(SHOW_BUTTON_INDEX, showButtonX, 
                         showButtonY, BUTTON_SIZE);
   agk::AddVirtualButton(HIDE_BUTTON_INDEX, hideButtonX, 
                         hideButtonY, BUTTON_SIZE);

   // Set the text of the virtual buttons.
   agk::SetVirtualButtonText(SHOW_BUTTON_INDEX, "Show");
   agk::SetVirtualButtonText(HIDE_BUTTON_INDEX, "Hide");
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Determine if the virtual "show" button was pressed.
   if(agk::GetVirtualButtonPressed(SHOW_BUTTON_INDEX))
      // Show the sprite.
      agk::SetSpriteVisible(SPRITE_INDEX, 1);
   
   // Determine if the virtual "hide" button was pressed.
   if(agk::GetVirtualButtonPressed(HIDE_BUTTON_INDEX))
      // Hide the sprite.
      agk::SetSpriteVisible(SPRITE_INDEX, 0);

   // Refresh the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
