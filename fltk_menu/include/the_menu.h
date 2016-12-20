#ifndef THE_MENU_H
#define THE_MENU_H

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>

class the_menu
{
    public:
        the_menu(Fl_Window*);
        int is_path_in_menu(const char*);
        Fl_Menu_Item *get_menuitem_name(const char *);
        //virtual ~the_menu();//undefined reference to vtable for xxx if not implemented.
    protected:
        Fl_Window *win;
        Fl_Menu_Bar *menubar;
        static void Menu_cb(Fl_Widget*, void*);
        void Menu_cb2();
    private:
};

#endif // THE_MENU_H
