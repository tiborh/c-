// Show the use of item_pathname() in a custom class.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>

class MyApp {
    Fl_Window *win;
    Fl_Menu_Bar *menubar;

    // Static menu callback
    static void Menu_CB(Fl_Widget*w, void*data) {
        MyApp *o = (MyApp*)data;
        o->Menu_CB2();
    }

    // Callback method with class access
    void Menu_CB2() {
        char picked[80];
        menubar->item_pathname(picked, sizeof(picked)-1);
        printf("CALLBACK: You picked '%s'\n", picked);

        // How to handle callbacks..
        if ( strcmp(picked, "File/Quit") == 0 ) exit(0);
        if ( strcmp(picked, "Help/Help") == 0 ) printf("Help goes here\n");
    }

public:
    MyApp() {
        // Make the app window and menu bar w/callbacks
        win = new Fl_Window(720, 486);
        menubar = new Fl_Menu_Bar(0, 0, win->w(), 25);
        menubar->add("File/Open", 0, Menu_CB, (void*)this);    // userdata is always 'this'
        menubar->add("File/Quit", 0, Menu_CB, (void*)this);
        menubar->add("Help/Help", 0, Menu_CB, (void*)this);
        win->end();
        win->show();
    }
};

// MAIN
int main() {
    MyApp app;
    return(Fl::run());
}
