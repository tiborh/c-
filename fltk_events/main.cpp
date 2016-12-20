#include "MyButton.h"
#include "callbacks.h"

#include <FL/Fl_Window.H>

using namespace std;

int main (int argc, char ** argv)
{
    Fl::set_font(FL_HELVETICA, "Kochi Mincho");
    Fl_Window win(120,150);
    win.begin();

    MyButton but_a(10,10,100,25,"あ");
    but_a.shortcut('a');
    but_a.callback(but_a_cb);

    MyButton but_b(10,50,100,25,"う");
    but_b.shortcut('u');
    but_b.callback(but_b_cb);

    MyButton but_c(10,90,100,25,"い");
    but_c.shortcut('i');
    but_c.callback(but_c_cb);

    win.end();
    win.show();
    return(Fl::run());
}
