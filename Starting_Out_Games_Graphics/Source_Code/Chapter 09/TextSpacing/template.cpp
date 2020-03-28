// This program demonstrates text spacing.
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

// Constants for the text objects
const int TEXT_A	= 1;
const int TEXT_B	= 2;
const int TEXT_C	= 3;

const int ALIGN_CENTER	= 1;
const float TEXT_SIZE	= 16;

const float CENTER_X	= SCREEN_WIDTH / 2;
const float CENTER_Y	= SCREEN_HEIGHT / 2;

// Begin app, called once at the start
void app::Begin( void )
{
	// Set the virtual screen resolution.
	agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

	// Set the window title.
	agk::SetWindowTitle("Text Spacing");

	// Create the text objects.
	agk::CreateText(TEXT_A, "Default Spacing");
	agk::CreateText(TEXT_B, "Ten Unit Spacing");
	agk::CreateText(TEXT_C, "Twenty Unit Spacing");

	// Set the size of each text object.
	agk::SetTextSize(TEXT_A, TEXT_SIZE);
	agk::SetTextSize(TEXT_B, TEXT_SIZE);
	agk::SetTextSize(TEXT_C, TEXT_SIZE);

	// Set the alignment of each text object.
	agk::SetTextAlignment(TEXT_A, ALIGN_CENTER);
	agk::SetTextAlignment(TEXT_B, ALIGN_CENTER);
	agk::SetTextAlignment(TEXT_C, ALIGN_CENTER);

	// Set the spacing of each text object.
	agk::SetTextSpacing(TEXT_A, 0);
	agk::SetTextSpacing(TEXT_B, 10);
	agk::SetTextSpacing(TEXT_C, 20);

	// Set the position of each text object.
	agk::SetTextPosition(TEXT_A, CENTER_X, CENTER_Y - 40);
	agk::SetTextPosition(TEXT_B, CENTER_X, CENTER_Y);
	agk::SetTextPosition(TEXT_C, CENTER_X, CENTER_Y + 40);
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
