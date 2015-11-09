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

#include "Window.h"


//Constructors
Window::Window(){
    width = 0;
    height = 0;
    posX = 0;
    posY = 0;
}

//Deconstructor
Window::~Window(){

}

//Public function


/*Window setWidth(int width);*/
void Window::setWidth(int width){
    this->width = width;
}
/*Window getWidth();*/
int Window::getWidth(){
    return width;
}

/*Window setHeight(int height);*/
void Window::setHeight(int height){
    this->height = height;
}
/*Window getHeight();*/
int Window::getHeight(){
    return height;
}

/*Window setPosX(int posX);*/
void Window::setPosX(int posX){
    this->posX = posX;
}
/*Window getPosX();*/
int Window::getPosX(){
    return posX;
}

/*Window setPosY(int posY);*/
void Window::setPosY(int posY){
    this->posY = posY;
}
/*Window getPosY();*/
int Window::getPosY(){
    return posY;
}
