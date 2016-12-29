#include <iostream>
#include <string>

using namespace std;

const int MAXSIZE = 10;

template<class T>
int transfer(T* from, T* to, int size) {
  for (int i = 0; i < size; i++)
    to[i] = from[i];
  return size;
}

// this one was needed to avoid error below (for transfer a to c):
// deduced conflicting types for parameter ‘T’ (‘int’ and ‘double’)
template<class T1, class T2>
int transfer(T1* from, T2* to, int size) {
  for (int i = 0; i < size; i++)
    to[i] = from[i];
  return size;
}

template<class T>
string print_elems(T* elems, int size = MAXSIZE) {
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

  for (int i = MAXSIZE-1, j=0; j < MAXSIZE; --i,++j) {
    a[j] = i;
  }
  for (int i = 0; i < MAXSIZE*2; ++i) {
    c[i] = static_cast<double>(i);
  }

  cout << "Content of a: " << print_elems(a) << '\n';
  cout << "Content of c: " << print_elems(c) << '\n';
  
  transfer(a, b, 10);
  cout << "b after a to b: " << print_elems(b) << '\n';
  transfer(c, d, 20);
  cout << "d after c to d: " << print_elems(d,MAXSIZE*2) << '\n';
  transfer(a, c, 10); // gives type deduction error if only class T exists
  cout << "c after a to c: " << print_elems(c,MAXSIZE*2) << '\n';
  return 0;
}
