// This program demonstrates how to get
// the mouse pointer's location.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants
const int SCREEN_WIDTH	= 640;
const int SCREEN_HEIGHT	= 480;
const int SPRITE_INDEX	= 1;

// Variables to hold the mouse pointer's
// X and Y coordinates.
float mouseX, mouseY;

// Begin app, called once at the start
void app::Begin( void )
{
	 // Set the virtual resolution, window title, and
	 // create the sprite.
	 agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);
	 agk::SetWindowTitle("Sprite Mouse");
	 agk::CreateSprite(SPRITE_INDEX, "mouse.png");
}

// Main loop, called every frame
void app::Loop ( void )
{
	 // Get the mouse pointer's location.
	 mouseX = agk::GetRawMouseX();
	 mouseY = agk::GetRawMouseY();

	 // Set the sprite's position to the mouse
	 // pointer's location.
	 agk::SetSpritePosition(SPRITE_INDEX, mouseX, mouseY);

	 // Refresh the screen.
	 agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
