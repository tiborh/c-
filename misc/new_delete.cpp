#include <iostream>
using namespace std;

int main() {

  const int DEFAULT_VAL = 7;

  int* ip = new int(DEFAULT_VAL); // integer initialised to DEFAULT_VAL
  cout << *ip << endl;
  delete ip;

  const int SIZE = 10;

  int *iap = new int[10];	/* ip cannot be reused:
				 * error: redeclaration of ‘int* ip’ */
  for(int i = 0; i < SIZE; i++)
    cout << *(iap + i) << endl;	// initialised to zero
  delete [] iap;

  return 0;
}
