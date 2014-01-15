#include "Classes.h"
#include "GameSetup.h"



void Bullet::Direction(MovableObject &bullets)
{
	//set position to center of the screen
	//speed set
	//when shoot is called
	if (Game::shoot)
	{
		bullets.position.x = iScreenWidth/2; 
		bullets.position.y = iScreenHeight/2; 
		bullets.speed.y = -5; 
	}
}