/*This is my Balanced Tree .h file where I have the prototypes of the functions I plan to implement and the classes that I have defined. In this file contains the node class and the balanced tree class that have the proper constructors and destructors, copy constructors, and necessary insert, remove, and display functions that belong in the data sttructure BT class. In the node class I have the proper getter functions to be able to access the node's data since the nodes are protected to shield our info from the client.
*/

#include "ABC.h" 
#ifndef BST_H
#define BST_H
#include <iostream>

class node
{
	public:
		node();//constructor
		~node(); //destructor 
		node *& get_right();//getting right node
		node *& get_left();//getting left node
	 	node *& get_middle();//getting middle node 
		int add_info(ABC *&copy_from); //helper function that deals with special cases for 2-3 tree
		int insert(ABC *&copy_from);//insertion function that handles special cases for 2-3 tree
		int search_node(char *key);//function that checks both indexes of node
		int display(std::ostream & out); //overloaded display function
	private:
		int size;//size of the indices of the node variable
		node * left;//left node
		node * right;//right node
		node * middle; //middle node 
		ABC ** information; 
};

class BT //balanced_tree
{
	public:
		BT();//constructor
		~BT(); //destrcutor
		friend std::ostream & operator <<(std::ostream &, BT &); //overloading the << extraction operator
		int insert(ABC *&copy_from); //insertion wrapper function 
		int remove_all(); //wrapper for remove all functoin 
		int display(char * key);//display by key wrapper function 
		int display_all(std::ostream & out); //display all function
		//int retrieve(char * key);
	private:
		int display(char * key, node *current); //recursive display all
		node * root; //root of the tree
		int delete_all(node *&current); //helper function to help remove all nodes from tree

		int display_all(std::ostream & out, node * root);//helper function to display all nodes in the tree
};

#endif
