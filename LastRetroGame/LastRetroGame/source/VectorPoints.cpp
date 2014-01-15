//////////////////////////////////////////////////////////////////////////
//File:			VectorPoints.cpp
//Author:		Jayce Jastillana
//Date Created: 09/24/2013
//Brief:		All of my vector points in order to apply all the movement and sensing in the game. 
///////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include "Classes.h"
#include "math.h"




//equations that helps the variables that move in the game
//subtracting points and returning a new point
Vectors::Point2D Vectors::pointSubtract(Point2D &v, float s)
{
	Point2D result = {v.x - s, v.y - s};
	return result; 
}

//Adding two points and returning it as a new point
Vectors::Point2D Vectors::pointAdd(Point2D &v, float s)
{
	Point2D result = {v.x + s, v.y + s}; 
	return result;
}

//multiplying points by scalar to return a new point
Vectors::Point2D Vectors::multiplyScalar(Point2D &v, float s)
{
	Point2D result = {v.x*s, v.y*s};
	return result; 
}

//subtracting points by each other for a new point
Vectors::Point2D Vectors::pointSubtract(Point2D &v, Point2D &v2)
{
	Point2D result = {v.x - v2.x, v.y - v2.y};
	return result; 
}

//adding points by each other for a new point
Vectors::Point2D Vectors::pointAdd(Point2D &v, Point2D &v2)
{
	Point2D result = {v.x + v2.x, v.y+v2.y};
	return result; 
}

//Getting the normal of a point and returning it as a new point
Vectors::Point2D Vectors::getNormal(Point2D &v)
{
	float mag = sqrt (v.x*v.x + v.y*v.y);
	Point2D result = {v.x/mag, v.y/mag};
	return result; 
}

//Getting magnitude for point
float Vectors::getMagnitude(Point2D &v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}
