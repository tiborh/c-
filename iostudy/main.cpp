#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "ostream study:" << endl;
    cout << "doing same with \\n and 'flush'\n" << flush;
    cout << "ends:" << ends;
    cout << "text after 'ends'\n";
    int test_int = 1023;
    cout << hex;
    cout << test_int << '\n';
    cout << oct;
    cout << test_int << '\n';
    int test_input = 0;
    cin >> oct;
    cout << "Give me a(n octal) number: ";
    cin >> test_input;
    cout << dec;
    cout << "converted to decimal: ";
    cout << test_input << '\n';
    cout << hex;
    cout << "converted to hexadecimal: ";
    cout << test_input << '\n';
    return 0;
}
