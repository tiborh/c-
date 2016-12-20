#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;		// This is the price of generic: you cannot use "using namespace std"

template<class T>
T sum_array(T data[], int size)
{
  T sum = 0;
  for (int i = 1; i < size; i++)
    {
      cout << data[i] << endl;
      sum += data[i];
    }

  cout << "The sum of the numbers: " << sum << ".\n";

  return sum;
}


int main() {
  int sampleint[] = {1, 4, 5, 7, 97, 24};
  float samplefl[] = {12.3, 54.6547, 0.25, -12.56, 5.1236, 0.0003};
  string samplestr[] = {"a", "so", "lap", "passing", "goon", "navigate"};
  int length = 6;
  cout << sum_array(sampleint,length) << endl;
  cout << sum_array(samplefl,length) << endl;
  cout << sum_array(samplestr,length) << endl; // error

  return 0;
}
