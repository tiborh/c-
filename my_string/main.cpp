#include <iostream>
#include "collector.h"

using namespace std;

int main()
{
    collector a = collector();
    cout << "length after empty constructor: " << a.size() << endl;
    a.set("one");
    cout << "set to: " << a << endl;
    a.cat(" two");
    a.cat(" three");
    cout << "after contatenations: " << a << endl;
    collector b = collector("etc");
    cout << "b: " << b << endl;
    a.cat(" ");
    a.cat(b);
    cout << "after the concat of b: " << a << endl;
    return 0;
}
