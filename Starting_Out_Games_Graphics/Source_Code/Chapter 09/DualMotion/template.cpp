// This program simulates a ball that is falling
// and moving horizontally.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants
const int SCREEN_WIDTH   = 640;
const int SCREEN_HEIGHT  = 480;
const int BALL_IMAGE	 = 1;
const int BALL_SPRITE	 = 1;
const float X_MOVEMENT	 = 10.0f;
const float ACCELERATION = 0.98f;

// Global variables
float g_time     = 0;
float g_distance = 0;

// Begin app, called once at the start
void app::Begin( void )
{
	// Set the virtual resolution.
	agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

	// Set the window title.
	agk::SetWindowTitle("Dual Motion");

	// Load the ball image.
	agk::LoadImage(BALL_IMAGE, "ball.png");

	// Create the ball sprite.
	agk::CreateSprite(BALL_SPRITE, BALL_IMAGE);

	// Set the starting position of the ball sprite.
	agk::SetSpriteX(BALL_SPRITE, SCREEN_WIDTH - 
		 agk::GetSpriteWidth(BALL_SPRITE));
}

// Main loop, called every frame
void app::Loop ( void )
{
	// Get the XY coordinates of the ball sprite.
	float y = agk::GetSpriteY(BALL_SPRITE);
	float x = agk::GetSpriteX(BALL_SPRITE);

	// If the ball is above the bottom of the screen,
	// then update its position.
	if (y < SCREEN_HEIGHT - agk::GetSpriteHeight(BALL_SPRITE))
	{

		// Set the X coordinate of the ball sprite so
		// that it will move to the left.
		x -= X_MOVEMENT;

		// Calculate the object's distance using the
		// distance formula.
		g_distance = 0.5f * ACCELERATION * g_time * g_time;

		// Set the Y coordinate of the ball sprite to 
		// the distance.
		y = g_distance;

		// Increment time.
		g_time++;
	}
	// Else, set the Y coordinate of the ball sprite at 
	// the bottom of the screen.
	else
	{
		y = SCREEN_HEIGHT - agk::GetSpriteHeight(BALL_SPRITE);
	}

	// Update the XY coordinates of the ball sprite.
	agk::SetSpritePosition(BALL_SPRITE, x, y);

	// Refresh the screen.
	agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}

