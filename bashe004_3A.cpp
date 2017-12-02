//Csci 1113 HW 3
//Guled Bashe
//HW Problem 3A
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int seed; //variable declaration
double d;
double n;
double RollDie(); // function declaration
int main()
{

  char x = 'y';
  cout << "Input the random seed: ";  //input random seed
  cin >> seed;
  if (seed <= 0) // if seed is not positive, print error message and make seed = 246
  {
    cout << "Error: you should have entered a positive number. Your seed value is 246." << endl;;
    seed = 246;
  }
  else
  {
    srand(seed);
  }
  srand(time(NULL));
  do
  {
    cout << "Input the difference: ";
    cin >> d;

    cout << "       avg1      avg2" << endl; //set up headers for avg's
    cout << "       ----      ----" << endl;

    RollDie(); // call roll die function

    cout << "Enter 'Y' or 'y' to repeat this process: "; // ask user if they want to continue
    cin >> x;
  }
  while (x == 'Y' || x == 'y');
}


double RollDie()
{
  double s, t;  //variable declaration and initialization
  double tempS = 0;
  double tempT = 0;
  int counter = 1;
  int x = 0;
  int difference = 0;
  while (x < 10)  //while loop for the 10 averages
  {
    for (counter = 1; counter < 101; counter++) //for loop for the 100 rolls
    {
      s = rand() % 8 + 1; //generate random roll and store values
      t = rand() % 8 + 1;
      tempS += s; // store value in a temporary variables
      tempT = tempT + t;
    }
    cout << x+1 << ".     " << setprecision (2) << fixed << tempS/100;//prints averages
    cout << "     " << setprecision (2) << fixed << tempT/100 << endl;
    if(abs(tempT - tempS > d)) //checks difference between rolls
    {
      difference += 1;
    }
    tempS = 0;
    tempT = 0;
    x++;
  }
  cout << "Number of times when difference is larger than: " << d << " is: " << difference << endl;

  return 0;
}
