/*---------------------------------------------
* Assignment 7: Secret Message
* Developer: Anna Vadella
* Date: November 11, 2021
*--------------------------------------------*/

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int key; 

//This function establishes what the key will be for encryption/decryption
void establishKey() { 
	cout<<"Enter a number to be the encryption key: "; 
	cin>>key; 
} 

//
char messEncrypt(char x) { 
	if (x >= 'a' && x<= 'z' || x>= 'A' && x<= 'Z') { 
		x = (char) ((int)x + key); 
	} 
	return x; 
} 

//
char encryption(char message[], int messageLength) { 
	for (int i = 0; i < messageLength; i++) { 
		message[i] = messEncrypt(message[i]); 
		cout<<message[i]; 
	} 
	return 0; 
} 

//
char messDecrypt(char x) { 
	if (x >= 'a' && x<= 'z' || x>= 'A' && x<= 'Z') { 
		x = (char) ((int)x - key); 
	} 
	return x; 
} 

//
char decryption(char message[], int messageLength) { 
	for (int i = 0; i < messageLength; i++) { 
		message[i] = messDecrypt(message[i]); 
		cout<<message[i]; 
	} 
	return 0; 
} 

int main () { 
	
	char message[100]; 
	cout<<"_______________"<< endl; 
	cout<<" ** Secret Codes ** "<< endl; 
	cout<<"Enter your message: "; 
	cin.getline(message, 100); 
	
	establishKey(); 
	int messageLength = strlen(message); 
	
	cout<<"Would you like to encrypt (Y) or decrypt (N) your message?: "; 
	char userChoice; 
	cin>>userChoice; 
	
	cout<< "What would you like your file name to be? (add .txt at the end!): "; 
	char fileName[100]; 
	cin.getline(fileName, 100); 
	cin.getline(fileName, 100); 
	
	
if (userChoice == 'Y' || userChoice == 'y') { 
	cout << encryption(message, messageLength) << endl; 
	ofstream messageEncrypt; 
	messageEncrypt.open(fileName); 
	messageEncrypt << message << endl; 
	messageEncrypt.close(); 
	cout << "Thank you for encrypting with us! Your message can be found in: " << fileName << endl; 
} else if (userChoice == 'N' || userChoice == 'n') { 
	cout<< decryption(message, messageLength) << endl; 
} else { 
	cout<< "Sorry, that is not a valid input." << endl; 
} 
	
	cout<<"Thank you for using our services."<< endl; 
	cout<<"_______________"<< endl; 
	
	return 0; 
} 