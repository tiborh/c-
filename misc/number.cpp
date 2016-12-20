#include <iostream>
#include <cstdlib>
#include <cstdio>

#define MAX_WIDTH 64
#define DEBUG 0

int main(int argc, char **argv)
{
  long long int input_number = 0111; // binary number: 73 in decimal

  int collect[MAX_WIDTH];
  for (int i = 0; i < MAX_WIDTH; i++)
    collect[i] = -1;
  int last_array_index = 0;

  if (argc > 1)
    sscanf(argv[1], "%lld", &input_number);

  std::cout << input_number << " -> ";

  while (input_number > 0) {
    if (last_array_index == MAX_WIDTH) {
      std::cout << "number is too large\n";
      exit(1);
    }

    if (DEBUG)
      std::cout << input_number%2 << " ";

    collect[last_array_index++] = input_number%2;

    input_number>>=1;

    if (DEBUG)
      std::cout << input_number << "\n";
  }
  
  for (int i = last_array_index-1; i >= 0; i--)
    std::cout << collect[i];
  std::cout << "\n";

  return 0;
}
