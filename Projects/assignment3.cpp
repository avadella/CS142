/*-------------------------------------------------------------
Assignment 3: Loops
Developer: Anna Vadella
Date: September 23, 2021
-------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main() 
{
    //Program #1: Movie Night Cost
    //variable declaration
    int age;

    //print statements + user input
    cout << "_______________" << endl;
    cout << "** Welcome to Movies R Us! **" << endl;
    cout << "Your age determines the price of your ticket." << endl;

    //determining ticket price based on age
    for(int i = 0; i < 3; i++) 
    {
        cout << "Please enter your age: ";
        cin >> age;

        if (age > 13)
            cout << "The cost to enjoy a movie here at Movies R Us is $12. Thank you!" << endl;
        else if (age <= 12 && age >= 3)
            cout << "The cost to enjoy a movie here at Movies R Us is $8. Thank you!" << endl;
        else
            cout << "Congratulations! Your ticket is free! Thank you!" << endl;
    }

    //formatting print statement
    cout << "_______________" << endl;

    //Program #2: Tuition Cost
    //variable declaration
    int totalCredits;
    int additionalCost;
    double tuition;

    //print statements + user input
    cout << endl;
    cout << "_______________" << endl;
    cout << "** Tuition Cost Calculator! **" << endl;

    while(true)
    {
        cout << "How many credit hours do you want to take (enter 0 to exit): ";
        cin >> totalCredits;

        if(totalCredits == 0)
            break;

        if (totalCredits <= 11)
            tuition = (1760.00 * totalCredits);
        else if (totalCredits >= 12 && totalCredits <= 20)
            tuition = 21205.00;
        else 
        {
            additionalCost = totalCredits - 20;
            tuition = 21205.00 + (1760.00 * additionalCost);
        }

        cout << "Your tuition bill will be: $" << tuition << "." << endl;
    }
    
    //print statements
    cout << "Will that be cash or check?" << endl;
    cout << "_______________" << endl;

    return 0;
}