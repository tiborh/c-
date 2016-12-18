//The following program com putes
//the probability for dice possibilities
#include  <iostream>   //drops .h still available
#include  <cstdlib>
#include  <ctime>

using namespace std;

int sides;
inline int r_sides(){ return (rand() % sides + 1); }

int main(void)
{
  cout << "\nNumber of sides: ";
  cin >> sides;
  
  int   n_dice;
  cout << "\nNumber of dice: ";
  cin >> n_dice;

  srand(clock());

  cout << "\nNumber of trials: ";
  int trials;
  cin >> trials;  //compare to scanf

  int* outcomes = new int[n_dice * sides +1];
  
  for (int j = 0; j < trials; ++j) {
    int sidesum = 0;
    for(int k = 0; k < n_dice; ++k)
      sidesum += r_sides();
    outcomes[sidesum]++;
  }

  cout << "probability\n";
  for (int j = n_dice; j < n_dice * sides + 1; ++j)
    cout << "j = " << j << " p = " 
	 << (static_cast<double>(outcomes[j])/trials) * 100
	 << "%"
	 << endl;

  return(0);
}

