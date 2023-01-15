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
	virtual void validateTicket() = 0;
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
	Ticket():UNIQUE_ID(0),IdGenerator()
	{
		this->seat = 0;
		this->row = 0;
		this->category = "";
	}

	Ticket(Event event,int i,int row,int seat):event(event),UNIQUE_ID(generateId()),IdGenerator()
	{
		this->row = row;
		this->seat = seat;
		this->category="";
		this->event = event;
	}

	void setRow(int row)
	{
		this->row = row;
	}

	void setSeat(int s)
	{
		this->seat = s;
	}

	
	bool validateId()
	{
		ifstream idFile("idFile.txt", ios::in);
		bool ok = 1;
		if (idFile.is_open())
		{
			while (!idFile.eof())
			{
				int number;
				idFile >> number;
				if (number == UNIQUE_ID)
				{
					ok = 0;	//the id already exists (it's not unique)
				}
			}
			idFile.close();
		}
		return ok;
	}

	/*void setId()
	{
		this->UNIQUE_ID
		if(generateId())
	}*/
	void validateTicket()
	{

	}
	/*void serialize()
	{
		ofstream f("Tickets.bin", ios::binary);
		f.write((char*)&UNIQUE_ID, sizeof(UNIQUE_ID));
		f.write((char*)&row, sizeof(row));
		f.write((char*)&seat, sizeof(seat));
		f.write(&event.getEventName(), sizeof(event.getEventName()) );

		f.close();
	}

	void deserialize()
	{
		ifstream f("student.bin", ios::binary);
		if (f.is_open())
		{
			f.read((char*)&UNIQUE_ID, sizeof(UNIQUE_ID));
			f.read((char*)&row, sizeof(row));
			f.read((char*)&seat, sizeof(seat));
			f.read((&event.getEventName(), sizeof(event.getEventName()));
			f.close();
		}
	}*/

	~Ticket()
	{

	}

};
//float Ticket::BASE_PRICE = 25;