#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <cstdlib>                   //for exit(0)
using namespace std;

void copy_cb( Fl_Widget* , void* );  //function prototypes
void close_cb( Fl_Widget* , void* );
void make_window();
  
int main() {

   make_window();
   return Fl::run();
}

void make_window() {
 
  Fl::set_font(FL_HELVETICA, "Kochi Mincho");
   Fl_Window* win= new Fl_Window(300,200, "テスト 二");
   win->begin();      
      Fl_Button* copy = new Fl_Button( 50, 100, 140, 30, "コピー（&C）");
      Fl_Button* close = new Fl_Button(100, 150, 70, 30, "終了（&Q）");
      Fl_Input*  inp = new Fl_Input(50, 50, 140, 30, "入");            
   win->end();
   copy->callback(  copy_cb, inp );  //userdata is the inp pointer
   close->callback( close_cb );
   win->show();
 }

void copy_cb( Fl_Widget* o , void* v) {

   Fl_Button* b=(Fl_Button*)o;
   Fl_Input* i=(Fl_Input*)v;
   b->copy_label(i->value()); 
}

void close_cb( Fl_Widget* o, void*) {

   exit(0);
}
