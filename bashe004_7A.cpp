//CSCI 1113 HW 7
//Guled Bashe
//HW Problem 7A

#include <iostream>
#include <cmath>
using namespace std;

double series(double n); //function delcaration
int main()
{
 double n, finVal;
 char a;
 do{
  cout << "Enter the number n: ";
  cin >> n; //user input
  finVal = series(n); //store value from function in a variable
  cout << "The value of the series for n = " << n << " is: " << finVal << "\n\n"; //final answer
  cout << "Would you like to continue(Y or N): ";
  cin >> a;
   }
  while(a == 'y' || a == 'Y'); //runs until user stops program

}

double series(double n)
{
  if (n == 1) //base case
    return n;
  else
    return 1/pow(n, 2) + series(n-1);  //recursive function call for formula
}
