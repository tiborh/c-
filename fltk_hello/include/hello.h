#ifndef HELLO_H
#define HELLO_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#include <string>

class hello
{
public:
    hello(std::string title = "Hello",
             std::string label = "Hello, world!",
             int width = 350,
             int height = 180);
    virtual ~hello() {}
protected:
    Fl_Window *window;
    Fl_Box *box;
    Fl_Group *grp;
    Fl_Button *ok_btn;
    Fl_Button *no_btn;

    std::string title;
    std::string label;
    int width;
    int height;
    static void cb_ok( Fl_Button*, void* );
    inline void cb_ok_i( Fl_Button*, void* );

    static void cb_no( Fl_Button*, void* );
    inline void cb_no_i( Fl_Button*, void* );
private:
};

#endif // HELLO_H
