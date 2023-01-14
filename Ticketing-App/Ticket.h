#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Ticket
{
private:
	
	int UNIQUE_ID;
	//bool isVIP = false;
	float ticketPrice=BASE_PRICE;
	static float BASE_PRICE;
	//has an unique id


};
float Ticket::BASE_PRICE = 25;