// This program demonstrates setting the
// size and position of several text objects.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

// Constants for the text object index numbers
const int TEXT_A = 1;
const int TEXT_B = 2;
const int TEXT_C = 3;
const int TEXT_D = 4;
const int TEXT_E = 5;
const int TEXT_F = 6;

// Constants for the text object sizes
const float SIZE_A = 12;
const float SIZE_B = 16;
const float SIZE_C = 24;
const float SIZE_D = 36;
const float SIZE_E = 48;
const float SIZE_F = 72;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Set the window title.
   agk::SetWindowTitle("Text Sizes");

   // Create the text objects.
   agk::CreateText(TEXT_A, "Text Size 12");
   agk::CreateText(TEXT_B, "Text Size 16");
   agk::CreateText(TEXT_C, "Text Size 24");
   agk::CreateText(TEXT_D, "Text Size 36");
   agk::CreateText(TEXT_E, "Text Size 48");
   agk::CreateText(TEXT_F, "Text Size 72");

   // Set the size of each text object.
   agk::SetTextSize(TEXT_A, SIZE_A);
   agk::SetTextSize(TEXT_B, SIZE_B);
   agk::SetTextSize(TEXT_C, SIZE_C);
   agk::SetTextSize(TEXT_D, SIZE_D);
   agk::SetTextSize(TEXT_E, SIZE_E);
   agk::SetTextSize(TEXT_F, SIZE_F);

   // Variables to hold XY coordinates, initialized to 0.
   float x = 0;
   float y = 0;

   // Set the position of text object A.
   agk::SetTextPosition(TEXT_A, x, y);

   // Increment the Y coordinate with 
   // the size of text object A.
   y += SIZE_A;

   // Set the position of text object B.
   agk::SetTextPosition(TEXT_B, x, y);

   // Increment the Y coordinate with 
   // the size of text object B.
   y += SIZE_B;

   // Set the position of text object C.
   agk::SetTextPosition(TEXT_C, x, y);

   // Increment the Y coordinate with 
   // the size of text object C.
   y += SIZE_C;

   // Set the position of text object D.
   agk::SetTextPosition(TEXT_D, x, y);

   // Increment the Y coordinate with 
   // the size of text object D.
   y += SIZE_D;

   // Set the position of text object E.
   agk::SetTextPosition(TEXT_E, x, y);

   // Increment the Y coordinate with 
   // the size of text object E.
   y += SIZE_E;

   // Set the position of text object F.
   agk::SetTextPosition(TEXT_F, x, y);
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
