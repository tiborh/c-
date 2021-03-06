// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "hello.h"

void hello::cb_OK_i(Fl_Return_Button*, void*) {
  ecit(0);
}
void hello::cb_OK(Fl_Return_Button* o, void* v) {
  ((hello*)(o->parent()->parent()->user_data()))->cb_OK_i(o,v);
}

void hello::cb_Cancel_i(Fl_Button*, void*) {
  exit(1);
}
void hello::cb_Cancel(Fl_Button* o, void* v) {
  ((hello*)(o->parent()->parent()->user_data()))->cb_Cancel_i(o,v);
}

Fl_Double_Window* hello::make_window(string title, string msg) {
  { hello_win = new Fl_Double_Window(200, 150, "Hello Window");
    hello_win->user_data((void*)(this));
    { hello_lbl = new hello(25, 25, 145, 70, "Hello");
      hello_lbl->box(FL_ENGRAVED_BOX);
      hello_lbl->color(FL_BACKGROUND_COLOR);
      hello_lbl->selection_color(FL_BACKGROUND_COLOR);
      hello_lbl->labeltype(FL_NORMAL_LABEL);
      hello_lbl->labelfont(0);
      hello_lbl->labelsize(40);
      hello_lbl->labelcolor(FL_FOREGROUND_COLOR);
      hello_lbl->align(Fl_Align(FL_ALIGN_CENTER));
      hello_lbl->when(FL_WHEN_RELEASE);
    } // hello* hello_lbl
    { Fl_Group* o = new Fl_Group(25, 100, 150, 44);
      { Fl_Return_Button* o = new Fl_Return_Button(25, 115, 70, 25, "OK");
        o->callback((Fl_Callback*)cb_OK);
      } // Fl_Return_Button* o
      { Fl_Button* o = new Fl_Button(105, 115, 70, 25, "Cancel");
        o->callback((Fl_Callback*)cb_Cancel);
      } // Fl_Button* o
      o->end();
    } // Fl_Group* o
    Fl::visual(FL_DOUBLE|FL_RGB);
    hello_win->show(argc, argv);
    hello_win->end();
  } // Fl_Double_Window* hello_win
  return hello_win;
}

void hello::show(int argc, char **argv) {
  make_window->show(argc,argv);
}
