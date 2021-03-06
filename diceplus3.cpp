//The following program com putes
//the probability for dice possibilities
#include  <iostream>   //drops .h still available
#include  <random>
#include  <ctime>

using namespace std;

int main(void)
{
  int sides;
  cout << "\nNumber of sides: ";
  cin >> sides;
  
  int   n_dice;
  cout << "\nNumber of throwables: ";
  cin >> n_dice;

  uniform_int_distribution<unsigned> u(1,sides);
  default_random_engine e(time(0));

  cout << "\nNumber of trials: ";
  int trials;
  cin >> trials;
  int* outcomes = new int[n_dice * sides +1];
  
  for (int j = 0; j < trials; ++j) {
    int sidesum = 0;
    for(int k = 0; k < n_dice; ++k)
      sidesum += u(e);
    outcomes[sidesum]++;
  }

  cout << "probability\n";
  for (int j = n_dice; j < n_dice * sides + 1; ++j)
    cout << "j = " << j << " p = " 
	 << (static_cast<double>(outcomes[j])/trials) * 100
	 << "%"
	 << endl;

  delete(outcomes);
  
  return(0);
}
