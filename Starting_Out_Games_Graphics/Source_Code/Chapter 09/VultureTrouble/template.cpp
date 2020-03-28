// This program demonstrates the Vulture Trouble Game.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Constants for the screen resolution
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

// Constants for images
const int TITLE_SCREEN_IMAGE	= 1;
const int INTRO_SCREEN_IMAGE	= 2;
const int EGG_IMAGE				= 3;
const int BROKEN_EGG_IMAGE		= 4;
const int FARM_IMAGE			= 5;
const int BASKET_IMAGE			= 6;
const int HIT_BASKET_IMAGE		= 7;
const int VULTURE_IMAGE			= 8;

// Constants for sprites
const int TITLE_SCREEN_SPRITE	= 1;
const int INTRO_SCREEN_SPRITE	= 2;
const int EGG_SPRITE			= 3;
const int BROKEN_EGG_SPRITE		= 4;
const int FARM_SPRITE			= 5;
const int BASKET_SPRITE			= 6;
const int HIT_BASKET_SPRITE		= 7;
const int VULTURE_SPRITE		= 8;

// Constants for animation
const int FRAME_WIDTH			= 120;
const int FRAME_HEIGHT			= 110;
const int FRAME_COUNT			= 8;
const float FRAMES_PER_SECOND   = 8;

// Constants for the sounds
const int POP_SOUND				= 1;
const int CLAP_SOUND			= 2;
const int TYPE_SOUND			= 3;
const int COMPLETE_SOUND		= 4;
const int PERFECT_SCORE_SOUND	= 5;

// Constants for the music
const int INTRO_MUSIC			= 1;
const int MAIN_MUSIC			= 2;

// Constants for Text
const int GAME_OVER_TEXT		 = 1;
const int GAME_RESULTS_TEXT		 = 2;
const int EGGS_CAUGHT_TEXT		 = 3;
const int EGGS_MISSED_TEXT		 = 4;
const int TOTAL_SCORE_TEXT		 = 5;
const int CAUGHT_MULTIPLIER_TEXT = 6;
const int MISSED_MULTIPLIER_TEXT = 7;
const int PERFECT_SCORE_TEXT     = 8;
const float TEXT_SIZE		     = 36;

// Constants for the possible game states.
const int GAME_STARTED			= 1;
const int INTRO_STARTED			= 2;
const int GAME_IN_PLAY			= 3;
const int GAME_OVER				= 4;
const int SUMMARY_STARTED		= 5;

// Other constants
const int SCORE_MULTIPLIER  = 1000;
const int MAX_EGGS			= 40;
const float ACCELERATION	= 0.008f;
const float MIN_X			= 0;
const float MAX_X			= SCREEN_WIDTH;
const float BASKET_MOVE		= 4;
const float VULTURE_MOVE	= 2;
const float INTRO_TIMER		= 5;
const float SUMMARY_TIMER	= 5;
const float GAME_OVER_TIMER = 4;
const int EGG_CLONE			= 100;
const int HIDE				= 0;
const int SHOW				= 1;
const int LOOP				= 1;
const int NO				= 0;
const int YES				= 1;

// Global counter for the number of eggs caught and missed.
int g_eggs = MAX_EGGS;
int g_time = 0;
int g_eggsCaught = 0;
int g_eggsMissed = 0;
int g_totalScore = 0;
int g_summaryComplete = NO;
int g_gameState  = GAME_STARTED;

// Function prototypes
void displayTitleScreen();
void hideTitleScreen();
void displayIntroScreen();
void hideIntroScreen();
void playGame();
void hideGame();
void moveBasket();
void moveVulture();
void moveEgg();
void checkCollisions();
void showHitBasket();
void showBrokenEgg();
void resetEgg();
void displayGameOverScreen();
void hideGameOverScreen();
void displaySummaryScreen();
void hideSummaryScreen();

