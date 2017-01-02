#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstring>

using namespace std;

const int PROBRANGE = 100;

void help(const char* progname) {
  cout << "usage: " << progname
       << " <graph dimension>"
       << " [0 < probability value < 1.00]\n";
  exit(0);
}

bool prob(double probval=0.5) {
  assert(probval > 0 && probval < 1.00);
  int probint = static_cast<int>(probval*PROBRANGE);
  int randval = rand() % PROBRANGE;
  // cout << " probval: " << probval
  //      << " probint: " << probint
  //      << " randval: " << randval << '\n';
  return randval < probint ? true : false;
}

struct graph {
  graph(int s=10);
  void init(bool bv=false);
  void set(double d=0.5);
  int size() const { return gsize; }
  bool is_connected();
  friend ostream& operator<<(ostream&,const graph&);
private:
  vector<vector<bool>> gmatrix;
  int gsize;
};

graph::graph(int s):gsize(s) {
  srand(time(0));
  vector<vector<bool>> temp(s, vector<bool>(s));
  gmatrix = temp;
}

void graph::init(bool bv) {
  for (unsigned int i = 0; i < gmatrix.size(); ++i)
    for (unsigned int j = 0; j < gmatrix.at(i).size(); ++j)
      gmatrix[i][j] = bv;
}

void graph::set(double density) {
  for (unsigned int i = 0; i < gmatrix.size(); ++i)
    for (unsigned int j = 0; j < gmatrix.at(i).size(); ++j)
      if (i == j)
	gmatrix[i][j] = false;
      else
	gmatrix[i][j] = prob(density);
}

bool graph::is_connected() {
  // initialisation:
  int old_size = 0;
  int c_size = 0;
  vector<bool> close = vector<bool>(gsize,false);
  vector<bool> open = vector<bool>(gsize,false);

  open[0] = true;
  // add to close set:
  while(c_size < gsize) {
    for(int i = 0; i < gsize; ++i) {
      old_size = c_size;
      if (open[i] && (close[i] == false)) {
	close[i] = true;
	++c_size;
	// add to open set
	for (int j = 0; j < gsize; ++j)
	  open[j] = open[j] || gmatrix[i][j];
      }
    }
    if(c_size == gsize) return true;
    if(old_size == c_size) return false;
  }
  return false;
}

ostream& operator<<(ostream& os, const graph& gr) {
  os << "     ";
  for (int i = 0; i < gr.gsize; ++i)
    os << setw(2) << i << " ";
  os << '\n';
  for (int i = 0; i < gr.gsize; ++i) {
    os << setw(3) << i << ": ";
    for (int j = 0; j < gr.gsize; ++j) {
      //os << setw(5) << boolalpha << gr.gmatrix[i][j] << " ";
      os << setw(2) << gr.gmatrix[i][j] << " ";
    }
    os << '\n';
  }
  return os;
}

int main(int argc, char** argv) {
  double probval = 0.5;
  int readsuccess;
  graph a;
  if (argc > 2) {
    readsuccess = sscanf(argv[2],"%lf",&probval);
    if (readsuccess == 0) help(argv[0]);
    if (probval <= 0 || probval >= 1) help(argv[0]);
  }
  if (argc < 2) {
    help(argv[0]);
    a = graph();
  } else if (0 == strcmp(argv[1],"-h") ||
	   0 == strcmp(argv[1],"-help"))
    help(argv[0]);
  else {
    int gsize;
    sscanf(argv[1],"%d",&gsize);
    a = graph(gsize);
  }
  cout << "the generated graph:\n";
  cout << "size: " << a.size() << '\n';
  cout << a;
  cout << "init to true:\n";
  a.init(true);
  cout << a;
  cout << "set with probability: " << probval << '\n';
  a.set(probval);
  cout << a;
  cout << "is the graph connected? " << boolalpha << a.is_connected() << '\n';
  return 0;
}
