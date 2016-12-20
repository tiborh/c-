#include <iostream>
#include <unistd.h> // for f_stat and getcwd
#include <sys/types.h> // for f_stat
#include <sys/stat.h> // for f_stat
#include <cstdio> // for perror
#include <fstream>

using namespace std;

int f_stat(const char* fn)
{
    struct stat f_st;

    if (stat(fn, &f_st) == -1)
    {
        perror("stat");
        return 1;
    }

    clog << "\tFile type:                ";

    switch (f_st.st_mode & S_IFMT) {
    case S_IFBLK:  clog << "block device\n";            break;
    case S_IFCHR:  clog << "character device\n";        break;
    case S_IFDIR:  clog << "directory\n";               break;
    case S_IFIFO:  clog << "FIFO/pipe\n";               break;
    case S_IFLNK:  clog << "symlink\n";                 break;
    case S_IFREG:  clog << "regular file\n";            break;
    case S_IFSOCK: clog << "socket\n";                  break;
    default:       clog << "unknown?\n";                break;
    }

    clog << "\tI-node number:            " << f_st.st_ino << "\n";
    clog << "\tMode:                     " << oct << f_st.st_mode << "\n";
    clog << "\tLink count:               " << f_st.st_nlink << "\n";
    clog << "\tOwnership:                UID=" << f_st.st_uid
                                  << "   GID=" << f_st.st_gid << "\n";
    clog << "\tPreferred I/O block size: " << f_st.st_blksize << "\n";
    clog << "\tFile size:                " << f_st.st_size << "\n";
    clog << "\tBlocks allocated:         " << f_st.st_blocks << "\n";
    clog << "\tLast status change:       " << ctime(&f_st.st_ctime) << "\n";;
    clog << "\tLast file access:         " << ctime(&f_st.st_atime) << "\n";;
    clog << "\tLast file modification:   " << ctime(&f_st.st_mtime) << "\n";;

    return 0;
}

int check_flags(const fstream& fh)
{
  int status = 0;
  //cout << "file is:\n";
  if (fh.good())
      status+=16;
  if (fh.bad())
      status+=2;
  if (fh.fail())
      status+=4;
  if (fh.eof())
      status+=8;
  if (0 == status)
      status = -1;

  return status;
}