// Begin app, called once at the start
void app::Begin( void )
{
	// Set the virtual screen resolution.
	agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

	// Set the window title.
	agk::SetWindowTitle("Vulture Trouble");

	// Load the images.
	agk::LoadImage(TITLE_SCREEN_IMAGE, "titleScreen.png");
	agk::LoadImage(INTRO_SCREEN_IMAGE, "intro.png");
	agk::LoadImage(EGG_IMAGE, "egg.png");
	agk::LoadImage(BROKEN_EGG_IMAGE, "brokenEgg.png");
	agk::LoadImage(FARM_IMAGE, "farm.png");
	agk::LoadImage(BASKET_IMAGE, "basket.png");
	agk::LoadImage(HIT_BASKET_IMAGE, "hitBasket.png");
	agk::LoadImage(VULTURE_IMAGE, "vulture.png");

	// Create the sprites.
	agk::CreateSprite(TITLE_SCREEN_SPRITE, TITLE_SCREEN_IMAGE);
	agk::CreateSprite(INTRO_SCREEN_SPRITE, INTRO_SCREEN_IMAGE);
	agk::CreateSprite(FARM_SPRITE, FARM_IMAGE);
	agk::CreateSprite(EGG_SPRITE, EGG_IMAGE);
	agk::CreateSprite(VULTURE_SPRITE, VULTURE_IMAGE);
	agk::CreateSprite(BASKET_SPRITE, BASKET_IMAGE);
	agk::CreateSprite(BROKEN_EGG_SPRITE, BROKEN_EGG_IMAGE);
	agk::CreateSprite(HIT_BASKET_SPRITE, HIT_BASKET_IMAGE);

	// Load the sounds.
	agk::LoadSound(POP_SOUND, "pop.wav");
	agk::LoadSound(CLAP_SOUND, "clap.wav");
	agk::LoadSound(TYPE_SOUND, "type.wav");
	agk::LoadSound(COMPLETE_SOUND, "complete.wav");
	agk::LoadSound(PERFECT_SCORE_SOUND, "vulturePerfect.wav");

	// Load the music.
	agk::LoadMusic(INTRO_MUSIC, "vultureTrouble.mp3");
	agk::LoadMusic(MAIN_MUSIC, "vultureLevel.mp3");

	// Set up the vulture animation sequence.
	agk::SetSpriteAnimation(VULTURE_SPRITE, FRAME_WIDTH, 
		                    FRAME_HEIGHT, FRAME_COUNT);

	// Set the starting position of the vulture sprite.
	float vultureX = SCREEN_WIDTH / 2 - agk::GetSpriteWidth(VULTURE_SPRITE) / 2;
	float vultureY = 0;
	agk::SetSpritePosition(VULTURE_SPRITE, vultureX, vultureY);

	// Set the starting position of the basket sprite.
	float basketX = SCREEN_WIDTH / 2 - agk::GetSpriteWidth(BASKET_SPRITE) / 2;
	float basketY = SCREEN_HEIGHT - agk::GetSpriteHeight(BASKET_SPRITE);
	agk::SetSpritePosition(BASKET_SPRITE, basketX, basketY);

	// Set the starting position of the egg sprite.
	float eggX = vultureX;
	float eggY = vultureY + agk::GetSpriteHeight(EGG_SPRITE) * 1.5f;
	agk::SetSpritePosition(EGG_SPRITE, eggX, eggY);

	// Hide the sprites.
	agk::SetSpriteVisible(TITLE_SCREEN_SPRITE, HIDE);
	agk::SetSpriteVisible(INTRO_SCREEN_IMAGE, HIDE);
	agk::SetSpriteVisible(EGG_SPRITE, HIDE);
	agk::SetSpriteVisible(BROKEN_EGG_SPRITE, HIDE);
	agk::SetSpriteVisible(FARM_SPRITE, HIDE);
	agk::SetSpriteVisible(BASKET_SPRITE, HIDE);
	agk::SetSpriteVisible(HIT_BASKET_SPRITE, HIDE);
	agk::SetSpriteVisible(VULTURE_SPRITE, HIDE);

	// Generate the row of mini eggs clones.
	for(int count = 0; count < MAX_EGGS; count++)
	{
		int clone = EGG_CLONE + count;
		agk::CloneSprite(clone, EGG_SPRITE);
		agk::SetSpriteScale(clone, 0.5f, 0.5f);
		agk::SetSpritePosition(clone, agk::GetSpriteWidth(clone) * count, 0.0f);
	}

	// Create the text.
	agk::CreateText(GAME_OVER_TEXT, "GAME OVER");
	agk::CreateText(GAME_RESULTS_TEXT, "GAME RESULTS");
	agk::CreateText(EGGS_CAUGHT_TEXT, agk::Str(g_eggsCaught));
	agk::CreateText(EGGS_MISSED_TEXT, agk::Str(g_eggsMissed));
	agk::CreateText(CAUGHT_MULTIPLIER_TEXT, " X ");
	agk::CreateText(MISSED_MULTIPLIER_TEXT, " X ");
	agk::CreateText(TOTAL_SCORE_TEXT, agk::Str(g_totalScore));
	agk::CreateText(PERFECT_SCORE_TEXT, "PERFECT SCORE!");
	
	// Set the text size.
	agk::SetTextSize(GAME_OVER_TEXT, TEXT_SIZE);
	agk::SetTextSize(GAME_RESULTS_TEXT, TEXT_SIZE);
	agk::SetTextSize(EGGS_CAUGHT_TEXT, TEXT_SIZE);
	agk::SetTextSize(EGGS_MISSED_TEXT, TEXT_SIZE);
	agk::SetTextSize(CAUGHT_MULTIPLIER_TEXT, TEXT_SIZE);
	agk::SetTextSize(MISSED_MULTIPLIER_TEXT, TEXT_SIZE);
	agk::SetTextSize(TOTAL_SCORE_TEXT, TEXT_SIZE);
	agk::SetTextSize(PERFECT_SCORE_TEXT, TEXT_SIZE);

	// Set the game over text position.
	float gameOverTextX = SCREEN_WIDTH / 2 - agk::GetTextTotalWidth(GAME_OVER_TEXT) / 2;
	float gameOverTextY = SCREEN_HEIGHT / 2 - agk::GetTextTotalHeight(GAME_OVER_TEXT) / 2;
	agk::SetTextPosition(GAME_OVER_TEXT, gameOverTextX, gameOverTextY);

	// Set the game results text position.
	float gameResultsTextX = SCREEN_WIDTH / 2 - agk::GetTextTotalWidth(GAME_RESULTS_TEXT) / 2;
	float gameResultsTextY = SCREEN_HEIGHT / 6 - agk::GetTextTotalHeight(GAME_RESULTS_TEXT) / 2;
	agk::SetTextPosition(GAME_RESULTS_TEXT, gameResultsTextX, gameResultsTextY);

	// Set the eggs caught multiplier text position.
	float caughtMultiplierTextX = SCREEN_WIDTH / 4;
	float caughtMultiplierTextY = SCREEN_HEIGHT / 2 - agk::GetTextTotalHeight(CAUGHT_MULTIPLIER_TEXT) / 2;
	agk::SetTextPosition(CAUGHT_MULTIPLIER_TEXT, caughtMultiplierTextX, caughtMultiplierTextY);

	// Set the eggs caught text position.
	float eggsCaughtTextX = caughtMultiplierTextX + agk::GetTextTotalWidth(EGGS_CAUGHT_TEXT) * 3;
	float eggsCaughtTextY = SCREEN_HEIGHT / 2 - agk::GetTextTotalHeight(EGGS_CAUGHT_TEXT) / 2;
	agk::SetTextPosition(EGGS_CAUGHT_TEXT, eggsCaughtTextX, eggsCaughtTextY);

	// Set the eggs missed multiplier text position.
	float missedMultiplierTextX = SCREEN_WIDTH - SCREEN_WIDTH / 3;
	float missedMultiplierTextY = SCREEN_HEIGHT / 2 - agk::GetTextTotalHeight(MISSED_MULTIPLIER_TEXT) / 2;
	agk::SetTextPosition(MISSED_MULTIPLIER_TEXT, missedMultiplierTextX, missedMultiplierTextY);

	// Set the eggs missed text position.
	float eggsMissedTextX = missedMultiplierTextX + agk::GetTextTotalWidth(EGGS_MISSED_TEXT) * 3;
	float eggsMissedTextY = SCREEN_HEIGHT / 2 - agk::GetTextTotalHeight(EGGS_MISSED_TEXT) / 2;
	agk::SetTextPosition(EGGS_MISSED_TEXT, eggsMissedTextX, eggsMissedTextY);

	// Set the total score text position.
	float totalScoreTextX = SCREEN_WIDTH / 2 - agk::GetTextTotalWidth(TOTAL_SCORE_TEXT) / 2;
	float totalScoreTextY = SCREEN_HEIGHT - agk::GetTextTotalHeight(TOTAL_SCORE_TEXT) * 4;
	agk::SetTextPosition(TOTAL_SCORE_TEXT, totalScoreTextX, totalScoreTextY);

	// Set the perfect score text position.
	float perfectScoreTextX = SCREEN_WIDTH / 2 - agk::GetTextTotalWidth(PERFECT_SCORE_TEXT) / 2;
	float perfectScoreTextY = SCREEN_HEIGHT - agk::GetTextTotalHeight(TOTAL_SCORE_TEXT) * 2;
	agk::SetTextPosition(PERFECT_SCORE_TEXT, perfectScoreTextX, perfectScoreTextY);

	// Hide the text.
	agk::SetTextVisible(GAME_OVER_TEXT, HIDE);
	agk::SetTextVisible(GAME_RESULTS_TEXT, HIDE);
	agk::SetTextVisible(EGGS_CAUGHT_TEXT, HIDE);
	agk::SetTextVisible(EGGS_MISSED_TEXT, HIDE);
	agk::SetTextVisible(CAUGHT_MULTIPLIER_TEXT, HIDE);
	agk::SetTextVisible(MISSED_MULTIPLIER_TEXT, HIDE);
	agk::SetTextVisible(TOTAL_SCORE_TEXT, HIDE);
	agk::SetTextVisible(PERFECT_SCORE_TEXT, HIDE);
}

