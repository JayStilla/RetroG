//////////////////////////////////////////////////////////////////////////
//File:			Classes.h
//Author:		Jayce Jastillana
//Date Created: 11/4/2013
//Brief:		All of my classes and variables
///////////////////////////////////////////////////////////////////////////
#ifndef _CLASSES_H_
#define _CLASSES_H_

#include "AIE.h"
#include "math.h"

//screen size
const int iScreenWidth = 1280;
const int iScreenHeight = 780; 
//bullet size
static int bulletsH = 50; 
static int bulletsW = 50; 

static int playerOneW = 100; 
static int playerOneH = 100;
static bool playerOneDied = false; 
//enemy size
static int enemyH = 100; 
static int enemyW = 100; 
 
static bool bulletAlive;
static bool bulletDead;


//Check from menu if the player wants to play the game or end the game
struct GameMenu
{
	bool playGame; 
	bool gamePause; 
	bool gameOver; 
	bool escape; 
};

struct Shoot
{
	bool playerShoot;
	bool shoot; 
};

struct CheckDead
{
	bool playerOneDead; 
	bool enemyDead; 
	bool bulletDead; 
};

////////////////////////////////////////////////////Class for everything involving Vectors
class Vectors
{
public:
	Vectors(); 
	~Vectors(); 

	struct Point2D
	{
		float x;
		float y; 
	};
	
	
static	Point2D pointSubtract(Point2D &v, float s); 
static	Point2D pointAdd(Point2D &v, float s); 
static 	Point2D multiplyScalar(Point2D &v, float s); 
static	Point2D pointSubtract(Point2D &v, Point2D &v2); 
static 	Point2D pointAdd(Point2D &v, Point2D &v2); 
static 	Point2D getNormal(Point2D &v); 
	float getMagnitude(Point2D &v); 
};



//////////////////////////////////////////////////Class for everything involving sprites
class Sprite: public Vectors
{
public:
	Sprite(); 
	~Sprite(); 



	struct MovableObject
	{
		Point2D position; 
		Point2D speed; 
		int sprite; 
		int width; 
		int height;
	};

};
////////////////////////////////////////////////Class for all Bullet functions
class Bullet: public Sprite
{
public:
	Bullet(); 
	~Bullet(); 
	int bullets; 
	
	static void Direction(MovableObject &bullet); 
};






///////////////////////////////////////////////Class for all enemy functions
class Enemy
{
public:
	Enemy(); 
	~Enemy(); 


};

////////////////////////////////////////////////Class for all player functions
class Player
{
public:
	Player(); 
	~Player(); 

};





#endif