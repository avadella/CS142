/*---------------------------------------------
Assignment 8: Pi Program
Developer: Anna Vadella
----------------------------------------------*/

#include <iostream>
#include <cmath>
#include "mpi.h"
using namespace std;

//CHUNKING FUNCTION
//function to compute sum of the series 1/i^2 for a specific chunk of numbers
//MPI chunking ---> technique used to divide data into smaller chunks and distribute them across multiple processes
double chunk(int b, int id)         //b = number of terms each process should handle, id = unique identifier for each process
{
    double sum = 0;
	int start = (id * b) + 1;       //tells processor what number to start with 
	int stop = (id + 1) * b;        //tells processor what number to end with
    
    //calculates sum of series for the given range
	for(int i = stop; i >= start; i--) 
		sum = sum + 1.0/(i * i); 
	
	return sum; 
}

//STRIPING FUNCTION
//function to compute single term of series 1/i^2 based on processor's ID and interval
//MPI striping ---> technique used to distribute data evenly across multiple processes
//double striping(int b)
//{
//    return 1.0/(b * b);
//}
    
int main(int argc, char *argv[])
{
	//initializes MPI execution environment, must be done at the start of program
    MPI_Init(&argc, &argv);

	int id;                                 //identification number, lets us know which processor is which
    MPI_Comm_rank(MPI_COMM_WORLD, &id);     //gets the rank (ID) of the process
	
	int np;                                 //number of processors
	MPI_Comm_size(MPI_COMM_WORLD, &np);     //gets the total number of processes

	int n;                                  //n = total number of terms

    //"root" process = ID 0
	if(id == 0) 
    { 
	    //ask user for the number of terms (n)
		cout << "Please enter n: "; 
		cin >> n; 
	} 
    
	//broadcast ---> sends message from process w/ rank “root” to all other processes in group
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);  

	//everyone has the total term (n), can use n to compute sum
	cout << "n = " << n << " and I am " << id << "." << endl; 

    //chunking
	int b = n/np;                       //calculates how many terms each process will handle
	double sum = 0; 
	sum = chunk(b, id);                 //each process computes its part of the sum using chunking function

    //striping
    //double sum = 0;
    //for(int i = id + 1; i <= n; i += np)        //compute sum for specific range of indices for each process
    //     sum += striping(i);               
	
	double totalSums;                   //sum of all processor sums
	MPI_Reduce(&sum, &totalSums, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD); 
    //values sent by MPI processes combined using reduction operation, collects results from all processes into totalSums on "root"

    //"root" process calculates value of pi
	if(id == 0) 
    { 
		double pi = sqrt(totalSums * 6); 
		cout << "Pi = " << pi << endl; 
	} 

    //finishes process, similar to a return statement
	MPI_Finalize(); 

    return 0;
}