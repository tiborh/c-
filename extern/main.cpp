#include <iostream>
#include <cstdlib>		// for atof

extern double circle(double);

void printout(double rad) {
    std::cout << circle(rad) << " is the area of a circle of radius " 
	<< rad << std::endl;
}

int main(int argc, char** argv) {
    double x = 0.0;
    std::cout << "argc: " << argc << std::endl;
    if (argc > 1) {
      const int LOOP_MAXNUM = argc - 1;
      for (int i = 0; i < LOOP_MAXNUM; ++i)
	printout(atof(argv[i+1]));
    } else
      printout(x);

    return 0;
}
