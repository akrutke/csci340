/******************************************
Andrew Krutke
z1756942
Assignment3
Due 9/21/15
*******************************************/

#include <set>
#include <algorithm>
#include <iostream>
#include <iomanip>


//Global Constants
#define NO_ITEMS 10
#define ITEM_W   5

using namespace std;

/**************************************
Function:	Find prime numbers

Arguments:	set of ints, int

Returns:	nothing
***************************************/
void sieve( set<int>& s, int n) 
{
	for(int i = 2; i < n +1; i++)  //find  prime numbers
		{
			s.insert(i);  //insert i into the vector so long as it is prime
		}
	
	for(int m = 2; m < n; m++)   //test for multiples of prime numbers
		{
			for (int k = m * m; k <= n; k += m)  //if a non-prime number is found remove it
			{
				s.erase(k);  //via erase
			}
		} 

}

/*************************************
Funtion		Print out the content
		of the set

Arguments	set of ints

Returns		nothing
**************************************/
void print_primes( const set<int>& s) 
{

int endLine = 0;       // initialze counter
set <int>::const_iterator it;

cout<< endl;
cout << "There are " << s.size() <<" prime numbers." << endl; //show the number of prime numbers 
cout<< endl;

	for(it = s.begin(); it != s.end(); ++it)     // loops through set
        {
		cout << setw(ITEM_W) << *it;
		endLine++;   // prints each element in se

		if (endLine == NO_ITEMS)
                {
                cout << endl;   // creates new line every NO_ITEMS
                endLine = 0;   // reset the line counter
                }


	}

cout << "\n";//prevent bad formatting in command line
cout<< endl;
}

//Main function provided
int main() {
    set<int> s;
    sieve(s, 1000);
    print_primes(s);
    return 0;
}



