#include <iostream>
#include <fstream>
#include <iterator>
#include <numeric>		// accumulate
#include <cstdlib>		// random
#include <ctime>		// to seed random
#include <sys/stat.h>

inline bool file_exists (const char* name) {
    if (FILE *file = fopen(name, "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

long file_size(std::string filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

using namespace std;

void fill_file(const char* fn,int num_of_dat = 100) {
  srand((unsigned)time(0));
  ofstream outfile;
  outfile.open (fn);
  for (int i = 0; i < num_of_dat; ++i)
    outfile << rand() % (num_of_dat*10) << '\n';
  outfile.close();  
}


int main() {
  const char* fn = "accumulate.dat";
  if (!(file_exists(fn) && file_size(fn) > 0))
    fill_file(fn);

  ifstream in_file(fn);
  istream_iterator<unsigned long long> in(in_file);
  istream_iterator<unsigned long long> eos;
  cout << "Sum of data is "
       << accumulate(in,eos,0) << '\n';
  
  return 0;
}