// Main loop, called every frame
void app::Loop ( void )
{
	// This switch statement determines the game state.
	switch(g_gameState)
	{
		// The game has just started.
		case GAME_STARTED:

			// Display the title screen.
			displayTitleScreen();

			// If the user presses the enter key,
			// hide the title screen and change
			// the game state to intro started.
			if (agk::GetRawKeyPressed(AGK_KEY_ENTER))
				hideTitleScreen();
			break;

		// The intro has just started.
		case INTRO_STARTED:

			// Display the intructions to the user.
			displayIntroScreen();

			// When the time has expired, hide
			// the instructions and change the
			// game state to in play.
			if (agk::Timer() >= INTRO_TIMER)
				hideIntroScreen();
			break;

		// The game is in play.
		case GAME_IN_PLAY:

			// Play the game.
			playGame();

			// When the number of eggs in play
			// reaches zero, hide the game and
			// change the game state to game over.
			if (g_eggs <= 0)
				hideGame();
			break;

		// The game is over.
		case GAME_OVER:

			// Display the game over screen.
			displayGameOverScreen();

			// When the time has expired, hide
			// the game over screen and change the
			// game state to summary started.
			if (agk::Timer() >= GAME_OVER_TIMER)
				hideGameOverScreen();
			break;

		// The summary has started.
		case SUMMARY_STARTED:

			// Display the summary screen.
			displaySummaryScreen();

			// When the time has expired, hide
			// the summary screen and change the
			// game state to game started.
			if (agk::Timer() >= SUMMARY_TIMER)
				hideSummaryScreen();
			break;
	}

	// Refresh the screen.
	agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}

