// Includes, namespace and prototypes
#include "template.h"
#include <string>      // Needed for string class
using namespace std;   // Needed for string class
using namespace AGK;
app App;

// Function prototypes
void createCardSprites();
void shuffle();
void swap(int &, int &);

// Constants for the screen resolution
const int SCREEN_WIDTH  = 640;  // Screen width
const int SCREEN_HEIGHT = 480;  // Screen height

// Constants for the virtual button
const int   BUTTON_INDEX = 1;
const int   BUTTON_SIZE  = 100;
const float BUTTON_X     = 580;
const float BUTTON_Y     = 420;

// Constants for card sprite numbers
const int HEARTS_ACE = 1;
const int HEARTS_2   = 2;
const int HEARTS_3   = 3;
const int HEARTS_4   = 4;
const int HEARTS_5   = 5;
const int HEARTS_6   = 6;
const int HEARTS_7   = 7;
const int HEARTS_8   = 8;
const int HEARTS_9   = 9;
const int BACKFACE   = 10;

// Constants for card screen placement
const float STARTING_X    = 25;
const float CARD_Y        = 100;
const float CARD_DISTANCE = 10;
const float BACKFACE_X    = 25;
const float BACKFACE_Y    = 200;

// Constant for the number of cards
const int NUM_CARDS = 9;

// Array holding the card sprite numbers.
int g_cardSprites[NUM_CARDS] = { HEARTS_ACE, HEARTS_2,
   HEARTS_3, HEARTS_4, HEARTS_5, HEARTS_6, HEARTS_7,
   HEARTS_8, HEARTS_9 };

// Array holding the names of the card image files
string g_imageFiles[NUM_CARDS] = { "Cards/Ace_hearts.png", 
              "Cards/2_hearts.png", "Cards/3_hearts.png", 
              "Cards/4_hearts.png", "Cards/5_hearts.png", 
              "Cards/6_hearts.png", "Cards/7_hearts.png",
              "Cards/8_hearts.png", "Cards/9_hearts.png" };

// Variable to hold the number of cards dealt
int g_cardsDealt = 0;

// Variable to hold each card's X coordinate
float g_cardX = STARTING_X;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Card Dealer");

   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Add the vitual button.
   agk::AddVirtualButton(BUTTON_INDEX, BUTTON_X, BUTTON_Y, BUTTON_SIZE);
   agk::SetVirtualButtonText(BUTTON_INDEX, "Deal");

   // Create the backface card sprite.
   agk::CreateSprite(BACKFACE, "Cards/Backface_Red.png");

   // Position the backface card sprite.
   agk::SetSpritePosition(BACKFACE, BACKFACE_X, BACKFACE_Y);

   // Create the card sprites.
   createCardSprites();

   // Shuffle the card sprites.
   shuffle();
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Are cards left to be dealt?
   if (g_cardsDealt < NUM_CARDS)
   {
      // Check for a button press.
      if (agk::GetVirtualButtonPressed(BUTTON_INDEX))
      {
         // Position the card sprite that is being dealt.
         agk::SetSpritePosition(g_cardSprites[g_cardsDealt], 
                               g_cardX, CARD_Y);

         // Make the card sprite visible.
         agk::SetSpriteVisible(g_cardSprites[g_cardsDealt], 1);

         // Calculate the next card's X coordinate.
         g_cardX += agk::GetSpriteWidth(g_cardSprites[g_cardsDealt]) + 
                   CARD_DISTANCE;

         // Increment the number of cards dealt.
         g_cardsDealt++;
      }
   }
   else
   {
      // All cards are dealt. Print a message and hide
      // the backface card.
      agk::Print("All cards are dealt.");
      agk::SetSpriteVisible(BACKFACE, 0);
   }

    // Refresh the screen.
    agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}

// The createCardSprites function creates the card sprites
// and makes them invisible.
void createCardSprites()
{
   for (int count = 0; count < NUM_CARDS; count++)
   {
      // Create the next card sprite.
      agk::CreateSprite(g_cardSprites[count], 
                        g_imageFiles[count].c_str());

      // Make the sprite invisible.
      agk::SetSpriteVisible(g_cardSprites[count], 0);
   }
}

// The shuffle function shuffles the elements of the
// g_cardSprites array randomly.
void shuffle()
{
   // Variable to hold a random subscript
   int randomSub;

   // Step through the array, swapping each element with
   // a random subscript.
   for (int index = 0; index < NUM_CARDS; index++)
   {
      // Get a random subscript.
      randomSub = agk::Random(0, NUM_CARDS - 1);

      // Swap two elements.
      swap(g_cardSprites[index], g_cardSprites[randomSub]);
   }
}

// The swap function accepts two int arguments, passed
// by reference. the function swaps the contents of the
// two arguments.
void swap(int &a, int &b)
{
   // Assign a to temp.
   int temp = a;

   // Assign b to a.
   a = b;

   // Assign temp to b.
   b = temp;
}
