// reading a text file
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char** argv) {
  if (argc != 2) {
    cout << "\nUsage: " << argv[0]
	 << " infile" << endl;
    exit(1);
  }
  
  string line;
  ifstream myfile(argv[1]);
  if (myfile.is_open()) {
    while (getline (myfile,line))
      cout << line << '\n';
    myfile.close();
  } else cout << "Unable to open file\n"; 

  return 0;
}
