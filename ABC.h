/*This is the ABC.h File where i am defining the prototypes of all my functions that I plan to implement. This includes functions in my abstract base class, and all 3 derived classes. Zoom meeting, website, and sports news. The ABC class has the proper constructor, destructor, copy constructor along with the virtual functions I plan to implement in the other classes. The Derived classes have that implementation and their unique variables in each respecive class. The implementation can be found in the ABC.cpp file"
*/
#ifndef ABC_H
#define ABC_H
#include <iostream>



class ABC //abstract base class definition
{
	public:
		ABC();  //constructor
		virtual ~ABC();  //destructor
		ABC(const ABC & source); //copy constructor 
		ABC(char *, char *, int ); //copy constructor with arguments
		virtual int display(std::ostream & out) =0; //virtual display function
		virtual int compare_priority(int key) = 0;//virtual compare priority function
		virtual int compare_info(char * key) =0;//virtual compare info function
		virtual int get_priority() =0;	 //virtual get priority function
		virtual ABC * duplicate()=0; //virtual function to return the new type of class, instead of using RTTI
	protected:
		char * name; //name or title common variable
		char * subject; //subject of the derived classes
		int priority_level;//priority level
		
};

class zoom_meeting: public ABC //zoom meeting class
{
	public:
		zoom_meeting();//constructor
		~zoom_meeting();//destructor
		zoom_meeting(const zoom_meeting & source);//copy constructor
		zoom_meeting(char *, char *, int, char *);//constructor with arguments
		int compare_priority(int key);// virtual function to compare the priority
		int get_priority();//function to get priority
		int display(std::ostream & out ); //overloaded display function
		ABC * duplicate(); //virtual duplicate function to return new class type
	        int compare_info(char * key);//comparing the name and given key
	private:
		char * zoom_id;


};

class website: public ABC
{
	public:
		website();//constructor
		~website();//destructor
		website(const website & source);//copy constuctor
		website(char *, char *, int, char *);//contructor with arguments
		int display(std::ostream & out);//operator overloaded display function
		ABC * duplicate();//virtual duplicate function that returns a new class type instead of using RTTI
		int compare_priority(int key);//comparing the priority level
		int get_priority();//getting the priority level

	        int compare_info(char * key);//comparing the name to the key
	private:
		char * URL;//URL variable
};
class sports_news: public ABC //sports news class
{
	public:
		sports_news();//constructor
		~sports_news();//destrucotr
		sports_news(const sports_news & source); //copy constructor
		sports_news(char *, char *, int, char *); //constructor with arguments
		int display(std::ostream & out); //overloaded operator display function 
		int compare_priority(int key);//compare function that check priority level to the current priority leve
		int get_priority();//getting the priority level
		ABC * duplicate(); //duplicate function
 
	        int compare_info(char * key);//info to compare the key to current name
	private:
			
		char * game_time;//variable to hold the game date and time

};
#endif
