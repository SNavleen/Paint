#ifndef __DRAW_H__
#define __DRAW_H__

class Draw{
    public:
        //Constructors
        Draw();

        //Deconstructor
        ~Draw();

        //Public variables

        //Public function

        /*Draw setRed(float red)*/
        void setRed(float red);
        /*Draw setRed(float green)*/
        void setGreen(float green);
        /*Draw setBlue(float blue)*/
        void setBlue(float blue);
        /*Draw resetAllColours()*/
        void resetAllColours();

        /*Draw setColour();*/
        void setColour();

        /*Draw setShape(char shape);*/
        void setShape(char *shape);
        /*Draw getShape();*/
        char* getShape();

        void drawPoint(int posX, int posY);
        void drawPointForCircle(int x, int y, int x0, int y0);
        void drawLine(int x0, int y0, int x1, int y1);
        void drawRect(int x0, int y0, int x1, int y1);
        void drawCircle(int x0, int y0, int x1);
        
        void setStartPosX(int startPosX);
        void setStartPosY(int startPosY);
        int getStartPosX();
        int getStartPosY();

    private:
        //Private Variables
        float red, green, blue;
        char *shape;

};

#endif
