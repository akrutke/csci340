/**************************************
Andrew Krutke
z1756942
Assignment 4 
Due October 2 2015

***************************************/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <iomanip>

#define NO_ITEMS 3	//global constants
#define ITEM_W   16

using namespace std;

/*******************************************
Function:       make words lower case

Arguments:      char

Returns:        nothing
********************************************/
void low(char& x)
{

x=tolower(x);

}

/***************************************************
Function: 	Print words inside the map

Arguments:	const map

returns:	nothing	
****************************************************/
void print_words( const map<string, int>& m) 
{
int end_line = 0;
int clean_words = 0;		//clean words to store

map<string, int>::const_iterator printit;	//declare an iterator to print


	for( printit = m.begin(); printit!= m.end(); printit++ )
	{                                        //printing formatting for a map
		cout << left << setw(ITEM_W) << printit->first << "= " << setw(NO_ITEMS) << printit->second;

		end_line++;		//increment count to reset the line

		clean_words += printit->second;	//move through the map

	if( end_line == 3 )		//check if the end of the line is met

	{ 
		cout << endl; 

		end_line = 0; 
	}

	}



cout << endl << "Number of words in input stream: " << clean_words << endl;  //find the number of clean words in input
cout <<  "Number of words in outputlist: " << m.size() << endl;			//and the total number of clean words in output


}

/************************************************
Function:	cleans a words of punctuation

Arguments:	two strings 

returns:	nothing
*************************************************/
void clean_entry( const string& not_clean, string& clean) 
{

unsigned int start;
string temp;
for ( start = 0; start < not_clean.length(); start ++)
	{

	if( isalnum (not_clean[start] ) )break ;      //check for words with symbols

	}
unsigned int end;
for ( end = start; end < not_clean.length(); end++)
	{

	if ( !isalnum( not_clean[end] ) )break;		//check for the words without symbols

	}

clean = not_clean.substr(start, end-start);		//store the words into a substring

for_each(clean.begin(), clean.end(), low);		//convert the words to lowercase

}

/*********************************************
Function:	take words from inputstream
		save words into the map 
		container when they are clean.

Arguments:	map container and ifstream


Returns:	Nothing
**********************************************/
void get_words( map<string, int>& m, ifstream& input ) 
{

string clean, not_clean;

map<string, int>::const_iterator mit;                //map iterator

        input >> clean;		//store the inputfile into string clean to be iterated

        while(!input.eof())             //read tell end of file
        {
        not_clean = "";			//initialize notclean

	clean_entry(clean, not_clean);	//call clean entry to store words

		if((int)not_clean.length()>0)  
		{
		m[not_clean]++;
		}

	input >> clean;

	}

}



//provided main function
int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "command line argument: input-file-name" << endl;
        return 1;
    }

    ifstream infile(argv[1], ios::in);

    map<string, int> m;

    get_words( m, infile );

    infile.close();

    print_words( m );

    return 0;
}




