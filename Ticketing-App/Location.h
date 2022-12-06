#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Location
{
private:
	
	int noSeatsPerRow=0;
	char* zones = nullptr;
	int* noOfRowsPerZone=nullptr;
	int noZones = 0;

	const unsigned int MAX_NO_SEATS;

public:

	Location(unsigned int noSeats,int noZones,int* noOfRowsPerZone, int noSeatsPerRow) :MAX_NO_SEATS(noSeats)
	{
		if (noZones > 0 && noOfRowsPerZone != nullptr )
		{
			this->noZones = noZones;
			this->noOfRowsPerZone = new int[noZones+1];
			for (int i = 0; i < noZones; i++)
			{
				//to be revised
				this->noOfRowsPerZone[i] = noOfRowsPerZone[i];
			}
			//this->nameZone();
		}
		else
		{
			this->noOfRowsPerZone = nullptr;
			this->noZones = 0;
			char* zones = nullptr;
		}

		
		this->noSeatsPerRow = noSeatsPerRow;
	}


	//create the zones
	void nameZone()
	{
	
		if (noZones > 0)
		{
			this->zones = new char[noZones+1];
		
			for (int i = 0; i < noZones; i++)
			{
				this->zones[i] ='A'+i;
			}
		}
		
	}

	char getZoneName(int i)
	{
		if (i != 0 && i <= noZones)
		{
			return this->zones[i - 1];
		}
	}

	~Location()
	{
		if (this->noOfRowsPerZone != nullptr)
		{
			delete[] noOfRowsPerZone;
			this->noOfRowsPerZone = nullptr;
		}

		if (zones != nullptr)
		{
			delete[] zones;
			this->zones = nullptr;
		}
	}
};
//UNFINISHED