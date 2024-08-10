//------------------------------------------------------------
// Assignment 3: Loops
// Developer: Anna Vadella
// Date: September 23, 2021
//-------------------------------------------------------------

#include <iostream>

using namespace std;

int main() {
	
	//Program 1: Movie Night Cost 
	cout<<"_______________"<<endl; 
	cout<<"** Welcome to Movies R Us! **"<<endl; 
	cout<<"Your age determines the price of your ticket."<<endl; 
	cout<<"Please enter your age: "; 
	int movieAge; 
	cin>>movieAge; 
	
	if (movieAge >= 13) { 
		cout<<"The cost to enjoy a movie here at Movies R Us is $12. Thank you!"<<endl; 
	} else if (movieAge >= 3 && movieAge <= 12) { 
		cout<<"The cost to enjoy a movie here at Movies R Us is $8. Thank you!"<<endl; 
	} else if (movieAge < 3) { 
		cout<<"Congratulations! Your ticket is free! Thank you!"<<endl; 
	}  
	
	//Program 2: Tuition Cost
	cout<<"_______________"<<endl; 
	cout<<"** Tuition Cost Calculator! **"<<endl; 
	cout<<"How many credit hours do you want to take (enter 0 to exit): "; 
	int creditNum; 
	int creditSum = 0; 
	cin>>creditNum; 
	
	while (creditNum != 0) { 
		creditSum += creditNum; 
		cout<<"Enter another number (Enter 0 to quit): "; 
		cin>>creditNum; 
	} 
	
	double tuitionSum; 
	if (creditSum <= 11) { 
		tuitionSum = (1760.00 * creditSum);
	} else if (creditSum > 11 && creditSum <= 20) { 
		tuitionSum = 21205.00;
	} else if (creditSum >= 21) {
		int greaterSum; 
		greaterSum = creditSum - 20;
		tuitionSum = 21205.00 + (1760.00 * greaterSum); 
	} 
	
	cout<<"\nYour tuition bill will be: $" << tuitionSum << "." <<endl; 
	cout<<"Will that be cash or check?"<<endl; 
	cout<<"_______________"<<endl; 
	
	return 0;
} 