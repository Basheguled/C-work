//Csci 1113 HW 3
//Guled Bashe
//HW Problem 3B
#include <iostream>
using namespace std;
double FlipCoin(); // function declaration
int seed; // variable declaration
int rounds;
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
    srand(seed);  //initializing random seed
  }
  srand(time(NULL));
do{ //print game message
    cout << "\nTo begin, you and your adversary, the computer, each have 100 dollars\n\n";
    cout << "How many rounds rounds would you like to play (1-1000): ";
    cin >> rounds;  //number of rounds to run the game
    if(rounds > 1000 || rounds <= 0)  //if user input not positive , set rounds to 1.
      {
        cout << "\nError: You entered a number out of range" << endl;
        rounds = 1;
      }
    FlipCoin(); //call flip coin function
    cout << "Enter 'y' or 'Y' to repeat this process: "; //ask if user wants to conitnue
    cin >> x;
  }
while (x == 'Y' || x == 'y'); //keeps loop running
}

double FlipCoin()
{
  double playerMoney = 100; //declare and initialize variables
  double compMoney = 100;
  int playerWins = 0;
  int compWins = 0;
  int counter = 0;
  for(counter = 0; counter < rounds; counter++) //for loop to run through all rounds
  {
    int player = rand() % 2 + 1; //user's coin flip
    int comp = rand() % 2 + 1; //computer's coin flip
    if(player == 1 && comp == 1)//if both coins are heads
    {
      playerMoney += 3;
      compMoney -= 3;
      playerWins++;
    }
    else if(player == 2 && comp == 2)//if both coins are tails
    {
      playerMoney += 1;
      compMoney -= 1;
      playerWins++;
    }
    else //if one coin is heads and one is tails
    {
      playerMoney -= 2;
      compMoney += 2;
      compWins++;
    }
    player = 0;
    comp = 0;
  } //prints final tally of wins and money.
  cout << "\nYour wins: " << playerWins << "         Your total dollars after games: " << playerMoney << endl;
  cout << "Computer Wins: " << compWins << "     Computer's total dollars after games: " << compMoney << "\n\n";
  return 0;
}
