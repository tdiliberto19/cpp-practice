// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Function prototypes
void loadTiles();
void displayTiles();
void addObstacle(int);
void updateAlecX(float);
void updateAlecY(float);
void checkForCollision();

// Constants for the screen resolution
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

// Constants for the image numbers
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

// Constants for the Alec sprite sheet
const int ALEC_IMAGE        = 12;  // Texture atlas image index
const int ALEC_SPRITE       = 100; // Alec's sprite index
const int ALEC_FRAME_WIDTH  = 40;  // Alec's frame width
const int ALEC_FRAME_HEIGHT = 75;  // Alec's frame height
const int ALEC_FRAME_COUNT  = 16;  // Alec's frame count
const int EAST_START        = 1;   // First frame for going east
const int EAST_END          = 4;   // Last frame for going east
const int NORTH_START       = 5;   // First frame for going north
const int NORTH_END         = 8;   // Last frame for going north
const int SOUTH_START       = 9;   // First frame for going south
const int SOUTH_END         = 12;  // Last frame for going south
const int WEST_START        = 13;  // First frame for going west
const int WEST_END          = 16;  // Last frame for going west
const int ALEC_FPS          = 5;   // Alec's frames per second
const int ANIMATION_LOOP    = 1;   // To make Alec loop
const float ALEC_STARTING_X = 0;   // Alec's starting X coordinate
const float ALEC_STARTING_Y = 150; // Alec's starting Y coordinate

// Constants for Alec's direction
const int NORTH   = 1;
const int SOUTH = 2;
const int EAST  = 3;
const int WEST  = 4;

// Constant for the maximum number of obstacles
const int MAX_OBSTACLES = 7;

// Constant for the collision sound index
const int COLLISION_SOUND = 1;

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

// Obstacle array
int g_obstacles[MAX_OBSTACLES];

// Variable for Alec's direction
int g_alecDirection = EAST;

// Begin app, called once at the start
void app::Begin( void )
{
    // Set the window title.
    agk::SetWindowTitle("Obstacles");

    // Set the virtual resolution.
    agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);

   // Load the collision sound.
   agk::LoadSound(COLLISION_SOUND, "Alec/boink.wav");

    // Load the texture atlas.
   agk::LoadImage(ALEC_IMAGE, "Alec/Alec.png");

   // Create the sprite using the texture atlas as the image.
   agk::CreateSprite(ALEC_SPRITE, ALEC_IMAGE);

   // Make sure Alec is displayed on top of the tile sprites.
   agk::SetSpriteDepth(ALEC_SPRITE, 0);

   // Set Alec's starting position.
   agk::SetSpritePosition(ALEC_SPRITE, ALEC_STARTING_X, 
                         ALEC_STARTING_Y);

   // Set the sprite animation.
   agk::SetSpriteAnimation(ALEC_SPRITE, ALEC_FRAME_WIDTH, 
                            ALEC_FRAME_HEIGHT, ALEC_FRAME_COUNT);

   // Load the tile images.
   loadTiles();

   // Create the tile sprites and display them.
   displayTiles();
}

// Main loop, called every frame
void app::Loop ( void )
{
   // Get the state of the direction keys.
   float directionX = agk::GetDirectionX();
   float directionY = agk::GetDirectionY();

   // If the right or left arrow keys are pressed,
   // update Alec's position.
   if (directionX != 0)
   {
      // Update Alec's X coordinate.
      updateAlecX(directionX);

      // Check for any collisions.
      checkForCollision();
   }

   // If the up or down arrow keys are pressed,
   // update Alec's position.
   if (directionY != 0)
   {
      // Update Alec's Y coordinate
      updateAlecY(directionY);

      // Check for any collisions.
      checkForCollision();
   }

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

   // Variable to be an obstacle counter
   int obstacleCounter = 0;
   
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

         // If this is an obstacle, add it to the
         // obstacle array.
         if (g_tileMap[r][c] > PATHSW)
         {
            // Add it to the array.
            g_obstacles[obstacleCounter] = spriteIndex;
            // Update the obstacle counter.
            obstacleCounter++;
         }

         // Set the tile's position.
         agk::SetSpritePosition(spriteIndex, x, y);

         // Update the X coordinate for the next tile.
         x += TILE_WIDTH;
      }
   
      // Increase y for the next row.
      y += TILE_HEIGHT;
    }
}

