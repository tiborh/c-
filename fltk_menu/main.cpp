#include "include/the_menu.h"
#include "include/a_browser.h"
#include <iostream>

using namespace std;

int main (int argc, char ** argv)
{
    Fl_Window *mwin = new Fl_Window(720, 486);
    the_menu *sample_menu = new the_menu(mwin);
    a_browser *sample_browser = new a_browser();

    int outputnum = -1;
    const char* test_path = "&File/&Quit";
    outputnum = sample_menu->is_path_in_menu(test_path);
    cout << "Trying to find '&File/&Quit': " << outputnum << endl;
    cout << "Trying to find 'File/Quit': " << sample_menu->is_path_in_menu("File/Quit") << endl;
    if (outputnum > -1)
    {
        Fl_Menu_Item *found_menu_item = sample_menu->get_menuitem_name(test_path);
        if (found_menu_item->active())
            found_menu_item->deactivate();
        else
            found_menu_item->activate();
    }
    mwin->end();
    mwin->show();

  return(Fl::run());
}
