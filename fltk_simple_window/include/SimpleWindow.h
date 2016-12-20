#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>

class SimpleWindow : public Fl_Window
{
public:
    SimpleWindow(int w, int h, const char* title );
    virtual ~SimpleWindow();
    Fl_Button* copy;
    Fl_Button* quit;
    Fl_Input* inp;
    Fl_Output* out;
protected:
    static void cb_copy(Fl_Widget*, void*); // callbacks can only be static
    inline void cb_copy_i(); // inline to make it a single function call with cb_copy
    static void cb_quit(Fl_Widget*, void*);
    inline void cb_quit_i();
private:
};

#endif // SIMPLEWINDOW_H
