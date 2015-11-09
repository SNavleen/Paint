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
#include "Menu.h"

Draw drawMenu;

//Constructors
Menu::Menu(){
}

//Deconstructor
Menu::~Menu(){
}

//Public function

Menu mainmenu;
void Menu::ClearScreen(){
    drawMenu.resetAllColours();
    drawMenu.setRed(1.0f);
    drawMenu.setGreen(1.0f);
    drawMenu.setBlue(1.0f);
    drawMenu.setColour();
//glutGet(GLUT_WINDOW_WIDTH)
//glutGet(GLUT_WINDOW_HEIGHT)
    glPointSize(500);
    glBegin(GL_POINTS);
        for(int i = -25; i < 25; i++){
            for(int j = -25; j < 25; j++){
                glVertex2i(i/1, j/1);     
            }       
        }
    glEnd();  
    glFlush();
}

//MenuActionShapes
void MenuAction(int input){
    switch(input){
        case 0:
            mainmenu.ClearScreen();
            break;
        case 1:
            exit(0);
            break;

        default:
            break;
    }
}

//MenuActionColour
void MenuActionColour(int input){
    drawMenu.resetAllColours();
    switch(input){
        case 0:
            drawMenu.setRed(1.0f);
            drawMenu.setColour();
            break;
        case 1:
            drawMenu.setBlue(1.0f);
            break;
        case 2:
            drawMenu.setGreen(1.0f);
            break;
        case 3:
            drawMenu.setRed(0.33f);
            drawMenu.setGreen(0.10f);
            drawMenu.setBlue(0.55f);
            break;
        case 4:
            drawMenu.setRed(1.0f);
            drawMenu.setGreen(1.0f);
            break;
        case 5:
            drawMenu.setRed(rand()/(double)RAND_MAX);
            drawMenu.setGreen(rand()/(double)RAND_MAX);
            drawMenu.setBlue(rand()/(double)RAND_MAX);
            break;

        default:
            break;
    }
    drawMenu.setColour();
}

//MenuActionShapes
void MenuActionShapes(int input){
    switch(input){
        case 0:
            drawMenu.setShape("Point");
            break;
        case 1:
            drawMenu.setShape("Line");
            break;
        case 2:
            drawMenu.setShape("Rectangle");
            break;
        case 3:
            drawMenu.setShape("Circle");
            break;

        default:
            break;
    }
}

/*Meun AddMenuEntry*/
/*void Menu::AddMenuEntry(char listOfEntries[]){
    for(int i = 0; i < sizeof(listOfEntries)-1; i++){
        printf("%s\n", listOfEntries[i]);
    }
}*/

/*Meun GlutInitMenu*/
void Menu::GlutInitMenu(){
    int submenuActionColour = glutCreateMenu(MenuActionColour);
    // TODO Move to different file as an array//
    glutAddMenuEntry("Red", 0);
    glutAddMenuEntry("Blue", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Purple", 3);
    glutAddMenuEntry("Yellow", 4);
    glutAddMenuEntry("Random Colour", 5);

    int submenuActionShapes = glutCreateMenu(MenuActionShapes);
    // TODO Move to different file as an array//
    glutAddMenuEntry("Point", 0);
    glutAddMenuEntry("Line", 1);
    glutAddMenuEntry("Rectangle", 2);
    glutAddMenuEntry("Circle", 3);

    int menuAction = glutCreateMenu(MenuAction); 
    glutAddSubMenu("Colour", submenuActionColour);
    glutAddSubMenu("Shapes", submenuActionShapes);
    glutAddMenuEntry("Clear", 0);
    glutAddMenuEntry("Quit", 1);

    glutSetMenu(menuAction);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

char* Menu::getShape(){
    return drawMenu.getShape();
}