// The displayTitleScreen function plays the
// intro music and displays the title screen.
void displayTitleScreen()
{
	// If the title screen is not visible, display it.
	if (!agk::GetSpriteVisible(TITLE_SCREEN_SPRITE))
		agk::SetSpriteVisible(TITLE_SCREEN_SPRITE, SHOW);

	// If the intro music is not playing, play it.
	if (!agk::GetMusicPlaying())
		agk::PlayMusic(INTRO_MUSIC, LOOP, INTRO_MUSIC, INTRO_MUSIC);
}

// The hideTitleScreen function hides the title screen
// and changes the game state to intro started.
void hideTitleScreen()
{
	// Hide the title screen.
	agk::SetSpriteVisible(TITLE_SCREEN_SPRITE, HIDE);

	// Reset the game timer.
	agk::ResetTimer();

	// Change the game state.
	g_gameState = INTRO_STARTED;
}

// The displayIntroScreen function displays an
// intro screen with instructions for how to
// play the game.
void displayIntroScreen()
{	
	// If the intro screen is not visible, display it.
	if (!agk::GetSpriteVisible(INTRO_SCREEN_SPRITE))
		agk::SetSpriteVisible(INTRO_SCREEN_SPRITE, SHOW);

	// If the main music is not playing, play it.
	if (agk::GetMusicPlaying() != MAIN_MUSIC)
		agk::PlayMusic(MAIN_MUSIC, LOOP, MAIN_MUSIC, MAIN_MUSIC);
}

