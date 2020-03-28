// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Function prototypes
void generateNewBug();
void displayIntro();
void hideIntro();
void playGame();
void checkForHighScore();
void newHighScore();
void closingScreen();

// Constants for the screen resolution
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Constants for sprites
const int INTRO_INDEX = 1;
const int GRASS_INDEX = 2;
const int BUG_INDEX   = 3;

// Constant for the sound file
const int BOINK_SOUND = 1;

// Constants for animation
const int FRAME_WIDTH = 64;
const int FRAME_HEIGHT = 64;
const int FRAME_COUNT = 2;

// Constant for game time
const int MAX_TIME = 10;

// Constants for the possible game states.
const int GAME_JUST_STARTED    = 0;
const int GAME_IN_PLAY         = 1;
const int CHECK_FOR_HIGH_SCORE = 2;
const int GAME_OVER            = 3;

// Constant for the high score file number
const int HIGH_SCORE_FILE = 1;

// Global variables
int g_bugsZapped = 0;        // Counter for bugs zapped
int g_prevHighScore = 0;     // Previous high score
int g_gameState = GAME_JUST_STARTED;  // Game state

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Set the text in the window title bar.
   agk::SetWindowTitle("Bug Zapper");

   // Create the background sprite.
   agk::CreateSprite(GRASS_INDEX, "BugZapper/Grass.png");

   // Create the bug sprite.
   agk::CreateSprite(BUG_INDEX, "BugZapper/Bug.png");

   // Create the intro screen sprite.
   agk::CreateSprite(INTRO_INDEX, "BugZapper/Intro.png");

   // Load the sound file.
   agk::LoadSound(BOINK_SOUND, "BugZapper/Boink.wav");

   // Randomly position the bug.
   generateNewBug();

   // Set the sprite animation
   agk::SetSpriteAnimation(BUG_INDEX, FRAME_WIDTH,
                 FRAME_HEIGHT, FRAME_COUNT);

   // Play the bug animation.
   agk::PlaySprite(BUG_INDEX);
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Determine the game state and
   // act accordingly.
   switch (g_gameState)
   {
   case GAME_JUST_STARTED:
      // Display the intro screen.
      displayIntro();

      // Check for a key press.
      if (agk::GetRawLastKey())
      {
         // Hide the intro screen
         hideIntro();

         // Change the game state.
         g_gameState = GAME_IN_PLAY;

         // Reset the timer.
         agk::ResetTimer();
      }
      break;

   case GAME_IN_PLAY:
      // Engage in game play.
      playGame();
      break;

   case CHECK_FOR_HIGH_SCORE:
      // Get the high score so far.
      checkForHighScore();

   case GAME_OVER:
      // Display the closing screen.
      closingScreen();
      break;
   };

   // Update the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}

// The generateNewBug function generates a new bug at
// random location.
void generateNewBug()
{
    // Get the bug's width and height.
    int bugWidth = agk::GetSpriteWidth(BUG_INDEX);
    int bugHeight = agk::GetSpriteHeight(BUG_INDEX);

    // Generate a new location.
    int x = agk::Random(0, SCREEN_WIDTH - bugWidth);
    int y = agk::Random(0, SCREEN_HEIGHT - bugHeight);

    // Put the bug at that location.
    agk::SetSpritePosition(BUG_INDEX, x, y);
}

// The displayIntro function hides the grass and the
// bug sprite, and makes the intro screen visible.
void displayIntro()
{
   // Make the grass and bug invisible.
   agk::SetSpriteVisible(GRASS_INDEX, 0);
   agk::SetSpriteVisible(BUG_INDEX, 0);

   // Make the intro screen visible.
   agk::SetSpriteVisible(INTRO_INDEX, 1);
}

// The hideIntro function hides the intro screen
// and makes the grass and bug visible.
void hideIntro()
{
   agk::SetSpriteVisible(INTRO_INDEX, 0);
   agk::SetSpriteVisible(BUG_INDEX, 1);
   agk::SetSpriteVisible(GRASS_INDEX, 1);
}

// The playGame function processes a frame of game play.
void playGame()
{
   // Variables for mouse coordinates
   float mouseX, mouseY;

   // Do we still have time left?
   if (agk::Timer() < MAX_TIME)
   {
      // Determine if the left mouse button was pressed.
      if(agk::GetRawMouseLeftPressed())
      {
         // Get the mouse pointer location.
         mouseX = agk::GetRawMouseX();
         mouseY = agk::GetRawMouseY();

         // Check to see if the bug was hit.
         if (agk::GetSpriteHit(mouseX, mouseY) == BUG_INDEX)
         {
            // Play the boink sound.
            agk::PlaySound(BOINK_SOUND);

            // Update the count.
            g_bugsZapped++;

            // Generate a new bug.
            generateNewBug();
         }
      }
   }
   else
   {
      // Time is up, check for a high score.
      g_gameState = CHECK_FOR_HIGH_SCORE;
   }
}

// The closingScreen function displays the closing screen.
void closingScreen()
{
   // Hide the bug and the grass.
   agk::SetSpriteVisible(GRASS_INDEX, 0);
   agk::SetSpriteVisible(BUG_INDEX, 0);

   // Display the results.
   agk::PrintC("Number of bugs zapped: ");
   agk::Print(g_bugsZapped);

   if (g_bugsZapped > g_prevHighScore)
   {
      // Congratulate the user.
      agk::Print("Congratulations!");
      agk::Print("You set a new high score!");
   }
}

// The checkForHighScore function reads the high score from
// the BugZapperHighScore.dat file and determines whether
// the user's score is the new high score.
void checkForHighScore()
{
   // If the BugZapperHighScore.dat file exists, open it
   // and read its value. Otherwise, set highScore to 0.
   if (agk::GetFileExists("BugZapperHighScore.dat"))
   {
      // Open the file.
      agk::OpenToRead(HIGH_SCORE_FILE, 
                        "BugZapperHighScore.dat");

      // Read the high score.
      g_prevHighScore = agk::ReadInteger(HIGH_SCORE_FILE);

      // Close the file.
      agk::CloseFile(HIGH_SCORE_FILE);
   }
   else
   {
      g_prevHighScore = 0;
   }

   // If this is the new high score, write it to
   // the file.
   if (g_bugsZapped > g_prevHighScore)
   {
      newHighScore();
   }

   // Change the game state to end the game.
   g_gameState = GAME_OVER;
}

// The newHighScore function writes the current score to
// the BugZapperHighScore.dat 
void newHighScore()
{
   // Open the BugZapperHighScore.dat file for writing.
   // If the file already exists, this will replace it.
   agk::OpenToWrite(HIGH_SCORE_FILE, 
                        "BugZapperHighScore.dat");

   // Write the current score to the file.
   agk::WriteInteger(HIGH_SCORE_FILE, g_bugsZapped);

   // Close the file.
   agk::CloseFile(HIGH_SCORE_FILE);
}
