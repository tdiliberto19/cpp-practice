// This program lets the user chase randomly generated
// pizza slices with a robot. It demonstrates collision
// detection with sprites.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

// Constants for images
const int ROBOT_IMAGE = 1;
const int PIZZA_IMAGE = 2;
const int YUM_IMAGE   = 3;

// Constants for sprites
const int ROBOT_SPRITE = 1;
const int PIZZA_SPRITE = 2;
const int YUM_SPRITE   = 3;

// Constants for animation
const int FRAME_WIDTH   = 128;
const int FRAME_HEIGHT  = 128;
const int FRAME_COUNT   = 3;
float FRAMES_PER_SECOND = 3;

// Constant for the amount to move the robot
const float ROBOT_MOVE = 4;

// Constants for the robot's initial XY values.
const float ROBOT_X = 0;
const float ROBOT_Y = SCREEN_HEIGHT - FRAME_HEIGHT;

// Constant for the sleep time.
const int HALF_SECOND = 500;

// Constants for showing and hiding sprites.
const int HIDE = 0;
const int SHOW = 1;

// Function prototypes
void updateRobot();
void detectCollision();
void showYum();
void generatePizza();

// Begin app, called once at the start
void app::Begin( void )
{
	// Set the virtual resolution.
	agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

	// Set the window title.
	agk::SetWindowTitle("PizzaBot");

	// Load the images.
	agk::LoadImage(ROBOT_IMAGE, "PizzaBot/Robot.png");
	agk::LoadImage(PIZZA_IMAGE, "PizzaBot/Pizza.png");
	agk::LoadImage(YUM_IMAGE, "PizzaBot/Yum.png");

	// Create the sprites.
	agk::CreateSprite(ROBOT_SPRITE, ROBOT_IMAGE);
	agk::CreateSprite(PIZZA_SPRITE, PIZZA_IMAGE);
	agk::CreateSprite(YUM_SPRITE, YUM_IMAGE);

	// Set the sprite animation sequence for the robot.
	agk::SetSpriteAnimation(ROBOT_SPRITE, FRAME_WIDTH, 
							FRAME_HEIGHT, FRAME_COUNT);

	// Set the position of the robot sprite.
	agk::SetSpritePosition(ROBOT_SPRITE, ROBOT_X, ROBOT_Y);

	// Play the robot sprite animation.
	agk::PlaySprite(ROBOT_SPRITE, FRAMES_PER_SECOND);

	// Generate a slice of pizza.
	generatePizza();
}

// Main loop, called every frame
void app::Loop ( void )
{
	// Update the robot's position.
	updateRobot();

	// Check for a collision between 
	// the robot and the pizza.
	detectCollision();

	// Refresh the screen.
	agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}

// The update function moves the robot if the user
// is pressing an arrow key.
void updateRobot()
{
	// Store the robot's X and Y coordinates.
	float robotX = agk::GetSpriteX(ROBOT_SPRITE);
	float robotY = agk::GetSpriteY(ROBOT_SPRITE);

	// Determine if the user is pressing the down arrow key,
	// and if so move the robot down.
	if (agk::GetRawKeyState(AGK_KEY_DOWN))
		robotY += ROBOT_MOVE;

	// Determine if the user is pressing the up arrow key,
	// and if so, move the robot up.
	if (agk::GetRawKeyState(AGK_KEY_UP))
		robotY -= ROBOT_MOVE;

	// Determine if the user is pressing the left arrow key,
	// and if so, move the robot left.
	if (agk::GetRawKeyState(AGK_KEY_LEFT))
		robotX -= ROBOT_MOVE;

	// Determine if the user is pressing the right arrow key,
	// and if so, move the robot up.
	if (agk::GetRawKeyState(AGK_KEY_RIGHT))
		robotX += ROBOT_MOVE;

	// Update the robot's position.
	agk::SetSpritePosition(ROBOT_SPRITE, robotX, robotY);
}

// The generatePizza function generates a new slice of 
// pizza at a random location.
void generatePizza()
{
	// Store the width and height of the pizza sprite.
	float width = agk::GetSpriteWidth(PIZZA_SPRITE);
	float height = agk::GetSpriteHeight(PIZZA_SPRITE);

	// Calculate the maximum XY values for the 
	// random position of the pizza sprite.
	float maxX = SCREEN_WIDTH - width;
	float maxY = SCREEN_HEIGHT - height;

	// Generate and store the random XY 
	// coordinates of the the pizza.
	float x = (float)(agk::Random(0, (int)maxX));
	float y = (float)(agk::Random(0, (int)maxY));

	// Hide the yum sprite.
	agk::SetSpriteVisible(YUM_SPRITE, HIDE);

	// Set the new position of the pizza and yum sprites.
	agk::SetSpritePosition(PIZZA_SPRITE, x, y);
	agk::SetSpritePosition(YUM_SPRITE, x, y);

	// Show the pizza sprite.
	agk::SetSpriteVisible(PIZZA_SPRITE, SHOW);
}

// The showYum function momentarily displays the Yum!
// sprite in place of the pizza sprite.
void showYum()
{
	// Hide the pizza sprite.
	agk::SetSpriteVisible(PIZZA_SPRITE, HIDE);

	// Show the yum sprite.
	agk::SetSpriteVisible(YUM_SPRITE, SHOW);

	// Refresh the screen, so we can see the changes.
	agk::Sync();

	// Wait for half a second.
	agk::Sleep(HALF_SECOND);
}

// The detectCollision function determines whether the 
// robot has collided with the pizza. If so, a new slice 
// of pizza is generated.
void detectCollision()
{
	// Determine if the robot has collided with the pizza.
	if (agk::GetSpriteCollision(ROBOT_SPRITE, PIZZA_SPRITE))
	{
		// Hide the pizza and show the yum sprite.
		showYum();

		// Hide the yum sprite and show the pizza.
		generatePizza();
	}
}
