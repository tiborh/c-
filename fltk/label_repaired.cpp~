#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
using namespace std;

void butcb(Fl_Widget* o, void*){
    char newcap[]="changed";
    o->label(newcap);
}

int main(){
    Fl_Window win (200,100, "window");
    Fl_Button but (50,50,80,25,"caption");
    but.callback (butcb);
    win.end();
    win.show();
    return Fl::run();
}
