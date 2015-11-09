#ifndef __POINT_H__
#define __POINT_H__

class Point{
    public:
        //Constructors
        Point();

        //Deconstructor
        ~Point();

        //Public variables

        //Public function
        void setPosX(int posX);
        void setPosY(int posY);

        int getPosX();
        int getPosY();

        void setStartPosX(int startPosX);
        void setStartPosY(int startPosY);

        int getStartPosX();
        int getStartPosY();

    private:
        //Private variables
        int posX, posY;
        int startPosX, startPosY;
};

#endif
