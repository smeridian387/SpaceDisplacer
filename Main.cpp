//Library includes
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <chrono>

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
#include "Pickups.h"


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
	
	//start game time counter
	auto start_time = std::chrono::high_resolution_clock::now();
	int secondsPassed;

	//start game time counter millisecond
	auto start_timeMill = std::chrono::high_resolution_clock::now();
	float millisecondsPassed;

	//spalshscreen and gameover

	bool splashscreen = true;
	bool gameover = false;

	// Create test objects
	Player myPlayer;
	SpaceDisplacer mySpaceDisplacer;
	myPlayer.SetPosition(500.0f, 400.0f);
	AsteroidBelt asteroidBelt;
	asteroidBelt.SetSpaceDisplacer(&mySpaceDisplacer);
	asteroidBelt.SetPlayer(&myPlayer);
	Asteroid myAsteroid;
	PickUp myPickUp;
	Torpedo myTorpedo;
	UIelements UI_E;
	//EnemyFire enemyFire;
	Enemy myEnemy;
	Persuit thePersuit;
	thePersuit.SetPlayer(&myPlayer);
	thePersuit.SetSpaceDisplacer(&mySpaceDisplacer);
	thePersuit.SetTorpedo(&myTorpedo);
	thePersuit.SetAsteroid(&myAsteroid);
	myPickUp.SetPlayer(&myPlayer);
	myPickUp.SetSpaceDisplacer(&mySpaceDisplacer);
	UI_E.SetPlayer(&myPlayer);
	UI_E.SetSpaceDisplacer(&mySpaceDisplacer);


	//testing zone
	
	
	bool timer = true;
	
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
		//counts time passed since game starts

		//millisecond clock

		auto current_timeMill = std::chrono::high_resolution_clock::now();
		millisecondsPassed = std::chrono::duration_cast<std::chrono::milliseconds>(current_timeMill - start_time).count();
		auto current_time = std::chrono::high_resolution_clock::now();
		secondsPassed = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			splashscreen = false;
		}

		// Get the time passed since the last frame and restart our game clock
		sf::Time frameTime = gameClock.restart();

		if (splashscreen == false && gameover == false)
		{
			/*int milliSecondsSinceLastFrame;
			bool clockStartMilliSeconds = true;
			if (clockStartMilliSeconds == true)
			{
				milliSecondsSinceLastFrame = frameTime.asMilliseconds();
			}
			float millisecondsPassed;

			millisecondsPassed += milliSecondsSinceLastFrame;
			millisecondsPassed = millisecondsPassed / 100;

			int SecondsSinceLastFrame;
			bool clockStartSeconds = true;
			if (clockStartSeconds == true)
			{
				SecondsSinceLastFrame = frameTime.asSeconds();
			}
			int secondsPassed;

			secondsPassed += SecondsSinceLastFrame;*/
			int secondsPassed1;
			float millisecondsPassed1;
			if (timer = true)
			{
				secondsPassed1 = secondsPassed - secondsPassed;
				millisecondsPassed1 = (millisecondsPassed - millisecondsPassed) ;
				timer = false;
			}
			
			// TODO: Update all game objects
			if (myPlayer.IsActive())
				myPlayer.Update(frameTime);
			if (mySpaceDisplacer.IsActive())
				mySpaceDisplacer.Update(frameTime);
			if (asteroidBelt.IsActive())
			{
				asteroidBelt.Update(frameTime);
				asteroidBelt.SetGameTimer(secondsPassed1);
			}
			if (thePersuit.IsActive())
			{
				thePersuit.Update(frameTime);
				thePersuit.SetGameTimer(secondsPassed1);
			}
			myPickUp.Update(frameTime);
			myPickUp.SetGameTimer(secondsPassed1);
			UI_E.SetMillisecondsSinceGameStart(millisecondsPassed);
			UI_E.Update(frameTime);
		}

		// -----------------------------------------------
		// Draw Section
		// -----------------------------------------------

		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// TODO: Draw game object
		UI_E.Draw(gameWindow);
		if (thePersuit.IsActive())
			thePersuit.Draw(gameWindow);
		if (asteroidBelt.IsActive())
			asteroidBelt.Draw(gameWindow);
		myPickUp.Draw(gameWindow);
		mySpaceDisplacer.Draw(gameWindow);
		if (myPlayer.IsActive())
			myPlayer.Draw(gameWindow);
		

		// Display the window contents on the screen
		gameWindow.display();
	}//end game loop

	return 0;
}
