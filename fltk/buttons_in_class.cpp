//************************************
//C++ FLTK Buttons Tutorial
//Button Example 3
//************************************
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <cstdlib>
using namespace std;
  
class SimpleWindow : public Fl_Window{ 
 
   public: 
	  SimpleWindow( int w, int h, const char* title ); 
	  ~SimpleWindow(); 
	  Fl_Button* copy; 
	  Fl_Button* quit; 
	  Fl_Input* inp; 
	  Fl_Output* out; 
	 
   private: 
	  static void cb_copy( Fl_Button*, void* ); 
	  inline void cb_copy_i( Fl_Button*, void* ); 
   
	  static void cb_quit( Fl_Button*, void* ); 
	  inline void cb_quit_i( Fl_Button*, void* ); 
};

int main( int argc, char* argv[] )
{
   SimpleWindow win( 600,250,"C++ FLTK Buttons Tutorial - Example 3" ); 
   return Fl::run(); 
} 

SimpleWindow::SimpleWindow( int w, int h, const char* title ):Fl_Window( w,h,title )
{ 
  begin(); 
	  copy = new Fl_Button( 375, 0,  70, 30, "C&opy" ); 
	  copy->callback(( Fl_Callback*)cb_copy, this ); 
	  
	  quit = new Fl_Button( 450, 0,  70, 30, "&Quit" ); 
	  quit->callback(( Fl_Callback*)cb_quit, this ); 
	
	  inp = new Fl_Input( 40, 0, 140, 30, "Input:" ); 
	  out = new Fl_Output( 230, 0, 140, 30, "Output:" );
   end();
   resizable( this );
   show();
} 

SimpleWindow::~SimpleWindow()
{

} 

void SimpleWindow::cb_copy( Fl_Button* obj, void* v )
{  
   SimpleWindow* T=( SimpleWindow* )v; 
   T->cb_copy_i(obj,v); 
} 

void SimpleWindow::cb_copy_i( Fl_Button* , void* )
{ 
   out->value( inp->value() );   
} 

void SimpleWindow::cb_quit( Fl_Button*obj , void* v )
{ 
   SimpleWindow* T=( SimpleWindow* )v; 
   T->cb_quit_i( obj,v ); 
} 

void SimpleWindow::cb_quit_i( Fl_Button* , void* )
{ 
   exit(0);  
} 
