/****************************************************
Andrew Krutke
z1756942
Assignment 9 
Due 12/02/2015

NOTE: I'm the student that talked to you
about the program not printing the labels correctly
on the first execution of the program. On the second
execution the program is correct. We seemed to fix
it but I'm going to leave this note for a just in
case.
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "assignment9.h"
#include <stdlib.h>
#include <utility>

using namespace std;

#define ASSIGNMENT9_TEST
#ifdef  ASSIGNMENT9_TEST


bool *visited;		//global variables for traversing DFS
vector<pair <int,int> > trav;

//provided main function
int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }

    graph g(argv[1]);

    g.print();

    g.traverse();

    return 0;
}
/************************************
Constructor
take an input file to build an 
adjacency list
************************************/
graph::graph( const char* filename )
{

//open inout file used to build adj matrix
ifstream infile;
infile.open("assignment9input.txt");

if(infile.fail())	//make sure input file was provided
	{
	cout << "input file failed to open" <<endl;
	exit(-1);
	}

infile>>size;	//store the size of the graph for use

for(int i=0 ; i < size; i++) 	//loop through to store the letters of the
	{
	char letters;
	infile >> letters;
	labels.push_back(letters);
	}
list<int> temp_list; //temp list for storage

for(int j=0; j < size; j++)   //loop through to skip over the first part of the matrix and store values
	{
	char adj_begin;
	infile >> adj_begin;

	for(int k=0; k < size; k++)  //loop through to find the edges in the column
		{
		int adj_num; infile >> adj_num; //read in and store the edges of the graph

			if(adj_num == 1)
			{
			temp_list.push_back(k);   //store index into temp_list
			}
		}

adj_list.push_back(temp_list);	//store the temp list into the adj_list

temp_list.clear();	//clear the temp list

	}
infile.close();
}

/********************************************
traverse function
traverse the graph searching for unvisited 
nodes in the graph make calls to depth_first
when a node is not visited
*********************************************/
void graph::traverse( ) const
{
visited = new bool[size];

	for(int i=0; i<size;i++) //make sure everything is set to false for proper visiting
		{
		visited[i]=false;
		}

cout<<"------- travere of graph ------" <<endl;

for(int i=0; i < get_size(); i++)  //failed attempt to loop through this thing
	{
		if(!visited[i])
		{
		depth_first(i);		//call DFS for i since it's not visited
		}
	}

cout<<endl;

for(unsigned j=0; j < trav.size(); j++)	//print out the pair to see the connected vertexs
{
	cout<<"("<< labels[trav[j].first]<< ","<<labels[trav[j].second]<<")"<<" ";  //print out the labels of connected vertexs
}
cout << endl;

	delete[] visited;	//delete visited to reloop
cout<< "--------- end of traverse -------" <<endl;

}
/**************************************
depth_first function
perform depth first search traversal
on the adj_matrix in the input file
***************************************/
void graph::depth_first(int v) const
{
visited[v]=true;	//mark the vertex as visited

cout << labels[v]<< " ";

list<int>::const_iterator gIt;

for(gIt=adj_list[v].begin(); gIt!=adj_list[v].end(); ++gIt)  //loop through to search the 
	{
	int w = *gIt;

		if(!visited[w])  //check if a vertex is visited
		{
		trav.push_back(make_pair (v, w));  //make a pair  on the vertex's
		
	depth_first(w);		//recursve call to depth_first for a new vertex
		}
	}
}

/******************************
Print function:
Print the contents of the graph
and the traversal of the graph
*******************************/
void graph::print( ) const  
{
list<int>::const_iterator lit;

cout<<"Number of vertices in the graph: "<<size << endl;
cout<< endl;
cout<<"-------- graph ------- "<<endl;

for(int i=0; i<get_size(); i++)  //print the labels of the graph out
{ 
	cout<<labels[i]<<" : ";

for(lit=adj_list[i].begin(); lit!=adj_list[i].end(); lit++)
	{
	cout<<labels[*lit]<<", ";  //print the contents of the list
	
	}
	cout<<endl;
}
cout<<"------- end of graph ------ " <<endl;
cout<<endl;
}

#endif

