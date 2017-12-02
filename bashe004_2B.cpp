//Csci 1113 HW 3
//Guled Bashe
//HW Problem 2B

#include <iostream>
#include <cmath>
using namespace std;

void GenGrowth();
void Doubling();
int main()
{
  //Variable holds which calculation the user wants to use
  char input;
  bool keepgoing; //boolean variable used to determine
	                // if the body of the indefinite loop
	                // below will be executed

	keepgoing = true;  //initially, we want to go into the while loop

	while (keepgoing)
  {  // indefinte loop, we don't know how many times the loop body will execute
		                 // when the condition is evaluated for the first time

		keepgoing = false; // assume that the user will enter a legal input value



    cout << "Welcome to the Program to Calculate Population Growth\n\n";

    cout << "Would you like to base your calculations on generations of growth or time and rate of doubling (Please Enter (G,g,T,or t): ";
    cin >> input;

    if ((input == 'G') || (input == 'g'))
    {
      GenGrowth();
    }
    else if((input == 'T') ||(input == 't') )
    {
      Doubling();
    }
    else
    {
      cout << "Error: Your selection: " << input << " is not recognized, please try again\n\n";
      keepgoing = true;
    }
  }

}



void GenGrowth()
{
  //Declare variables
  int initialpop; //size of initial population
  int offspring;  //number of offspring per parent
  int gen;  //generation whose population you would like to compute
  int growth; //population growth

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

void Doubling()
{
  double t, d, Nzero, n;
  cout << "Please enter the size of the initial population (Nzero): ";
  cin >> Nzero;
  cout << "Please enter the rate at which the population doubles (d): ";
  cin >> d;
  cout << "Please enter the amount of time used to compute the population(t): ";
  cin >> t;

  n = Nzero*pow(2, (t/d));

  cout << "The population after " << t << " time units at a doubling rate " << d << " per unit is: " << n << endl;

}
