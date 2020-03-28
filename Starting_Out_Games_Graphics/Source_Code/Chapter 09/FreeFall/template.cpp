// This program simulates a falling ball.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants
const int SCREEN_WIDTH   = 640;
const int SCREEN_HEIGHT  = 480;
const int BALL_IMAGE	 = 1;
const int BALL_SPRITE	 = 1;
const float ACCELERATION = 0.98;

// Global variables
float g_time     = 0;
float g_distance = 0;

// Begin app, called once at the start
void app::Begin( void )
{
	// Set the virtual resolution.
	agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

	// Set the window title.
	agk::SetWindowTitle("Free Fall");

	// Load the ball image.
	agk::LoadImage(BALL_IMAGE, "ball.png");

	// Create the ball sprite.
	agk::CreateSprite(BALL_SPRITE, BALL_IMAGE);

	// Set the starting position of the ball sprite.
	agk::SetSpriteX(BALL_SPRITE, SCREEN_WIDTH / 2 - 
		 agk::GetSpriteWidth(BALL_SPRITE) / 2);
}

// Main loop, called every frame
void app::Loop ( void )
{
	// Get the Y coordinate of the ball sprite.
	float y = agk::GetSpriteY(BALL_SPRITE);

	// If the ball is above the bottom of the screen,
	// then update its position.
	if (y < SCREEN_HEIGHT - agk::GetSpriteHeight(BALL_SPRITE))
	{
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

	// Update the Y coordinate of the ball sprite.
	agk::SetSpriteY(BALL_SPRITE, y);

	// Refresh the screen.
	agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
