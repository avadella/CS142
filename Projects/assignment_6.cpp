/*--------------------------------------------
* Assignment 6: ES Program
* Developer: {Anna Vadella}
* Date: {11/4/2021}
*-------------------------------------------*/

#include <iostream>
#include <fstream>

using namespace std; 

void loadArray (int buildArray[], int &length) {
	//Loads values from text file into array
	ifstream scoreExam; 
	scoreExam.open("examScores.txt"); 
	//Puts length value from file (i.e., first value from file) into length variable 
	scoreExam>>length;
	//Builds array with a for loop
	for (int i = 0; i < length; i++) { 
		scoreExam>>buildArray[i]; 
	} 
	//Closes file
	scoreExam.close(); 
} 

//Establishes the minimum score, goes through array to find the lowest score + return value
int minScore(int minimum[], int length) { 
	int lowestScore = minimum[0]; 
	for (int i = 1; i < length; i++) { 
		if(minimum[i] < lowestScore) { 
			lowestScore = minimum[i]; 
		} 
	} 
	return lowestScore; 
} 

//Establishes the maximum score, goes through array to find the highest score + return value
int maxScore(int maximum[], int length) { 
	int highestScore = maximum[0]; 
	for (int i = 1; i < length; i++) { 
		if(maximum[i] > highestScore) { 
			highestScore = maximum[i]; 
		} 
	} 
	return highestScore; 
} 

//Establishes the average score; goes through array, adds up all scores, then divides by the length value (or number of scores)
double avgScore(int average[], int length) { 
	double averageScore; 
	for (int i = 0; i < length; i++) { 
		averageScore += average[i]; 
	} 	
	averageScore = averageScore/length; 
	return averageScore; 
} 

//Defines letter grades as variables
int letterA; 
int letterB; 
int letterC; 
int letterD; 
int letterF; 

//Establishes the number of A's, B's, C's, D's, and F's using a 90-80-70-60 grading scale 
void gradingScale(int letterGrade[], int length) { 
	for (int i = 0; i < length; i++) { 
		if (letterGrade[i] >= 90) { 
			letterA++; 
		} else if (letterGrade[i] >= 80) { 
			letterB++; 
		} else if (letterGrade[i] >= 70) { 
			letterC++; 
		} else if (letterGrade[i] >= 60) { 
			letterD++; 
		} else { 
			letterF++; 
		} 
	} 
} 

int main() { 
	
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(2); 
	
	int length; 
	int examArray[1000]; 
	
	loadArray(examArray, length); 
	
	cout<<"_________________________________"<<endl; 
	cout<<"** Exam Statistics Program **"<<endl;
	cout<<"Minimum Score: " << minScore(examArray, length) << endl; 
	cout<<"Maximum Score: " << maxScore(examArray, length) << endl; 
	cout<<"Average Score: " << avgScore(examArray, length) << endl; 
	cout<<"There are a total of " << length << " scores:"<< endl; 
	gradingScale(examArray, length); 
	cout<<"A: " << letterA << endl; 
	cout<<"B: " << letterB << endl; 
	cout<<"C: " << letterC << endl; 
	cout<<"D: " << letterD << endl; 
	cout<<"F: " << letterF << endl; 
	cout<<"_________________________________"<<endl; 

	return 0;
} 