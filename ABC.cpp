#include "ABC.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

ABC::ABC()//constructor for my base
{
	name = NULL;
	subject = NULL;
	priority_level = 0;
}
ABC::~ABC() //destructor for ABC class
{
	delete [] name;
	delete [] subject;
}
ABC::ABC(const ABC & source)//copy constructor
{
	if(source.name)
	{
		this->name = new char[strlen(source.name) + 1];
		strcpy(this->name, source.name);
	}
	else
		name = NULL;
	if(source.subject)
	{
		this->subject = new char[strlen(source.subject) + 1];
		strcpy(this->subject, source.subject);
	}
	else
		subject = NULL;
	
	priority_level = source.priority_level;

}
ABC::ABC(char * name_source, char * subject_source, int priority_level_source)//constructor with arguments
{
	this->name = new char[strlen(name_source) + 1];
	strcpy(this->name, name_source);

	this->subject = new char[strlen(subject_source) + 1];
	strcpy(this->subject, subject_source);

	priority_level = priority_level_source;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////......../
///////////////////////////////////////////////////////////////////////////////////////////////////////////////........./
zoom_meeting::zoom_meeting()//zoom meeting constructor
{
	zoom_id = NULL;
}
zoom_meeting::~zoom_meeting() //destructor
{
	delete [] zoom_id;

}
zoom_meeting::zoom_meeting(const zoom_meeting & source): ABC(source)//zoom meeting copy constructor
{
	
	if(source.zoom_id)
	{
		this->zoom_id = new char[strlen(source.zoom_id) + 1];
		strcpy(this->zoom_id, source.zoom_id);
	}
	else
		zoom_id = NULL;
}
zoom_meeting::zoom_meeting(char * name_source, char * subject_source, int priority_level_source, char * zoom_id_source): ABC(name_source, subject_source, priority_level_source) //constructor with arguments initialization list calling the base class copy constructor
{
	this->zoom_id = new char[strlen(zoom_id_source) + 1];
	strcpy(this->zoom_id, zoom_id_source);
}

int zoom_meeting::display(ostream & out) //virtual display function
{
	out << "The name of this zoom meeting: " << name << endl;
	out << "The subject of this zoom meeting: " << subject << endl;
	out << "Priority level: " << priority_level << endl;
	out << "Zoom id: " << zoom_id << endl;
	
	return 1;
}
ABC * zoom_meeting::duplicate()//virtual duplicate function to create a new class type variable
{
	return new zoom_meeting(*this);

}
int zoom_meeting::compare_priority(int key) //comparing the priority level
{
	if(key == priority_level)
	{
		display(cout);
		return 1;
	}
}
int zoom_meeting::compare_info(char * key)
{
	if(!name) return 0;
	if(strcmp(key, name)==0)
	{
		display(cout);
		return 1;
	}


}
int zoom_meeting::get_priority()
{
	if(priority_level)
		return priority_level;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////......../
///////////////////////////////////////////////////////////////////////////////////////////////////////////////........./
website::website()//website constructor
{
	URL = NULL;	
}
website::~website()//website destructor
{
	delete [] URL;
}
website::website(const website & source): ABC(source)//website copy constructor 
{
	if(source.URL)
	{
		this->URL = new char[strlen(source.URL) +1];
		strcpy(this->URL, source.URL);
	}
	else 
		URL = NULL;
}
website::website(char * name_source, char * subject_source, int priority_level_source, char * URL_source): ABC(name_source, subject_source, priority_level_source) //website constructor with arguments and initialization list to call the base class copy constructor
{
	this->URL = new char[strlen(URL_source) + 1];
	strcpy(this->URL, URL_source);
}
int website::display(ostream & out) //virtual display function
{
	out << "The name of this website: " << name << endl;
	out << "The subject of this website: " << subject << endl;
	out << "Priority level: " << priority_level << endl;
	out << "URL link: " << URL << endl;
	
	return 1;

}
ABC * website::duplicate()//virtual duplicate function 
{
	return new website(*this);

}
int website::compare_priority(int key) //virtual compare function to check if theres a match in priority level
{
	if(key == priority_level)
	{
		display(cout);
		return 1;
	}
}
int website::get_priority()//getting the priority
{
	if(priority_level)
		return priority_level;

}
int website::compare_info(char * key) //comparing the key to the current name
{
	if(!name) return 0;
	if(strcmp(key, name)==0)
	{
		display(cout);
		return 1;
	}


}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////......../
///////////////////////////////////////////////////////////////////////////////////////////////////////////////........./
sports_news::sports_news() //sports news constructor
{
	game_time = NULL;	
}
sports_news::~sports_news() //sports news destructor
{
	delete [] game_time;
}
sports_news::sports_news(const sports_news & source): ABC(source) //sports news copy constructor
{
	if(source.game_time)
	{
		this->game_time = new char[strlen(source.game_time) +1];
		strcpy(this->game_time, source.game_time);
	}
	else 
		game_time = NULL;
}
sports_news::sports_news(char * name_source, char * subject_source, int priority_level_source, char * game_time_source): ABC(name_source, subject_source, priority_level_source) //sports news copy_constructor using an initialization list 
{
	this->game_time = new char[strlen(game_time_source) + 1];
	strcpy(this->game_time, game_time_source);
}
int sports_news::display(ostream & out)//virtual display function
{
	out << "The name of this game: " << name << endl;
	out << "The type of this game: " << subject << endl;
	out << "Priority level: " << priority_level << endl;
	out << "game time: " << game_time<< endl;
	
	return 1;
}

ABC * sports_news::duplicate()//virtual duplicate function
{
	return new sports_news(*this);
}

int sports_news::compare_priority(int key) //virtual compare priority function
{
	if(key == priority_level)
	{
		display(cout );
		return 0;
	}

}
int sports_news::get_priority()//getting priority level
{
	if(priority_level)
		return priority_level;

}
int sports_news::compare_info(char * key)//comparing the key to current name
{
	if(!name) return 0;
	if(strcmp(key, name)==0)
	{
		display(cout);
		return 1;
	}


}


