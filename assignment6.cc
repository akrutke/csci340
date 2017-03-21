/************************************
Andrew Krutke
z1756942
Assignment6
Due 10/30/2015
*************************************/
#include <iostream>
#include "assignment5.h"
#include "assignment6.h"

using namespace std;

//------------------------------Public Member Functions-----------------------
/*************************************
Public member insert that will make
recursive calls to private member
insert
**************************************/
void BST::insert(int val)
{
	insert(root, val);  //call the private insert member
}


/*************************************
Public member search that will make
recursive calls to private member
searcg
**************************************/
bool BST::search(int val)
{
	return(search(root, val));	//call the private search member

}

/*************************************
Public member remove that will make
recursive calls to private member
remove
**************************************/

bool BST::remove(int val)
{
	return(remove(root, val));	//call the private remove member
	
}

/*************************************
Public member print that will make
recursive calls to private member
print
**************************************/

void BST::printLeftLeaves()
{
	printLeftLeaves(root); //call private print member
}


/*************************************
Public sumAncestors insert that will make
recursive calls to private member
sumAncestors
**************************************/

void BST::sumAncestors(int val, int& sum)
{
	sumAncestors(root,val, sum); //call the private sumAncestors member
}

//-----------------------------Private Member Functions---------------------------

/*************************************
private insert function
returns nothing inserts values into 
the BST based on being larger or
smaller than the root
**************************************/
void BST::insert(Node * &ptr, int val)
{
	if(ptr==NULL)	//check if the value being passed in exsists
		ptr = new Node(val);	//create a temp value if it does not
	else 
		{
			if(val < ptr -> data)	//if val is less than the root
				insert(ptr->left,val);	//insert left
			else				//if val is greater than the root
				insert(ptr->right,val);	//insert right
		}
}

/**********************************
Pivate search function
returns boolean value 
and calls search recursivly to
check the values against the root
***********************************/
bool BST::search(Node* &ptr, int val)
{
if(ptr == NULL) //check if root is empty
	return false;
else
{
if(val == ptr-> data)  //check value in the root
	return true;

else if(val < ptr->data)		//check if the value being searched for is less than the root
	return search(ptr->left, val);		//if it is return left
	else return search(ptr->right,val);	//if it is not return right

}

}

/**************************************
Private remove function
returns boolean value after searching
the left and right nodes of BST. Three
cases are searched: a node with a leaf
2 children node and 1 children node
***************************************/
bool BST::remove(Node* &ptr, int val)
{

Node * tempPtr;
//int data;
 if (ptr==NULL)   //check if the tree is empty 
 {
 return false;
 }
 if(ptr->data > val)  //check if left subtree
 {
 return(remove(ptr->left,val));
 }
 if(ptr->data < val)   //check if right subtree
 {
 return(remove(ptr->right,val));
 }

	//two children case
	if(ptr->right!=NULL && ptr->left!=NULL)
		{
		tempPtr=ptr->left;	//set the pred

		while(tempPtr->right!=NULL)	//search it if it has a right child
		  {
		   tempPtr=tempPtr->right;	//set it
		  }
		ptr->data=tempPtr->data;	//set the value for removal
		return(remove(ptr->left, tempPtr->data)); //remove the node with two children	
		}
		
		//leaf case
		else if(ptr->left == NULL && ptr->right == NULL)
		{
		delete ptr;
		ptr=NULL;	//set the ptr to null for leaf case after deleting storage
		}

			else if(ptr->left==NULL)  //one child case on left
		        {
        		tempPtr=ptr;
 		        ptr=ptr->right;		//put the right tree back into BST
			delete tempPtr;		//free memory
	       		}
                	else if(ptr->right==NULL)    //one child case on right
                	{
			tempPtr=ptr;
                	ptr=ptr->left;	//put the left tree back into the BST
                	delete tempPtr;		//free memory
                	}

return true;
}

/**********************************
Private printLeftLeaves
print the left leaves in the BST
***********************************/
void BST::printLeftLeaves(Node* ptr)
{
if(ptr!=NULL)	//make sure the tree is not null
{
	if(ptr->left!=NULL && ptr->left->left==NULL&&ptr->left->right==NULL)   //make sure that there are parts in the tree to print
	{
	cout<< ptr->left->data <<" ";  //print the left node
	}
 printLeftLeaves(ptr->left);			//recursive call to printLeftLeaves
 printLeftLeaves(ptr->right);
}

}

/*********************************
private sumAncestors
take the ptr, val and passed in 
sum from main and total up the 
ancestors of the node being looked
at
**********************************/
bool BST::sumAncestors(Node *ptr, int val, int& sum)
{
//check if the BST is empty
if(ptr==NULL)
	return false;	

	if(ptr->data == val)	//if it's not empty move  execute
	return true;

if(sumAncestors(ptr->left,val,sum) || sumAncestors(ptr->right,val,sum)) //recursive call to sumAncestors to search the tree for ancestors
{
	sum+=ptr->data;	//add up the value of the nodes ancestors that is being looked at
	return true;
}
return false; 
}


