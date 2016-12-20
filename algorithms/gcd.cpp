#include <iostream>
#include <cstdio>
using namespace std;

void swap(int& n1, int& n2)
{
  int temp = n1;
  n1 = n2;
  n2 = temp;
}

int gcd(int n1, int n2)
{
  if (0 == n1 * n2)
    {
      char errorstr[128];
      sprintf(errorstr,"None of the numbers can be zero (%d,%d)\n",n1,n2);
      throw errorstr;
    }

  if (n1 < n2)
    swap(n1,n2);
  int remainder;

  while(n2 != 0)
    {
      remainder = n1 % n2;
      n1 = n2;
      n2 = remainder;
    }
  return n1;
}

int gcd1(int n1, int n2)
{
  if (0 == n1 * n2)
      throw "None of the numbers can be zero\n";

  if (n1 < n2)
    swap(n1,n2);

  int remainder;

  for(;n2 != 0;remainder = n1 % n2,n1 = n2,n2 = remainder);

  return n1;
}


int main()
{
  int n1, n2;
  n1 = n2 = 0;

  cout << "\nProgram gcd in C++";
  do {
    cout << "\nEnter two integers (if equal, end of program): ";
    cin >> n1 >> n2;
    try
      {
	cout << "\ngcd(" << n1 << ", " << n2 << ") = " << gcd1(n1,n2) << endl;
      }
    catch (char const* e)
      {
	cerr << "wrong input number\n";
	cerr << e;
	return 1;
      }
  }while (n1 != n2);

  return 0;
}
