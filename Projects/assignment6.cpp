/*-------------------------------------------------------------
Assignment 6: Exam Statistics Program
Developer: Anna Vadella
Date: November 4, 2021
-------------------------------------------------------------*/

#include <iostream>
#include <fstream>
using namespace std;

//function declarations
void loadArray(int createArray[], int &length);
int minimumScore(int minimum[], int length);
int maximumScore(int maximum[], int length);
double averageScore(int average[], int length);
void gradingScale(int letterGrade[], int length);

//variable declarations -- global
int letterA;
int letterB;
int letterC;
int letterD;
int letterF;

//function which loads the exam scores from a .txt file into an array
void loadArray(int createArray[], int &length)
{
    //load values from .txt file into array
    ifstream loadExamScores;
    loadExamScores.open("SampleExamScores.txt");

    //put length value (first number) from .txt file into length variable 
    loadExamScores >> length;

    //build array filled w/ exam scores from .txt file
    for(int i = 0; i < length; i++)
        loadExamScores >> createArray[i];

    loadExamScores.close();
}

//function to calculate the minimum exam score
int minimumScore(int minimum[], int length)
{
    int lowestScore = minimum[0];
    for (int i = 1; i < length; i++) 
    {
        if(minimum[i] < lowestScore) 
            lowestScore = minimum[i];
    }

    return lowestScore; 
}

//function to calculate the maximum exam score
int maximumScore(int maximum[], int length)
{
    int highestScore = maximum[0];
    for (int i = 1; i < length; i++) 
    {
        if(maximum[i] > highestScore) 
            highestScore = maximum[i];
    }
    
    return highestScore; 
}

//function to calculate the average exam score
double averageScore(int average[], int length)
{
    double avgScore = average[0];
    for (int i = 1; i < length; i++)
        avgScore += average[i];

    avgScore = avgScore/length;
    return avgScore;
}

//function that determines the number of A's, B's, C's, D's, and F's using a 90-80-70-60 grading scale
void gradingScale(int letterGrade[], int length)
{
    for(int i = 0; i < length; i++)
    {
        if(letterGrade[i] >= 90)
            letterA++;
        else if(letterGrade[i] >= 80)
            letterB++;
        else if(letterGrade[i] >= 70)
            letterC++;
        else if(letterGrade[i] >= 60)
            letterD++;
        else
            letterF++;
    }
}

int main()
{
    //variable declarations
    int length;
    int examArray[1000];

    loadArray(examArray, length);
    
    cout.setf(ios::fixed);          //controls formatting of floating-point numbers, changes format to fixed-point notation
    cout.setf(ios::showpoint);      //ensures that decimal points and trailing zeros are always displayed 
    cout.precision(2);              //controls number of decimal places displayed (in this case, 2)

    cout << "_______________" << endl;
    cout << "** My Exam Statistics Program **" << endl;
    cout << "Minimum Score: " << minimumScore(examArray, length) << endl;
    cout << "Maximum Score: " << maximumScore(examArray, length) << endl;
    cout << "Average Score: " << averageScore(examArray, length) << endl;

    cout << "There are a total of " << length << " scores: " << endl;
    gradingScale(examArray, length);
    cout << "A: " << letterA << endl;
    cout << "B: " << letterB << endl;
    cout << "C: " << letterC << endl;
    cout << "D: " << letterD << endl;
    cout << "F: " << letterF << endl;
    cout << "_______________" << endl;

    return 0;
}