//fltk-config --complile name_of_the_file.cpp
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main(int argc, char **argv) {
  Fl_Window *window = new Fl_Window(340,180,"世界へようこそ！");
  Fl_Box *box = new Fl_Box(20,40,300,100,"ようこそ、世界！"); 
  Fl::set_font(FL_HELVETICA, "Kochi Mincho");

  window->begin();

  // Fl_Widget(x, y, width, height, label)

  //box->box(FL_UP_BOX);
  box->box(FL_NO_BOX);
  box->labelsize(36);
  box->labeltype(FL_SHADOW_LABEL);

  window->end();
  window->show(argc, argv);

  return Fl::run();
}
