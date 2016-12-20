/*
 * computing probabilities with two dice
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIDES = 6;
const int N_DICE = 2;
const int OUTCOMES = SIDES * N_DICE;
const int LINELENGTH = 80;

inline int R_SIDE(void){ return (rand() % SIDES + 1); }

int get_nu_of_trials(void)
{
  cout << "\nEnter the number of trials: ";
  int trials = 0;
  cin >> trials;

  return trials;
}

int* make_trials(int trials)
{
  srand(clock());
  int* outcomes = new int[OUTCOMES];
  int d1,d2; d1 = d2 = 0;
  for(int j = 0; j < trials; j++)
    outcomes[(d1 = R_SIDE()) + (d2 = R_SIDE())]++;

  return outcomes;
}

void print_results(int trials, int* outcomes)
{
  cout << "Probabilities:\n";
  for(int j = 2; j < OUTCOMES+1; j++)
    cout << "j = " << j << " p = " << static_cast<double>(outcomes[j]) / trials * 100.0 << " %" << endl;
}

int main()
{
  /* get input */
  int trials = 0;
  if (0 == (trials = get_nu_of_trials()))
    return 0;

  /* roll the dice */
  int* outcomes = make_trials(trials);
  if (NULL == outcomes)
    {
      cout << "Cannot allocate enough space for outcomes. Exiting...";
      exit(1);
    }

  /* show results */
  print_results(trials,outcomes);

  /* cleanup */
  delete [] outcomes;

  return 0;
}
