#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Location
{
private:
	
	int noSeatsPerRow=0;
	//char** zones = nullptr;
	int* noOfRowsPerZone=nullptr;
	int noZones = 0;

	const unsigned int MAX_NO_SEATS;

public:

	Location(unsigned int noSeats,int noZones,int* noOfRowsPerZone, int noSeatsPerRow) :MAX_NO_SEATS(noSeats)
	{
		if (noZones > 0 && noOfRowsPerZone != nullptr )
		{
			this->noZones = noZones;
			
			this->noOfRowsPerZone = new int[this->noZones];
			for (int i = 0; i < noZones; i++)
			{
				//to be revised
				this->noOfRowsPerZone[i] = noOfRowsPerZone[i];
			}
			this->noSeatsPerRow = noSeatsPerRow;
		}
		else
		{
			this->noOfRowsPerZone = nullptr;
			this->noZones = 0;
			this->noSeatsPerRow = 0;
		}
		
	}

	void printNoOfRowsPerZone()
	{
		for (int i = 0; i <this->noZones; i++)
		{
			cout << this->noOfRowsPerZone[i]<<" ";
		}
	}




	~Location()
	{
		if (this->noOfRowsPerZone != nullptr)
		{
			delete[] noOfRowsPerZone;
			this->noOfRowsPerZone = nullptr;
		}

		/*if (zones != nullptr)
		{
			delete[] zones;
			this->zones = nullptr;
		}*/
	}
};
//UNFINISHED