#include "file_utils.hpp"
#include <iostream>

using namespace std;

inline bool file_exists (const char* fn) {
    if (FILE *file = fopen(fn, "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

long file_size(const char* fn) {
    struct stat stat_buf;
    int rc = stat(fn, &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

vector<vector<unsigned int>> read_file(const char* fn) {
  cout << "Reading input file: " << fn << '\n';
  assert(file_exists(fn));
  assert(file_size(fn) > 0);
  ifstream infile(fn);
  unsigned int num_of_nodes = 0;
  string line;
  getline(infile, line);
  // anonymous block:
  {
    istringstream iss(line);
    if (!(iss >> num_of_nodes)) {
      cout << "Reading number of points has failed.";
      exit(1);
    }
  }
  assert(num_of_nodes > 0);
  //cout << "number of points: " << num_of_nodes << '\n';
  vector<vector<unsigned int>> connections;
  vector<unsigned int> the_num = {num_of_nodes,num_of_nodes};
  connections.push_back(the_num);
  while (std::getline(infile, line)) {
    istringstream iss(line);
    unsigned int from,to;
    if (!(iss >> from >> to)) {
      cout << "Reading route has failed in: " << line;
      exit(1);
    }
    assert(from < num_of_nodes && to < num_of_nodes);
    //cout << "from " << from << " to " << to << '\n';
    vector<unsigned int> from_to = {from,to};
    connections.push_back(from_to);
  }
  cout << "Number of nodes: " << num_of_nodes << '\n';
  cout << "Number of lines read: " << connections.size()-1 << '\n';  
  return connections;
}
