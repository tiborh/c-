#include "hello.h"
#include <iostream>

using namespace std;

hello::hello(std::string wtitle, std::string wlabel,
             int wwidth, int wheight):
                 title(wtitle),label(wlabel),width(wwidth),height(wheight)
{
    //Fl::set_font(FL_HELVETICA, "Kochi Mincho");
    //Fl::set_font(FL_HELVETICA, "AoyagiKouzanFontT");
    Fl::set_font(FL_HELVETICA, "AoyagiSosekiFont2");

    window = new Fl_Window (350, 180, title.c_str());
    window->begin();
        box = new Fl_Box (20, 20, 300, 100, label.c_str());
        box->box (FL_UP_BOX);
        box->labelsize (46);
        //box->labelfont (FL_BOLD+FL_ITALIC);
        box->labeltype (FL_SHADOW_LABEL);
        grp= new Fl_Group(15,130,310,35);
            //grp->box(FL_FLAT_BOX);
            //grp->color(FL_RED);
            ok_btn = new Fl_Button(20,135,50,25,"はい");
            ok_btn->callback((Fl_Callback*)cb_ok, this);
            no_btn = new Fl_Button(270,135,50,25,"無い");
            no_btn->callback((Fl_Callback*)cb_no, this);
        grp->end();
    window->end();
    window->show();
}

void hello::cb_ok( Fl_Button* obj, void* v)
{
    hello* T = (hello*) v;
    T->cb_ok_i(obj,v);
}
void hello::cb_ok_i( Fl_Button* obj, void* v)
{
    ((hello*)v)->window->hide();
    cout << "はい" << '\n';
    //exit(0);
}

void hello::cb_no( Fl_Button* obj, void* v)
{
    hello* T = (hello*) v;
    T->cb_no_i(obj,v);
}
void hello::cb_no_i( Fl_Button* obj, void* v)
{
    ((hello*)v)->window->hide();
    cout << "無い" << '\n';
    //exit(1);
}
