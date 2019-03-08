//Library includes
#include <SFML/Graphics.hpp>

//Project includes
#include "Framework/AssetManager.h"
#include "Level.h"
#include "Player.h"
#include "Asteroid.h"
#include "Framework/SpriteObject.h"

int main()
{
	// -----------------------------------------------
	// Game Setup
	// -----------------------------------------------

	//Window set up
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode(1280, 720), "Space Displacer", sf::Style::Titlebar | sf::Style::Close);

	// Seed our random number generator 
	srand(time(NULL));

	// Create AssetManager
	AssetManager assets;

	// Game Clock - to keep track of time passed each frame
	sf::Clock gameClock;

	// Create the game level
	//Level ourLevel;

	// Create test objects
	Player myPlayer;
	myPlayer.SetPosition(250.0f, 250.0f);
	Asteroid myAsteroid;
	myAsteroid.SetPosition(rand() % 1000+100, 40);
	// -----------------------------------------------
	// Game Loop
	// -----------------------------------------------
	while (gameWindow.isOpen())
	{
		// -----------------------------------------------
		// Input Section
		// -----------------------------------------------
		// Check all events since the last frame and process 
		// each one until there are no more
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			
			//Did the player close the window?
			if (gameEvent.type == sf::Event::Closed)
			{
				//if so, call the close function
				gameWindow.close();
			}
				
		}// end of event polling loop

		// -----------------------------------------------
		// Update Section
		// -----------------------------------------------

		// Get the time passed since the last frame and restart our game clock
		sf::Time frameTime = gameClock.restart();


		// TODO: Update all game objects
		if (myPlayer.IsActive())
			myPlayer.Update(frameTime);

		// -----------------------------------------------
		// Draw Section
		// -----------------------------------------------

		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// TODO: Draw game object
		if (myPlayer.IsActive())
			myPlayer.Draw(gameWindow);
		if (myAsteroid.IsActive())
			myAsteroid.Draw(gameWindow);

		// Display the window contents on the screen
		gameWindow.display();
	}//end game loop

	return 0;
}
