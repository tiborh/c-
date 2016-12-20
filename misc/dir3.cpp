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
#include <string>
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

const char* check_file_type(unsigned char dtype)
{
  switch(dtype)
    {
    case DT_UNKNOWN:
      return "unknown";
    case DT_REG:
      return "regular";
    case DT_DIR:
      return "directory";
    case DT_FIFO:
      return "named_pipe";
    case DT_SOCK:
      return "socket";
    case DT_CHR:
      return "char_device";
    case DT_BLK:
      return "block_device";
    case DT_LNK:
      return "symlink";
    default:
      return "undef";
    }
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
  string curr_dir = ".";
  string up_dir = "..";

  do 
    {
      string elemname = direntry->d_name;
      cout << direntry->d_name << "\t<" << check_file_type(direntry->d_type) << ">\n";
      if (curr_dir != elemname.c_str() && up_dir != elemname.c_str())
	{
	  ++entry_count;
	  if (DT_DIR == direntry->d_type)
	      entry_count += dir(direntry->d_name);
	}
    } while((direntry = readdir(dp)));
  
  closedir(dp);

  return entry_count;
}

int main(int argc, char** argv)
{
  char* target = (argc < 2) ? pwd() : argv[1];
  int entrycount = dir(target);
  cout << entrycount << ((entrycount > 1) ? " files\n" : " file\n");
  //cout << "directory type: '" << dirinfo->d_type << "'\n";

return 0;
}
