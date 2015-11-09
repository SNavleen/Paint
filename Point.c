#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/freeglut.h>
#endif

#include "Point.h"


//Constructors
Point::Point(){
}

//Deconstructor
Point::~Point(){
}

//Public variables

//Public function
void Point::setPosX(int posX){
	this->posX = posX;
}
void Point::setPosY(int posY){
	this->posY = posY;
}

int Point::getPosX(){
	return posX;
}
int Point::getPosY(){
	return posY;
}

void Point::setStartPosX(int startPosX){
	this->startPosX = startPosX;
}
void Point::setStartPosY(int startPosY){
	this->startPosY = startPosY;
}

int Point::getStartPosX(){
	return startPosX;
}
int Point::getStartPosY(){
	return startPosY;
}
