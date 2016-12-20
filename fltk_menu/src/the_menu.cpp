#include "../include/the_menu.h"

int GetIndexForPath(Fl_Menu_Bar* menubar, const char *findname) {
    char menupath[1024] = "";            // File/Export
    for ( int t=0; t < menubar->size(); t++ ) {
        Fl_Menu_Item *m = (Fl_Menu_Item*)&(menubar->menu()[t]);
        if ( m->submenu() ) {
            // Submenu?
            if ( menupath[0] ) strcat(menupath, "/");
            strcat(menupath, m->label());
            if ( strcmp(menupath, findname) == 0 ) return(t);
        } else {
            if ( m->label() == NULL ) {
                // End of submenu? Pop back one level.
                char *ss = strrchr(menupath, '/');
                if ( ss ) *ss = 0;
                else      menupath[0] = '\0';
                continue;
            }
            // Menu item?
            char itempath[1024];         // eg. Edit/Copy
            strcpy(itempath, menupath);
            if ( itempath[0] ) strcat(itempath, "/");
            strcat(itempath, m->label());
            if ( strcmp(itempath, findname) == 0 ) {
                return(t);
            }
        }
    }
    return(-1);
}

// FIND A MENU ITEM BY MENU PATHNAME
//     eg. "Edit/Copy"
//     Will also return submenus, eg. "Edit"
//     Returns NULL if not found.
//
Fl_Menu_Item *GetMenuItemForPath(Fl_Menu_Bar* menubar, const char *findname) {
    int index = GetIndexForPath(menubar, findname);
    if ( index == -1 ) return(NULL);
    Fl_Menu_Item *m = (Fl_Menu_Item*)&(menubar->menu()[index]);
    return(m);
}

Fl_Menu_Item *the_menu::get_menuitem_name(const char *findname)
{
    return GetMenuItemForPath(menubar,findname);
}

int the_menu::is_path_in_menu(const char* searchlabel)
{
    return GetIndexForPath(menubar,searchlabel);
}

the_menu::the_menu(Fl_Window *mwin): win(mwin)
{
            // Make the app window and menu bar w/callbacks
            //win = new Fl_Window(720, 486);
            menubar = new Fl_Menu_Bar(0, 0, win->w(), 25);
            menubar->add("&File/&New", FL_CTRL+'n', Menu_cb, (void*)this);
            menubar->add("&File/&Open", FL_CTRL+'o', Menu_cb, (void*)this);    // userdata is always 'this'
            menubar->add("&File/&Save", FL_CTRL+'s', Menu_cb, (void*)this);
            menubar->add("&File/&Close", FL_CTRL+'w', Menu_cb, (void*)this);
            menubar->add("&File/&Quit", FL_ALT+FL_F+4, Menu_cb, (void*)this);
            menubar->add("&Edit/&Copy", FL_CTRL+'c', Menu_cb, (void*)this);
            menubar->add("&Edit/C&ut", FL_CTRL+'x', Menu_cb, (void*)this);
            menubar->add("&Edit/&Paste", FL_CTRL+'v', Menu_cb, (void*)this);

            menubar->add("&Window/&Open", FL_CTRL+FL_SHIFT +'o', Menu_cb, (void*)this);
            menubar->add("&Window/&Close", FL_CTRL+FL_SHIFT+'w', Menu_cb, (void*)this);
            menubar->add("&Window/&Next", FL_CTRL+FL_F+6, Menu_cb, (void*)this);
            menubar->add("&Window/&Previous", FL_CTRL+FL_SHIFT+FL_F+6, Menu_cb, (void*)this);
            menubar->add("&Help/&Help", FL_F + 1, Menu_cb, (void*)this);
            menubar->add("&Help/&About", 0, Menu_cb, (void*)this);
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
