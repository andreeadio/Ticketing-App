#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "Event.h"
#include "Ticket.h"
#include "Location.h"
#include "Date.h"
using namespace std;

enum type{concert, movie, football_match, play, other };

class Event
{
private:
	char* eventName;
	//has a Date
	//has a Location
	type eventType;
	bool isOutside;
	Date date;

public:
	Event()
	{
		this->eventName = new char[strlen("unknown") + 1];
		strcpy_s(this->eventName, strlen("unknown") + 1, "unknown");

		this->isOutside = false;
		this->eventType = other;
	}


	Event(const char* eventName,Date date):date(date)
	{
		
		if (eventName != nullptr && strlen(eventName) > 1)
		{
			this->eventName = new char[strlen(eventName) + 1];
			strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		}
		else
		{
			throw "Enter a valid event name";

		}
		this->isOutside = false;
		this->eventType = type::other;
	}
	

	void setEventName(const char* eventName)
	{
		if (eventName != nullptr && strlen(eventName) > 1)
		{
			this->eventName = new char[strlen(eventName) + 1];
			strcpy_s(this->eventName, strlen(eventName) + 1, eventName);
		}
		else
		{
			cout << "Enter a valid event name.";
		}
	}

	char* getEventName()
	{
		
		if (this->eventName != nullptr)
		{
			char* copyEventName = new char[strlen(this->eventName) + 1];
			strcpy_s(copyEventName, strlen(this->eventName) + 1, this->eventName);
			return copyEventName;
		}
		else
			return nullptr;
	}


	void setIsOutside()
	{
		this->isOutside = true;
	}

	string getIsOutside()
	{
		if (isOutside == true)
			return "Outside";
		else
			return "Inside";
	}

	void setEventType(type eventType)
	{
		if (eventType >= 0 && eventType <= 4)
			this->eventType = eventType;
	}
	
	void setEventTypeString(string type)
	{
		if (type == "concert")
			this->eventType = type::concert;
		else
			if (type == "movie")
				this->eventType = type::movie;
			else
				if (type == "play")
					this->eventType = type::play;
				else
					if (type == "football match")
						this->eventType = type::football_match;
					else
						this->eventType = type::other;
	}

	string getEventType()
	{
		switch (this->eventType)
		{
		case concert:
			return "Concert";
			break;
		case movie:
			return "Movie";
			break;
		case football_match:
			return "Football match";
			break;
		case play:
			return "Play";
			break;
		default:
			return "Event";
		}
	}

	//TODO set and get for date
	
	//copy constructor
	Event(const Event& e)
	{
		if (e.eventName != nullptr)
		{
			this->eventName = new char[strlen(e.eventName) + 1];
			strcpy_s(this->eventName, strlen(e.eventName) + 1, e.eventName);
		}
		else
		{
			this->eventName = new char[strlen("unknown") + 1];
			strcpy_s(this->eventName, strlen("unknown") + 1, "unknown");
		}
		
		this->eventType = e.eventType;
		this->isOutside = e.isOutside;

		//should copy the date
		this->date = e.date;  //see if works with the default copyctor 

	}

	Event& operator=(const Event& e)
	{
		if (this != &e)
		{
			delete[] eventName;

			if (e.eventName != nullptr)
			{
				this->eventName = new char[strlen(e.eventName) + 1];
				strcpy_s(this->eventName, strlen(e.eventName) + 1, e.eventName);
			}
			else
			{
				this->eventName = new char[strlen("unknown") + 1];
				strcpy_s(this->eventName, strlen("unknown") + 1, "unknown");
			}

			this->eventType = e.eventType;
			this->isOutside = e.isOutside;
			
			//should copy the date
			this->date = e.date;
		}

		return *this;
	}

	//destructor
	~Event()
	{
		if (this->eventName != nullptr)
		{
			delete[] this->eventName;
		}
	}
	

	// << and >> operators
	friend void operator<<(ostream& out, Event e);
	friend void operator>>(istream& in, Event& e);
};


void operator<<(ostream& out, Event e)
{
	out << endl;
	out << "Event name: " << e.eventName << endl;
	out << e.date;
	out << "Type: " << e.getEventType() << endl;
	out << "Where it takes place: " <<e.getIsOutside() << endl;
	
}

void operator>>(istream& in, Event& e)
{
	//event name
	cout << "\nEvent name: ";
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);

	if (e.eventName != nullptr)
	{
		delete[] e.eventName;
		e.eventName = nullptr;
	}
	e.setEventName(buffer);
	
	in >> e.date;

	//enum type 
	cout << "\nThe event type (concert,play,football match,movie,other): ";
	char type[100];
	in >> ws;
	in.getline(type, 99);
	e.setEventTypeString(type);

	//bool isOutside
	cout << endl << "\nIs outside? (y/n):";
	in >> ws;
	string confirmation;
	in >> confirmation;
	if (confirmation == "y") {
		e.isOutside = true;
	}
	else {
		e.isOutside = false;
	}
}

