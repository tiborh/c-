#include <iostream>
#include <vector>

using namespace std;

bool is_connected_old(bool *graph[], int size) {
  // initialisation:
  int old_size = 0;
  int c_size = 0;
  bool* close = new bool[size];
  bool* open = new bool[size];
  for(int i = 0; i < size; ++i)
    open[i] = close[i] = false;
  open[0] = true;
  // add to close set:
  while(c_size < size) {
    for(int i = 0; i < size; ++i) {
      old_size = c_size;
      if (open[i] && (close[i] == false)) {
	close[i] = true;
	++c_size;
	// add to open set
	for (int j = 0; j < size; ++j)
	  open[j] = open[j] || graph[i][j];
      }
    }
  }
  if(c_size == size) return true;
  if(old_size == c_size) return false;
  return false;
}

bool is_connected(vector<vector<bool>> graph) {
  // initialisation:
  int size = graph.size();
  int old_size = 0;
  int c_size = 0;
  vector<bool> close = vector<bool>(size,false);
  vector<bool> open = vector<bool>(size,false);

  open[0] = true;
  // add to close set:
  while(c_size < size) {
    for(int i = 0; i < size; ++i) {
      old_size = c_size;
      if (open[i] && (close[i] == false)) {
	close[i] = true;
	++c_size;
	// add to open set
	for (int j = 0; j < size; ++j)
	  open[j] = open[j] || graph[i][j];
      }
    }
  }
  if(c_size == size) return true;
  if(old_size == c_size) return false;
  return false;
}


int main() {

  return 0;
}
