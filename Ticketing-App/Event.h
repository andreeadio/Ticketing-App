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

	char time[6];
	type eventType;
	bool isOutside;

	static int CURRENT_YEAR;
	static int MAX_YEAR;

	Event()
	{
		this->eventName = new char[strlen("unknown") + 1];
		strcpy_s(this->eventName, strlen("unknown") + 1, "unknown");
		this->year = CURRENT_YEAR;
		this->day = 5;					//current day
		this->monthName = month::December;//current month
		strcpy_s(time, strlen("00:00") + 1, "00:00");
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

		if (time != nullptr && strlen(time)==5)
		{
			strcpy_s(this->time, strlen(time)+1, time);
		}
		else
		{
			throw "Enter a valid time";
			strcpy_s(this->time, strlen("00:00")+1, "00:00");
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

	void setYear(int yy)
	{
		if (yy >= CURRENT_YEAR && yy <= MAX_YEAR)
		{
			this->year = yy;
		}
		else
		{
			throw "Enter a valid year";
		}
	}

	int getYear()
	{
		int copy;
		copy = this->year;
		return copy;
	}

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

		this->year = e.year;
		this->day = e.day;
		this->monthName = e.monthName;
		this->eventType = e.eventType;
		this->isOutside = e.isOutside;

		if (e.time != nullptr && strlen(e.time) == 4)
		{
			strcpy_s(this->time, strlen(e.time) + 1, e.time);
		}
		else
		{
			strcpy_s(this->time, strlen("00:00") + 1, "00:00");
		}

	}

	Event& operator=(const Event& e)
	{
		if (this != &e)
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

			this->year = e.year;
			this->day = e.day;
			this->monthName = e.monthName;
			this->eventType = e.eventType;
			this->isOutside = e.isOutside;

			if (e.time != nullptr && strlen(e.time) == 4)
			{
				strcpy_s(this->time, strlen(e.time) + 1, e.time);
			}
			else
			{
				strcpy_s(this->time, strlen("00:00") + 1, "00:00");
			}
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

	friend ostream& operator<<(ostream& out, Event e);
	friend istream& operator>>(istream& in, Event& e);

};
int Event::CURRENT_YEAR = 2022;
int Event::MAX_YEAR = 2050;

ostream& operator<<(ostream& out, Event e)
{
	out << "Event name: " << e.eventName << endl;
	out << "Type: " << e.getEventType() << endl;
	out << "Date: " << e.getMonth() << " " << e.day << "," << e.year << endl;
	out << "Hour: " << e.time << endl;
	out << "Where it takes place: " <<e.getIsOutside() << endl;
	
	return out;
}

//istream& operator>>(istream& in, Event& e)
//{
//	cout << "Event name: ";
//	char buffer[100];
//
//
//	in >> buffer;
//	e.setEventName(buffer);
//	cout << "Type: ";
//	in >> e.eventType;
//	cout << "Month: ";
//	in >> e.monthName;
//	cout << "Day: ";
//	in >> e.day;
//	cout << "Year: ";
//	in >> e.year;
//
//	return in;
//}