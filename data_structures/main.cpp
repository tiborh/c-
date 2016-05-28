#include <iostream>

using namespace std;

void print_out(int i, int j)
{
    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
}

int main()
{
    int i,j;
    i=j=0;
    print_out(i,j);
    cout << "Give me two integers: ";
    cin >> i >> j;
    print_out(i,j);
    return 0;
}
