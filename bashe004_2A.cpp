//Csci 1113 HW 2
//Guled Bashe
//HW Problem 2A

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double RH, T, HI, P, A1, A2;
void hIndex();
//int constraints();
// Function Calculates Heat Index
void hIndex()
{


  //return constraints();
  //Equation for calculating heat index
  HI = 0.5*(T + 61.0 + ((T - 68.0)*1.2) + (RH * 0.094));

  if (HI > 80.00)
  {
    HI =  -42.379 + 2.04901523 * T + 10.14333127 * RH - .22475541 * T * RH - .00683783 *T * T - .05481717 *RH * RH + .00122874 * T * T * RH + .00085282 * T * RH * RH - .00000199 * T * T * RH * RH;

    if ((RH < 13) && (80 <= T) && (112 >= T))
    {
      A1 = ( (13 - RH) / 4 ) * sqrt( (17 - fabs(T - 95.0) ) / 17 );
      HI = HI - A1;
    }

    else if ((RH > 85) && (80 <= T) && (88 >= T))
    {
      A2 = ( (RH - 85) / 10 ) * ( (87 - T) / 5);
      HI = HI + A2;
    }
  }

  cout << "\n\nThe Heat Index is: " << setprecision (P) << fixed << HI;  //print out final heat index
  cout << "\n\n";

}

int main () {

	bool keepgoing; //boolean variable used to determine
	                // if the body of the indefinite loop
	                // below will be executed

	keepgoing = true;  //initially, we want to go into the while loop

	while (keepgoing) {  // indefinte loop, we don't know how many times the loop body will execute
		                 // when the condition is evaluated for the first time

		keepgoing = false; // assume that the user will enter a legal input value

    //Print what the program is
    cout << "Welcome to the Program to Calculate the Heat Index\n\n";
    cout << "Please enter the temperature in degrees Farenheit: ";
    cin >> T;  //Input for temperature

    cout << "\nPlease enter the relative humidity: ";
    cin >> RH;  //Input for humidity

    cout << "\nEnter the number of digits to display after a decimal point: ";
    cin >> P;

    if ( ((-200) > T) || (212 < T))
      {
        cout << "\nError Temperature " << T << ": Must be in the range -200.0 to 212.0\n";
        keepgoing = true;
      }
   if ((0 > RH) || (100 < RH) )
      {
        cout << "Error Relative humidity " << RH << ": Must be in the range 0.0 to 100.0\n";
        keepgoing = true;
      }
    if ((0 > P) || (10 < P))
      {
        cout << "Error Precision " << P << ": Must be in range 0 to 10\n\n";
        keepgoing = true;
      }
	}

  hIndex();

	return 0;
}








//Function reads values and verifies they fit the constraints.
/*int constraints()
{
  while ( ((-200) > T) || (212 < T))
    {
      cout << "Error Temperature " << T << ": Must be in the range -200.0 to 212.0\n";
      break;
    }
  while ((0 > RH) || (100 > RH) )
    {
      cout << "Error Relative humidity " << RH << ": Must be in the range 0.0 to 100.0\n";
      break;
    }
  while ((0 > P) || (10 < P))
    {
      cout << "Error Precision " << P << ": Must be in range 0 to 10\n";
      break;
    }

}*/
