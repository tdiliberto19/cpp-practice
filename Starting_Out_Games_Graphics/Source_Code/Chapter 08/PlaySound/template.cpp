// This program loads a sound file and plays it.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Play Sound");

  // Set the virtual resolution.
   agk::SetVirtualResolution(640, 480);

   // Load the sound file sparkle.wav as
   // sound number 1.
   agk::LoadSound(1, "sparkle.wav");

   // Play sound number 1.
   agk::PlaySound(1);
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
