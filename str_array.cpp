#include <iostream>
#include <cstring>

using namespace std;

int main() {
  const int NUM_OF_DAYS = 7;
  const int LENGTH_OF_DAY = strlen("日曜日"); // UTF-8: each char is 3 bytes.

  char days[NUM_OF_DAYS][LENGTH_OF_DAY+1] = {"日曜日",
					     "月曜日",
					     "火曜日",
					     "水曜日",
					     "木曜日",
					     "金曜日",
					     "土曜日"}; // 2D array
  
  for (int i = 0; i < NUM_OF_DAYS; ++i)
    cout << "Day " << i << ": " << days[i] << endl;
  cout << "First element of the array: 0x" << hex << (int)days[0][0] << endl;
  cout << "The whole week:\n";
  for (int j = 0; j < NUM_OF_DAYS; ++j) {
    for (int i = 0; i < LENGTH_OF_DAY; ++i)
      cout << " " << hex << (int)days[j][i];
    cout << "\n";
  }
  cout << endl;
  
       
  return 0;
}