// The hideIntroScreen function hides the intro screen
// shows the game sprites, and changes the agme state 
// to game in play.
void hideIntroScreen()
{
	// Hide the intro screen.
	agk::SetSpriteVisible(INTRO_SCREEN_IMAGE, HIDE);

	// Show the farm, basket, egg, and vulture sprites.
	agk::SetSpriteVisible(FARM_SPRITE, SHOW);
	agk::SetSpriteVisible(BASKET_SPRITE, SHOW);
	agk::SetSpriteVisible(VULTURE_SPRITE, SHOW);
	agk::SetSpriteVisible(EGG_SPRITE, SHOW);

	// Show the row of mini egg sprites.
	for(int count = 0; count < MAX_EGGS; count++)
	{
		int clone = EGG_CLONE + count;
		agk::SetSpriteVisible(clone, YES);
	}

	// Change the game state.
	g_gameState = GAME_IN_PLAY;
}

// The playGame function processes a frame of game play.
void playGame()
{
	// Move the basket.
	moveBasket();

	// Move the vulture.
	moveVulture();

	// Move the egg.
	moveEgg();

	// Check for collisions.
	checkCollisions();
}

// The hideGame function stops the game's main music
// and hides the sprite's. It changes the game state
// to game over.
void hideGame()
{
	// Stop the music.
	agk::StopMusic();

	// Hide the farm, basket, egg, and vulture sprites.
	agk::SetSpriteVisible(FARM_SPRITE, HIDE);
	agk::SetSpriteVisible(BASKET_SPRITE, HIDE);
	agk::SetSpriteVisible(VULTURE_SPRITE, HIDE);
	agk::SetSpriteVisible(EGG_SPRITE, HIDE);

	// Reset the game timer.
	agk::ResetTimer();

	// Change the game State.
	g_gameState = GAME_OVER;
}

// The moveBasket function moves the basket sprite back 
// and forth along the X axis according to user input.
void moveBasket()
{
	// Get the X coordinate of the basket sprite.
	float x = agk::GetSpriteX(BASKET_SPRITE);

	// Get the width of the basket sprite.
	float width = agk::GetSpriteWidth(BASKET_SPRITE);

	// Store the minimum value that the X coordinate of 
	// the basket sprite can reach without going beyond
	// the left edge of the screen.
	float minimumX = MIN_X;

	// Store the maximum value that the X coordinate of 
	// the basket sprite can reach without going beyond 
	// the right edge of the screen.
	float maximumX = MAX_X - width;

	// Determine if the keyboard's left arrow key is being held down.
	if (agk::GetRawKeyState(AGK_KEY_LEFT))
	{
		// If the X coordinate of the basket sprite 
		// has reached the left edge of the screen, 
		// it can go no further.
		if (x <= minimumX)
			x = minimumX;

		// Otherwise, move to the left.
		else
			x -= BASKET_MOVE;
	}

	// Determine if the keyboard's right arrow key is being held down.
	if (agk::GetRawKeyState(AGK_KEY_RIGHT))
	{
		// If the X coordinate of the basket sprite 
		// has reached the right edge of the screen, 
		// it can go no further.
		if (x >= maximumX)
			x = maximumX;

		// Otherwise, move to the right.
		else
			x += BASKET_MOVE;
	}

	// Update the basket sprite's X coordinate.
	agk::SetSpriteX(BASKET_SPRITE, x);
}

