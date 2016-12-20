#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <vector>

using namespace std;

void clb_lbl(Fl_Widget* o, void*)
{
    Fl::set_font(FL_HELVETICA, "Kochi Mincho");
    const vector<const char*> labels = {"月", "木", "水", "木", "金", "土", "日"};
    //const vector<const char*> labels = {"Monday", "Tuesday", "Wednesday",
                                        //"Thursday", "Friday", "Saturday", "Sunday"};
    static int counter = 0;

    Fl_Button* b=(Fl_Button*)o;
    b->label(labels[counter % labels.size()]); //redraw not necessary if not resized
    ++counter;
    //b->resize(10,150,140,30); //redraw needed because of resize
    //b->redraw();
}

void exit_action(Fl_Widget* o, void*)
{
    exit(0);
}

int the_days(int argc, char** argv)
{
    Fl_Window *window;
    Fl_Box *box;
    Fl_Button *button;
    Fl_Button *b_exit;
    Fl::set_font(FL_HELVETICA, "Kochi Mincho");  // ttf-kochi-mincho
    //Fl::set_font(FL_HELVETICA, "Kochi Gothic"); // ttf-kochi-gothic

    window = new Fl_Window(300, 180);
    box = new Fl_Box(20, 50, 260, 100, "七曜"); // しちよう the seven days of the week
    button = new Fl_Button(10, 5, 100, 35, "クリック"); // click
    b_exit = new Fl_Button(120, 5, 60, 35, "終了"); // しゅうりょう exit
    //box = new Fl_Box (20, 40, 260, 100, u8"月"); // c++11 charset selection
    box->box (FL_UP_BOX);
    box->labelsize (48);
    //box->labelfont (FL_BOLD+FL_ITALIC);
    box->labeltype (FL_SHADOW_LABEL);
    button->labelsize(24);
    b_exit->labelsize(24);
    window->end ();
    button->callback(clb_lbl);
    b_exit->callback(exit_action);
    window->show (argc, argv);

    return(Fl::run());
}

int main (int argc, char ** argv)
{
    the_days(argc,argv);
}

