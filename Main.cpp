//Library includes
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>

//Project includes
#include "Framework/AssetManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Framework/SpriteObject.h"
#include "asteroidBelt.h"
#include "Enemy.h"
#include "Persuit.h"
#include "UIelements.h"
#include "EnemyFire.h"
#include "Torpedo.h"
#include "SpaceDisplacer.h"

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

	for (int i = 0; i < 40; ++i)
	{
		int random = std::rand() % 260 + 40;
		std::cout << -random << std::endl;
	}

	// Create test objects
	Player myPlayer;
	SpaceDisplacer mySpaceDisplacer;
	myPlayer.SetPosition(400.0f, 400.0f);
	AsteroidBelt asteroidBelt;
	asteroidBelt.SetSpaceDisplacer(&mySpaceDisplacer);
	Asteroid myAsteroid;
	Torpedo myTorpedo;
	UIelements UI_E;
	//EnemyFire enemyFire;
	Enemy myEnemy;
	Persuit thePersuit;
	thePersuit.SetPlayer(&myPlayer);
	myTorpedo.SetPlayer(&myPlayer);
	
	//EnemyFire enemyFire;
	//enemyFire.SetPersuit(&thePersuit);
	//enemyFire.SetTorpedo(&myTorpedo);
	
	
	
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
		if (mySpaceDisplacer.IsActive())
		mySpaceDisplacer.Update(frameTime);
		if (asteroidBelt.IsActive())
			asteroidBelt.Update(frameTime);
		if (thePersuit.IsActive())
			thePersuit.Update(frameTime);
		if (myTorpedo.IsActive())
			myTorpedo.Update(frameTime);


		// -----------------------------------------------
		// Draw Section
		// -----------------------------------------------

		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// TODO: Draw game object
		UI_E.Draw(gameWindow);
		mySpaceDisplacer.Draw(gameWindow);
		if (myPlayer.IsActive())
			myPlayer.Draw(gameWindow);
		if (asteroidBelt.IsActive())
			asteroidBelt.Draw(gameWindow);
		if (thePersuit.IsActive())
			thePersuit.Draw(gameWindow);
		if (myTorpedo.IsActive())
			myTorpedo.Draw(gameWindow);
		

		// Display the window contents on the screen
		gameWindow.display();
	}//end game loop

	return 0;
}
