#define __cplusplus 201103L // for c++11
//#define __cplusplus 199711L // for c++98 and c++03

#include <iostream>
//#include <algorithm>  // e.g. split
//#include <cassert> // assert()
//#include <climits> // e.g. INT_MAX
//#include <cmath>
#include <cstdio>
//#include <cstdlib> // e.g. for srand(time(NULL)) and rand()
#include <cstring> // e.g. for strlen
//#include <ctime>   // for time operation
//#include <deque>	       // double linked list
#include <dirent.h>
//#include <exception>
//#include <fstream> // file operations
//#include <functional> // for lambda
//#include <iomanip> // e.g. setw, setprecision, setfill, setbase
//#include <limits>  // e.g. numeric_limits<streamsize>::max()
//#include <list>
//#include <sstream> // stringstream
//#include <stack>  // for single-linked lists
//#include <string>
#include <sys/types.h> // for stat
#include <sys/stat.h> // for stat
//#include <typeinfo> // for typeid
#include <unistd.h>
//#include <vector>

using namespace std;

char *pwd()
{
  return get_current_dir_name();
}

bool is_dir(const char *fn)
{
  struct stat f_st;
  
  if (stat(fn, &f_st) == -1)
    {
      perror("stat");
      return 1;
    } 

  return (S_IFDIR == (f_st.st_mode & S_IFMT));
}

int dir(char *target)
{
  if (!is_dir(target))
    {
      cout << "Not a directory: " << target << '\n';
      return -1;
    }
  DIR *dp = opendir( target );
  if (dp == NULL) {
    cout << target << '\n';
    perror("opendir");
    return -1;
  }
  
  struct dirent *direntry = readdir(dp);
  int entry_count = 0;
  do 
    {
      ++entry_count;
      cout << direntry->d_name << '\n';
    } while((direntry = readdir(dp)));
  
  closedir(dp);

  return entry_count;
}

int main(int argc, char** argv)
{
  char* target = (argc < 2) ? pwd() : argv[1];
  int entrycount = dir(target);
  cout << entrycount << " file(s)\n";
  //cout << "directory type: '" << dirinfo->d_type << "'\n";

return 0;
}
