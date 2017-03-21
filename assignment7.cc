/*******************************
Andrew Krutke
z1756942
Assignment 7 
Due 11/6/2015
********************************/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdlib>

#define ITEM_W  4
#define NO_ITEMS 10

using namespace std;

//Function Prototypes
void build_heap(vector<int> & v, int heap_size, bool (*compar)(int, int) );
void heapify(vector<int> & v, int heap_size, int r, bool (*compar)(int, int));
bool less_than(int e1, int e2);
bool greater_than(int e1, int e2);
void heap_sort(vector<int> & v, int heap_size, bool(*compar)(int, int));
int extract_heap(vector<int> &v, int& heap_size, bool (*compar)(int, int));
void print_vector(vector<int> &v, int pos, int size);

//Main Function provided
int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake    
    int heap_size = 24;
    for (int i=1; i<=heap_size; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+heap_size+1 );
    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, heap_size );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
   build_heap(v, heap_size, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, heap_size );
    
    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
   build_heap(v, heap_size, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, heap_size );
                        
    return 0;
}
/********************************
Build Heap
build a heap using heapify
*********************************/
void build_heap(vector<int> & v, int heap_size, bool (*compar)(int max, int min))
{
	for(int i = heap_size/2;  i > 0 ; i--)
		{
		heapify(v, heap_size, i, *compar);   //call to heapify to structure the heap
		}
}

/*************************************
Heapify Function
heapify the tree at the root postion
and compare for which side the parent 
value will be
**************************************/
void heapify(vector<int> & v, int heap_size, int r, bool (*compar)(int, int ))
{
//values to determine left and right trees for the heap
int left= 2*(r);
int right = 2*(r)+1;
int largest=r/2;

if(left <= heap_size && compar(v[left],v[r]))  //move the value to the left
	{
	largest= left;
	}
else	
{
largest = r;
}

	if( right <=  heap_size && compar(v[right],v[largest])) //move the value to the right
	{
	largest=right;
	}

if(largest != r)  //if larget is not temp the value to then call recursive heapify
	{
	int temp = v[r];	//swap r and largest
	v[r]=v[largest];
	v[largest] = temp;
	
	heapify(v, heap_size, largest, *compar); //recursive call to heaify to go back through the heap
	}
}
/****************************
less than function
compare two ints to use that will
used as predicate
*****************************/
bool less_than(int e1, int e2)
{

if(e1 < e2)
	
	return true;

else 
	return false;

}

/*******************************
Great Than Function
compare two ints to use that will 
used as predicate
********************************/
bool greater_than(int e1, int e2)
{
if(e1 > e2)

	return true;

else

	return false;
}

/*******************************
Heap Sort Function
sort the contents of the heap 
and move them into a sorted vector
********************************/
void heap_sort(vector<int> & v, int heap_size, bool(*compar)(int, int ))
{
//call build heap	
build_heap(v, heap_size, *compar);
	
	//loop through the heap
	for(int i = heap_size;  i > 0 ; i--)
	{
	v[i]=extract_heap(v, heap_size, *compar); //assign the vector postion to recursize extract_heap
	
	}
	
}

/*******************************************
Extract heap Function
extracts the root of the heap
and fills it with the last element in the 
current heap then returns the old root value
********************************************/
int extract_heap (vector <int> &v, int& heap_size, bool (*compar)(int, int))
{
int temp;
 if(heap_size < 1)
	{	
	//error if the heapsize is too small
	cout << "error: heap underflow";
	return 0;
	}
else 
	{		//move through the heap to find th min value
	temp = v[1];
	v[1] = v[heap_size];  //swap around  the root
	heap_size=heap_size-1;   //decrease the size of the heap as it is moved through
	heapify(v, heap_size, 1, *compar); //invoke recurisve heapify
	}
	

return temp;  //return the value before it was  swapped
}

/********************************
Print Vector function
Print the contents of the heap
*********************************/
void print_vector(vector<int>& v, int pos, int size)
{
int endline=0;
vector<int>::iterator pVec;  //iterator to move through the vector

	for(pVec = v.begin()+1;pVec!=v.end();++pVec) //print contents found in the vector
	{ 
	cout <<setw(ITEM_W)<<*pVec;
	endline++;

		if(endline == NO_ITEMS)	//make sure the printing wraps
		{
		cout << "\n";
		endline=0;
		}
	}
cout << "\n";
}

