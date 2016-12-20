#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <FL/Fl.H>
#include <FL/Fl_Button.H>

#include <iostream>

class MyButton: public Fl_Button
{
    static int count;

public:
    MyButton(int x,int y,int w,int h,const char*l=0)
        :Fl_Button(x,y,w,h,l) {}

    int handle(int e)
    {
        int ret = Fl_Button::handle(e);
        std::cout<<'\n'<<++count<<" ******** button "<<label()<<" receives ";

        switch(e)
        {
        case FL_PUSH:
            std::cout<<"push"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_RELEASE:
            std::cout<<"release"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_ENTER:
            color(FL_CYAN);
            std::cout<<"enter"<<" event and returns:"<<ret<<'\n';
            redraw();
            break;

        case FL_LEAVE:
            color(FL_BACKGROUND_COLOR);
            std::cout<<"leave"<<" event and returns:"<<ret<<'\n';
            redraw();
            break;

        case FL_DRAG:
            std::cout<<"drag"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_FOCUS:
            std::cout<<"focus"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_UNFOCUS:
            std::cout<<"unfocus"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_KEYDOWN:
            std::cout<<"keydown"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_KEYUP:
            if ( Fl::event_key() == shortcut() )
            {
                box(FL_UP_BOX);
                redraw();
                ret=1; //return handled so keyup event stops
            }         //being sent to ALL other buttons unecessarily

            std::cout<<"keyup"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_CLOSE:
            std::cout<<"close"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_MOVE:
            std::cout<<"move"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_SHORTCUT:
            if ( Fl::event_key() == shortcut() )
            {
                box(FL_DOWN_BOX);
                redraw();
            }
            std::cout<<"shortcut"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_DEACTIVATE:
            std::cout<<"deactivate"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_ACTIVATE:
            std::cout<<"activate"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_HIDE:
            std::cout<<"hide"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_SHOW:
            std::cout<<"show"<<" event and returns:"<<ret<<'\n';
            break;

        case FL_PASTE:
            std::cout<<"paste"<<" event and returns:"<<ret<<'\n';
            break;

        case  FL_SELECTIONCLEAR:
            std::cout<<"selectionclear"<<" event and returns:"<<ret<<'\n';
            break;

        case  FL_MOUSEWHEEL:
            std::cout<<"mousewheel"<<" event and returns:"<<ret<<'\n';
            break;

        case  FL_NO_EVENT:
            std::cout<<"no event"<<" and returns:"<<ret<<'\n';
            break;

        }
        return(ret);
    }

};

#endif // MYBUTTON_H
