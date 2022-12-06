#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Ticket
{
private:
	
	const int UNIQUE_ID;
	bool isVIP = false;
	float ticketPrice=BASE_PRICE;
	static float BASE_PRICE;


};
float Ticket::BASE_PRICE = 25;