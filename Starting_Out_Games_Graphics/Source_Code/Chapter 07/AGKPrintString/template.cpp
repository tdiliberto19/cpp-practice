// Includes, namespace and prototypes
#include <string>       // Needed for string objects
#include "template.h"
using namespace AGK;
using namespace std;    // Needed for string objects
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
   // Declare a string object.
   string str = "This is a test.";

   // Display the string object.
   agk::Print(str.c_str());

   // Display the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
