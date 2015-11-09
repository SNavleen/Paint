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

#include "Draw.h"
#include "Point.h"

Point point;

//Constructors
Draw::Draw(){
    red = 0.0f;
    green = 0.0f;
    blue = 0.0f;
}

//Deconstructor
Draw::~Draw(){
}

//Public function

/*Draw setRed(float red)*/
void Draw::setRed(float red){
    this->red = red;
}
/*Draw setRed(float green)*/
void Draw::setGreen(float green){
    this->green = green;
}
/*Draw setBlue(float blue)*/
void Draw::setBlue(float blue){
    this->blue = blue;
}
/*Draw resetAllColours()*/
void Draw::resetAllColours(){
    red = 0.0f;
    green = 0.0f;
    blue = 0.0f;
}

/*Draw setColour();*/
void Draw::setColour(){
    glColor3f(red, green, blue);
}

/*Draw setShape(char shape);*/
void Draw::setShape(char *shape){
    this->shape = shape;
}
/*Draw getShape();*/
char* Draw::getShape(){
    return shape;
}

void Draw::drawPoint(int posX, int posY){
    posY = (glutGet(GLUT_WINDOW_HEIGHT)) - posY;
    point.setPosX(posX);
    point.setPosY(posY);

    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex2i(point.getPosX(), point.getPosY());
    glEnd();  
    glFlush();
}

void Draw::drawPointForCircle(int x, int y, int x0, int y0){
    drawPoint( x + x0,  y + y0);
    drawPoint( y + x0,  x + y0);
    drawPoint(-x + x0,  y + y0);
    drawPoint(-y + x0,  x + y0); 
    drawPoint(-x + x0, -y + y0); 
    drawPoint(-y + x0, -x + y0); 
    drawPoint( x + x0, -y + y0); 
    drawPoint( y + x0, -x + y0);
}

//http://rosettacode.org/wiki/Bitmap/Bresenham's_line_algorithm#C
void Draw::drawLine(int x0, int y0, int x1, int y1){ 

    int dx = abs(x1-x0);
    int sx;
    if(x0<x1){
        sx = 1;
    }else{
        sx = -1;
    }
    int dy = abs(y1-y0);
    int sy;
    if(y0<y1){
        sy = 1;
    }else{
        sy = -1;
    }
    int exitPoint = (dx>dy ? dx : -dy)/2;

    for(;;){
        drawPoint(x0,y0);
        if (x0==x1 && y0==y1) 
            break;
        if (exitPoint >-dx){
            exitPoint -= dy;
            x0 += sx;
        }
        if(exitPoint < dy){
            exitPoint += dx;
            y0 += sy;
        }
    }


}
void Draw::drawRect(int x0, int y0, int x1, int y1){
    drawLine(x0, y0, x1, y0);
    drawLine(x0, y0, x0, y1);
    drawLine(x1, y1, x0, y1);
    drawLine(x1, y1, x1, y0);
}

//https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
void Draw::drawCircle(int x0, int y0, int x1){
    int x = abs(x1-x0);
    int y = 0;
    int counter = 1 - x;

    while( y <= x ){
        drawPointForCircle(x, y, x0, y0); 
        if (counter<=0){
            counter += 2 * y + 1; 
        }else{
            x--;
            counter += 2 * (y - x) + 1; 
        }
        y++;
    }
}

void Draw::setStartPosX(int startPosX){
    point.setStartPosX(startPosX);
}
void Draw::setStartPosY(int startPosY){
    point.setStartPosY(startPosY);
}

int Draw::getStartPosX(){
    return point.getStartPosX();   
}
int Draw::getStartPosY(){
    return point.getStartPosY();
}
