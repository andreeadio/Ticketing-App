#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include<regex>
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

	string time;
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
		this->day = 1;				
		this->monthName = month::December;//current month
		this->time = "00:00";
		this->isOutside = false;
		this->eventType = other;
	}


	Event(const char* eventName, int dd, month mm, int yy,string time)
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
		
		this->monthName = mm;
		this->setDay(dd);
		

		if (time.length() == 5)
		{
			if (regex_match(time, regex("[0-1][0-9]:[0-5][0-9]")) || regex_match(time, regex("2[0-3]:[0-5][0-9]")))
			{
				this->time = time;
			}
			else
			{
				this->time = "00:00";
			}

		}
		else
		{
			this->time = "00:00";
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

	void setDay(int day)
	{
		
		if ((this->monthName <= 7 && this->monthName % 2 != 0) && (day >= 1 && day <= 31))
		{
			this->day = day;
		}
		else
		if ((this->monthName >=8 && this->monthName % 2 == 0) && (day >= 1 && day <= 31))
		{
			this->day = day;
		}
		else
		if ((this->monthName == 4 || this->monthName == 6 || this->monthName == 9|| this->monthName == 11) && (day >= 1 && day <= 30))
		{
			this->day = day;
		}
		else
		if (this->monthName == 2 && (day >= 1 && day <= 29) && this->year % 4 == 0)
		{
			this->day = day;
		}
		else
			this->day = 1;
			
	}

	int getDay()
	{
		int copy = this->day;
		return day;
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
		{cout << "Enter a valid month number";
		this->monthName = month::December; }
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
			cout<< "Enter a valid year";
			this->year = CURRENT_YEAR;
		}
	}

	int getYear()
	{
		int copy;
		copy = this->year;
		return copy;
	}

	//setter time

	void setTime(string time)
	{
		if (time.length() == 5)
		{
			if (regex_match(time, regex("[0-1][0-9]:[0-5][0-9]")) || regex_match(time, regex("2[0-3]:[0-5][0-9]")))
			{
				this->time = time;
			}
			else
			{
				this->time = "00:00";
			}
		}
		else
		{
			this->time = "00:00";
		}
	}

	string getTime()
	{
		string copy;
		copy = this->time;
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
		this->monthName = e.monthName;
		this->day = e.day;
		this->eventType = e.eventType;
		this->isOutside = e.isOutside;
		this->time = e.time;

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
			this->time = e.time;

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
	out << endl;
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

	cout << "\nYear: ";
	int yy;
	in >> yy;
	e.setYear(yy);
	
	//enum month
	int month;
	cout << "\nEnter the Month's number: ";
	in >> month;
	e.setMonthNumber(month);
	
	cout << "\nDay: ";
	int dd;
	in >> dd;
	e.setDay(dd);
	
	//enum type 
	
	cout << "\nThe event type (concert,play,football match,movie,other): ";
	string type;
	//to be revised : it skips this part
	getline(in, type);
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

//time:
	cout << "\nHour: ";
	string time;
	in>>time;
	e.setTime(time);
}

//TODO
//validations for date and time
//set and get for time