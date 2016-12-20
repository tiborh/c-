#include <iostream>
#include <limits>
#include <climits>

#define MAXLEN 80

using namespace std;

void clearstr(char* instr)
{
  for(int i = 0; i < MAXLEN; ++i)
    *(instr+i) = '\0';
}

template <class TYPE = int> // a default type is given to avoid unused parameter
TYPE get_num(TYPE test = {})
{
  int bad_input;
  TYPE retnum;
  do{
    bad_input=0;
    cin >> retnum;
    if(!cin)
      {
	bad_input=1;
	cin.clear();		// clear the fail bit
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); // clear the bad input
      }
  }while(bad_input);
  cin.ignore(numeric_limits<streamsize>::max(),'\n'); // clear everything unneeded after the valid input

  return retnum;
}

int main()
{
  cout << "The usage if cin\n";
  cout << "Input an integer: ";
  long long int an_int = 0; 
  an_int = get_num();
  cout << "Read: " << an_int << endl;

  cout << "Input a double: ";
  long double a_dbl = 0.0;
  a_dbl = get_num();
  cout << "Read: " << a_dbl << endl;

  cout << "Enter a char: ";
  char c1;
  c1 = '\0';			// otherwise: error: ‘c1’ may be used uninitialized in this function
  c1 = get_num();

  char c2;
  cout << "Enter another char (cin.get()): ";
  cin.get(c2);
  cin.ignore(INT_MAX,'\n');
  cout << "Read: " << c1 << " " << c2 << endl;

  cout << "Enter a string: ";
  char a_str[MAXLEN] = {};
  cin >> a_str;			// read only up to the first white space
  cin.ignore(INT_MAX,'\n');
  cout << "Read: " << a_str << endl;

  cout << "Enter another string: ";
  clearstr(a_str);
  cin.get(a_str,MAXLEN,'\n');	// white space is not a problem, 3rd is optional
  cin.ignore(INT_MAX,'\n');	// in case its longer than maxlen
  cout << "Read: " << a_str << endl;
  
  cout << "Enter yet another string (getline): ";
  clearstr(a_str);
  cin.getline(a_str,MAXLEN,'\n');
  //cin.ignore(INT_MAX,'\n');	// if previous one does not overflow, a second ENTER is also needed
  cout << "Read: " << a_str << endl;

  cout << "And a last (multiline) string (ENTER and then ctrl-d to end): ";
  clearstr(a_str);		// without this, remaining junk is also printed
  cin.read(a_str,MAXLEN);	// does not seem to close the string with '\0'
  //cin.ignore(INT_MAX,'\n');
  cout << "Read: " << a_str << endl;

  return 0;
}
