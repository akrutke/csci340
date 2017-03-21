/***************************************
Andrew Krutke
z1756942
Due 9/11/2015
Program 2
****************************************/
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <iostream>
//Global Constants

const int TOBE_SEARCHED = 5000;
#define HIGH 10000
#define LOW 1

using namespace std;

/********************************************
Function: 	find random numbers

Arguments:	2 vectors, 1 int

Returns:	Nothing
********************************************/
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

/**********************************************
Function:	will iterate through each part
		of the vector until it matches 
		to the iterator

Arguments:	vector and int

Returns:	boolean value
***********************************************/
bool linearSearch( const vector<int>& v, int x) 
{

vector<int>::const_iterator it;    //declare iterator
it = find(v.begin(), v.end(), x);  //search through the vector
//	*it;

	if (it != v.end()) 		//check for a match

	return true;

	else 

	return false;
}

/*******************************************
Function:	perform a binary search on 
		a vector

Arguments:	vector and int

Retuns 		boolean value
********************************************/
bool binarySearch( const vector<int>& v, int x) 
{

return binary_search(v.begin(), v.end(), x);   //returns true when matched with x

}

/***************************************************
Function:	will search through a vector
		and then build the amount of times 
		the vector was succesfully searched

Arguements:	3 vectors, boolean pointer

Returns:	totalSucCnt
****************************************************/
int search( const vector<int>& container, const vector<int>& searchNums,
            bool (*p)( const vector<int>&, int) ) 
{

int vectorSize= searchNums.size();  

int totalSucCnt = 0;  //intialize the success  count

	for(int i=0; i <vectorSize; i++)  // call the vector that is going to be searched using p as a pointer
	{
		if( p (container, searchNums[i]))	//for each successful search, incriment
		 ++totalSucCnt; 
	}

return totalSucCnt;
}

/*********************************************
Function:	sort the vector from begining
		to end.

Arguments:	vector

Returns:	Nothing
**********************************************/
void sortVec (vector<int>& v) 
{

sort( v.begin() , v.end() );  //sort the vector

}

/**************************************
Function:	print out the successful 
		searches perfomed in the 
		vectors.

Arguments:	2 ints

Returns:	Nothing
***************************************/
void printStat (int totalSucCnt, int vec_size) 
{

float avgSuc = ((float)totalSucCnt /(float) vec_size) * 100;  //calculate average success 
							      //type case float to convert ints
cout<< fixed << setprecision(2) << "Successful searches: " << setw(1) << avgSuc << "%" << endl;

}

//Main Function provided
int main() {
    vector<int> container, tobeSearched;
    genRndNums(container, 10000, 9);
    genRndNums(tobeSearched, TOBE_SEARCHED, 3);

    cout << "\nConducting linear search ..." << endl;
    int linear_search_count = search( container, tobeSearched, linearSearch );
    printStat ( linear_search_count, TOBE_SEARCHED );

    cout << "\nConducting binary search on unsorted container ..." << endl;
    int binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );

    sortVec( container );

    cout << "\nConducting binary search on sorted container ..." << endl;
    binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );

    return 0;
}
