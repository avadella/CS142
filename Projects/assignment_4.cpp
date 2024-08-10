/*-------------------------------------------------------------
* Assignment 4: Guessing Game
* Developer: Anna Vadella
* Date: October 4, 2021
*-------------------------------------------------------------*/

#include <iostream> 
#include <ctime>

using namespace std; 

int numGuess; 
char play; 
void playAgain(); 

void ran_num_game() { 
	int randNumber = 1 + rand()%100;
	cout<<"_______________"<<endl; 
	cout<<"** Number Guessing Game **"<<endl; 
	
	do { 
		cout<<"Enter a number between 1-100: "; 
		cin>>numGuess; 
		
		if (numGuess > randNumber) { 
			cout<<"Your guess is too high! Guess again."<<endl; 
		} else if (numGuess < randNumber) { 
			cout<<"Your guess is too low! Guess again."<<endl; 
		} else if (numGuess == randNumber) { 
			cout<<"You guessed it! Way to go!"<<endl; 
			cout<<"_______________"<<endl;  
		} 
	} while (randNumber != numGuess); 
	playAgain(); 
}

void playAgain() { 
	do { 
		cout<<"Do you want to play again?: (Y or N) "; 
		cin>>play; 
		
		if (play == 'Y' || play == 'y') { 
			ran_num_game(); 
		} else if (play == 'N' || play == 'n') {
			cout<<"Thank you for playing!"<<endl; 
		} else {
			cout<<"That is not a valid response."<<endl; 
		} 
	} while (play != 'N' && play != 'n');  
} 

int main() { 

	srand(time(NULL));
	ran_num_game(); 

	return 0;
} 