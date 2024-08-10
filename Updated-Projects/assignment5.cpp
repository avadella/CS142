/*-------------------------------------------------------------
Assignment 5: Candy Database
Developer: Anna Vadella
-------------------------------------------------------------*/

#include <iostream>
#include <fstream>
using namespace std;

//variable declarations -- global
int candy1;         //candy corn
int candy2;         //peanut butter cups
int candy3;         //M&Ms 
int candy4;         //other
int totalCandy;    
int candyEat; 
int candyGet;

//function for displaying menu options
void printMenu()
{
    cout << "Options Menu:" << endl;
    cout << "E - Eat a piece of candy" << endl;
    cout << "T - Trick or Treat! Get a piece of candy" << endl;
    cout << "I - Current inventory list" << endl;
    cout << "C - List candy types" << endl;
    cout << "M - Print this command menu" << endl;
    cout << "S - Save to the file candy.txt" << endl;
    cout << "L - Load from the file candy.txt" << endl;
    cout << "Q - Quit this program" << endl;
}

//function for summing up total candy amount
int candySum(int &candy1, int &candy2, int &candy3, int &candy4)
{
    totalCandy = candy1 + candy2 + candy3 + candy4;
    return totalCandy;
}

//function which reduces user's selected candy type by one
void eatCandy(int &candyEat)
{
    if(candyEat == 1)
    { 
        if(candy1 > 0)
            candy1 -=1;
        else    
            cout << "Sorry, you don't have any of that candy!" << endl;
    }
    else if(candyEat == 2)
    {
        if(candy2 > 0)
             candy2 -=1;
        else    
            cout << "Sorry, you don't have any of that candy!" << endl;
    }
    else if(candyEat == 3)
    {
        if(candy3 > 0)
            candy3 -=1;
        else    
            cout << "Sorry, you don't have any of that candy!" << endl;
    }
    else if(candyEat == 4)
    {
        if(candy4 > 0)
            candy4 -=1;
        else    
            cout << "Sorry, you don't have any of that candy!" << endl;
    }
    else 
        cout << "ERROR: Invalid Input." << endl;
}

//function which increases user's selected candy type by one
void trickOrTreat(int candyGet)
{
    if(candyGet == 1)
        candy1 +=1;
    else if(candyGet == 2)
        candy2 +=1;
    else if(candyGet == 3)
        candy3 +=1;
    else if(candyGet == 4)
        candy4 +=1;
    else 
        cout << "ERROR: Invalid Input." << endl;
}

//function for printing candy inventory
void inventory()
{
    cout << "  **Candy Inventory**  " << endl;
    cout << "Candy Corn:            " << candy1 << endl;
    cout << "Peanut Butter Cups:    " << candy2 << endl;
    cout << "M&Ms:                  " << candy3 << endl;
    cout << "Other:                 " << candy4 << endl;
    candySum(candy1, candy2, candy3, candy4); 
    cout << "You have " << totalCandy << " piece(s) of candy." << endl;
}

//function for displaying available candy types
void candyTypes()
{
    cout << "1 - Candy Corn" << endl;
    cout << "2 - Peanut Butter Cups" << endl;
    cout << "3 - M&Ms" << endl;
    cout << "4 - Other" << endl;
}

//function for saving candy values into txt file named candy.txt
void saveCandy()
{
    ofstream candySave;                 //ofsteam --> class describes output stream, used to create files and write data to files
    candySave.open("candy.txt");
    candySave << candy1 << endl;
    candySave << candy2 << endl;
    candySave << candy3 << endl;
    candySave << candy4 << endl;
    candySave.close();
    cout << "Save Completed!" << endl;
}

//function for loading stored candy values in txt file named candy.txt
void loadCandy()
{
    //variable declarations
    int candyAmount1;
    int candyAmount2;
    int candyAmount3;
    int candyAmount4;
    
    ifstream candyLoad;                 //ifsteam --> class describes input stream, reads data from files and displays it
    candyLoad.open("candy.txt");
    candyLoad >> candyAmount1;
    candyLoad >> candyAmount2;
    candyLoad >> candyAmount3;
    candyLoad >> candyAmount4;

    cout << "The saved file reads: " << candyAmount1 << ", " << candyAmount2 << 
    ", " << candyAmount3 << ", " << candyAmount4 << "." << endl;;
    candyLoad.close();

    candy1 = candyAmount1;
    candy2 = candyAmount2;
    candy3 = candyAmount3;
    candy4 = candyAmount4;
}

int main()
{
    //variable declaration
    char menuOption; 

    cout << "-------------------" << endl;
    cout << "** My Candy Database **" << endl;

    printMenu();
    do 
    {   
        cout << "Enter your menu selection: ";
        cin >> menuOption;
        
        if(menuOption == 'E' || menuOption == 'e')          //eat candy
        {
            cout << "Please enter the candy type (1-4): ";
            cin >> candyEat;
            eatCandy(candyEat);
        }
        else if(menuOption == 'T' || menuOption == 't')     //trick or treat
        {
            cout << "Please enter the candy type (1-4): ";
            cin >> candyGet;
            trickOrTreat(candyGet);
        }
        else if(menuOption == 'I' || menuOption == 'i')     //inventory
        {
            inventory();
        }
        else if(menuOption == 'C' || menuOption == 'c')     //candy types
        {
            candyTypes();
        }
        else if(menuOption == 'M' || menuOption == 'm')     //command menu
        {
            printMenu();
        }
        else if(menuOption == 'S' || menuOption == 's')     //save to file
        {
            saveCandy();
        }
        else if(menuOption == 'L' || menuOption == 'l')     //load file
        {
            loadCandy();
        }
        else if(menuOption == 'Q' || menuOption == 'q')     //quit program
        {
            cout << "Don't eat too much candy all at once! Happy Halloween! :)" << endl;
        }
        else                                                //invalid selection
        {
            cout << "ERROR: Invalid Input. Please Try Again." << endl;
            printMenu();                                    //call printMenu function again for valid input
        }
    } while (menuOption != 'Q' && menuOption != 'q');
    //Note: originally had || instead of &&, but then if menuOption is 'Q', then menuOption != 'q' is true and vice versa...

    cout << "-------------------" << endl;

    return 0;
}