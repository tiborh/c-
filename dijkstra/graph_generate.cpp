#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

using namespace std;

const int MATRIX_SIZE = 10;
const int PROBRANGE = 100;
const int MAX_EDGE_WEIGHT = 30;
const bool DEFAULT_BOOL = false;
const double DEFAULT_PROBABILITY = 0.5;
const char* DEFAULT_FILE_NAME = "graph_generate.txt";
const char DEFAULT_DATA_SEP = ' ';

void help(const char* progname) {
  cout << "usage: " << progname
       << " <graph dimension>"
       << " [0 < probability value < 1.00]"
       << " [maximum weight of edges > 0]"
       << " [output filename]\n";
  exit(0);
}

bool prob(double probval=DEFAULT_PROBABILITY) {
  assert(probval > 0 && probval < 1.00);
  int probint = static_cast<int>(probval*PROBRANGE);
  int randval = rand() % PROBRANGE;
  return randval < probint ? true : false;
}

class graph {
public:
  graph(int s=MATRIX_SIZE);
  void init(bool default_val=DEFAULT_BOOL, int max_weight = MAX_EDGE_WEIGHT);
  void set(double d=DEFAULT_PROBABILITY);
  int size() const { return gsize; }
  bool is_connected() const;
  void to_file(string);
  friend ostream& operator<<(ostream&,const graph&);
protected:
  vector<vector<bool>> bmatrix;	// boolean matrix
  vector<vector<int>> wmatrix;	// weight matrix
  void init_bool(bool bv);
  void init_weights(int max);
private:
  int gsize;
};

graph::graph(int s):gsize(s) {
  srand(time(0));
  vector<vector<bool>> btemp(s, vector<bool>(s));
  vector<vector<int>> wtemp(s, vector<int>(s));
  bmatrix = btemp;
  wmatrix = wtemp;
}

void graph::init_bool(bool bv) {
  for (unsigned int i = 0; i < bmatrix.size(); ++i)
    for (unsigned int j = 0; j < bmatrix.at(i).size(); ++j)
      bmatrix[i][j] = bv;
}

void graph::init_weights(int max) {
  for (unsigned int i = 0; i < wmatrix.size(); ++i)
    for (unsigned int j = 0; j < wmatrix.at(i).size(); ++j) {
      if (i == j)
	wmatrix[i][j] = 0;
      else
	wmatrix[i][j] = (rand() % max)+1;
    }
}

void graph::init(bool default_val, int max_weight) {
  init_bool(default_val);
  init_weights(max_weight);
}

void graph::set(double density) {
  for (unsigned int i = 0; i < bmatrix.size(); ++i)
    for (unsigned int j = 0; j < bmatrix.at(i).size(); ++j)
      if (i == j)
	bmatrix[i][j] = false;
      else {
	bmatrix[i][j] = prob(density);
	if (i != j && !bmatrix[i][j])
	  wmatrix[i][j] = -1;
      }
}

bool graph::is_connected() const {
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
	  open[j] = open[j] || bmatrix[i][j];
      }
    }
    if(c_size == gsize) return true;
    if(old_size == c_size) return false;
  }
  return false;
}

ostream& operator<<(ostream& os, const graph& gr) {
  os << "connections:\n";
  os << "     ";
  for (int i = 0; i < gr.gsize; ++i)
    os << setw(2) << i << " ";
  os << '\n';
  for (int i = 0; i < gr.gsize; ++i) {
    os << setw(3) << i << ": ";
    for (int j = 0; j < gr.gsize; ++j) {
      //os << setw(5) << boolalpha << gr.bmatrix[i][j] << " ";
      os << setw(2) << noboolalpha << gr.bmatrix[i][j] << " ";
    }
    os << '\n';
  }
  os << "\nweights:\n";
  os << "     ";
  for (int i = 0; i < gr.gsize; ++i)
    os << setw(2) << i << " ";
  os << '\n';
  for (int i = 0; i < gr.gsize; ++i) {
    os << setw(3) << i << ": ";
    for (int j = 0; j < gr.gsize; ++j) {
      os << setw(2) << noboolalpha << gr.wmatrix[i][j] << " ";
    }
    os << '\n';
  }
  return os;
}

void graph::to_file(string fn) {
  cout << "out filename: " << fn << '\n';
  ofstream outfile(fn.c_str());
  outfile << gsize << '\n';
  for (unsigned int i = 0; i < bmatrix.size(); ++i)
    for (unsigned int j = 0; j < bmatrix.at(i).size(); ++j)
      if (bmatrix[i][j])
	outfile << i << DEFAULT_DATA_SEP << j << DEFAULT_DATA_SEP << wmatrix[i][j] << '\n';
  outfile.close();
}

class bigraph: public graph {
public:
  bigraph(int s=MATRIX_SIZE): graph(s) {}
  void set(double d=DEFAULT_PROBABILITY);
};

void bigraph::set(double d) {
  graph::set(d);
  for (unsigned int i = 0; i < bmatrix.size(); ++i)
    for (unsigned int j = i; j < bmatrix.at(i).size(); ++j) {
      bmatrix[i][j] = bmatrix[j][i];
      wmatrix[i][j] = wmatrix[j][i];
    }
}

int main(int argc, char** argv) {
  double probval = DEFAULT_PROBABILITY;
  int readsuccess,max_weight=MAX_EDGE_WEIGHT;
  string fn = (argc > 4) ? string(argv[4]) : string(DEFAULT_FILE_NAME);
  graph a;
  bigraph b;
  
  if (argc > 3) {
    readsuccess = sscanf(argv[3],"%d",&max_weight);
    if (readsuccess == 0 || max_weight <= 0) help(argv[0]);
  }
  if (argc > 2) {
    readsuccess = sscanf(argv[2],"%lf",&probval);
    if (readsuccess == 0) help(argv[0]);
    if (probval <= 0 || probval >= 1) help(argv[0]);
  }
  if (argc < 2) {
    help(argv[0]);
    a = graph();
    b = bigraph();
  } else if (0 == strcmp(argv[1],"-h") ||
	   0 == strcmp(argv[1],"-help"))
    help(argv[0]);
  else {
    int gsize;
    sscanf(argv[1],"%d",&gsize);
    a = graph(gsize);
    b = bigraph(gsize);
  }
  cout << "the generated graph:\n";
  cout << "size: " << a.size() << '\n';
  cout << a;
  cout << "init to true:\n";
  a.init(true,max_weight);
  cout << a;
  cout << "set with probability: " << probval << '\n';
  a.set(probval);
  cout << a;
  cout << "is the graph connected? (only bigraph connectedness is examined) " << boolalpha << a.is_connected() << '\n';
  //a.to_file(fn);

  cout << "\nsame with a bigraph:\n";
  b.init(DEFAULT_BOOL,max_weight);
  b.set(probval);
  cout << b;
  cout << "is the bigraph connected? " << boolalpha << b.is_connected() << '\n';
  b.to_file(fn);
  
  return 0;
}
