#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

enum type{concert, movie, football_match, play, other };
enum month{January=1, February, March, April, May, June, July, August, September, October, November, December};

class Event
{
private:
	char* eventName;
	
	int year;
	int day;
	month monthName;

	char time[5];
	type eventType;
	bool isOutside;

	static int CURRENT_YEAR;
	static int MAX_YEAR;

	Event()
	{
		strcpy_s(this->eventName, strlen("unknown") + 1, "unknown");
		this->year = CURRENT_YEAR;
		this->day = 5;					//current day
		this->monthName = month::December;//current month
		strcpy_s(time, 5, "00:00");
		this->isOutside = false;
		this->eventType = other;
	}

public:
	Event(const char* eventName, int dd, month mm, int yy,const char* time)
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

		if (yy >= CURRENT_YEAR && yy <= MAX_YEAR)
		{
			this->year = yy;
		}
		else
		{
			throw "Enter a valid year";
		}

		this->day = dd;
		this->monthName = mm;

		if (time != nullptr && strlen(time)==4)
		{
			strcpy_s(this->time, 5, time);
		}
		this->isOutside = false;
		this->eventType = other;

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


	bool setIsOutside()
	{
		this->isOutside = true;
	}

	void setEventType(type eventType)
	{
		if (eventType >= 0 && eventType <= 4)
			this->eventType = eventType;
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

	void setMonth(month mm)
	{
		if (mm >= 1 && mm <= 12)
			this->monthName = mm;
		else
			cout << "Enter a valid month";

	}

	string getMonth()
	{
		switch (this->monthName)
		{
			case January:
				return "January";
				break;
			case February:
				return "February";
				break;
			case March:
				return "March";
				break;
			case April:
				return "April";
				break;
			case May:
				return "May";
				break;
			case June:
				return "June";
				break;
			case July:
				return "July";
				break;
			case August:
				return "August";
				break;
			case September:
				return "September";
				break;
			case October:
				return "October";
				break;
			case November:
				return "November";
				break;
			case December:
				return "December";
				break;
		}
	}

	~Event()
	{
		if (this->eventName != nullptr)
		{
			delete[] this->eventName;
		}
	}

};
int Event::CURRENT_YEAR = 2022;
int Event::MAX_YEAR = 2050;