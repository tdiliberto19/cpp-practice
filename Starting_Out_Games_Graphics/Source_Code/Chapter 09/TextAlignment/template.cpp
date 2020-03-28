// This program demonstrates text alignment.
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

// Constants for the text objects
const int LEFT_TEXT		= 1;
const int CENTER_TEXT	= 2;
const int RIGHT_TEXT	= 3;

const int ALIGN_LEFT	= 0;
const int ALIGN_CENTER	= 1;
const int ALIGN_RIGHT	= 2;

const float TEXT_SIZE	= 16;

const float CENTER_X	= SCREEN_WIDTH / 2;
const float CENTER_Y	= SCREEN_HEIGHT / 2;

// Begin app, called once at the start
void app::Begin( void )
{
	// Set the virtual screen resolution.
	agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

	// Set the window title.
	agk::SetWindowTitle("Text Alignment");

	// Create the text objects.
	agk::CreateText(LEFT_TEXT, "Left-aligned");
	agk::CreateText(CENTER_TEXT, "Center-aligned");
	agk::CreateText(RIGHT_TEXT, "Right-aligned");

	// Set the size of each text object.
	agk::SetTextSize(LEFT_TEXT, TEXT_SIZE);
	agk::SetTextSize(CENTER_TEXT, TEXT_SIZE);
	agk::SetTextSize(RIGHT_TEXT, TEXT_SIZE);

	// Set the alignment of each text object.
	agk::SetTextAlignment(LEFT_TEXT, ALIGN_LEFT);
	agk::SetTextAlignment(CENTER_TEXT, ALIGN_CENTER);
	agk::SetTextAlignment(RIGHT_TEXT, ALIGN_RIGHT);

	// Set the position of each text object.
	agk::SetTextPosition(LEFT_TEXT, CENTER_X, CENTER_Y - 40);
	agk::SetTextPosition(CENTER_TEXT, CENTER_X, CENTER_Y);
	agk::SetTextPosition(RIGHT_TEXT, CENTER_X, CENTER_Y + 40);
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