// The moveVulture function moves the vulture sprite back 
// and forth along the X axis based on location and angle.
void moveVulture()
{
	// If the vulture animation is not playing, play it.
	if (!agk::GetSpritePlaying(VULTURE_SPRITE))
		agk::PlaySprite(VULTURE_SPRITE, FRAMES_PER_SECOND);

	// Get the X coordinate of the vulture sprite.
	float x = agk::GetSpriteX(VULTURE_SPRITE);

	// Get the width of the vulture sprite.
	float width = agk::GetSpriteWidth(VULTURE_SPRITE);

	// Store the minimum value that the X coordinate of 
	// the vulture sprite can reach without going beyond
	// the left edge of the screen.
	float minimumX = MIN_X;

	// Store the maximum value that the X coordinate of 
	// the vulture sprite can reach without going beyond 
	// the right edge of the screen.
	float maximumX = MAX_X - width;

	// If the X coordinate of the vulture sprite 
	// has reached the left edge of the screen, 
	// it can go no further.
	if (x <= minimumX)
	{
		// Flip the sprite vertically and set it's angle to 180 degrees.
		// This will make the sprite turn and face right.
		agk::SetSpriteFlip(VULTURE_SPRITE, NO, YES);
		agk::SetSpriteAngle(VULTURE_SPRITE, 180.0f);
	}

	// If the X coordinate of the vulture sprite 
	// has reached the right edge of the screen, 
	// it can go no further.
	if (x >= maximumX)
	{
		// Do not flip the sprite, just set the angle to 0 degrees.
		// This will make the sprite turn and face left.
		agk::SetSpriteFlip(VULTURE_SPRITE, NO, NO);
		agk::SetSpriteAngle(VULTURE_SPRITE, 0.0f);
	}

	// If the vulture sprite is facing right, move right.
	if (agk::GetSpriteAngle(VULTURE_SPRITE) == 180.0f)
		x += VULTURE_MOVE;

	// Otherwise, the vulture sprite is facing left, so move left.
	else
		x -= VULTURE_MOVE;

	// Update the vulture sprite's X coordinate.
	agk::SetSpriteX(VULTURE_SPRITE, x);
}

// The moveEgg function moves the egg sprite both
// down the scren and across the screen.
void moveEgg()
{
	// Get the egg sprite's XY cooridinates.
	float eggX = agk::GetSpriteX(VULTURE_SPRITE);
	float eggY = agk::GetSpriteY(EGG_SPRITE);

	// Create a variable to hold the falling distance.
	float distance;

	// Set the egg's X position so it is below
	// the vulture's beak. This will depend on 
	// the vulture's angle.
	if(agk::GetSpriteAngle(VULTURE_SPRITE) == 180.0f)
	{
		eggX = agk::GetSpriteX(VULTURE_SPRITE) + 
		       agk::GetSpriteWidth(VULTURE_SPRITE) - 
			   agk::GetSpriteWidth(EGG_SPRITE);
	}

	// Calculate the falling distance.
	distance = 0.5f * ACCELERATION * g_time * g_time;

	// Update the egg sprite's Y cooridinate.
	eggY += distance;

	// Update teh egg sprite's position.
	agk::SetSpritePosition(EGG_SPRITE, eggX, eggY);
	
	// Increment the falling time.
	g_time++;
}

// The checkCollisions function checks for a collision
// between the egg and the basket or the ground.
void checkCollisions()
{
	// Get the Y coordinate for the bottom of the egg sprite.
	float eggBottom =  agk::GetSpriteY(EGG_SPRITE) + 
		               agk::GetSpriteHeight(EGG_SPRITE);

	// Determine if the egg has hit the basket.
	if (agk::GetSpriteCollision(EGG_SPRITE, BASKET_SPRITE))
	{
		// Increment the number of eggs caught.
		g_eggsCaught++;

		// Decrement the number of eggs in play.
		g_eggs--;

		// Show the hit basket effect.
		showHitBasket();

		// Reset the egg.
		resetEgg();

		// Reset the falling time.
		g_time = 0;
	}

	// The egg has missed the basket and hit the ground.
	else if (eggBottom >= SCREEN_HEIGHT)
	{
		// Increment the number of eggs missed.
		g_eggsMissed++;

		// Decrement the number of eggs in play.
		g_eggs--;
		
		// Show the broken egg effect.
		showBrokenEgg();

		// Reset the egg.
		resetEgg();

		// Reset the falling time.
		g_time = 0;
	}
}

// The showHitBasket function displays the hit
// basket effect and plays the pop sound.
void showHitBasket()
{
	// Set the hit basket sprite to the same
	// position as the basket sprite.
	agk::SetSpritePosition(HIT_BASKET_SPRITE, 
		                   agk::GetSpriteX(BASKET_SPRITE), 
						   agk::GetSpriteY(BASKET_SPRITE));

	// Show the hit basket sprite.
	agk::SetSpriteVisible(HIT_BASKET_SPRITE, SHOW);

	// Play the pop sound.
	agk::PlaySound(POP_SOUND);

	// Refresh the screen now, so we can see the changes.
	agk::Sync();

	// Wait for 1/10 of a second.
	agk::Sleep(100);

	// Hide the hit basket sprite.
	agk::SetSpriteVisible(HIT_BASKET_SPRITE, HIDE);
}

