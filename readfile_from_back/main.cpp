#include <iostream>
#include "readfromback.h"

using namespace std;

int main()
{
    cout << read_from_rear("txt/empty.txt");
    cout << read_from_rear("txt/wandrers_nachtlied.txt");
    cout << read_from_rear("txt/konnichiwa.txt");
    cout << read_from_rear("txt/test_hun.txt");
    cout << read_from_rear("txt/utf8_4byte.txt");
    //cout << read_from_rear("txt/murphy.txt");
    //cout << read_from_rear("txt/one.txt");

    return 0;
}
