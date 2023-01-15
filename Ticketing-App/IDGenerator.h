#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include<regex>
#include<time.h>
#include<cstdlib>
#include <fstream>

using namespace std;

class IdGenerator
{
	int id;

public:
	IdGenerator()
	{
		id = 0;
	}
	//create random numbers of 
	int generateId()
	{
		int number=0;
		for (int i = 0; i < 9; i++)
		{
			number = number*10+ ( rand() % 10);
		}
		return number;
	}

	//write the id in a file 
	virtual void manageId()
	{
		ofstream idFile("idFile.txt", ios::out | ios::app);
		if (idFile.is_open())
			idFile << id << endl;
		idFile.close();
	}

	//validate the id
	virtual bool validateId(int id)
	{
		ifstream idFile("idFile.txt", ios::in);
		bool ok=1;
		if (idFile.is_open())
		{
			while (!idFile.eof())
			{
				int number;
				idFile >> number;
				if (number==id)
				{
					ok=0;	//the id already exists (it's not unique)
				}
			}
			idFile.close();
		}
		return ok;
	}

	~IdGenerator()
	{

	}
};
