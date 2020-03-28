// This program demonstrates detecting the
// last key that was pressed on the keyboard.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants
const int SCREEN_WIDTH     = 640;
const int SCREEN_HEIGHT    = 480;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Last Key Pressed");

   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Get the key code of the last key that was pressed.
   int keycode = agk::GetRawLastKey();

   // Determine which message to display.
   switch(keycode)
   {
      case AGK_KEY_SPACE:
         agk::Print("You pressed the spacebar.");
         break;

      case AGK_KEY_ENTER:
         agk::Print("You pressed the enter key.");
         break;

      default:
         agk::Print("Press the spacebar or enter key.");
         break;
   }

   // Refresh the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
