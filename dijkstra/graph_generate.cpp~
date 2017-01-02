#include <iostream>
#include <iomanip>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

struct graph {
  graph(int s=10);
  ~graph();
  void init();
  int size() const { return gsize; }
  friend ostream& operator<<(ostream&,const graph&);
private:
  bool** gmatrix;
  int gsize;
};

graph::graph(int s):gsize(s) {
  gmatrix = new bool*[s];
  for(int i = 0; i < s; ++i)
    gmatrix[i] = new bool[s];
}

graph::~graph() {
  for (int i = 0; i < gsize; ++i)
    delete[] gmatrix[i];
  delete[] gmatrix; // to avoid double delete message
}

void graph::init() {
  for (int i = 0; i < gsize; ++i)
    for (int j = 0; j < gsize; ++j)
      gmatrix[i][j] = false;
}

ostream& operator<<(ostream& os, const graph& gr) {
  for (int i = 0; i < gr.gsize; ++i)
    os << setw(5) << i << " ";
  os << '\n';
  for (int i = 0; i < gr.gsize; ++i) {
    for (int j = 0; j < gr.gsize; ++j) {
      os << setw(5) << boolalpha << gr.gmatrix[i][j] << " ";
    }
    os << '\n';
  }
  return os;
}

int main(int argc, char** argv) {
  graph a;
  if (argc < 2) {
    cout << "help: " << argv[0] << " <graph dimension>\n";
    a = graph();
  } else {
    int gsize;
    sscanf(argv[1],"%d",&gsize);
    a = graph(gsize);
  }
  cout << "Uninitialised graph has been created\n";
  a.init();
  cout << "the generated graph:\n";
  cout << "size: " << a.size() << '\n';
  cout << a;
  
  return 0;
}
