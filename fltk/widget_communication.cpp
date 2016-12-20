#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <cstdlib>                   //for exit(0)
#include <string.h>
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
   Fl_Window* win= new Fl_Window(300,200, "テスト 二"); // parent
   win->begin();      
   //Fl_Button* copy = new Fl_Button( 10, 150, 70, 30, "C&opy");  //child 0  : 1st widget
   Fl_Button* copy = new Fl_Button( 10, 150, 100, 30, "コピー（&C）");  //child 0  : 1st widget
      Fl_Button* close = new Fl_Button(130, 150, 100, 30, "終了（&Q）"); //child 1  : 2nd widget
      Fl_Input*  inp = new Fl_Input(50, 50, 140, 30, "入");        //child 2  : 3rd widget
      Fl_Output* out = new Fl_Output(50, 100, 140, 30, "出");     //child 3  : 4th widget
   win->end();
   copy->callback(  copy_cb );
   close->callback( close_cb );
   win->show();
 }

// not a nice solution, but works as a first approach
void copy_cb( Fl_Widget* o , void* ) {

  Fl::set_font(FL_HELVETICA, "Kochi Mincho");
   Fl_Button* b=(Fl_Button*)o;
   Fl_Input* iw = (Fl_Input*) b -> parent() -> child(2);
   Fl_Output* ow = (Fl_Output*) b -> parent() -> child(3);
   ow->value( iw->value() );
}

// in the current solution, this is the only way to free up memory
void close_cb( Fl_Widget* o, void*) {

   exit(0);
}
