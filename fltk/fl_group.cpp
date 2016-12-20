#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
//
// Demonstrate clipping problem with widgets outside their parent's xywh extents
// erco 04/20/08
//
Fl_Window *win = 0;
Fl_Group  *grp = 0;
void Why_CB(Fl_Widget*, void*) {
    grp->box(FL_FLAT_BOX);
    grp->color(FL_RED);
    win->redraw();
}
int main() {
    win = new Fl_Window(175,200);
    Fl::set_font(FL_HELVETICA, "Kochi Mincho");
    grp = new Fl_Group(3,5,73,155);
    new Fl_Button(5,10 ,40,40,"左"); new Fl_Button(55,10 ,40,40,"左|右"); new Fl_Button(105,10 ,40,40,"右");
    new Fl_Button(5,60 ,40,40,"左"); new Fl_Button(55,60 ,40,40,"左|右"); new Fl_Button(105,60 ,40,40,"右");
    new Fl_Button(5,110,40,40,"左"); new Fl_Button(55,110,40,40,"左|右"); new Fl_Button(105,110,40,40,"右");
    grp->end();
    Fl_Button *but = new Fl_Button(5, 165, 150, 25, "左 works 右 does not");
    but->callback(Why_CB);
    win->end();
    win->show();
    return(Fl::run());
}
