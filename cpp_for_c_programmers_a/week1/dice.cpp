// Dice Probabilty in C++
// Dalton Hall
// August 1st, 2021

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int sides = 6;
inline int r_sides() { return (rand() % sides + 1); }

int main()
{
  const int n_dice = 2;
  int trials;
  int *outcomes = new int[n_dice * sides + 1]; // n_dice * sides + 1 = 13 to populate outcomes 1-12

  srand(clock()); // set random seed

  cout << "\nEnter number of trials: ";
  cin >> trials;

  for (int j = 0; j < trials; ++j)
  {
    outcomes[r_sides() + r_sides()]++; // if r_sides() = 2 and r_sides() = 5, add to outcomes at 7 and increment count;
  }

  cout << "\nProbability\n";
  for (int j = 2; j < n_dice * sides + 1; ++j) // start at 2, since outcomes of 0 and 1 are impossible
  {
    cout << "j = " << j
    << " p = " << static_cast<double>(outcomes[j]) / trials
    << endl;
  }

  cout << endl;

  return 0;
}