#pragma once

#include <iostream>
#include <vector>		// for most common array substitute
#include <string>		// for c++ string
#include <fstream>		// for file operations

class Blank {
public:
  friend std::ostream& operator<<(std::ostream& os, const Blank& bl);

protected:

private:

};

// Local Variables:
// mode: c++
// End:
