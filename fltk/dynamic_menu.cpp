#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <iostream>

// FIND MENU ITEM INDEX, GIVEN MENU PATHNAME
//     eg. "Edit/Copy"
//     Will also return submenus, eg. "Edit"
//     Returns -1 if not found.
//
int GetIndexByName(Fl_Menu_Bar* menubar, const char *findname) {
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
Fl_Menu_Item *GetMenuItemByName(Fl_Menu_Bar* menubar, const char *findname) {
    int index = GetIndexByName(menubar, findname);
    if ( index == -1 ) return(NULL);
    Fl_Menu_Item *m = (Fl_Menu_Item*)&(menubar->menu()[index]);
    return(m);
}

// TURN ON RADIO BUTTON GIVEN MENU PATHNAME
//    eg. SetRadioByName(menubar, "File/Radio-1")
//
void SetRadioByName(Fl_Menu_Bar *menubar, const char *menuname) {
    Fl_Menu_Item *m = GetMenuItemByName(menubar, menuname);
    if ( m == NULL ) return;
    m->setonly();
}

// SET TOGGLE BUTTON ON OR OFF, GIVEN MENU PATHNAME
//    eg. SetToggleByName("File/Toggle-1", "on")
//
void SetToggleByName(Fl_Menu_Bar *menubar, const char *menuname, int val ) {
    Fl_Menu_Item *m = GetMenuItemByName(menubar, menuname);
    if ( m == NULL ) return;
    if ( val ) m->set();
    else       m->clear();
}

// ACTIVATE MENU ITEM, GIVEN MENU ITEM PATHNAME
//    eg. SetActivateByName("File/Radio-1")
//
void SetActivateByName(Fl_Menu_Bar *menubar, const char *menuname, int val) {
    Fl_Menu_Item *m = GetMenuItemByName(menubar, menuname);
    if ( m == NULL ) return;
    if ( val ) m->activate();
    else       m->deactivate();
}

// GET TOGGLE BUTTON STATE, GIVEN MENU PATHNAME
//    eg. GetToggleByName("Edit/Preferences/Toggle-1")
//
int GetToggleValueByName(Fl_Menu_Bar *menubar, const char *menuname) {
    Fl_Menu_Item *m = GetMenuItemByName(menubar, menuname);
    if ( m == NULL ) return -1;
    return(m->value());
}

// CLEAR ALL ITEMS IN SUBMENU BELOW THE NAMED ITEM
//    eg. ClearItemsBelow("File/Save As");
//    where menu looks like:
//
//       File..New
//             Open
//             Save
//             Save As
//             -------          __
//             /usr/tmp/foo.st    |__ Clear all these so they
//             /usr/tmp/bar.st    |   can be recreated later.
//             /usr/tmp/bla.st  __|
//                    __
//       Edit..Cut      |
//             Copy     | These are unaffected.
//             Paste  __|
//
static void ClearItemsBelow(Fl_Menu_Bar *menubar, const char *menuname) {
    int index = GetIndexByName(menubar, menuname);
    if ( index == -1 ) return;
    int level = 0;
    ++index;    // skip the item itself, so we delete stuff _below_ it
    while ( index <= menubar->size() ) {
        Fl_Menu_Item *m = (Fl_Menu_Item*)&(menubar->menu()[index]);
        if ( m->label() == NULL ) {
            // Pop out of submenu, keep track of level
            if ( --level < 0 ) return;
        } else {
            // Descending into a submenu? Keep track of leveL
            if ( m->submenu() )
                ++level;
        }
        // Remove all menu items *and* submenus
        menubar->remove(index);
    }
}

int main(int argc, char** argv)
{
  std::cerr << "Functions are in place, no GUI has been implemented yet.\n";

  return 0;
}
