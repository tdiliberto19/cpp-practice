 // Includes, namespace and prototypes
 #include "template.h"
 #include <string>      // Needed for the string class
 using namespace std;   // Needed for the string class
 using namespace AGK;
 app App;
 
 class Sprite
 {
 private:
    int spriteIndex;  // The sprite index
    string imageFile;   // The name of the image file
 public:
    // Constructors
    Sprite();
    Sprite(int, string);
 
    // Mutators
    void createSprite();
    void createSprite(int, string);
    void setPosition(float, float);
    void setX(float);
    void setY(float);
 
    // Accessors
    int getSpriteIndex() const;
    string getImageFile() const;
    float getX() const;
    float getY() const;
 
    // Destructor
    ~Sprite();
 };
 
 // This is the default constructor for the Sprite
 // class. It sets index to 1 and imageFile to
 // an empty string.
 Sprite::Sprite()
 {
    spriteIndex = 1;
    imageFile = "";
 }
 
 // This Sprite class constructor accepts as arguments
 // the sprite index and the name of the image file,
 // and initializes the member variables.
 Sprite::Sprite(int index, string filename)
 {
    spriteIndex = index;
    imageFile = filename;
 }
 
 // The Sprite::createSprite member function 
 void Sprite::createSprite()
 {
    // If the sprite does not already exist,
    // then create it.
    if (!agk::GetSpriteExists(spriteIndex))
    {
       agk::CreateSprite(spriteIndex, imageFile.c_str());
    }
 }
 
 // The Sprite::createSprite member function 
 void Sprite::createSprite(int index, string filename)
 {
    // Set the member variables.
    spriteIndex = index;
    imageFile = filename;
 
    // If the sprite does not already exist,
    // then create it.
    if (!agk::GetSpriteExists(spriteIndex))
    {
       agk::CreateSprite(spriteIndex, imageFile.c_str());
    }
 }
 
 // The Sprite::setPosition member function sets the
 // sprite's position.
 void Sprite::setPosition(float x, float y)
 {
    agk::SetSpritePosition(spriteIndex, x, y);
 }
 
 // The Sprite::setX member function sets the
 // sprite's X coordinate.
 void Sprite::setX(float x)
 {
    agk::SetSpriteX(spriteIndex, x);
 }
 
 // The Sprite::setY member function sets the
 // sprite's Y coordinate.
 void Sprite::setY(float y)
 {
    agk::SetSpriteY(spriteIndex, y);
 }
 
 // The Sprite::getSpriteIndex member function
 // returns the sprite's index.
 int Sprite::getSpriteIndex() const
 {
    return spriteIndex;
 }
 
 // The Sprite::getImageFile member function
 // returns the name of the image file used to 
 // create this sprite.
 string Sprite::getImageFile() const
 {
    return imageFile;
 }
 
 // The Sprite::getX member function returns the
 // sprite's X coordinate.
 float Sprite::getX() const
 {
    return agk::GetSpriteX(spriteIndex);
 }
 
 // The Sprite::getY member function returns the
 // sprite's Y coordinate.
 float Sprite::getY() const
 {
    return agk::GetSpriteY(spriteIndex);
 }
 
 // The Sprite class destructor deletes the
 // sprite from memory.
 Sprite::~Sprite()
 {
    agk::DeleteSprite(spriteIndex);
 }
 
 // Constants for the screen resolution
 const int SCREEN_WIDTH = 640;
 const int SCREEN_HEIGHT = 480;
 
 // Constants for the sprite indices
 const int SPACESHIP1_INDEX = 1;
 const int SPACESHIP2_INDEX = 2;
 const int SPACESHIP3_INDEX = 3;
 
 // Constants for the sprite positions
 const float SPACESHIP1_X = 0;
 const float SPACESHIP1_Y = 0;
 
 const float SPACESHIP2_X = 215;
 const float SPACESHIP2_Y = 212;
 
 const float SPACESHIP3_X = 430;
 const float SPACESHIP3_Y = 424;
 
 // Declare three Sprite objects.
 Sprite spaceship1;
 Sprite spaceship2;
 Sprite spaceship3;
 
 // Begin app, called once at the start
 void app::Begin( void )
 {
    // Set the virtual resolution.
    agk::SetVirtualResolution(SCREEN_WIDTH, SCREEN_HEIGHT);
 
    // Create the sprites on the screen.
    spaceship1.createSprite(SPACESHIP1_INDEX, "Space/spaceship.png");
    spaceship2.createSprite(SPACESHIP2_INDEX, "Space/spaceship.png");
    spaceship3.createSprite(SPACESHIP3_INDEX, "Space/spaceship.png");
 
    // Position the sprite.
    spaceship1.setPosition(SPACESHIP1_X, SPACESHIP1_Y);
    spaceship2.setPosition(SPACESHIP2_X, SPACESHIP2_Y);
    spaceship3.setPosition(SPACESHIP3_X, SPACESHIP3_Y);
 }
 
 // Main loop, called every frame
 void app::Loop ( void )
 {
    // Display the screen.
    agk::Sync();
 }
 
 // Called when the app ends
 void app::End ( void )
 {
 }
