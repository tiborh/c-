#include <stdio.h>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>

//
// Demonstrate how to toggle a menu item procedurally -- erco 05/14/09
//

// SET A MENU ITEM'S STATE
//    Find the menuitem by name, and change its state.
//    Returns -1 if named menu item not found.
//
int SetMenuItemState(Fl_Menu_Bar *menubar, const char *name, int state) {
    Fl_Menu_Item *m = (Fl_Menu_Item*)menubar->find_item(name);
    if ( ! m ) return(-1);
    if ( state ) { m->set(); }
    else         { m->clear(); }
    return(0);
}
int main(int argc, char **argv) {
    Fl_Double_Window *win = new Fl_Double_Window(720,486);
    Fl_Menu_Bar *menubar = new Fl_Menu_Bar(0,0,720,25);
    menubar->add("Options/One",   0, 0,0, FL_MENU_TOGGLE);
    menubar->add("Options/Two",   0, 0,0, FL_MENU_TOGGLE);
    menubar->add("Options/Three", 0, 0,0, FL_MENU_TOGGLE);
    win->end();
    win->show();
    // TEST THE STATE CHANGES -- TURN 'ONE' OFF, OTHERS 'ON'
    if ( SetMenuItemState(menubar, "Options/One",   0) < 0 ) { fprintf(stderr, "FAILED[1]\n"); }
    if ( SetMenuItemState(menubar, "Options/Two",   1) < 0 ) { fprintf(stderr, "FAILED[2]\n"); }
    if ( SetMenuItemState(menubar, "Options/Three", 1) < 0 ) { fprintf(stderr, "FAILED[3]\n"); }
    return(Fl::run());
}
