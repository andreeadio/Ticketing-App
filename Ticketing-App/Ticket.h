#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Event.h"
#include "Location.h"
#include "Date.h"
#include "IDGenerator.h"
using namespace std;

class TicketAbstract
{
public:
	virtual void validateTicket(int i) = 0;
};

class Ticket: public IdGenerator,public TicketAbstract
{
private:
	int UNIQUE_ID;
	Event event;
	string category;
	int seat;
	int row;
	//bool isVIP = false;
	/*float ticketPrice=BASE_PRICE;
	static float BASE_PRICE;*/
	

public:
	Ticket():UNIQUE_ID(0),IdGenerator(),event()
	{
		this->seat = 0;
		this->row = 0;
		this->category = "";
	}

	Ticket(Event event,int i,int row,int seat):event(event)/**, UNIQUE_ID(generateId())*/, IdGenerator()
	{
		this->row = row;
		this->seat = seat;
		this->category="";
		this->event = event;
		setId();
	}

	void setRow(int row)
	{
		this->row = row;
	}

	void setSeat(int s)
	{
		this->seat = s;
	}

	
	bool validateId(int id)
	{
		ifstream idFile("idFile.txt", ios::in);
		bool ok = 1;
		if (idFile.is_open())
		{
			while (!idFile.eof())
			{
				int number;
				idFile >> number;
				if (number == id)
				{
					ok = 0;	//the id already exists (it's not unique)
				}
			}
			idFile.close();
		}
		return ok;
	}

	virtual void manageId()
	{
		ofstream idFile("idFile.txt", ios::out | ios::app);
		if (idFile.is_open())
			idFile << UNIQUE_ID << endl;
		idFile.close();
	}
	void setId()
	{
		int i;
		int ok = 0;
		i= generateId();
		while(ok==0)
		{
			if (validateId(i) == 0)
			{
				i = generateId();
			}
			else
			{
				this->UNIQUE_ID = i;
				ok = 1;
				manageId();
			}
		}

	}
	void validateTicket(int i)
	{
		if (validateId(i) == 0)
			cout <<endl<< "The ticket is valid";
	}
	void serialize()
	{
		ofstream f("Tickets.bin", ios::binary|ios::app);
		f.write((char*)&UNIQUE_ID, sizeof(UNIQUE_ID));
		f.write((char*)&row, sizeof(row));
		f.write((char*)&seat, sizeof(seat));
		//f.write(&event.getEventName(), sizeof(event.getEventName()) );
		//f.write((char*)&event, sizeof(event));
		f.close();
	}

	void deserialize()
	{
		ifstream f("Tickets.bin", ios::binary);
		if (f.is_open())
		{
			f.read((char*)&UNIQUE_ID, sizeof(UNIQUE_ID));
			f.read((char*)&row, sizeof(row));
			f.read((char*)&seat, sizeof(seat));
			//f.read((&event.getEventName(), sizeof(event.getEventName()));
			//f.read((char*)&event, sizeof(event));
			f.close();
		}
	}

	static bool validate(int i)
	{
		ifstream idFile("idFile.txt", ios::in);
		bool ok = 1;
		if (idFile.is_open())
		{
			while (!idFile.eof())
			{
				int number;
				idFile >> number;
				if (number == i)
				{
					ok = 0;	//the id already exists (it's not unique)
				}
			}
			idFile.close();
		}
		return ok;
	}

	~Ticket()
	{

	}


	friend ostream& operator<<(ostream&, Ticket);
	friend istream& operator>>(istream&, Ticket&);
};

ostream& operator<<(ostream& out, Ticket t)
{
	out << "Id: ";
	out << t.UNIQUE_ID <<endl;
	out << "Row: ";
	out << t.row << endl;
	out << "Seat: ";
	out << t.seat << endl;
	out << endl;

	//out << "Date: " << date.getMonth() << " " << date.day << "," << date.year << endl;
	//out << "Hour: " << date.time << endl;
	return out;
}

istream& operator>>(istream& in, Ticket& t)
{
	cout << "Row: ";
	int r;
	in >> r;
	t.row = r;
	cout << "Seat: ";
	int s;
	in >> s;
	t.seat= s;
	

	return in;
}
//float Ticket::BASE_PRICE = 25;