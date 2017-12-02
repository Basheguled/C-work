//Csci 1113
//Guled bashe
//HW Problem 1B

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  //Declare variables
  int initialpop; //size of initial population
  int offspring;  //number of offspring per parent
  int gen;  //generation whose population you would like to compute
  int growth; //population growth

//Print message for program
  cout << "Welcome to the Program to Calculate Population Growth\n";
  cout << "Please enter the size of the initial population: ";
  cin >> initialpop;  //input for population

  cout << "Please enter the number of offspring per parent: ";
  cin >> offspring; //input for offspring

  cout << "Please enter the generation whose population you would like to compute: ";
  cin >> gen; //input for generation

  //Equation for population growth
  growth = initialpop * pow(offspring, gen);

  cout << "The population of generation: " << gen << " is: " << growth << endl;


}
