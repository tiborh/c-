#include <iostream>
#include <string>
using namespace std;

inline void print_message(string s = "Hello, World!")
{ cout << s << endl; }

int main()
{
    print_message();
    print_message("another text.");
    print_message("and something more");
}
