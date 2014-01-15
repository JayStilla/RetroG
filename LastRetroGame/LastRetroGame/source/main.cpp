//////////////////////////////////////////////////////////////////////////
//File:			main.cpp
//Author:		Jayce Jastillana
//Date Created: 09/24/2013
//Brief:		All of my game functions being called to run. 
///////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include "Classes.h"
#include "GameSetup.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include <stdio.h>

using namespace std; 
//void setGame(); 
unsigned int bgImage = -1; 
unsigned int gameImage = -1; 
Sprite::MovableObject bullets;
Sprite::MovableObject playerOne = {iScreenWidth/2, iScreenHeight/2, playerOne.sprite, 100, 100}; 
Sprite::MovableObject enemy = {0, 640, 100, 100};

int frameCounter = 0; 

GameMenu Menu = {false, false, false, false}; 
Shoot fire = {false, false}; 
CheckDead dead = {false, false, false};



int main()

{
	Initialise(iScreenWidth, iScreenHeight, false);
	Game::initGame(gameImage, playerOne);
	Game::initMenu(bgImage);
	do
	{

		do
		{

			frameCounter++; 
			if(frameCounter > 5000)
				frameCounter = 0; 

			ClearScreen(); 


			Game::updateMenu(bgImage, Menu, dead); 
			Game::drawMenu(bgImage); 
		}
		while ((FrameworkUpdate() == false) && (Menu.playGame == false) && Menu.gameOver == false);



		while (FrameworkUpdate() == false && (Menu.playGame == true) && Menu.gameOver == false) 
		{
			frameCounter++; 
			if (frameCounter>5000)
				frameCounter = 0;

			ClearScreen(); 

			//Game::initGame(bgImage, bullets, playerOne, enemy); 

			Game::updateGame(gameImage, bgImage, Menu, playerOne, fire, dead); 
			Game::drawGame(gameImage, Menu, playerOne);
		}
	}
	while(FrameworkUpdate() == false && (Menu.escape == false)); 

	Game::destroyGame(gameImage, playerOne); 

	Shutdown(); 


	return 0;
}

