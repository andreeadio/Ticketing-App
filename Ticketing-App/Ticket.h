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

class Ticket: public IdGenerator
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
	Ticket():UNIQUE_ID(0)
	{
		this->seat = 0;
		this->row = 0;
		this->category = "";
	}

	Ticket(Event event):event(event),UNIQUE_ID(generateId())
	{
		this->seat = 0;
		this->row = 0;
		this->category = "";
	}

	~Ticket()
	{

	}

};
//float Ticket::BASE_PRICE = 25;