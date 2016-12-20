#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    int i = rand() % 1024;
    cout << setiosflags (ios::showbase | ios::uppercase); // more infp: ios_base::fmtflags
    cout << i << endl;
    cout << setbase(8) << i << endl;
    cout << setbase(16) << i << endl;
    return 0;
}
