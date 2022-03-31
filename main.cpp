#include "BT.h"
#include "ABC.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;
/*My name is Mohamed Esmail. In this main.cpp file is where I test the implementation of the functions I have created in the .h and.cpp files. Below is a menu user interface to help the user decide what they want to organize different information sources. The main goal of this program is to experience operator overloading in an object oriented program, while tackling the difficult concept of balanced 2-3 trees. Since that is the chosen data structure, I will go over the functions and classes in their appropriate files.*/
int main()
{
	int SIZE = 100;
	bool running = true;
	BT my_tree;
	/*
	ifstream file_in;
	file_in.open("information.txt", ios::in);
	char name[SIZE];
	char subject[SIZE];
	char 
	if(!file_in.eof())
	{	
		while(getline(file_in, name, subject,source, ',');

	
	*/
	
	while(running) 
	{
		int main_choice;
		
		cout << "Welcome to the info organizor where we are organizing important info \n Enter 1 for zoom meetings \n Enter 2 for websites \n Enter 3 for sports info " << endl;
		cin>>main_choice;
		cin.ignore(100, '\n');

		if(main_choice ==0)
			running = false;
		else if(main_choice == 1) //prompt the user for the types of information
		{
			//defining the proper variables to take in the input from the user
			int zoom_choice = 0;
			char name_source[SIZE];//creating variable for name
			char subject_source[SIZE];//variable for the subject of the zoom meeting
			char zoom_id_source[SIZE];	//zoom id
			int priority_level_source;//priority level
			
			//prompting the user for options to add, remove, display, or retrieve
			cout << "Enter 1 to add a new zoom meeting lecture \n Enter 2 to remove all \n Enter 3 to display all in the tree\n Enter 4  to retrieve by  name" << endl;
			cin>>zoom_choice;
			cin.ignore(100, '\n');

			if(zoom_choice == 1)
			{
				cout << "Please enter the title of this zoom meeting\n" << endl;
				cin.get(name_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				cout << "What is the subject of this zoom meeting\n" << endl; 
				cin.get(subject_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				cout << "What is the priority level of this meeting? Between 1 and 5. 1 being highest priority, 5 being lowest." << endl;
				cin >> priority_level_source;
				cin.ignore(SIZE, '\n');

				cout << "What kind of food does this restaurant serve" << endl;
				cin.get(zoom_id_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				ABC * temp = new zoom_meeting(name_source, subject_source, priority_level_source, zoom_id_source); 
				my_tree.insert(temp);
			}
			else if(zoom_choice ==2)
			{
				cout << "We are now removing everything \n" << endl;
				my_tree.remove_all();
			}
			else if(zoom_choice==3)
			{
				cout << my_tree;

			}
			else if(zoom_choice==4)
			{
				
				cout << "Please enter the name of the zoom meeting you'd like to retrieve" << endl;
				cin.get(name_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				my_tree.display(name_source); 
			}
		
		}
		else if(main_choice==2)//website choice
		{
			
			int website_choice = 0;
			char name_source[SIZE];//creating variable for website name name
			char subject_source[SIZE];//variable for subject of website
			char URL_source[SIZE];//URL source variable	
			int priority_level_source; //priority level variable
			cout << "Please enter 1 to add a new website \n Enter 2 to remove everything\n Enter 3 to display everything in the tree \n Enter 4 to retrieve a website by name " << endl;

			cin >> website_choice; 
			cin.ignore(100, '\n');

			if(website_choice ==1)
			{

				cout << "Please enter the title of this website\n" << endl;
				cin.get(name_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				cout << "What is the subject of this website\n" << endl; 
				cin.get(subject_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				cout << "What is the priority level of this meeting? Between 1 and 10. 1 being highest priority, 10 being lowest." << endl;
				cin >> priority_level_source;
				cin.ignore(SIZE, '\n');

				cout << "Enter the URL" << endl;
				cin.get(URL_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				ABC * temp = new website(name_source, subject_source, priority_level_source, URL_source); 
				my_tree.insert(temp);
			}
			else if(website_choice ==2)
			{
				cout << "We are now removing everything \n" << endl;
				my_tree.remove_all();
			}
			else if(website_choice==3)
			{
				cout << my_tree;

			}
			else if(website_choice==4)
			{
				cout << "Please enter the name of the website you'd like to retrieve" << endl;
				cin.get(name_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				my_tree.display(name_source); 
	
			}
		
		}
		else if(main_choice ==3)
		{
			//zoo option
			int sports_choice = 0;
			char name_source[SIZE];//creating variable for sports name
			char subject_source[SIZE];//variable for the subject
			char game_source[SIZE];//game date and time variable	
			int priority_level_source;//priority level variable
			
			
			cout << "Please enter 1 to add a new sports news \n Enter 2 to remove everything\n Enter 3 to display everything in the tree \n Enter 4 to retrieve a sports news by name " << endl;
			if(sports_choice ==1)//prompting for their choice
			{

				cout << "Please enter the title of this sports game. For example, NBA finals\n" << endl;
				cin.get(name_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				cout << "Enter the type of sport\n" << endl; 
				cin.get(subject_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				
				cout << "What is the priority level of this game? Between 1 and 10. 1 being highest priority, 10 being lowest." << endl;
				cin >> priority_level_source;
				cin.ignore(SIZE, '\n');

				cout << "What is the date and time of this game?" << endl;
				cin.get(game_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');

				ABC * temp = new website(name_source, subject_source, priority_level_source, game_source); 
				my_tree.insert(temp);


			}
			else if(sports_choice ==2)
			{
				cout << "We are now removing everything \n" << endl;//calling remove all function
				my_tree.remove_all();
			}
			else if(sports_choice==3)
			{
				cout << my_tree; //using extraction operator overloading function

			}
			else if(sports_choice==4)
			{
				cout << "Please enter the name of the sports news you'd like to retrieve" << endl;
				cin.get(name_source, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				my_tree.display(name_source); 
			}
		}

	}
	
}	
