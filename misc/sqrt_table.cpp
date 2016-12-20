#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

inline void argument_tester(int argc)
{
  if (argc < 2)
    {
      cout << "Give the number of rows.\n";
      throw "Not enough arguments.";
    }
}

int test_input(char** argv)
{
  int lines = 0;
  istringstream ss(argv[1]);
  if (!(ss >> lines))
    throw "Invalid number: " + static_cast<string>(argv[1]);
  return lines;
}

int main(int argc, char** argv)
{
  int i_width = 0;
  int isq_wth = 8;
  int sqrt_wh = 12;
  int icb_wth = 12;
  string colsep = "   ";

  try
    {
      argument_tester(argc);
    }
  catch (char* e)
    {
      cerr << e << endl;
      return 1;
    }
  int lines = 0;
  try
    {
      lines = test_input(argv);
    }
  catch (string e)
    {
      cerr << e << endl;
      return 1;
    }
  i_width = log10(lines)+1;


  //heading
  cout << setw(i_width) << left << "i" 
       << colsep
       << setw(isq_wth) << right << "i * i" 
       << colsep
       << setw(sqrt_wh) << left << "square root" 
       << colsep
       << setw(icb_wth) << right << "i * i * i"
       << endl;
  //headsep
  for (int i = 0; i < i_width + isq_wth + sqrt_wh + icb_wth + 3 * colsep.length(); i++)
    cout << "-";
  cout << "\n";
 
  for(int i = 0; i < lines; i++)
    cout << setw(i_width) << right << i
	 << colsep
	 << setw(isq_wth) << right << i * i
	 << colsep
	 << fixed << setprecision(5) << sqrt(i) 
	 << colsep
	 << setw(icb_wth) << right << i * i * i
	 << endl;

  return 0;
}
