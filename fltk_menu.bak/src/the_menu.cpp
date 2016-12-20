#include "../include/the_menu.h"

the_menu::the_menu()
{
            // Make the app window and menu bar w/callbacks
            win = new Fl_Window(720, 486);
            menubar = new Fl_Menu_Bar(0, 0, win->w(), 25);
            menubar->add("File/Open", 0, Menu_cb, (void*)this);    // userdata is always 'this'
            menubar->add("File/Quit", 0, Menu_cb, (void*)this);
            menubar->add("Help/Help", 0, Menu_cb, (void*)this);
            win->end();
            win->show();
}

void the_menu::Menu_cb(Fl_Widget*w, void*data)
{
    the_menu *o = (the_menu*)data;
    o->Menu_cb2();
}

void the_menu::Menu_cb2()
{
    char picked[80];
    menubar->item_pathname(picked, sizeof(picked)-1);
    printf("CALLBACK: You picked '%s'\n", picked);

    // How to handle callbacks..
    if ( strcmp(picked, "File/Quit") == 0 ) exit(0);
    if ( strcmp(picked, "Help/Help") == 0 ) printf("Help goes here\n");
}
