#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

long long int add_int_nums(int, char**);

int main(int argc, char **argv) {
  const int NUM_LENGTH = 64;
  // if there are no args, print help
  if (argc == 1) {
    cout << argv[0] << " -i\n";
    cout << "Interactive mode\n\n";
    cout << argv[0] << " <int1> <int2> ... <intN>\n";
    cout << "Returns the sum of the integers.\n";
    exit(1);
  } 

  // fill the value of argv[1] into an object for comparison
  string the_switch (argv[1]);
  long long int the_sum = 0;

  // if interactive mode, ask for two input nums
  if (the_switch.compare("-i") == 0) {
    cout << "Give two integers: ";
    char string1[NUM_LENGTH] = "interactive";
    char string2[NUM_LENGTH],string3[NUM_LENGTH];
    cin >> string2 >> string3;
    char *input_array[] = {string1, string2, string3};
    the_sum = add_int_nums(3,input_array);
  } else { // the addition part from program args
    the_sum = add_int_nums(argc,argv);
  }
  cout << "Sum: " << the_sum << "\n";

  return 0;
}

long long int add_int_nums(int array_length, char **in_array) {
  long long int the_sum = 0;
  int an_input = 0;

  for (int i=1; i < array_length; i++) {
    sscanf(in_array[i], "%d", &an_input);
    the_sum += an_input;
    an_input = 0;
  }

  return the_sum;
}