// The showBrokenEgg function displays the broken
// egg effect and plays the clap sound.
void showBrokenEgg()
{
	// Set the broken egg sprite's position.
	agk::SetSpritePosition(BROKEN_EGG_SPRITE, 
		                   agk::GetSpriteX(EGG_SPRITE), 
						   agk::GetSpriteY(EGG_SPRITE) - 
						   agk::GetSpriteHeight(EGG_SPRITE) / 2);

	// Show the broken egg sprite.
	agk::SetSpriteVisible(BROKEN_EGG_SPRITE, SHOW);

	// Play the clap sound.
	agk::PlaySound(CLAP_SOUND);

	// Refresh the screen now, so we can see the changes.
	agk::Sync();

	// Wait for 1/10 of a second.
	agk::Sleep(100);

	// Hide the broken egg sprite.
	agk::SetSpriteVisible(BROKEN_EGG_SPRITE, HIDE);
}

// The resetEgg function resets the egg after it has
// either been caught in the basket, or hit the ground.
void resetEgg()
{
	// Hide the current mini egg sprite clone.
	agk::SetSpriteVisible(EGG_CLONE + g_eggs, HIDE);

	// Reset the egg sprite's position.
	agk::SetSpriteY(EGG_SPRITE, agk::GetSpriteY(VULTURE_SPRITE) + 
		            agk::GetSpriteHeight(EGG_SPRITE) * 1.5f);
}

// The displayGameOverScreen function displays the
// game over text and plays the complete sound.
void displayGameOverScreen()
{
	// Display the game over text.
	agk::SetTextVisible(GAME_OVER_TEXT, SHOW);

	// If the complete sound is not playing, play it.
	if (!agk::GetSoundsPlaying(COMPLETE_SOUND))
		agk::PlaySound(COMPLETE_SOUND);
}

// The hideGameOverScreen function prepares the
// game for the summary screen.
void hideGameOverScreen()
{
	// Hide the game over text.
	agk::SetTextVisible(GAME_OVER_TEXT, HIDE);

	// Stop the complete sound.
	agk::StopSound(COMPLETE_SOUND);

	// Reset the timer.
	agk::ResetTimer();

	// Change the game state.
	g_gameState = SUMMARY_STARTED;
}

