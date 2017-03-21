
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
#include "assignment5.h"

using namespace std;

/**************************************

Default Constructor

Function:       build the binary tree

***************************************/
binTree::binTree()
{
        root = NULL;  //construct the binary tree
}

/***************************************

insert

Function:       use private member insert
                to move val to the tree

****************************************/
void binTree::insert(int val)
{
        insert(root, val);  //call for the private member insert
}

/************************************
height

Function:       access private height
                member

Retuns:         private member height

*************************************/
unsigned binTree::height() const
{
        return height(root);  //call for the private member height
}


/************************************

size

Function:       call private member size

Returns:        private member size(root)

*************************************/
unsigned binTree::size() const
{
        return size(root);  //call to private member size

}
/**********************************************
inorder

Function:       call private member inorder

Returns:        private member inorder

Arguments:      void * ptr, int data

**********************************************/
void binTree::inorder(void(* ptr)(int data))
{
        return inorder(root, ptr);      //call for the private member inorder

}
/******************************************
preorder

Function:       call private member preorder

Returns:        private memebr preorder

Arguments:      int data, void * ptr

******************************************/
void binTree::preorder(void(* ptr)(int data))
{
        return preorder(root, ptr);  //call for the private member preorder
}

/********************************************
postorder

Function:       call private member postorder

Returns:        private member postorder

Arguments:      void * ptr, int data

********************************************/
void binTree::postorder(void(* ptr)(int data))
{
        return postorder(root, ptr);    //call for the private member postorder
}


//Private Members----------------------------------------------------------------$

/**************************************

Private insert

Function:       insert information into
                the nodes of the tree

Arguments:      node *&ptr, int val

***************************************/
void binTree::insert(Node *&ptr, int val)
{

        if(ptr == NULL)
        {
        ptr= new Node(val);             //make a new node to store val
        }
                else
                {
                int leftheight = height(ptr->left);     //set the heights for ins$
                int rightheight= height(ptr->right);

                        if(leftheight <= rightheight)           //compare left an$
                        {
                        insert(ptr->left, val);                 //insert into the$
                        }
                        else
                        {
                        insert(ptr->right, val);
                        }
                }
}


/*************************************

Private height

Function:       find the height of the
                binary tree

Returns:        the max height of the
                trees


Arguments:      node* ptr


***************************************/
unsigned binTree::height(Node* nodeVal) const
{
if(nodeVal == NULL)     //check if ptr is empty

        return 0;

else                    //find the max height of the current tree

        return std::max(height(nodeVal->left), height(nodeVal->right))+1;

}

/****************************************

Private Size

Function:       find the max size of
                information going into
                the tree

Returns:        the size of the tree

Arguments:      Node* ptr

*****************************************/
unsigned binTree::size(Node* ptr) const
{

if(ptr == NULL)
        return 0;

else            //access left and right node to find their size
        return size(ptr->left) + size(ptr->right)+1;
}


/***********************************

Private inorder

Function:       sort the binary tree in
                inorder

Arguments:      node* nodeVal, void(*ptr)
                (int data)

************************************/
void binTree::inorder(Node* nodeVal, void(* ptr)(int data) )
{

if(nodeVal != NULL)             //run inorder sorting of the binary tree
        {
                inorder(nodeVal->left, ptr);
                ptr(nodeVal->data);
                inorder(nodeVal->right, ptr);
        }
}


/************************************

Private preorder

Function:       sort the tree in
                preorder

Arguments:      node* nodeVal,
                void(*ptr)(int data)

*************************************/
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

/**************************************

Private postorder

Function:       sort the binary tree in
                post order

Arguments:      node* nodeVal,
                void(*ptr)(int data)

**************************************/
void binTree::postorder(Node * nodeVal, void(* ptr)(int data))
{
if(nodeVal != NULL)
        {                       //run postordersorting of binary tree
                postorder(nodeVal->left, ptr);
                postorder(nodeVal->right, ptr);
                ptr(nodeVal->data);
        }
}


#ifdef BINTREE_MAIN
//------------------------------------------------
// Do not modify this section of code
//------------------------------------------------
const int MAX_SIZE = 1000;
const int MAX_COUNT = 20;
const int WIDTH = 5;
const int ROW_SIZE = 5;
int mcount = 0;
int rcount = 0;

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}
//--------------------------------------------
// End
//--------------------------------------------                        
                        




//-------------------------------------------
// Do not modify this section of code
//-------------------------------------------
//#define BINTREE_MAIN
//#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);    
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );
    //mcount = rcount = 0;
    //for_each( v.begin(), v.end(), display );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}


//---------------------------------
// End
//--------------------------------                                             
#endif                                              

