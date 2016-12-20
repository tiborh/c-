#include "a_browser.h"

a_browser::a_browser()
{
    test_browser = new Fl_Browser(0,25,500,500,"Test");
    add_coloured();
    add_lines();
}

void a_browser::add_lines()
{
    test_browser->add("One");            // fltk does strdup() internally
    test_browser->add("Two");
    test_browser->add("Three");
}

void a_browser::add_coloured()
{
    test_browser->add("Black @C1Red @C2Green @C3Yellow");
}

void a_browser::clear()
{
    test_browser->clear();
}
