//============================================================================
// Name        : numberGuesser.cpp
// Author      : Andrew Kaldani
//   :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <cctype>
#include <ctime>
using namespace std;
void playGame();
bool wantToPlayAgain();
bool IsGameOver(int secret, int numOfTries, int guess);
int GetGuess(int numOfTries);
void DisplayResult(int secret, int numOfTries);
const int IGNORE = 256;

int main() {
	// store secret number
   //must be within range 0-100
	//store number of guesses left
	//store player's guess
	// should be range of secret number
	// number of guesses will be log base 2 of upper range
	// output secret number how to change secret number

	//we need a variable that stores the secret number
	//range: 0 - 100
	//we need a variable that stores the number of guesses the player has left
	//we need a variable that will store the player's guess
	//number of guesses will be the log base 2 of the upper range - eg. log2(100) ~ 6.64 -> 7
	//how do we change the secret number?

	/*

	 do
	 {
	 	 Play The Game

	 }while ( Want to play again )

	 Play the Game:

	 1. set the secret number - set it a known value for now
	 2. set the number of guesses -> ceil(log2(100))

	 do
	 {
	 	 3. Prompt the user to make a guess (output the number of guesses left)
	 	 4. Get the guess from the player
	 	 5. check to see if the guess is equal to the secret number
	 	 	 5a. if the guess is not equal to the secret number then
	 	 	 	5a1. decrement the number of guesses left
	 	 	 	5a2. check to see if the guess was higher or lower than the secret number
	 	 	 		5a2a. if it was higher - print that the guess was too high
	 	 	 		5a2b. if the guess was lower - then print that the guess was too low

	 }while(the game is not over)

	 Display the result - tell the player if he got it or not

	 Functions:

	 Play the Game -> PlayGame()
	 Want to play again -> WantToPlayAgain()
	 Get the guess from the player -> GetGuess()

	 the is not over -> IsGameOver()

	 number of guesses left == 0 || player's guess == secret number

	 Display result -> DisplayResult()

	 if(the player got it)
	 {
	 	 print that they got it and print the secret number
	 }
	 else
	 {
	 	 print that they didn't get it and print the secret number
	 }

	 */
	 srand((unsigned int) time(NULL));

	do{
	playGame();

	}while(wantToPlayAgain());

	return 0;
}
void playGame(){
	const int UPPER = 100;

	int secret = rand()%UPPER;
	int numOfTries = ceil(log2(UPPER));
	int guess  = 0;

	do {
		guess = GetGuess(numOfTries);
		if(guess != secret){
			numOfTries--;
			if(guess>secret){
				cout<<"guess is too high"<<endl;
			}
			else{
				cout<<"guess is too low"<<endl;
			}
		}
		//DisplayResult(secret,numOfTries);
	}while(!IsGameOver(secret,numOfTries,guess));
	DisplayResult(secret, numOfTries);


}
bool wantToPlayAgain()
{
	char input;
	bool failure;

	do
	{
		failure = false;

		cout << "Would you like to play again? (y/n) ";
		cin >> input;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE, '\n');
			cout << "Input Error! Please try again." << endl;
			failure = true;
		}
		else
		{
			cin.ignore(IGNORE, '\n');

			input = tolower(input);
		}

	}while(failure);

	return input == 'y';
}


bool IsGameOver(int secret, int numOfTries, int guess){
	return secret == guess || numOfTries <= 0;

}
int GetGuess(int numOfTries){
int guess;
bool failure;
do{
	failure= false;
	cout<<"please eneter your guess(num left : "<<numOfTries<<"): ";
	cin >> guess;
	if(cin.fail()){
		cin.clear();
		cin.ignore(IGNORE,'\n');
		cout<<"error try again"<<endl;
		failure=true;
	}
}while(failure);
return guess;

}

void DisplayResult(int secret, int numOfTries)
{
	if (numOfTries > 0)
	{
		cout << "right! It was " << secret << "!" << endl;
	}
	else
	{
		cout << "no more guesses It was " << secret << "!" << endl;
	}
}
