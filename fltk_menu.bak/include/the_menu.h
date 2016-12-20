#ifndef THE_MENU_H
#define THE_MENU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>

class the_menu
{
    public:
        the_menu();
        virtual ~the_menu();
    protected:
        Fl_Window *win;
        Fl_Menu_Bar *menubar;
        static void Menu_cb(Fl_Widget*, void*);
        void Menu_cb2();
    private:
};

#endif // THE_MENU_H
