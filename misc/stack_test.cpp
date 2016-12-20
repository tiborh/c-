#include "stack.h"
#include <iostream>
using namespace std;

int main() {
  const int N = 5;
  Stack<float> stk(N);

  for (int i = 0; i < N; i++)
    stk.push(i + 0.5);
  while (stk.size() > 0)
    cout << stk.pop() << ' ';
  cout << "\n";

  return 0;
}
