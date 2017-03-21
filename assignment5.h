#ifndef ASSIGNMENT5_H
#define ASSIGNMENT5_H

/****************************************
Andrew Krutke
z1756942
Assignment 5
Due 10/14
*****************************************/
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iostream>

//using namespace std;

//--------------------------
// You need to add definition of the Node class
//--------------------------

//Class Node
class Node{

	friend class binTree;   //friend class declaration
	friend class BST;

        Node(int d){data=d; left = NULL; right = NULL;}         //defualt constructor

        private:                //private data members of the Node class
                int data;
                Node* left;
                Node* right;

};

//Class binTree
//Provided
class binTree{
    
    public:
        binTree();
        virtual void insert( int );
        unsigned height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );

    protected:
        Node* root;
    private:
        void insert( Node*&, int );
        unsigned height( Node* ) const;
        unsigned size( Node* ) const;
	void inorder( Node*, void(*)(int) );
	void preorder( Node*, void(*)(int) );
	void postorder( Node*, void(*)(int) );
};
#endif
//Public Members--------------------------------------------------

/**************************************

Default Constructor

Function:	build the binary tree

***************************************/
/*
binTree::binTree()
{
	root = NULL;  //construct the binary tree
}
*/
/***************************************

insert

Function: 	use private member insert
		to move val to the tree

****************************************/
/*
void binTree::insert(int val)
{
	insert(root, val);  //call for the private member insert
}
*/
/************************************
height

Function:	access private height
		member

Retuns:		private member height

*************************************/
/*
unsigned binTree::height() const
{
	return height(root);  //call for the private member height
}
*/
/************************************

size

Function:	call private member size

Returns:	private member size(root)

*************************************/
/*
unsigned binTree::size() const
{
	return size(root);  //call to private member size

}
*/
/**********************************************
inorder

Function: 	call private member inorder

Returns:	private member inorder

Arguments:	void * ptr, int data

**********************************************/
/*
void binTree::inorder(void(* ptr)(int data))
{
	return inorder(root, ptr);	//call for the private member inorder

}
*/
/******************************************
preorder

Function:	call private member preorder

Returns:	private memebr preorder

Arguments:	int data, void * ptr

******************************************/
/*
void binTree::preorder(void(* ptr)(int data))
{
	return preorder(root, ptr);  //call for the private member preorder
}
*/
/********************************************
postorder

Function:	call private member postorder

Returns:	private member postorder

Arguments: 	void * ptr, int data

********************************************/
/*
void binTree::postorder(void(* ptr)(int data))
{
	return postorder(root, ptr);	//call for the private member postorder
}
*/

//Private Members---------------------------------------------------------------------

/**************************************

Private insert

Function:	insert information into
		the nodes of the tree

Arguments:	node *&ptr, int val

***************************************/
/*
void binTree::insert(Node *&ptr, int val)
{

	if(ptr == NULL)
	{
	ptr= new Node(val);		//make a new node to store val
	}
		else
		{
		int leftheight = height(ptr->left);	//set the heights for insert
		int rightheight= height(ptr->right);
		
			if(leftheight <= rightheight)		//compare left and right right
			{
			insert(ptr->left, val);			//insert into the smaller
			}
			else
			{
			insert(ptr->right, val);
			}
		}
}
*/
/*************************************

Private height

Function:	find the height of the 
		binary tree

Returns: 	the max height of the 
		trees


Arguments:	node* ptr

***************************************/
/*
unsigned binTree::height(Node* nodeVal) const
{
if(nodeVal == NULL)	//check if ptr is empty
	
	return 0;

else			//find the max height of the current tree

	return std::max(height(nodeVal->left), height(nodeVal->right))+1;

}
*/
/****************************************

Private Size

Function:	find the max size of 
		information going into 
		the tree

Returns:	the size of the tree
	
Arguments:	Node* ptr

*****************************************/
/*
unsigned binTree::size(Node* ptr) const
{

if(ptr == NULL)
	return 0;

else		//access left and right node to find their size
	return size(ptr->left) + size(ptr->right)+1; 
}
*/
/***********************************

Private inorder

Function:	sort the binary tree in 
		inorder

Arguments:	node* nodeVal, void(*ptr)
		(int data)

************************************/
/*
void binTree::inorder(Node* nodeVal, void(* ptr)(int data) )
{

if(nodeVal != NULL)		//run inorder sorting of the binary tree
	{
		inorder(nodeVal->left, ptr);
		ptr(nodeVal->data);
		inorder(nodeVal->right, ptr);
	}
}
*/
/************************************

Private preorder

Function:	sort the tree in 
		preorder

Arguments:	node* nodeVal, 
		void(*ptr)(int data)

*************************************/
/*
void binTree::preorder(Node* nodeVal, void(* ptr)(int data))
{
if(nodeVal != NULL)
	{
				//run preorder sorting of binary tree
	ptr(nodeVal->data);
	preorder(nodeVal->left, ptr);
	preorder(nodeVal->right,ptr);

	}
}
*/
/**************************************

Private postorder

Function:	sort the binary tree in 
		post order

Arguments:	node* nodeVal, 
		void(*ptr)(int data)

**************************************/
/*
void binTree::postorder(Node * nodeVal, void(* ptr)(int data))
{
if(nodeVal != NULL)
	{			//run postordersorting of binary tree
		postorder(nodeVal->left, ptr);
		postorder(nodeVal->right, ptr);
		ptr(nodeVal->data);
	}
}
*/ 



