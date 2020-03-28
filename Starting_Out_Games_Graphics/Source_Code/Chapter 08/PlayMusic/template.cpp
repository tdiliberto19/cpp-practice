// This program demonstrates playing music
// when a virtual button is clicked by the mouse.

// Includes, namespace and prototypes
#include "template.h"
using namespace AGK;
app App;

// Begin app, called once at the start
void app::Begin( void )
{
   // Set the window title.
   agk::SetWindowTitle("Music Player");

   // Set the virtual resolution.
   agk::SetVirtualResolution(640, 480);

   // Load the music files.
   agk::LoadMusic(1, "MusicA.mp3");
   agk::LoadMusic(2, "MusicB.mp3");
   agk::LoadMusic(3, "MusicC.mp3");

   // Add the virtual buttons.
   agk::AddVirtualButton(1, 220, 240, 100);
   agk::AddVirtualButton(2, 320, 240, 100);
   agk::AddVirtualButton(3, 420, 240, 100);

   // Set the text for the virtual buttons.
   agk::SetVirtualButtonText(1, "1");
   agk::SetVirtualButtonText(2, "2");
   agk::SetVirtualButtonText(3, "3");
}

// Main loop, called every frame
void app::Loop ( void )
{
   // If button 1 was pressed, play music 1.
   if(agk::GetVirtualButtonPressed(1))
   {
      agk::PlayMusic(1);
   }

   // If button 2 was pressed, play music 2.
   if(agk::GetVirtualButtonPressed(2))
   {
      agk::PlayMusic(2);
   }

   // If button 3 was pressed, play music 3.
   if(agk::GetVirtualButtonPressed(3))
   {
      agk::PlayMusic(3);
   }

   // Refresh the screen.
   agk::Sync();
}

// Called when the app ends
void app::End ( void )
{
}
