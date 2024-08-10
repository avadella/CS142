/*-------------------------------------------------------------
 Assignment 2: Decisions, Decisions
 Developer: Anna Vadella
-------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main() 
{
    //Program #1: Temperature Convertor
    //variable declarations
    int fahrenheit; 
    int celsius;

    //print statements + user input
    cout << "_______________" << endl;
    cout << "** Anna's Temperature Convertor! **" << endl;
    cout << "Please enter today's temperature in degrees Fahrenheit: ";
    cin >> fahrenheit;

    //temperature conversion calculation
    celsius = (fahrenheit - 32) * 5/9;

    //print statements
    cout << "Today's temperature is " << celsius << " degrees Celsius." << endl;
    cout << "_______________" << endl;

    //Program #2: Ride Height Calculator
    //variable declarations
    int height;

    //print statements + user input
    cout << endl;
    cout << "_______________" << endl;
    cout << "** Welcome to Queen's Isle MegaCoaster! **" << endl;
    cout << "The riders of the MegaCoaster must be a certain height to maintain their safety during the ride." << endl;
    cout << "Please enter your height in inches: ";
    cin >> height;

    if(height < 60)
        cout << "I'm sorry. You are not tall enough to ride this ride."
             << "You must be at least 5' tall. You can wait in the waiting area to the left " 
             << "while the rest of your party enjoys the ride." << endl;
    else
        cout << "Congratulations! You are tall enough to ride the MegaCoaster! Enjoy your ride!" << endl;

    //formatting print statement
    cout << "_______________" << endl;

    return 0; 
}