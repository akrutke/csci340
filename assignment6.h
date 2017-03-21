/************************************
Andrew Krutke
z1756942
Assignment6
Due 10/27/2015
*************************************/
#ifndef ASSIGNMENT6_H
#define ASSIGNMENT6_H

#include "assignment5.h"
//provided main
class BST : public binTree {

    public:
        BST() : binTree() {}
        void insert( int );
        bool search( int );
        bool remove( int );
	void printLeftLeaves();
	void sumAncestors(int, int&);
    
    private:
        void insert( Node*&, int );
        bool search( Node*&, int );
        bool remove( Node*&, int );
	void printLeftLeaves(Node*);
	bool sumAncestors(Node*,int, int&);

};

#endif