// The updateAlecX function turns Alec either east or west,
// depending on which arrow key is being pressed, and moves
// him to his new X coordinate.
void updateAlecX(float directionX)
{
   float alecX,   // Alec's current X position
         newX;    // Alec's new X coordinate

   // Get Alec's X coordinate
   alecX = agk::GetSpriteX(ALEC_SPRITE);

   // Which key was pressed? Right or left?
   if (directionX > 0)
   {
      // Turn Alec east
      agk::PlaySprite(ALEC_SPRITE, ALEC_FPS, 
                      ANIMATION_LOOP, 
                      EAST_START, EAST_END);

      // Save Alec's current direction.
      g_alecDirection = EAST;

      // Calculate Alec's new X coordinate.
      newX = alecX + 1;
   }
   else if (directionX < 0)
   {
      // Turn Alec west
      agk::PlaySprite(ALEC_SPRITE, ALEC_FPS, 
                      ANIMATION_LOOP, 
                      WEST_START, WEST_END);

      // Save Alec's current direction.
      g_alecDirection = WEST;

      // Calculate Alec's new X coordinate
      newX = alecX - 1;
   }

   // Move Alec
   agk::SetSpriteX(ALEC_SPRITE, newX);
}

// The updateAlecY function turns Alec either north or south,
// depending on which arrow key is being pressed, and moves
// him to his new Y coordinate.
void updateAlecY(float directionY)
{
   float alecY,   // Alec's current Y position
         newY;    // Alec's new Y coordinate

   // Get Alec's Y coordinate
   alecY = agk::GetSpriteY(ALEC_SPRITE);

   // Which key was pressed? Up or down?
   if (directionY < 0)
   {
      // Turn Alec north
      agk::PlaySprite(ALEC_SPRITE, ALEC_FPS, 
                      ANIMATION_LOOP, 
                      NORTH_START, NORTH_END);

      // Save Alec's current direction.
      g_alecDirection = NORTH;

      // Calculate Alec's new Y coordinate.
      newY = alecY - 1;
   }
   else if (directionY > 0)
   {
      // Turn Alec south
      agk::PlaySprite(ALEC_SPRITE, ALEC_FPS, 
                      ANIMATION_LOOP,
                      SOUTH_START, SOUTH_END);

      // Save Alec's current direction.
      g_alecDirection = SOUTH;

      // Calculate Alec's new Y coordinate.
      newY = alecY + 1;
   }

   // Move Alec
   agk::SetSpriteY(ALEC_SPRITE, newY);
}
// The checkForCollision function determines whether Alec
// has collided with an obstacle. If Alec has collided 
// with an obstacle, it moves his position in the opposite
// direction one pixel.
void checkForCollision()
{
   // Get Alec's position.
   float x = agk::GetSpriteX(ALEC_SPRITE);
   float y = agk::GetSpriteY(ALEC_SPRITE);

   // Step through the obstacles array checking for
   // a collision.
   for (int index = 0; index < MAX_OBSTACLES; index++)
   {
      if (agk::GetSpriteCollision(ALEC_SPRITE, g_obstacles[index]))
      {
         // Play the collision sound.
         agk::PlaySound(COLLISION_SOUND);

         // Move Alec one pixel in the direction opposite
         // that which he is facing.
         switch (g_alecDirection)
         {
         case NORTH:
            y++;
            break;

         case SOUTH:
            y--;
            break;

         case EAST:
            x--;
            break;

         case WEST:
            x++;
            break;
         }

         // Move Alec.
         agk::SetSpritePosition(ALEC_SPRITE, x, y);
      }
   }
}
