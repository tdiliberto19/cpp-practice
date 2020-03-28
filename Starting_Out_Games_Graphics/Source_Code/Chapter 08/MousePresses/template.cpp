// This program demonstrates pressing 
// the left or right mouse buttons.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title and the virtual resolution.
   agk::SetWindowTitle("Mouse Presses");
   agk::SetVirtualResolution(agk::GetDeviceWidth(), 
                             agk::GetDeviceHeight());
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Determine if the left mouse button was pressed.
   if(agk::GetRawMouseLeftPressed())
   {
      // Create a sprite using the "mouse.png" image, and 
      // set its position to the current mouse coordinates.
      agk::SetSpritePosition(agk::CreateSprite("mouse.png"), 
                             agk::GetRawMouseX(), 
                             agk::GetRawMouseY());
   }

   // Determine if the right mouse button was pressed.
   if(agk::GetRawMouseRightPressed())
   {
      // Create a sprite using the "cat.png" image, and 
      // set its position to the current mouse coordinates.
      agk::SetSpritePosition(agk::CreateSprite("cat.png"), 
                             agk::GetRawMouseX(), 
                             agk::GetRawMouseY());
   }

   // Refresh the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
