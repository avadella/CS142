/*---------------------------------------------------
* Assignment 5: Candy Database
* Developer: Anna Vadella
* Date: October 28, 2021
*---------------------------------------------------*/

#include <iostream>
#include <fstream> 

using namespace std; 

int candy1;
int candy2;
int candy3;
int candy4; 
int totalCandy; 
int eat; 
int getCandy; 

//Prints menu
void printMenu() { 
	cout<<"Options Menu:"<<endl; 
	cout<<"E - Eat a piece of candy"<<endl; 
	cout<<"T - Trick or Treat! (Get a piece of candy)"<<endl; 
	cout<<"I - Current Inventory List"<<endl; 
	cout<<"C - List Candy Types"<<endl; 
	cout<<"S - Save to the file candy.txt"<<endl; 
	cout<<"L - Load from the file candy.txt"<<endl; 
	cout<<"M - Print Command Menu"<<endl; 
	cout<<"Q - Quit the Program"<<endl; 
} 

//Tallys total candy amount 
int candySum(int &candy1, int &candy2, int &candy3, int &candy4) { 
	totalCandy = candy1 + candy2 + candy3 + candy4; 
	return totalCandy; 
} 

//Inventory
void inventory() {
	cout<<"Candy Inventory:"<<endl; 
	cout<<"Candy Corn:          " <<candy1<<endl;
	cout<<"Peanut Butter Cups:  " <<candy2<<endl; 
	cout<<"M&Ms:                " <<candy3<<endl;
	cout<<"Other:               " <<candy4<<endl; 
	candySum(candy1, candy2, candy3, candy4); 
	cout<<"You have " << totalCandy << " piece(s) of candy in your bag."<<endl; 
} 

//Eat menu option 
int eatCandy(int &eat) {
	if (eat == 1) {
		if (candy1 > 0) { 
			candy1 -= 1; 
		} else { 
			cout<<"Sorry, you don't have any of that candy!"<<endl; 
		} 
	} else if (eat == 2) { 
		if (candy2 > 0) { 
			candy2 -= 1;
		} else { 
			cout<<"Sorry, you don't have any of that candy!"<<endl; 
		} 
	} else if (eat == 3) { 
		if (candy3 > 0) { 
			candy3 -= 1; 
		} else { 
			cout<<"Sorry, you don't have any of that candy!"<<endl; 
		} 
	} else if (eat == 4) { 
		if (candy4 > 0) { 
			candy4 -= 1; 
		} else { 
			cout<<"Sorry, you don't have any of that candy!"<<endl; 
		} 
	} else {
		cout<<"Error: invalid input."<<endl; 
	} 
		
	return 0; 
}  

//Trick or Treat menu option 
int trickOrTreat(int getCandy) { 
	if(getCandy == 1) {
		candy1 += 1; 
	} else if (getCandy == 2) { 
		candy2 += 1; 
	} else if (getCandy == 3) {
		candy3 += 1; 
	} else if (getCandy == 4) { 
		candy4 += 1; 
	} else { 
		cout<<"Error: invalid input."<<endl; 
	} 
	return 0; 
} 

//Saves entered candy values into text file candy.txt
void saveCandy() { 
	ofstream candySave; 
	candySave.open("candy.txt"); 
	candySave<<candy1<<endl; 
	candySave<<candy2<<endl; 
	candySave<<candy3<<endl;
	candySave<<candy4<<endl; 
	candySave.close(); 
	cout<<"Save completed!"<<endl; 
} 

//Reads and loads numbers stored in candy.txt file 
void loadCandy() { 
	ifstream candyLoad; 
	candyLoad.open("candy.txt"); 
	int candyAmount1; 
	int candyAmount2;
	int candyAmount3; 
	int candyAmount4; 
	candyLoad>>candyAmount1; 
	candyLoad>>candyAmount2; 
	candyLoad>>candyAmount3; 
	candyLoad>>candyAmount4; 
	cout<<"The saved file reads: " << candyAmount1 << ", " << candyAmount2 << ", " << candyAmount3 << ", and " << candyAmount4 << "." <<endl; 
	candyLoad.close(); 
	candy1 = candyAmount1; 
	candy2 = candyAmount2; 
	candy3 = candyAmount3; 
	candy4 = candyAmount4; 
} 

int main() { 
	cout<<"_______________"<<endl; 
	cout<<"** Candy Database **"<<endl; 
	
	printMenu(); 
	char menuOption; 
	
	do { 
		cout<<"Enter your menu selection: ";
		cin>>menuOption; 
		
		if (menuOption == 'E') { 
			cout<<"Please enter the candy type (1-4): "; 
			cin>>eat; 
			eatCandy(eat); 
		} else if (menuOption == 'T') { 
			cout<<"Please enter the candy type (1-4): "; 
			cin>>getCandy; 
			trickOrTreat(getCandy); 
		} else if (menuOption == 'I') { 
			inventory(); 
		} else if (menuOption == 'C') { 
			cout<<"1 - Candy Corn"<<endl; 
			cout<<"2 - Peanut Butter Cups"<<endl; 
			cout<<"3 - M&Ms"<<endl; 
			cout<<"4 - Other"<<endl;
		} else if (menuOption == 'M') { 
			printMenu(); 
		} else if (menuOption == 'S') { 
			saveCandy(); 
		} else if (menuOption == 'L') {  
			loadCandy(); 
		} else if (menuOption == 'Q') { 
			cout<<"Don't eat too much candy all at once, happy Halloween!"<<endl; 
			cout<<"_______________"<<endl; 
		} else {
			cout<<"Error: invalid input."<<endl;
			cout<<"Sorry, your input was invalid, please try again."<<endl; 
			printMenu(); 
		} 
	} while (menuOption != 'Q'); 
	
	return 0; 
} 