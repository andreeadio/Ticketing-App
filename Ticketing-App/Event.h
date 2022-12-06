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

public:
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

		if (time != nullptr && strlen(time)== 5)
		{
			strcpy_s(this->time, strlen(time)+1, time);
		}
		else
		{
			cout<< "Enter a valid time";
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

	void setMonth(month mm)
	{
		if (mm >= 1 && mm <= 12)
			this->monthName = mm;
		else
			cout << "Enter a valid month";

	}

	void setMonthNumber(int m)
	{
		
		switch (m)
		{
		case 1:
			this->monthName = month::January;
			break;
		case 2:
			this->monthName = month::February;
			break;
		case 3:
			this->monthName = month::March;
			break;
		case 4:
			this->monthName = month::April;
			break;
		case 5:
			this->monthName = month::May;
			break;
		case 6:
			this->monthName = month::June;
			break;
		case 7:
			this->monthName = month::July;
			break;
		case 8:
			this->monthName = month::August;
			break;
		case 9:
			this->monthName = month::September;
			break;
		case 10:
			this->monthName = month::October;
			break;
		case 11:
			this->monthName = month::November;
			break;
		case 12:
			this->monthName = month::December;
			break;
		default:
			cout << "Enter a valid month number";
			break;
		}
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

	//setter time

	void setTime(const char* time)
	{
		if (strlen(time) == 5)
		{
			strcpy_s(this->time, strlen(time) + 1, time);
		}
		else
		{
			strcpy_s(this->time, strlen("00:00") + 1, "00:00");
		}
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

		if (e.time != nullptr && strlen(e.time) == 5)
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

			this->year = e.year;
			this->day = e.day;
			this->monthName = e.monthName;
			this->eventType = e.eventType;
			this->isOutside = e.isOutside;

			if (e.time != nullptr && strlen(e.time) == 5)
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

	friend void operator<<(ostream& out, Event e);
	friend void operator>>(istream& in, Event& e);

};
int Event::CURRENT_YEAR = 2022;
int Event::MAX_YEAR = 2050;

void operator<<(ostream& out, Event e)
{
	out << "Event name: " << e.eventName << endl;
	out << "Type: " << e.getEventType() << endl;
	out << "Date: " << e.getMonth() << " " << e.day << "," << e.year << endl;
	out << "Hour: " << e.time << endl;
	out << "Where it takes place: " <<e.getIsOutside() << endl;
	
	
}

void operator>>(istream& in, Event& e)
{
	//event name
	cout << "\nEvent name: ";
	string buffer;
	getline(in, buffer);
	if (e.eventName != nullptr)
	{
		delete[] e.eventName;
		e.eventName = nullptr;
	}
	e.setEventName(buffer.c_str());

	cout << "\nDay: ";
	in >> e.day;
	
	//enum month
	int month;
	cout << "\nEnter the Month's number :";
	in >> month;
	e.setMonthNumber(month);
	
	cout << "\nYear: ";
	in >> e.year;

	////time
	//
	//cout << "\nHour: ";
	//string time;
	//getline(in, time);
	//
	//e.setTime(time.c_str());
	
	//enum type 
	cout << "\nThe event type (concert,play,football match,movie,other): ";
	string type;
	in >> type;
	e.setEventTypeString(type);

	//bool isOutside
	cout << endl << "\nIs outside? (y/n):";
	string confirmation;
	in >> confirmation;
	if (confirmation == "y") {
		e.isOutside = true;
	}
	else {
		e.isOutside = false;
	}

}

//TODO
//validations for date and time
//set and get for time