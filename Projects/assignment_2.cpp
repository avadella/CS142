//-------------------------------------------------------------
// Assignment 2: Decisions, Decisions
// Developer: Anna Vadella
// Date: September 16, 2021
//-------------------------------------------------------------

#include <iostream>

using namespace std; 

int main() {
	//Program 1: Temperature Conversion
	
	cout<<"_______________"<<endl; 
	cout<<"** Anna's Temperature Converter! **"<<endl; 
	cout<<"Please enter today's temperature in degrees Fahrenheit: "; 
	int deg_fahrenheit; 
	cin>>deg_fahrenheit; 
	int deg_celsius = (deg_fahrenheit - 32) * 5/9; 
	cout<<"Today's temperature is "<< deg_celsius << " degrees Celsius."<<endl; 
	cout<<"_______________"<<endl; 
	
	//Program 2: Ride Height Calculator
	cout<<"_______________"<<endl; 
	cout<<"** Welcome to Queen's Isle MegaCoaster! **"<<endl; 
	cout<<"The riders of the MegaCoaster must be a certain height to maintain their safety during the ride."<<endl; 
	cout<<"Please enter your height in inches: "; 
	int inch_height;
	cin>>inch_height; 
	
	if (inch_height < 60) {
		cout<<"I'm sorry. You are not tall enough to ride this ride. You must be at least 5' tall. You can wait in the waiting area to the left while the rest of your party enjoys the ride."<<endl; 
		cout<<"_______________"<<endl; 
	} 
	else {
		cout<<"Congratulations! You are tall enough to ride the MegaCoaster! Enjoy your ride!"<<endl; 
		cout<<"_______________"<<endl; 
	}
	return 0; 
} 