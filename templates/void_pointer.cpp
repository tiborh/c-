#include <iostream>
#include <string>

using namespace std;

const int MAXSIZE = 10;

int transfer(void* from, void* to,
	     int elementSize, int size) {
  int nBytes = size * elementSize;
  for (int i = 0; i < nBytes; i++)
    static_cast<char*>(to)[i] =
      static_cast<char*>(from)[i];
  return size;
}

string print_elems(int* elems, int size = MAXSIZE) {
  string os = string("");
  os.append("(");
  for (int i = 0; i < size; ++i) {
    os.append(to_string(elems[i]));
    os.append(i < (size-1) ? ", " : ") ");
  }
  return os;
}
string print_elems(double* elems, int size = MAXSIZE) {
  string os = string("");
  os.append("(");
  for (int i = 0; i < size; ++i) {
    os.append(to_string(elems[i]));
    os.append(i < (size-1) ? ", " : ") ");
  }
  return os;
}

using namespace std;

int main() {
  int a[MAXSIZE], b[MAXSIZE];
  double c[MAXSIZE*2], d[MAXSIZE*2];

  int i = 0;
  for (; i < MAXSIZE; ++i) {
    a[i] = i;
    c[i] = static_cast<double>(i);
  }
  for (; i < MAXSIZE*2; ++i) {
    c[i] = static_cast<double>(i);
  }

  cout << "Content of a: " << print_elems(a) << '\n';
  cout << "Content of c: " << print_elems(c) << '\n';
  
  transfer(a, b, sizeof(int), 10);
  cout << "b after a to b: " << print_elems(b) << '\n';
  transfer(c, d, sizeof(double), 20);
  cout << "d after c to d: " << print_elems(d,MAXSIZE*2) << '\n';
  transfer(a, c, sizeof(int), 10); // system-dependent results
  cout << "c after a to c: " << print_elems(c,MAXSIZE*2) << '\n';
  return 0;
}
