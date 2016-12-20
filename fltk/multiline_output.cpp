#include <FL/Fl.H>
#include <FL/Fl_Multiline_Output.H>
#include <iostream>
#include <cstdlib>

int main()
{
  Fl_Multiline_Output output(0,0,500,500);

// CLEAR OUTPUT
output.value("");

// SET OUTPUT
output.value("one\ntwo");          // fltk does strdup() internally       

// APPENDING OUTPUT
//     Would be nice if this were an add() method in fltk ;)
//
const char *news = "Add this text";
char *cat = (char*)malloc(strlen(output.value()) + strlen(news) + 1);
strcpy(cat, output.value());
strcat(cat, news);
output.value(cat);
free(cat);

 std::cout << "Nothing happens, mere code illustration.\n";

return Fl::run(); 
}
