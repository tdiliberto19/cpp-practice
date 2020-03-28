// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution, refresh rate,
// and refresh mode
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int REFRESH_RATE = 1;
const int REFRESH_MODE = 0;

// Constant for the file number
const int INPUT_FILE = 1;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Set the sync rate.
   agk::SetSyncRate(REFRESH_RATE, REFRESH_MODE);

   // Open the output file.
   agk::OpenToRead(INPUT_FILE, "Colors.dat");
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Variables to hold color channel values
   int red, green, blue;

   // If not at the end of the file, read the next
   // set of color values and clear the screen to 
   // that color.
   if (!agk::FileEOF(INPUT_FILE))
   {
      // Generate random color values
      red = agk::ReadInteger(INPUT_FILE);
      green = agk::ReadInteger(INPUT_FILE);
      blue = agk::ReadInteger(INPUT_FILE);

      // Set the screen's clear color.
      agk::SetClearColor(red, green, blue);

      // Clear the screen.
      agk::ClearScreen();
   }
   else
   {
      agk::Print("Finished!");
   }

   // Update the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
   // Close the file.
   agk::CloseFile(INPUT_FILE);
}
