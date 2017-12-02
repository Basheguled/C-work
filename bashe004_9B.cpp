//CSCI 1113 HW9
//Guled Bashe
//HW Problem 9B

#include <iostream>
#include <cmath>
using namespace std;

double *force(double ax, double ay, double az, double mass) //function to
{																										//calculate force
	double *f = new double[3]; //dynamically create array
	f[0] = ax*mass; //store force vakues in the array
	f[1] = ay*mass;
	f[2] = az*mass;

	return f;//return array

}
int main()
{
  char a;
  double ax, ay, az, mass;
	do{

  	double* F = new double [3]; //dynamically create array and double
  	double* magnitude = new double;
		cout << "\nWelcome to the program to compute force\n\n";
		cout << "Please enter the mass of the object: ";
		cin >> mass;

		cout << "Please enter acceleration of the object along each axis (x,y,z)";
    cout << "in meters/second^2: ";
		cin >> ax >> ay >> az;

		F = force(ax, ay, az, mass); //store return value of function in array

		cout << "\nThe force of the object is: \n"; //output force values
		cout << F[0] << " newtons in the x direction\n";
		cout << F[1] << " newtons in the y direction\n";
		cout << F[2] << " newtons in the z direction\n";
		//calculate magnitude of the force
		*magnitude = sqrt(pow(F[0], 2) + pow(F[1], 2) + pow(F[2], 2));
		cout << "\nThe magnitude of the force is " << *magnitude<< " newtons\n";

    delete [] F; //delete them from memory
		delete magnitude;

    cout << "\nWould you like to continue (Enter ‘y’ or ‘n’): ";
		cin >> a;
    cout << "\n";
	   }
	while(a == 'y' || a == 'Y'); //do this while user wants to continue

}
