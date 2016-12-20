#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool open_file(fstream& fh, const char* fn, const char* fm)
{
  ios::openmode fmode;
  int fmode_int = 0;

  for(unsigned int i = 0; i < strlen(fm); i++)
  switch(fm[i])
    {
    case 'r': fmode_int += ios::in; break;
    case 'w': fmode_int += ios::out; break;
    case 'a': fmode_int += ios::app; break; // use it with write
    case 't': fmode_int += ios::trunc; break; // use it with write
    case 'e': fmode_int += ios::ate; break; // use it with r (if used with write, it overwrites file)
    case 'b': fmode_int += ios::binary; break; // use it with r or w
    default:
      cerr << "Unknown fileopen mode:" << fm << "Exiting...\n";
      return false;
    }

  fmode = static_cast<ios::openmode>(fmode_int);
  fh.open(fn,fmode);
  if (fh.is_open())
    return true;
  else
    return false;
}
