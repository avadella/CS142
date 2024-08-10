/*-------------------------------------------------------------
Assignment 7: Secret Code
Developer: Anna Vadella
-------------------------------------------------------------*/

#include <iostream>
#include <cstring>
using namespace std;

//variable declarations -- global
int key;

//function that determines whether the key will be for encrypting/decrypting
void determineKey()
{
    cout << "Enter a number to be the encryption/decryption key: ";
    cin >> key;
}

//function which mathematically encrypts a character
char encrypt(char x)
{
    if(x >= 'a' && x <= 'z') 
    {
        x = (char)((((x - 'a') + key) % 26 + 26) % 26 + 'a');
        //(x - 'a') ----> converts character to an index in the range [0,25]
        //% 26      ----> handles wrapping around the alphabet
        //add 26    ----> ensures the result is non-negative before applying % again
        //add 'a'   ----> converts the index back to the corresponding ASCII character
    }
    else if(x >= 'A' && x <= 'Z') {
        x = (char)((((x - 'A') + key) % 26 + 26) % 26 + 'A');
    }
    return x; 
}

//function which mathematically decrypts a character
char decrypt(char x)
{
    if(x >= 'a' && x <= 'z') 
    {
        x = (char)((((x - 'a') - key) % 26 + 26) % 26 + 'a');
    }
    else if(x >= 'A' && x <= 'Z') 
    {
        x = (char)((((x - 'A') - key) % 26 + 26) % 26 + 'A');
    }
    return x; 
}

//function which encrypts the user's desired message
void messageEncryption(char message[], int messageLength)
{
    for(int i = 0; i < messageLength; i++)
    {
        message[i] = encrypt(message[i]);
        cout << message[i];
    }
    cout << endl;
}

//function which decrypts the user's desired message
void messageDecryption(char message[], int messageLength)
{
    for(int i = 0; i < messageLength; i++)
    {
        message[i] = decrypt(message[i]);
        cout << message[i];
    }
    cout << endl;
}

int main()
{
    //variable declarations
    char message[100];
    char userChoice;

    cout << "_______________" << endl;
    cout << "** Secret Codes **" << endl;
    cout << "Enter your message: ";
    cin.getline(message, 100);

    determineKey();
    int messageLength = strlen(message);

    cout << "Would you like to encrypt (E) or decrypt (D) your message?: ";
    cin >> userChoice;

    if(userChoice == 'E' || userChoice == 'e')
    {
        cout << "The encrypted version of your message is: ";
        messageEncryption(message, messageLength);
    }
        
    else if(userChoice == 'D' || userChoice == 'd')
    {
        cout << "The decrypted version of your message is: ";
        messageDecryption(message, messageLength);
    }
        
    else 
        cout << "ERROR: Invalid Input." << endl;

    cout << "Thank you for using our services." << endl;
    cout << "_______________" << endl;

    return 0;
}