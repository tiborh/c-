//#include <consoleoutput>
#include <iostream>

int main()
{
  //  cout>>"Program to find area of a trapezium: ";
  std::cout << "Program to find area of a trapezium: ";
  int a,b,h;
  float area;
  // cout<<"Enter lengths of parallel sides a and b, and height:";
  std::cout << "Enter lengths of parallel sides a and b, and height:";
  //cin>>a>>b>>h;
  std::cin >> a >> b >> h;
  area = (h/2)*(a+b);
  //cout<<"The area is "<<area;
  std::cout << "The area is " << area;

  return 0;
}
