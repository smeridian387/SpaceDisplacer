//Library includes
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <time.h>

//Project includes
#include "Framework/AssetManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Framework/SpriteObject.h"
#include "asteroidBelt.h"
#include "Enemy.h"
#include "Persuit.h"
#include "UIelements.h"
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

	//generates a few random numbers
	for (int i = 0; i < 40; ++i)
	{
		int random = std::rand() % 260 + 40;
		std::cout << -random << std::endl;
	}

	// Create test objects
	Player myPlayer; //player object
	SpaceDisplacer mySpaceDisplacer;// space displacer object
	AsteroidBelt asteroidBelt;// asteroid belt object (asteroid manager object)
	asteroidBelt.SetSpaceDisplacer(&mySpaceDisplacer);//passing asteroid belt a pointer to the space displacer
	asteroidBelt.SetPlayer(&myPlayer);//passing asteroid belt a pointer for the player
	Asteroid myAsteroid;//asteroid object
	PickUp myPickUp;//pick up object
	Torpedo myTorpedo;//torpedo object
	UIelements UI_E;//interface object
	Enemy myEnemy;//enemy object
	Persuit thePersuit;//persuit object (enemy manager object)
	thePersuit.SetPlayer(&myPlayer);//passing the persuit a pointer to player
	thePersuit.SetSpaceDisplacer(&mySpaceDisplacer);//passing the persuit a pointer to space displacer
	thePersuit.SetTorpedo(&myTorpedo);//passing the persuit a pointer to the torpedo object
	thePersuit.SetAsteroid(&myAsteroid);//passing the persuit a pointer
	myPickUp.SetPlayer(&myPlayer);//passing the pick up object a pointer to the player
	myPickUp.SetSpaceDisplacer(&mySpaceDisplacer);//passing the pick up object a ponter to the space dsplacer
	UI_E.SetPlayer(&myPlayer);//passing the interface object a pointer to the player
	UI_E.SetSpaceDisplacer(&mySpaceDisplacer);//passing the interface object a pointer to space displacer

	//global variables
	float milliseconds = 0;
	int seconds = 0;
	//timer bools
	bool timer = true;
	bool timer2 = false;
	//timer holders
	int preCurrentTime;
	int preCurrentTime2;
	//game screen bools
	bool mainmenu = true;
	bool splashscreen = true;
	bool gameover = false;
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
		// if the players health is equal to or less than the game will end 
		if (myPlayer.GetHullIntergity() <= 0)
		{
			gameover = true;
		}
		
		//timers that manage game screen transitions
		time_t m_time;
		if (timer == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				mainmenu = false;//removes title screen
				timer = false;
			}
			preCurrentTime = time(&m_time);
		}
		if (time(&m_time) >= preCurrentTime + 3)
		{
			timer2 = true;
		}
		time_t m_time2;
		if (timer2 == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				splashscreen = false;//removes tutorial screen
			}
			preCurrentTime2 = time(&m_time2);
			timer2 = false;
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
		//passing game screen booleans so the objects and draw properly
		UI_E.Update(frameTime);
		UI_E.IsGameOver(gameover);
		UI_E.IsMainMenuActive(mainmenu);
		UI_E.IsSplashScreenActive(splashscreen);
		mySpaceDisplacer.IsMainMenuActive(mainmenu);
		myPlayer.IsMainMenuActive(mainmenu);
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
			asteroidBelt.Draw(gameWindow);
			myPickUp.Draw(gameWindow);
			if (myPlayer.IsActive())
				myPlayer.Draw(gameWindow);
		}
		
		

		// Display the window contents on the screen
		gameWindow.display();
	}//end game loop

	return 0;
}
