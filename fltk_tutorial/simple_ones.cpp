#include "simple_ones.h"

using namespace std;

void clb_lbl(Fl_Widget* o, void*)
{
    Fl::set_font(FL_HELVETICA, "Kochi Mincho");
    const vector<const char*> labels = {"月", "木", "水", "木", "金", "土", "日"};
    //const vector<const char*> labels = {"Monday", "Tuesday", "Wednesday",
                                        //"Thursday", "Friday", "Saturday", "Sunday"};
    static int counter = 0;

    Fl_Button* b=(Fl_Button*)o;
    b->label(labels[counter % labels.size()]); //redraw not necessary
    ++counter;
    //b->resize(10,150,140,30); //redraw needed
    //b->redraw();
}

void exit_action(Fl_Widget* o, void*)
{
    exit(0);
}

int the_days(int argc, char** argv)  //expanded a little
{
    Fl_Window *window;
    Fl_Box *box;
    Fl_Button *button;
    Fl_Button *b_exit;
    Fl::set_font(FL_HELVETICA, "Kochi Mincho");
    //Fl::set_font(FL_HELVETICA, "Kochi Gothic");

    window = new Fl_Window(300, 180);
    box = new Fl_Box(20, 50, 260, 100, "七曜");
    button = new Fl_Button(10, 5, 100, 35, "クリック");
    b_exit = new Fl_Button(120, 5, 60, 35, "終了");
    //box = new Fl_Box (20, 40, 260, 100, u8"月");
    box->box (FL_UP_BOX);
    box->labelsize (48);
    //box->labelfont (FL_BOLD+FL_ITALIC);
    box->labeltype (FL_SHADOW_LABEL);
    button->labelsize(24);
    b_exit->labelsize(24);
    window->end ();
    button->callback(clb_lbl); // button action for box would be needed.
    b_exit->callback(exit_action);
    window->show (argc, argv);

    return(Fl::run());
}
//--------------------------------------------
void but_cb( Fl_Widget* o, void*  )
{
    Fl_Button* b=(Fl_Button*)o;
    b->label("Good job"); //redraw not necessary
    b->resize(10,150,140,30); //redraw needed
    b->redraw();
}
void but_px( Fl_Widget* o, void*  )
{
    std::cout << "x\n";
}
//--------------------------------------------
int tut1()
{

    Fl_Window win( 300,200,"Testing" );
    win.begin();
    Fl_Button but( 10, 150, 70, 30, "Click me" );
    Fl_Button but2( 160, 150, 70, 30, "Print x" );
    win.end();
    but.callback( but_cb );
    but2.callback( but_px );
    win.show();
    return Fl::run();
}

