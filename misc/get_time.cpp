//#define __cplusplus 201103L // for c++11 but it does not help either
// get_time example
#include <iostream>     // std::cin, std::cout
#include <iomanip>      // std::get_time
#include <ctime>        // struct std::tm

int main ()
{
  struct std::tm when;
  std::cout << "Please, enter the time: ";
  std::cin >> std::get_time(&when,"%R");   // extract time (24H format)
  // get_time() does not work ing gcc 4.7: ‘get_time’ is not a member of ‘std’

  if (std::cin.fail()) std::cout << "Error reading time\n";
  else {
    std::cout << "The time entered is: ";
    std::cout << when.tm_hour << " hours and " << when.tm_min << " minutes\n";
  }

  return 0;
}
