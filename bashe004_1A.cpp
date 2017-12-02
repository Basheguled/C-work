//Csci 1113 Hw1
//Guled bashe
//HW Problem 1A

#include <iostream>
using namespace std;

int main()
{
  double humidity;
  double temp;
  double hIndex;

//Print what the program is
  cout << "Welcome to the Program to Calculate the Heat Index\n\n";
  cout << "Please enter the temperature in degrees Farenheit: ";
  cin >> temp;  //Input for temperature

  cout << "\nPlease enter the relative humidity: ";
  cin >> humidity;  //Input for humidity

  //Equation for calculating heat index
  hIndex = 0.5*(temp + 61.0 + ((temp - 68.0)*1.2) + (humidity * 0.094));

  cout << "\n\nThe Heat Index is: " << hIndex;  //print out final heat index
  cout << "\n\n";

}
