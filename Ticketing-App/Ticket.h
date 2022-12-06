#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Ticket
{
private:
	int price;
	const int UNIQUE_ID;

public:

	Ticket():UNIQUE_ID(0)
	{
		this->price = 0;
	}
};