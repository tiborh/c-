#include <iostream>
using namespace std;

//original
int sum0()
{
  int sum, i, j, k;
  for (sum = i = 0, j = 2, k = i + j; k < 10; i++, j++, k++)
    sum += (i < j) ? k : i;
  return sum;
}

//simplified
int sum1()
{
  int sum = 0;
  for (int k = 2; k < 10; k++)
    sum += k;
  return sum;
}

int main()
{
  
  cout << "sum0 == " << sum0() << endl;
  cout << "sum1 == " << sum1() << endl;

  return 0;
}
