// get_money manipulator example
#include <iostream>     // std::cin, std::cout
#include <iomanip>      // std::get_money

int main ()
{
  long double price;
  std::cout << "Please, enter the price: ";
  std::cin >> std::get_money(price);

  if (std::cin.fail()) std::cout << "Error reading price\n";
  else std::cout << std::setprecision(2) << "The price entered is: " << std::put_money(price) << '\n'; //very limited usability: handles it as integer, decimals are cut, currency symbols are not handled.
  //  std::cout << "Price: " << std::put_money(10.50L) << '\n'; // same poor results

  return 0;
}
