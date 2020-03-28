// This program demonstrates collision detection 
// with a text object and the mouse pointer.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

// Constant for the text object index number.
const int TEXT = 1;

// Constant for the text object size.
const float TEXT_SIZE = 16;

// Constant for the text object alignment.
const int ALIGN_CENTER = 1;

// Constants for the center of the screen.
const float CENTER_X = SCREEN_WIDTH / 2;
const float CENTER_Y = SCREEN_HEIGHT / 2;

// Begin app, called once at the start
void app::Begin( void )
{
	// Set the virtual resolution.
	agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

	// Set the window title.
	agk::SetWindowTitle("Text Object Collision");

	// Create the text object.
	agk::CreateText(TEXT, "");

	// Set the size of the text object.
	agk::SetTextSize(TEXT, TEXT_SIZE);

	// Set the alignment of the text object.
	agk::SetTextAlignment(TEXT, ALIGN_CENTER);

	// Set the position of the text object.
	agk::SetTextPosition(TEXT, CENTER_X, CENTER_Y);
}

// Main loop, called every frame
void app::Loop ( void )
{
	// Get the mouse coordinates.
	float mouseX = agk::GetRawMouseX();
	float mouseY = agk::GetRawMouseY();

	// Determine if the mouse pointer has hit the text object.
	if (agk::GetTextHitTest(TEXT, mouseX, mouseY))
		agk::SetTextString(TEXT, "Ouch! You hit me.");
	else
		agk::SetTextString(TEXT, "I am a text object.");

	// Refresh the screen.
	agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
