#ifndef CALLBACKS_H_INCLUDED
#define CALLBACKS_H_INCLUDED

#include <FL/Fl.H>

void but_a_cb(Fl_Widget* w, void* v){
    std::cout <<'\n'<< "Button あ callback!"<<'\n';
}

void but_b_cb(Fl_Widget* w, void* v){
    std::cout <<'\n'<< "Button う callback!"<<'\n';
}

void but_c_cb(Fl_Widget* w, void* v){
    std::cout <<'\n'<< "Button い callback!"<<'\n';
}

#endif // CALLBACKS_H_INCLUDED
