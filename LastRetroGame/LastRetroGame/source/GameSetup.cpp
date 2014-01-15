//////////////////////////////////////////////////////////////////////////
//File:			GameSetup.cpp
//Author:		Jayce Jastillana
//Date Created: 11/4/2013
//Brief:		Actually writing all the code used in the game. 
///////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include "Classes.h" 
#include "GameSetup.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std; 
Sprite::MovableObject enemy[10];
Sprite::MovableObject bullets[3];
//Bullet abullets[3];
unsigned int Score;
unsigned int tick; 

clock_t prevTime;
float waitTime = 5; 
float timeWaited = 0; 


bool Collision::checkCollision(Sprite::MovableObject &obj1, Sprite::MovableObject &obj2)
{
	double radiusOne = 25; 
	double radiusTwo = 25; 
	double distX = obj1.position.x - obj2.position.x;
	double distY = obj1.position.y - obj2.position.y;
	float dist = sqrt ((distX * distX) + (distY * distY)); 

	if(dist < radiusOne + radiusTwo)
		return true; 
	else 
		return false; 
}

void Game::seek(Sprite::MovableObject &playerOne, Shoot &fire)
{

	int spawn = rand() % iScreenWidth;
	//int spawn = 10;
	float speed = 2; 
	for(int i =0; i<10; i++)
	{
		spawn = rand() % iScreenWidth;
		enemy[i].position.y += 2; 


		if(enemy[i].position.y > iScreenHeight)
		{
			enemy[i].position.x = spawn; 
			enemy[i].position.y = rand() % -1000 + -1520; 

		}
	}
}


void allCollision(Sprite::MovableObject &playerOne, GameMenu &Menu, CheckDead &dead)
{

	for(int i=0; i<10; i++)
	{
		if(Collision::checkCollision(playerOne, enemy[i])== true)
		{
			dead.playerOneDead = true; 
			Menu.gameOver = true; 
		}
		for(int j = 0; j<3; j++)
		{
			if(Collision::checkCollision(bullets[j], enemy[i])== true)
			{
				dead.enemyDead = true; 
				Score++;
				int spawn = rand() % iScreenWidth; 
				enemy[i].position.y = -1000; 

			}
		}
	}

}

//initiating the menu state of the game
void Game::initMenu(unsigned int &bgImage){
	//srand(time(0)); 
	bgImage = CreateSprite("./images/GundamBG.png", iScreenWidth, iScreenHeight, true);	//image for the background
	MoveSprite(bgImage, iScreenWidth>>1, iScreenHeight>>1);

}

//drawing the menu state  
void Game::drawMenu(unsigned int &bgImage){
	DrawSprite(bgImage);	//calling the background image to the screen that was initialised earlier
	DrawString("Press SPACE key to PLAY", 0, 360);	//calling the play game button to the screen
	DrawString("Press 'Esc' key to Exit", 0, 400);//calling the exit game button to the screen 
	DrawString("Press the 'Backspace' key to return to menu", 0, 440);
	DrawString("Controls: W, A, S, D to move around", 0, 480);
	DrawString("To shoot: Press SPACE bar", 0, 525);
}

//updating the menu to check for user input
void Game::updateMenu(unsigned int &bgImage, GameMenu &Menu, CheckDead &dead){
	if(IsKeyDown(KEY_SPACE))
	{
		Menu.playGame = true; 
		Menu.gamePause = true; 
		Menu.gameOver = false; 
		Menu.escape = false; 
		dead.playerOneDead = false; 
	}
	else if (IsKeyDown (KEY_ESC))
	{
		Menu.escape = true; 
		Menu.playGame = false; 
	}
}

//initiating the variables needed to start the game
void Game::initGame(unsigned int &gameImage, Sprite::MovableObject &playerOne){
	//srand(time(0)); 
	Score = 1;
	gameImage = CreateSprite("./images/carbonfiber.png", iScreenWidth, iScreenHeight, true);//draw bgImage
	MoveSprite(gameImage, iScreenWidth>>1, iScreenHeight>>1); 
	playerOne.sprite = CreateSprite("./images/spaceship.png", playerOneW, playerOneH, true);//player
	MoveSprite(playerOne.sprite, iScreenWidth/2, iScreenHeight/2); 
	for (int i = 0; i < 10; i++)
	{
		enemy[i].sprite = CreateSprite("./images/enemy.png", enemyW, enemyH, true);//enemies
	}
	for(int i = 0; i<3; i++)
	{
		bullets[i].sprite = CreateSprite("./images/bullet.png", bulletsW, bulletsH, true);//bullets
	}
}

