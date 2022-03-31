#include "BT.h"
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

node::node()//node constructor initializing proper variables
{
	size =2;
	left = NULL;
	right = NULL;
	middle = NULL;
	information = new ABC * [size];
	for(int i=0; i<size; i++) //initializing the array
		information[i] = NULL;
}
node::~node() //destructor to deallocate all dynamic memory
{
	if(!information) return;
	
	left = NULL;
	right = NULL;
	middle = NULL;
	
	for(int i=0; i<size;i++)
		delete information[i];
	if(information) delete [] information;
	information = NULL;

}

node *& node::get_left()//getter function for left node
{
	return left;
}


node *& node::get_right()//getter function for right node
{
	return right;
}


node *& node::get_middle()//getter function for middle node
{
	return middle;
}

int node::add_info(ABC *&copy_from)//add info function to add at the leaf of the 2-3 tree 
{
	int index =0;
	
	if(!information[0]) //if we are empty, add at this index
	{
		information[0] = copy_from->duplicate();
		return 0;
	}

	else if(information[0] && !information[1]) //if we have on element, see what is less or greater and add at tht according location
	{
		if(information[0]->get_priority() <= copy_from->get_priority())
			information[1] = copy_from->duplicate();
		else 
		{	information[1] = information[0];
			information[0] = copy_from->duplicate();	
		}
		return 0;
	}
	else //otherwise if we are full, we allocate new nodes and manage the splitting and moving the nodes around according to their value of priority level. If it less than we go left, if it is greater than go right
	{	
		
		left = new node;
		middle = new node;
		if(information[0]->get_priority() > copy_from->get_priority())
		{	
			left->information[0]= copy_from->duplicate();	
			right->information[0] = information[1];
		}
		
		else if(information[1]->get_priority()  > copy_from->get_priority())
		{
			left->information[0] = information[0];
			information[0] = copy_from->duplicate();	
			right->information[0] = information[1];
		}
		else
		{	left->information[0] = information[0];
			information[0] = information[1];
			right->information[0] = copy_from->duplicate();
		}
		information[1] = NULL;
		return 1;	
	}
}

int node::insert(ABC *&copy_from)
{
	
	if(!left && !right && !middle) 
	{
		return add_info(copy_from); //base case to add the leaf

	}
	int priority = copy_from->get_priority(); //make a get priority function, 
	if(priority < information[0]->get_priority()) //checking if the info we are adding is less than, if it is insert at the left and manage the nodes properly to make sure when splitting and pushing nodes up that we don't lose any of the children or connecting ndoes. 
	{	
		
		if(left->insert(copy_from))
		{
			if(!information[1])//if not full, add at this index
			{
				information[1] = information[0];//shifting the first index to the next one
				right = middle; //right node gets the value of the middle node
				information[0] = left->information[0]; 
				node * temp = left;//holding onto left
				left = temp->left;
				middle = temp->middle;
				delete temp;
				return 0;//return 0 for not splitting
			}
			else //if full, manage and split the ndoes to maintain the balanced tree  
			{	node * temp = new node;
				temp->information[0] = information[1];
				temp->left = middle;
				temp->middle = right;
				middle = temp;
				right = NULL;
				information[1] = NULL;
				return 1;//return 1 for splitting and pushing nodes
			}
		}
	}
	else if(!information[1] || priority < information[1]->get_priority())//otherwise if this node is full and it is less than the 2nd index, we belong in the middle 
	{	if(middle->insert(copy_from))
		{
			if(!information[1])//if not full, add here
			{
				information[1] = middle->information[0];
				node * temp = middle;
				middle = temp->left;
				right = temp->middle;
				delete temp;
				return 0; //for not splitting
			}
			else//otherwise allocate a new node and manage the splitting and pushing up to maintain the tree
			{	
				node * temp = new node;
				temp->information[0] = information[0];
				information[0] = middle->information[0];
				temp->left = left;
				temp->middle = middle->left;
				left = temp;
				middle->information[0] = information[1];					
				middle->left = middle->right;
				right->right = right;
				right = NULL;
				information[1] = NULL;
				return 1; //for splitting to communicate back to the calling routine
	
			}
		}
	}
	else  
	{
		if(right->insert(copy_from))//if we are coming from the right we know we are full so only one special case to handle
		{
			node * temp = new node;
			temp->information[0] = information[0];
			temp->left = left;
			temp->middle = middle;
			information[0] = information[1];
			middle = right;
			left = temp;
			right = NULL;	
			information[1] = NULL;
			return 1;
		}

	
	}

	

}
int node::search_node(char * key)//function that checks for both indexes and compare their values
{
	if(!information)return 0;
	for(int i=0; i < size; i++)
	{
		if(information[i]->compare_info(key)==1)
			return 1;
	}		



}

int node::display(ostream & out )//display function has been overloaded
{
	information[0]->display(out );
	if(information[1])
		information[1]->display(out);
	

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////......../
///////////////////////////////////////////////////////////////////////////////////////////////////////////////........./
BT::BT()//initializing the root variable
{
	root = NULL;


}
BT::~BT()//deallocating dynamic memory
{
	delete root;
	root = NULL;

}

int BT::insert(ABC *&copy_from) //wrapper insert function
{
	if(!root)
	{
		root = new node;
		root->add_info(copy_from);
	}
	else
		return root->insert(copy_from);
	
}
int BT::display(char * key)//display by name wrapper function
{
	if(!root) return 0;
	return display(key, root);

}
int BT::display(char * key, node * current) //display recursive function
{
	if(!root) return 0;
	if(current->get_left())
		display(key, current->get_left());
	if(current->search_node(key)==1)
		return 1;
	else 
		if(current->get_middle())
			display(key,current->get_middle());
		if(current->get_right())
			return display(key, current->get_right());

}
int BT::display_all(ostream & out)//display all, operator overloaded function
{
	if(!root) return 0;
	return display_all(out, root);
}
int BT::display_all(ostream & out, node * root)//display all recurisve function
{
	if(!root) return 0;
	display_all(out, root->get_left());
	display_all(out, root->get_middle());
	display_all(out, root->get_right());
	root->display(out);
	
	
}
ostream & operator <<(ostream & out, BT & source)//overloading extraction operator 
{

	source.display_all(out);
	return out;

}

int BT::delete_all(node *&current) //delete all recurisve function
{
	if(!current) return 0;
	
	if(current->get_left()) 
		delete_all(current->get_left());
	if(current->get_middle())
		delete_all(current->get_middle());
	if(current->get_right())
		delete_all(current->get_right());
	delete current;
	current = NULL;
	return 1;
}
int BT::remove_all()//remove all wrapper function
{
	if(root)
	{		if(delete_all(root));
			cout << "Everything has been removed" << endl;
	}
	else
			cout << "There was no data saved" << endl;	
}

