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
#include "Draw.h"
#include "Menu.h"
//#include "Point.h"


Window window;
Draw draw;
Menu menu;
//Point point;

//Window size
void CreateDisplayWindow(){
	window.setWidth(500);
	window.setHeight(500);

	window.setPosX((glutGet(GLUT_SCREEN_WIDTH)-window.getWidth())/2);
	window.setPosY((glutGet(GLUT_SCREEN_HEIGHT)-window.getHeight())/2);

	//Set the Window Size
	glutInitWindowSize(window.getWidth(), window.getHeight());
	//Set Window position
	glutInitWindowPosition(window.getPosX(), window.getPosY());
	//Creates the Paint window
	glutCreateWindow("Paint");
	menu.ClearScreen();
}

//Display
void Display(void){
	//glClear(GL_COLOR_BUFFER_BIT);
/*	glBegin(GL_POLYGON);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);	
	glEnd();*/
	//draw2.drawPoint(100, 100);
	glFlush();
}

//KeyBoardAction
void KeyBoardAction(unsigned char key, int posX, int posY){
	switch(key){
		case 27: //escape key with fall through
			exit(0);
			break;

		default:
			break;
	}
}

void Reshape(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, w, h);
}

//MouseClickAction
// TODO Move to different file//
void MouseClickAction(int button, int state, int posX, int posY){
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(menu.getShape() == "Line"){
				if(draw.getStartPosX() != -1 && draw.getStartPosY() != -1){
					draw.drawLine(draw.getStartPosX(), draw.getStartPosY(), posX, posY);
					draw.setStartPosX(-1);
					draw.setStartPosY(-1);
				}else{
					draw.setStartPosX(posX);
					draw.setStartPosY(posY);
				}
			}else if(menu.getShape() == "Rectangle"){
				if(draw.getStartPosX() != -1 && draw.getStartPosY() != -1){
					draw.drawRect(draw.getStartPosX(), draw.getStartPosY(), posX, posY);
					draw.setStartPosX(-1);
					draw.setStartPosY(-1);
				}else{
					draw.setStartPosX(posX);
					draw.setStartPosY(posY);
				}
			}else if(menu.getShape() == "Circle"){
				if(draw.getStartPosX() != -1 && draw.getStartPosY() != -1){
					draw.drawCircle(draw.getStartPosX(), draw.getStartPosY(), posX);
					draw.setStartPosX(-1);
					draw.setStartPosY(-1);
				}else{
					draw.setStartPosX(posX);
					draw.setStartPosY(posY);
				}
			}else{
				draw.drawPoint(posX, posY);		
			}
			break;

		default:
			break;
	}
}

//MouseMotionAction
// TODO Move to different file//
void MouseMotionAction(int posX, int posY){
	if(menu.getShape() == "Line"){
		//draw.drawLine(draw.getStartPosX(), draw.getStartPosY(), posX, posY);
	}else if(menu.getShape() == "Rectangle"){
		//draw.drawRect(posX, posY, draw.getStartPosX(), draw.getStartPosY());
	}else if(menu.getShape() == "Circle"){
	}else{
		draw.drawPoint(posX, posY);		
	}
}

//Init
void glutCallbacks(){
	glutDisplayFunc(Display);
	glutKeyboardFunc(KeyBoardAction);
	glutReshapeFunc(Reshape);
	glutMouseFunc(MouseClickAction);
	glutMotionFunc(MouseMotionAction);
}


void timerRedisplay(int value){
	glutTimerFunc(60, timerRedisplay, 0);
	Display();
}

void printAllInfoToTerminal(){
	printf("To exit press 'esc'.\n");
	printf("Right click opens a menu.\n");
	printf("Left click allows you to draw.\n");
	printf("For lines, rectangles, and circles you need to click and drag.\n");
}
//Maint
int main(int argc, char** argv){
	//Start GLUT
	glutInit(&argc, argv);
	//Set the window size
	CreateDisplayWindow();
	printAllInfoToTerminal();
    draw.resetAllColours();
    draw.setRed(0.0f);
    draw.setGreen(0.0f);
    draw.setBlue(0.0f);
    draw.setColour();
	draw.setStartPosX(-1);
	draw.setStartPosY(-1);

	//Call "glutCallbacks"
	glutCallbacks();
	//Setup right click menu
	menu.GlutInitMenu();

	timerRedisplay(0);

	//Start the events of mainloop
	glutMainLoop();
}