// The displaySummaryScreen function displays a
// summary of the player's performance, including
// points earned.
// Each egg caught earns 1000 points.
void displaySummaryScreen()
{
	// Determine if the summary is complete.
	if (g_summaryComplete == NO)
	{
		// Update the eggs caught text.
		agk::SetTextString(EGGS_CAUGHT_TEXT, agk::Str(g_eggsCaught));
		agk::SetTextX(EGGS_CAUGHT_TEXT, agk::GetTextX(CAUGHT_MULTIPLIER_TEXT) + 
			          agk::GetTextTotalWidth(CAUGHT_MULTIPLIER_TEXT) / 2 +
			          agk::GetTextTotalWidth(EGGS_CAUGHT_TEXT) / 2);

		// Set the egg sprite position inline with the text.
		agk::SetSpritePosition(EGG_SPRITE, agk::GetTextX(CAUGHT_MULTIPLIER_TEXT) - 
			                   agk::GetSpriteWidth(EGG_SPRITE) / 2, 
							   agk::GetTextY(EGGS_CAUGHT_TEXT));

		// Update the eggs missed text.
		agk::SetTextString(EGGS_MISSED_TEXT, agk::Str(g_eggsMissed));
		agk::SetTextX(EGGS_MISSED_TEXT, agk::GetTextX(MISSED_MULTIPLIER_TEXT) + 
					  agk::GetTextTotalWidth(MISSED_MULTIPLIER_TEXT) / 2 +
			          agk::GetTextTotalWidth(EGGS_MISSED_TEXT) / 2);

		// Set the broken egg sprite position inline with the text.
		agk::SetSpritePosition(BROKEN_EGG_SPRITE, agk::GetTextX(MISSED_MULTIPLIER_TEXT) - 
			                   agk::GetSpriteWidth(BROKEN_EGG_SPRITE), 
							   agk::GetTextY(EGGS_MISSED_TEXT));

		// Show the  sprites.
		agk::SetSpriteVisible(EGG_SPRITE, SHOW);
		agk::SetSpriteVisible(BROKEN_EGG_SPRITE, SHOW);

		// Show the text.
		agk::SetTextVisible(GAME_RESULTS_TEXT, SHOW);
		agk::SetTextVisible(EGGS_CAUGHT_TEXT, SHOW);
		agk::SetTextVisible(EGGS_MISSED_TEXT, SHOW);
		agk::SetTextVisible(CAUGHT_MULTIPLIER_TEXT, SHOW);
		agk::SetTextVisible(MISSED_MULTIPLIER_TEXT, SHOW);
		agk::SetTextVisible(TOTAL_SCORE_TEXT, SHOW);

		// Tally up the total score.
		for(int i = 0; i <= g_eggsCaught; i++)
		{
			// Update the total score text and position.
			agk::SetTextString(TOTAL_SCORE_TEXT, agk::Str(i * SCORE_MULTIPLIER));
			agk::SetTextX(TOTAL_SCORE_TEXT, SCREEN_WIDTH / 2 - 
				          agk::GetTextTotalWidth(TOTAL_SCORE_TEXT) / 2);

			// Play the type sound.
			agk::PlaySound(TYPE_SOUND);

			// Wait for 1/10 of a second.
			agk::Sleep(100);

			// Refresh the screen now, so we can see the changes.
			agk::Sync();
		}

		// If no eggs were broken, display a special message.
		if (g_eggsCaught == MAX_EGGS)
		{
			// Display perfect score text.
			agk::SetTextVisible(PERFECT_SCORE_TEXT, SHOW);
			
			// Play the perfect score sound.
			agk::PlaySound(PERFECT_SCORE_SOUND);

			// Wait for 1/10 of a second.
			agk::Sleep(100);

			// Refresh the screen now, so we can see the changes.
			agk::Sync();
		}

		// After we tally the score and exit the loop, 
		// the summary is complete.
		g_summaryComplete = YES;

		// Reset the timer.
		agk::ResetTimer();
	}
}

// The hideSummaryScreen hides the summary screen
// and changes the game state to when the game
// started.
void hideSummaryScreen()
{
	// Hide the text.
	agk::SetTextVisible(GAME_OVER_TEXT, HIDE);
	agk::SetTextVisible(GAME_RESULTS_TEXT, HIDE);
	agk::SetTextVisible(EGGS_CAUGHT_TEXT, HIDE);
	agk::SetTextVisible(EGGS_MISSED_TEXT, HIDE);
	agk::SetTextVisible(CAUGHT_MULTIPLIER_TEXT, HIDE);
	agk::SetTextVisible(MISSED_MULTIPLIER_TEXT, HIDE);
	agk::SetTextVisible(TOTAL_SCORE_TEXT, HIDE);
	agk::SetTextVisible(PERFECT_SCORE_TEXT, HIDE);

	// Hide the sprites.
	agk::SetSpriteVisible(EGG_SPRITE, HIDE);
	agk::SetSpriteVisible(BROKEN_EGG_SPRITE, HIDE);

	// Set the starting position of the vulture sprite.
	float vultureX = SCREEN_WIDTH / 2 - agk::GetSpriteWidth(VULTURE_SPRITE) / 2;
	float vultureY = 0;
	agk::SetSpritePosition(VULTURE_SPRITE, vultureX, vultureY);

	// Set the starting position of the basket sprite.
	float basketX = SCREEN_WIDTH / 2 - agk::GetSpriteWidth(BASKET_SPRITE) / 2;
	float basketY = SCREEN_HEIGHT - agk::GetSpriteHeight(BASKET_SPRITE);
	agk::SetSpritePosition(BASKET_SPRITE, basketX, basketY);

	// Set the starting position of the egg sprite.
	float eggX = vultureX;
	float eggY = vultureY + agk::GetSpriteHeight(EGG_SPRITE) * 1.5f;
	agk::SetSpritePosition(EGG_SPRITE, eggX, eggY);
	
	// Reset the timer.
	agk::ResetTimer();

	// Reset the global variables.
	g_summaryComplete = NO;
	g_eggs = MAX_EGGS;
	g_eggsMissed = 0;
	g_eggsCaught = 0;

	// Reset the game state.
	g_gameState = GAME_STARTED;
}
