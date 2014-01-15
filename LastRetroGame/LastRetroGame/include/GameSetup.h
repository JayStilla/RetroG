//////////////////////////////////////////////////////////////////////////
//File:			GameSetup.h
//Author:		Jayce Jastillana
//Date Created: 11/4/2013
//Brief:		Prototyping everything I use in game. 
///////////////////////////////////////////////////////////////////////////
#ifndef _GAMESETUP_H_
#define _GAMESETUP_H_


class Game
{
public:
	Game(); 
	~Game(); 
	

static void initMenu(unsigned int &bgImage);
static void drawMenu(unsigned int &bgImage);
static void updateMenu(unsigned int &bgImage, GameMenu &Menu, CheckDead &dead);
static void initGame(unsigned int &gameImage, Sprite::MovableObject &playerOne);
static void destroyGame(unsigned int &gameImage, Sprite::MovableObject &playerOne);
static void gameScore();
static void move(Sprite::MovableObject &playerOne, Shoot &fire);
static void seek(Sprite::MovableObject &playerOne, Shoot &fire); 
static void shoot(Sprite::MovableObject &playerOne, Shoot &fire); 
static void updateGame(unsigned int &gameImage, unsigned int &bgImage, GameMenu &Menu, Sprite::MovableObject &playerOne, Shoot &fire, CheckDead &dead);
static void drawGame(unsigned int &gameImage, GameMenu &Menu, Sprite::MovableObject &playerOne);

};

class Collision
{
public:
	Collision(); 
	~Collision(); 

	static bool checkCollision(Sprite::MovableObject &obj1, Sprite::MovableObject &obj2); 

};
#endif