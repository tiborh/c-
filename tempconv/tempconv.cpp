#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <sstream>

using namespace std;

int f2c(int f)
{
  return int(ceil(((double(f) - 32.0) * 5 / 9) - 0.5));
}

int c2f(int c)
{
  return int(ceil((double(c) * 9 / 5 + 32.0) - 0.5));
}

void drawline()
{
  for (int i = 0; i < 11; ++i)
    cout << '-';
  cout << '\n';
}

void drawtable(int func(int))
{
  for(int i = -30; i < 101; i+=10)
    cout << setw(3) << right << i << '\t' << setw(3) << right << func(i) << '\n';
}

int ftable(int n)		// input and output are not used
{
  cout << " F " << '\t' << " C\n";
  drawline();
  drawtable(&f2c);

  return 0;
}

int ctable(int n)		// input and output are not used
{
  cout << " C " << '\t' << " F\n";
  drawline();
  drawtable(&c2f);

  return 0;
}

void usage()
{
  cout << "Use c2f cels1 [cels2 ...] or f2c fahr1 [fahr2 ...]\n";
}

int main(int argc, char** argv)
{
  string progcalled = argv[0];
  string convtype = "";

  typedef int (*FuncPointer)(int); // function pointer type
  map<string,FuncPointer> fp;
  fp.insert(make_pair("f2c",&f2c)); 
  fp.insert(make_pair("c2f",&c2f)); 
  fp.insert(make_pair("ftable",&ftable));
  fp.insert(make_pair("ctable",&ctable)); 

  if (progcalled.rfind("f2c") != string::npos)
    {
      cout << "Fahrenheit to Celsius converter:\n";
      convtype = "f2c";
    }
  else if (progcalled.rfind("c2f") != string::npos)
    {
      cout << "Celsius to Fahrenheit converter:\n";
      convtype = "c2f";
    }
  else if (progcalled.rfind("ftable") != string::npos)
    {
      return ftable(0);
    }
  else if (progcalled.rfind("ctable") != string::npos)
    {
      return ctable(0);
    }
  else if  (progcalled.rfind("tempconv") != string::npos)
    {
      cout << "Converter between Fahrenheit and Celsius\n";
      usage();
      return 0;
    }
  else
    {
      cout << "Unknown conversion type. \"" << argv[0] << "\" Exiting...\n";
      return 1;
    }

  if (argc < 2)
    {
      cout << "No temperature value has been given.\n";
      return 0;
    }

  for(int i = 1; i < argc; ++i)
    {
      int input_number;
      stringstream(argv[i]) >> input_number;
      cout << argv[i] << " => ";
      cout << fp[convtype](input_number) << endl;
    }

  return 0;
}
