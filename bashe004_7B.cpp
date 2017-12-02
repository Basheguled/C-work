//CSCI 1113 HW 7
//Guled Bashe
//HW Problem 7B
#include <iostream>
#include <string>
using namespace std;

string punctuation(string S, int i); //declare function
int main()
{
 char a;
 do{
  int i = -1;
  string S, punc;
  cout << "Enter a Sentence: "; //user input
  getline(cin, S);
  punc = punctuation(S, i); //assign return value from function to variable
  cout << "The punctuation is: " << punc << "\n\n"; //print punctuation

  cout << "Would you like to continue? (Enter ‘Y’ or ‘N’): ";
  cin >> a; //continuation loop
  cin.ignore(); //delete the rest of the characters that are stored
   }
  while(a == 'y' || a == 'Y');
  return 0;
}

string punctuation(string S, int i)
{
   if (S.size() == 0) //if nothing is entered (ie: base case)
      return S;
   else if (S.substr(0, 1) == "." || S.substr(0, 1) == "," || S.substr(0, 1) == "'"  || S.substr(0, 1) == "!" || S.substr(0, 1) == "?")
    { //tests some of punctuation
        return S.substr(0, 1) +  punctuation(S.substr(1), i); //return the function and concatenate with punctuation
    }
   else if(S.substr(0, 1) == "-" || S.substr(0, 1) == ":" || S.substr(0, 1) == ";" || S.substr(0, 1) == "\"")
    { //tests rest of punctuation
        return S.substr(0, 1) +  punctuation(S.substr(1), i); //return the function and concatenate with punctuation
    }
   else
   {
      return punctuation(S.substr(1), i); //return function
   }
}
