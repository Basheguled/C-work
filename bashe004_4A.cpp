//Csci 1113 HW 4
//Guled Bashe
//HW Problem 4A

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI = 3.14159265;
double inputCheck(double& tolerance); //declare functions
double factorial(double n);
int main()
{
  char a = 'y';//holds value for continuing the function
  double x, actual, fin, tolerance, n;
  cout << "Welcome to the program to compute sin(x)\n\n"; //Welcome
  while (a == 'y' || a == 'Y')
    {
      cout << "Enter x: "; //input for x
      cin >> x;
      x = x*(PI / 180); //change x to radians
      inputCheck(tolerance); //call inputCheck for the tolerance
      actual = sin(x);
      n = 1;
      double fac = factorial(2*n+1); //value to hold factorial values
      fin = x + pow((-1), n) * (pow(x, (2*n+1))/fac); //first value of
      for(n = 2; abs(actual-fin) > tolerance*0.1; n++)//test against the power series value for sin(x)
      {
        fac = factorial(2*n+1);
        fin = fin + pow((-1), n) * (pow(x, (2*n+1))/fac); //runs until the precision is met
      }
      //Prints out the final value
      cout << "The approximate value of sin(x) for x: " << x << " using: " << n << " terms is: " << setprecision(8) << fixed << fin << endl;
      cout << "Would you like to try again? ('Y' or 'y' to continue): ";
      cin >> a;
     }
 }

double inputCheck(double& tolerance) //tests value of precision
{
  bool keepgoing;
  keepgoing = true;
  while(keepgoing)
  {
    keepgoing = false;
    cout << "Enter tolerance (precision) - example 0.0001: ";
    cin >> tolerance;
    if(tolerance >= 1 || tolerance < 0)
    { //The tolerance did not meet the standards
      cout << "Error: tolerance must be greater than 0 and less than 1\n";
      keepgoing = true; //runs through loop again
    }
  }
  return 0;
}

double factorial(double n)  //This function returns the factorial
{
  if (n < 1)
    return 1;
  else
    return n * factorial(n-1);
}
