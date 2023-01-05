#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include<regex>
#include "Event.h"
using namespace std;


//the event has a date
//the ticket has a date when is issued 
// should consider the fact that the date of ticket 
//should be less than the date of the event

enum month { January = 1, February, March, April, May, June, July, August, September, October, November, December };

class Date
{
	int year;
	int day;
	month monthName;
	string time;
	static int CURRENT_YEAR;
	static int MAX_YEAR;

public:
	//dctor and ctor with parameters
	Date()
	{
		this->year = CURRENT_YEAR;
		this->day = 1;
		this->monthName = month::January;
		this->time = "00:00";
	}
	Date(int yy, month mm, int dd, string time)
	{
		setYear(yy);
		setMonth(mm);
		setDay(dd);
		setTime(time);
	}

	//destructor
	~Date()
	{

	}

	//getters and setters
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
			if ((this->monthName >= 8 && this->monthName % 2 == 0) && (day >= 1 && day <= 31))
			{
				this->day = day;
			}
			else
				if ((this->monthName == 4 || this->monthName == 6 || this->monthName == 9 || this->monthName == 11) && (day >= 1 && day <= 30))
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
		this->monthName = month::January; }
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
			cout << "Enter a valid year";
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

	// << and >> operators
	friend ostream& operator<<(ostream&, Date );
	friend istream& operator>>(istream&, Date&);
};

ostream& operator<<(ostream& out, Date date)
{
	out<< "Date: ";
	out << date.monthName << "/";
	out << date.day << "/";
	out << date.year<<" ";
	out << date.time;
	out << endl;
	
	//out << "Date: " << date.getMonth() << " " << date.day << "," << date.year << endl;
	//out << "Hour: " << date.time << endl;
	return out;
}

istream& operator>>(istream& in, Date& date)
{
	cout << "\nYear: ";
	int yy;
	in >> yy;
	date.setYear(yy);

	int month;
	cout << "\nEnter the Month's number (1->12): ";
	in >> month;
	date.setMonthNumber(month);
	
	cout << "\nDay: ";
	int dd;
	in >> dd;
	date.setDay(dd);

	cout << "\nHour(hh:mm): ";
	char buffer[100];
	in >> ws;
	in.getline(buffer,99);
	date.setTime(buffer);

	return in;
}

int Date::CURRENT_YEAR = 2023;
int Date::MAX_YEAR = 2050;
