#ifndef __MENU_H__
#define __MENU_H__

class Menu{
    public:
        //Constructors
        Menu();

        //Deconstructor
        ~Menu();

        //Public variables

        //Public function
        /*Meun AddMenuEntry*/
        //void AddMenuEntry(char listOfEntries[]);
        /*Meun GlutInitMenu*/
        void GlutInitMenu();
        void ClearScreen();
        char* getShape();
};

#endif
