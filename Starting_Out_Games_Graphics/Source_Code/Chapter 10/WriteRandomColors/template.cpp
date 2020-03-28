// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Constant for the file number
const int OUTPUT_FILE = 1;

// Constant for the number of colors
const int MAX_COLORS = 10;

// Global variable to count the colors
int g_numColors = 0;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Open the output file.
   agk::OpenToWrite(OUTPUT_FILE, "Colors.dat");
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Variables to hold color channel values
   int red, green, blue;

   if (g_numColors < MAX_COLORS)
   {
      // Generate random color values
      red = agk::Random(0, 255);
      green = agk::Random(0, 255);
      blue = agk::Random(0, 255);

      // Write the color values to the file.
      agk::WriteInteger(OUTPUT_FILE, red);
      agk::WriteInteger(OUTPUT_FILE, green);
      agk::WriteInteger(OUTPUT_FILE, blue);

      // Increment the color counter.
      g_numColors++;
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
   agk::CloseFile(OUTPUT_FILE);
}
