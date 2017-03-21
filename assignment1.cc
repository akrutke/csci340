/**********************************
Andrew Krutke
z1756942
Assignment 1
Due 9/6/2015
************************************/
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

//Global Variables
#define HIGH 10000
#define LOW  1
#define NO_ITEMS 12
#define ITEM_W 5

using namespace std;

//Provided Functions

/*********************************
This function will generate a 
random number and insert it into 
the vector.
**********************************/
void genRndNums( vector<int>& v, int vec_size, int seed ) 
{

int value;
srand(seed);  //intialize the random number generator
  
      for (int i=0; i < vec_size; i++)
        {
                value = rand()% (HIGH - LOW + 1) + LOW;  //find the random numbers 
		v.push_back(value);   //push the new value into the vector
        }
}

/******************************
Print Function
Prints the content found by the
random number generator
*******************************/
void printVec( const vector<int>& v, int vec_size )
{
	int endLine=0;  

	vector<int>::const_iterator iv;   //declare the iterator that will go through the vector

	for (iv = v.begin(); iv != v.end(); ++iv)  //for loop to format the printing of our RNG
	{
		cout <<setw(ITEM_W)<< *iv;  
		endLine++;
		
		if (endLine == NO_ITEMS)  //check for endLine to resest and make a new line
		  { 
		   cout << "\n";
		   endLine=0;
 
		  }
	}
	cout << "\n";   //print null to avoid bad formatting
}

//Main function
int main() {

    vector<int> v;		//vector declaration
    genRndNums( v, 100, 9 );	//Random number generator
    sort(v.begin(), v.end());  //sort the vector
    printVec(v, 100);	       //print call

    return 0;
}


