// Includes, namespace and prototypes
#include "template.h"
#include <string>      // Needed for string class
using namespace std;   // Needed for string class
using namespace AGK;
app App;

// Function prototypes
void createCardSprites();
void shuffle();
void selectionSort();
void swap(int &, int &);
void displayCards();

// Constants for the screen resolution
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

// Constants for the virtual buttons
const int   BUTTON_SIZE  = 100;

const int   SORT_BUTTON_INDEX = 1;
const float SORT_BUTTON_X     = 60;
const float SORT_BUTTON_Y     = 420;

const int   SHUFFLE_BUTTON_INDEX = 2;
const float SHUFFLE_BUTTON_X     = 580;
const float SHUFFLE_BUTTON_Y     = 420;

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

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Card Dealer");

   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Add the vvirtual sort button.
   agk::AddVirtualButton(SORT_BUTTON_INDEX, SORT_BUTTON_X,
                         SORT_BUTTON_Y, BUTTON_SIZE);
   agk::SetVirtualButtonText(SORT_BUTTON_INDEX, "Sort");

   // Add the vitual shuffle button.
   agk::AddVirtualButton(SHUFFLE_BUTTON_INDEX, SHUFFLE_BUTTON_X,
                         SHUFFLE_BUTTON_Y, BUTTON_SIZE);
   agk::SetVirtualButtonText(SHUFFLE_BUTTON_INDEX, "Shuff");

   // Create the card sprites.
   createCardSprites();
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Check for the shuffle button.
   if (agk::GetVirtualButtonPressed(SHUFFLE_BUTTON_INDEX))
   {
      // Shuffle the card sprites.
      shuffle();

      // Display the cards.
      displayCards();
   }

   // Check for the sort button.
   if (agk::GetVirtualButtonPressed(SORT_BUTTON_INDEX))
   {
      // Shuffle the card sprites.
      selectionSort();

      // Display the cards.
      displayCards();
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

// The selectionSort function sorts the g_cardSprites array
// in ascending order.
void selectionSort()
{
   int startScan; // Starting position of the scan
    int index;      // To hold a subscript value
    int minIndex;   // Element with smallest value in the scan
    int minValue;   // The smallest value found in the scan

    // The outer loop iterates once for each element in the
    // g_cardSprites array. The startScan variable marks the position
    // where the scan should begin.
    for (startScan = 0; startScan < (NUM_CARDS - 1); startScan++)
    {
      // Assume the first element in the scannable area
        // is the smallest value.
        minIndex = startScan;
        minValue = g_cardSprites[startScan];

        // Scan the array starting at the 2nd element in the
        // scannable area. We are looking for the smallest
        // value in the scannable area. 
        for(index = startScan + 1; index < NUM_CARDS; index++)
        {
            if (g_cardSprites[index] < minValue)
            {
               minValue = g_cardSprites[index];
               minIndex = index;
            }
        }

        // Swap the element with the smallest value 
        // with the first element in the scannable area.
        swap( g_cardSprites[minIndex], g_cardSprites[startScan] );
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

// The displayCards function displays the card sprites
// in the order that their sprite numbers appear in
// the g_cardSprites array.
void displayCards()
{
   // Variable to hold each card's X coordinate
   float cardX = STARTING_X;

   for (int index = 0; index < NUM_CARDS; index++)
   {
      // Position this card sprite.
      agk::SetSpritePosition(g_cardSprites[index], 
                             cardX, CARD_Y);
      
      // Make the card sprite visible.
      agk::SetSpriteVisible(g_cardSprites[index], 1);

      // Calculate the next card's X coordinate.
      cardX += agk::GetSpriteWidth(g_cardSprites[index]) + 
                                      CARD_DISTANCE;
   }
}