//destroying the sprites in order to end the game
void Game::destroyGame(unsigned int &gameImage, Sprite::MovableObject &playerOne){
	DestroySprite(gameImage);//bgImage
	DestroySprite(playerOne.sprite);//player
	for(int i = 0; i<10; i++)
	{
		DestroySprite(enemy[i].sprite);//enemies
	}
	for(int i = 0; i<3; i++)
	{
		DestroySprite(bullets[i].sprite);//bullets
	}
}

//keeping track of player score
//void gameScore(){
//	if (enemyDied == true){//small enemies 100pts
//        playerOneScore += 100; 
//    }
//medium enemies 200pts
//big enemies 400pts
//	//boss' 800pts
//}
//void isBulletAlive()
//{
//	for(int i = 0; i<3; i++)
//	{
//		if(bullets[i].position.y < 0)
//		{
//			Bullet::bulletAlive = false; 
//			bulletDead = true; 
//		}
//		else if(bullets[i].position.y > 0)
//		{
//			bulletDead = false; 
//			bulletAlive = true; 
//		}
//	}
//}

void Game::shoot( Sprite::MovableObject &playerOne, Shoot &fire){

	/*for(int i = 0; i<3; i++)
	{*/
	if(timeWaited>= waitTime)
	{
		if(IsKeyDown(KEY_SPACE))
		{
			for(int i = 0; i<3; i++)
			{	
				if(bulletDead == true)
				{
					bullets[i].position.x = playerOne.position.x;
					bullets[i].position.y = playerOne.position.y;
					bulletDead = false;
					return;
				}
				bullets[i].position.y -=5;
			}
		}	
	}


}


//keys used to control playerOne
void Game::move(Sprite::MovableObject &playerOne, Shoot &fire) {
	if(IsKeyDown('W') && playerOne.position.y > playerOne.height/2){//put switch case statement for the player to choose whether they want
		playerOne.position.y -= 3;

	}
	else if(IsKeyDown('D') && playerOne.position.x < iScreenWidth - (playerOne.width/2)){
		playerOne.position.x += 3; 


	}
	else if(IsKeyDown ('S') && playerOne.position.y < iScreenHeight - (playerOne.height/2)){
		playerOne.position.y += 3;

	}
	else if(IsKeyDown ('A') && playerOne.position.x > playerOne.width/2){
		playerOne.position.x -= 3; 

	}

}



//updates game to check for player position/enemy position and score
void Game::updateGame(unsigned int &gameImage, unsigned int &bgImage, GameMenu &Menu, Sprite::MovableObject &playerOne, Shoot &fire, CheckDead &dead){
	//using delta time in game
	clock_t now = clock(); 
	float dt = (float)(now - prevTime)/CLOCKS_PER_SEC;
	prevTime = now;
	timeWaited += dt; 

	move(playerOne, fire); //player position on screen
	shoot(playerOne, fire);
	for(int i=0; i<3; i++)
	{
		bullets[i].sprite; 
	}
	allCollision(playerOne, Menu, dead); 
	 


	seek(playerOne, fire);//enemies

	//score 
	if(Menu.gameOver == false){
		if(IsKeyDown (KEY_BACKSPACE))
		{
			Menu.playGame = false;
		}
		else if(dead.playerOneDead == true)
		{
			Menu.gameOver = true;

		}
		MoveSprite(playerOne.sprite, playerOne.position.x, playerOne.position.y); 
		for(int i = 0; i<10; i++){
			MoveSprite(enemy[i].sprite, enemy[i].position.x, enemy[i].position.y); 
		}
		for(int i = 0; i<3; i++)
		{
			MoveSprite(bullets[i].sprite, bullets[i].position.x, bullets[i].position.y); 
		}
	}
}

//drawing the initialized variables to the screen
void Game::drawGame(unsigned int &gameImage, GameMenu &Menu, Sprite::MovableObject &playerOne)
{
	DrawSprite(gameImage); //draw player, enemies, bullets, bgImage
	MoveSprite(gameImage, iScreenWidth>>1, iScreenHeight>>1);


	for (int i = 0; i<10; i++)
	{
		DrawSprite(enemy[i].sprite); 
	}
	for(int i = 0; i<3; i++)
	{
		DrawSprite(bullets[i].sprite);
	}
	DrawSprite(playerOne.sprite);

	if(Menu.gameOver == true)
	{
		DrawString("Game Over" , iScreenWidth/2, 300);

	}



}