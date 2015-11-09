#ifndef __WINDOW_H__
#define __WINDOW_H__

class Window{
    public:
        //Constructors
        Window();

        //Deconstructor
        ~Window();

        //Public variables

        //Public function
        /*Window setWidth(int width);*/
        void setWidth(int width);
        /*Window getWidth();*/
        int getWidth();

        /*Window setHeight(int height);*/
        void setHeight(int height);
        /*Window getHeight();*/
        int getHeight();

        /*Window setPosX(int posX);*/
        void setPosX(int posX);
        /*Window getPosX();*/
        int getPosX();

        /*Window setPosY(int posY);*/
        void setPosY(int posY);
        /*Window getPosY();*/
        int getPosY();

    private:
        //Private Variables
        int width, height, posX, posY;

};

#endif
