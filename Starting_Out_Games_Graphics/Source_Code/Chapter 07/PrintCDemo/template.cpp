// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Declare variables
   int iNum = 1;
   float fNum = 99.5;

   // Display some values.
   agk::PrintC("Here are an int and a float:");
   agk::PrintC(iNum);
   agk::PrintC(fNum);

   // Display the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
