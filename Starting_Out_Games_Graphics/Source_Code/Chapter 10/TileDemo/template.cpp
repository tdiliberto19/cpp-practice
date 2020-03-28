// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Function prototypes
void loadTiles();
void displayTiles();

// Constants for the screen resolution
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

// Constants for the image indices
const int GRASS  = 1;
const int PATH   = 2;
const int PATHNE = 3;
const int PATHNW = 4;
const int PATHSE = 5;
const int PATHSW = 6;
const int TREENW = 7;
const int TREENE = 8;
const int TREESW = 9;
const int TREESE = 10;
const int ROCK   = 11;

// Constants for the tile image sizes
const int TILE_WIDTH  = 64;
const int TILE_HEIGHT = 48;

// Constants for the tile map size declarators
const int TILE_ROWS = 10;
const int TILE_COLS = 10;

// The tile map
int g_tileMap[TILE_ROWS][TILE_COLS] =
{ {GRASS, GRASS, GRASS, GRASS, GRASS,  GRASS,  GRASS,  GRASS,  GRASS, GRASS},
  {GRASS, GRASS, GRASS, ROCK,  GRASS,  GRASS,  GRASS,  GRASS,  GRASS, GRASS},
  {GRASS, GRASS, GRASS, GRASS, GRASS,  GRASS,  GRASS,  PATHNW, PATH,  PATH },
  {GRASS, GRASS, GRASS, GRASS, GRASS,  TREENW, TREENE, PATH,   GRASS, GRASS},
  {PATH,  PATH,  PATH,  PATH,  PATHNE, TREESW, TREESE, PATH,   ROCK,  GRASS},
  {GRASS, GRASS, GRASS, GRASS, PATH,   GRASS,  GRASS,  PATH,   GRASS, GRASS},
  {GRASS, GRASS, GRASS, GRASS, PATHSW, PATH,   PATH,   PATHSE, GRASS, GRASS},
  {GRASS, GRASS, GRASS, GRASS, GRASS,  GRASS,  GRASS,  GRASS,  GRASS, GRASS},
  {GRASS, ROCK,  GRASS, GRASS, GRASS,  GRASS,  GRASS,  GRASS,  GRASS, GRASS},
  {GRASS, GRASS, GRASS, GRASS, GRASS,  GRASS,  GRASS,  GRASS,  GRASS, GRASS}
};

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Tile Demo");

   // Set the virtual resolution.
   agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Load the tile images.
   loadTiles();

   // Create the tile sprites and display them.
   displayTiles();
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

// The loadTiles function loads the images that will be
// used for tiles.
void loadTiles()
{
   agk::LoadImage(GRASS,  "Alec/Grass.png");
   agk::LoadImage(PATH,   "Alec/Path.png");
   agk::LoadImage(PATHNE, "Alec/PathNE.png");
   agk::LoadImage(PATHNW, "Alec/PathNW.png");
   agk::LoadImage(PATHSE, "Alec/PathSE.png");
   agk::LoadImage(PATHSW, "Alec/PathSW.png");
   agk::LoadImage(TREENE, "Alec/TreeNE.png");
   agk::LoadImage(TREENW, "Alec/TreeNW.png");
   agk::LoadImage(TREESE, "Alec/TreeSE.png");
   agk::LoadImage(TREESW, "Alec/TreeSW.png");
   agk::LoadImage(ROCK,   "Alec/Rock.png");
}

// The displayTiles function displays the tiles, as
// specified by the tile map.
void displayTiles()
{
   // Variables for the tile coordinates
   float x = 0, y = 0;

   // Variable to temporarily hold a sprite index
   int spriteIndex;
   
   // Display all the tiles specified in the map.
   for (int r = 0; r < TILE_ROWS; r++)
   {
      // Set x to 0.
      x = 0;

      // Display all the tiles in this row.
      for (int c = 0; c < TILE_COLS; c++)
      {
         // Create a sprite for this tile.
         spriteIndex = agk::CreateSprite(g_tileMap[r][c]);

         // Set the tile's position.
         agk::SetSpritePosition(spriteIndex, x, y);

         // Update the X coordinate for the next tile.
         x += TILE_WIDTH;
      }
   
      // Increase y for the next row.
      y += TILE_HEIGHT;
    }
}
