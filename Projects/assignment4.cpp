/*-------------------------------------------------------------
Assignment 4: Guessing Game
Developer: Anna Vadella
Date: October 4, 2021
-------------------------------------------------------------*/

#include <iostream>
#include <ctime>
using namespace std;

//function declarations
void playAgain();
void randomNumberGame();

//function to ask the user if they'd like to play the game again
void playAgain()
{
    //variable declaration
    char playChar;

    cout << "Do you want to play again? (Y or N): ";
    cin >> playChar;
    
    //check that user input is valid char and handle it 
    if(playChar == 'Y' || playChar == 'y')
        randomNumberGame();
    else if(playChar == 'N' || playChar == 'n')
        cout << "Okay, thank you for playing! :)" << endl;
    else
    {
        cout << "That is not a valid response. Try again." << endl;
        playAgain();    //Call playAgain function again for valid input
    }
}

//function for playing random number game
void randomNumberGame() 
{
    //variable declarations
    int numGuess;
    int randomNum = 1 + rand() % 100;  //create random number
    
    //formatting print statements
    cout << "_______________" << endl;
    cout << "** Number Guessing Game **" << endl;

    //checking if user's guess is correct
    do {
        cout << "Please guess a number between 1-100: ";
        cin >> numGuess;

        if(numGuess > randomNum)
            cout << "Your guess is too high! Guess again." << endl;
        else if (numGuess < randomNum)
            cout << "Your guess is too low! Guess again." << endl;
        else 
            cout << "You guessed it! Way to go!" << endl;
        
    } while(numGuess != randomNum);

    cout << "_______________" << endl;
    playAgain();
}

int main() 
{
    srand(time(NULL));  //seed the random number generator
    randomNumberGame();
    return 0;
}