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
	
	float milliseconds = 0;
	int seconds = 0;
	bool timer = true;
	int secondsnow = 0;
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
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			splashscreen = false;
		}
		
		if (myPlayer.GetHullIntergity() <= 0)
		{
			gameover = true;
		}

		// Get the time passed since the last frame and restart our game clock
		sf::Time frameTime = gameClock.restart();

		if (splashscreen == false && gameover == false)
		{
			milliseconds = milliseconds + (float)frameTime.asMilliseconds();
			
			seconds = seconds + (int)frameTime.asMilliseconds();
			//turn milliseconds into seconds
			seconds = milliseconds / 100;

			std::cout << seconds << std::endl;
			// TODO: Update all game objects
			if (myPlayer.IsActive())
				myPlayer.Update(frameTime);
			if (mySpaceDisplacer.IsActive())
				mySpaceDisplacer.Update(frameTime);
			if (asteroidBelt.IsActive())
			{
				asteroidBelt.Update(frameTime);
				asteroidBelt.SetGameTimer(seconds);
			}
			if (thePersuit.IsActive())
			{
				thePersuit.Update(frameTime);
				thePersuit.SetGameTimer(seconds);
			}
			myPickUp.Update(frameTime);
			myPickUp.SetGameTimer(seconds);
			UI_E.SetMillisecondsSinceGameStart(milliseconds/100);
			UI_E.SetGameTimer(seconds);
			UI_E.Update(frameTime);
		}
		UI_E.Update(frameTime);
		UI_E.IsGameOver(gameover);
		UI_E.IsSplashScreenActive(splashscreen);
		if (gameover == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			gameWindow.close();
		}
		// -----------------------------------------------
		// Draw Section
		// -----------------------------------------------

		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// TODO: Draw game object
		UI_E.Draw(gameWindow);
		if (gameover == false)
		{
			mySpaceDisplacer.Draw(gameWindow);
			if (thePersuit.IsActive())
				thePersuit.Draw(gameWindow);
			if (asteroidBelt.IsActive())
				asteroidBelt.Draw(gameWindow);
			myPickUp.Draw(gameWindow);
			if (myPlayer.IsActive())
				myPlayer.Draw(gameWindow);
		}
		else
		{
			//draw game over screen
		}
		
		

		// Display the window contents on the screen
		gameWindow.display();
	}//end game loop

	return 0;
}
