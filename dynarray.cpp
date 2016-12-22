#include <iostream>
#include  <cstdlib>
#include  <ctime>

using namespace std;

int main() {
  const int MAGIC_NUM = 10;
  const int MIN_SIZE = 3;
  const int MAX_SIZE = MAGIC_NUM - MIN_SIZE;
  const int MAX_NUM = MAX_SIZE * MAGIC_NUM;
  srand(clock());
  const int ARRAY_SIZE = rand() % MAX_SIZE + MIN_SIZE + 1;

  int* data;
  data = new int[ARRAY_SIZE];

  for(int i = 0; i < ARRAY_SIZE; ++i)
    data[i] = rand() % MAX_NUM + 1;

  for(int i = 0; i < ARRAY_SIZE; ++i)
    cout << data[i] << " ";
  cout << endl;

  delete[] data;

  return 0;
}
