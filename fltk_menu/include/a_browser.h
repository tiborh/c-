#ifndef A_BROWSER_H
#define A_BROWSER_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Browser.H>

class a_browser
{
    public:
        a_browser();
        ~a_browser(){}
        void add_lines();
        void clear();
        void add_coloured();
        void format_disable();
        void print_items();
        void preselect_all();
        void deselect_all();
        void get_single_selected();
        void indexed_return(int index_num);
    protected:
        Fl_Browser *test_browser;
    private:
};

#endif // A_BROWSER_H
