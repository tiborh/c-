#include "SimpleWindow.h"

using namespace std;

SimpleWindow::SimpleWindow(int w, int h, const char* title):Fl_Window(w,h,title)
{
    begin();  // "this" is implicit
    Fl::set_font(FL_HELVETICA, "Kochi Mincho");
    copy = new Fl_Button( 50, 150, 100, 30, "コピー（&C）");
    copy->callback( cb_copy, this ); // "this" does not exist for static functions

    quit = new Fl_Button(165, 150, 100, 30, "終了（&Q）");
    quit->callback(cb_quit, this);

    inp = new Fl_Input(60, 50, 200, 30, "入");
    out = new Fl_Output(60, 100, 200, 30, "出");
    end();

    // only one widget per group can be resizable
    resizable(this); // all items are resized
    //resizable(copy); // buttons are resizable with the window
    // see comments at the bottom too...

    show();
}

SimpleWindow::~SimpleWindow() {}  // Fl_Window takes care of it

void SimpleWindow::cb_copy(Fl_Widget* o, void* v)
{
    //SimpleWindow* T=(SimpleWindow*)v;
    //T->cb_copy_i();

    // or just the one line below
    ( (SimpleWindow*)v )->cb_copy_i();
}

void SimpleWindow::cb_copy_i()
{
    out->value(inp->value());
}

void SimpleWindow::cb_quit(Fl_Widget* , void* v)
{
    ( (SimpleWindow*)v )->cb_quit_i();
}

void SimpleWindow::cb_quit_i()
{
    hide(); // when all objects are hidden, memory is freed, destructors are called.
}

/* // a possible solution:
void fl_exit()
{
  while( Fl::first_window() )
    Fl::first_window()->hide();
}
*/

/*
- to make things more predictable, it helps to fill groups with
  widgets only in one direction: either horizontally or vertically.
  (this also helps explain the following hints).

- If you need to fill groups both horizontally and vertically,
  fill a group WITH GROUPS in one direction, then those 'sub'groups
  in the other direction.

- In a group, at most one widget can be set to "resizable".
  Attempts to setting several widgets to 'resizable' causes
  only the last one to be marked resizable.

- Setting a widget to "resizable" means that that widget can be
  resized BOTH horizontally and vertically, not that it is the
  only resizable widget in the group.

- all other widgets in the group may resize along proportionally to
  the size of the group, but only in one direction (if the group
  is populated horizontally, 'nonresizable' widgets only resize
  vertically, only the 'resizable' widget resizes in both directions.

- if a group is only resizable in one direction, only the resizable
  widget will resize, all other widgets will stay the way they are.
*/
