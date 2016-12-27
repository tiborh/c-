#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    cout << "ostream study: (this line has 'endl')" << endl;
    cout << "doing same with \\n and 'flush'\n" << flush;
    cout << "'ends' is flush only, no newline:" << ends;
    cout << "text after 'ends'\n";
    int test_int = 1023;
    cout << "starting with: " << test_int << '\n';
    cout << "in hex: " << hex << test_int << '\n';
    cout << "in oct: " << oct << test_int << '\n';
    int test_input = 0;
    cout << "Give me a(n octal) number: ";
    cin >> oct >> test_input;
    cout << "converted to decimal: " << dec << test_input << '\n';
    cout << "converted to hexadecimal: " << hex << test_input << '\n';
    cout << "in iostream, cout.put is used for chars: ";
    cout.put('a');
    cout.put('\n');
    cout << dec;
    cout << "and 'write' can be used to put out only a number of chars from a constant char array:\n";
    const char* temp_str = "the full text";
    cout << temp_str << '\n';
    // may not work perfectly with UTF8, having a hexadecimal at the end
    cout << "cout.write(temp_str, 5): '" << cout.write(temp_str, 5) << "'\n";
    cout << "cout.write(temp_str+2, 5): '" << cout.write(temp_str+2, 5) << "'\n";
    char* str_arr = new char[strlen(temp_str + 1)];
    strcpy(str_arr,temp_str);
    cout << "trying the same with dynamic array.\n";
    cout.flush();		// no use
    cout << "cout.write(temp_str, 5): '" << cout.write(str_arr, 5) << "'\n";
    cout << "cout.write(temp_str+2, 5): '" << cout.write(str_arr+2, 5) << "'\n";
    cout << "skip white space test.\n";
    cout << "enter string with white space front,middle,end: ";
    delete(str_arr);
    str_arr = new char[1024+1];
    //cin >> ws >> str_arr; // no visible effect
    cin >> str_arr;
    cout << "'" << str_arr << "' only the first non white space string segment is printed out.\n";
    return 0;
}
