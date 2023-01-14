#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include<regex>
#include<time.h>
#include<cstdlib>

using namespace std;

class IdGenerator
{

public:

	int generateId()
	{
		int number=0;
		for (int i = 0; i < 9; i++)
		{
			number = number*10+ ( rand() % 10);
		}
		return number;
	}

};
