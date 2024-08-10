/*---------------------------------------------
* Assignment 8: Pi Program
* Developer: Anna Vadella
* Date: December 14, 2021
*----------------------------------------------*/
/*
Command Prompt Instructions:
Compile: mpicxx filename.cpp
Run: mpirun -np 10 ./a.out
*/

#include <iostream>
#include <cmath>
#include "mpi.h"

using namespace std;

double chunk(int b, int id) { 
	//Tells processor what number to start with
	int start = (id * b) + 1; 
	//Tells processor what to end with
	int stop = (id + 1) * b; 
    
    double sum = 0;

	for (int i = stop; i >= start; i--) 
	{ 
		sum = sum + 1.0/(i * i); 
	} 
	
	return sum; 
} 
 
int main(int argc, char *argv[]){

    //initialize MPI
	//initializes the MPI execution environment, must be done at the start of the program
    MPI_Init(&argc, &argv);

    //Identification number that lets us know which processor is which
		//This retrieves the local ID and stores it in the local variable rank
	int id; 
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
	
	//Number of processors
		//This retrieves the total number of MPI processes running and stores it in the local variable size
	int np; 
	MPI_Comm_size(MPI_COMM_WORLD, &np); 

	//n = total number of terms
	int n;

	if (id == 0) { 
	//Ask user for the number of terms (n)
		cout << "Please enter n: "; 
		cin >> n; 
	} 
    
	//Broadcast sends a message from the process with rank “root” to all other processes in the group
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);  

	//Everyone has the total term (n)
	//Can use n to compute the sum
	cout<<"n = " << n << " and I am " << id << "." << endl; 

    //Start chunking process here!
	int b = n/np; 
	double sum = 0; 
	sum = chunk(b, id); 
	
	//Sum of all the processor sums
	double totalSums; 
	
	//this is the means by which MPI process can apply a reduction calculation
		//values sent by the MPI processes will be combined using the reduction operation 
		//given and the result will be stored on the MPI process specified as root
	MPI_Reduce(&sum, &totalSums, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD); 

	if(id == 0) { 
		double pi = sqrt(totalSums * 6); 
		cout<<"Pi = " << pi << endl; 
	} 
	
	//Finishes process, similar to a return statement
	MPI_Finalize(); 
	
	return 0;
}