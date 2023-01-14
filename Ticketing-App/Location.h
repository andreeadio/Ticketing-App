#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Location
{
private:

	char** zones;
	int noZones;
	const unsigned int NO_ROWS_PER_ZONE;
	const unsigned int NO_SEATS_PER_ROW;
	

public:

	Location() :NO_ROWS_PER_ZONE(0), NO_SEATS_PER_ROW(0)
	{
		this->zones = nullptr;
		this->noZones = 0;
		
	}

	Location(int noZones,const char** zones, unsigned int noRows, int noSeats) :NO_ROWS_PER_ZONE(noRows), NO_SEATS_PER_ROW(noSeats)
	{
		if (noZones > 0 && zones != nullptr )
		{
			this->noZones = noZones;
			this->zones = new char*[noZones];
			for (int i = 0; i < noZones; i++)
			{
				this->zones[i] = new char[strlen(zones[i]) + 1];
				strcpy_s(this->zones[i], strlen(zones[i])+1, zones[i]);
			}
		}
		else
		{
			this->zones = nullptr;
			this->noZones = 0;
		}
		
	}

	//copy ctor
	Location(const Location& loc)
		:NO_ROWS_PER_ZONE(loc.NO_ROWS_PER_ZONE),NO_SEATS_PER_ROW(loc.NO_SEATS_PER_ROW)
	{
		if (loc.zones != nullptr && loc.noZones > 0)
		{
			this->noZones = loc.noZones;
			this->zones = new char* [loc.noZones];
			for (int i = 0; i < noZones; i++)
			{
				this->zones[i] = new char[strlen(loc.zones[i]) + 1];
				strcpy_s(this->zones[i], strlen(loc.zones[i]) + 1, loc.zones[i]);
			}
		}
		else
		{
			this->zones = nullptr;
			this->noZones = 0;
		}
	}

	//operator=
	Location& operator=(const Location& loc)
	{
		if (this != &loc)
		{
			if (zones != nullptr)
			{
				delete[] zones;
			}
			if (loc.zones != nullptr && loc.noZones > 0)
			{
				this->noZones = loc.noZones;
				this->zones = new char*[loc.noZones + 1];
				for (int i = 0; i < noZones; i++)
				{
					this->zones[i] = new char[strlen(loc.zones[i]) + 1];
					strcpy_s(this->zones[i], strlen(loc.zones[i]) + 1, loc.zones[i]);
				}
			}
			else
			{
				this->zones = nullptr;
				this->noZones = 0;
			}
		}
	}

	void setZones(int noZones, const char** zones)
	{
		if (noZones > 0 && zones != nullptr)
		{
			delete[] this->zones;
			this->noZones = noZones;
			this->zones = new char* [noZones];
			for (int i = 0; i < noZones; i++)
			{
				this->zones[i] = new char [strlen(zones[i]) + 1];
				strcpy_s(this->zones[i], strlen(zones[i]) + 1, zones[i]);
			}
		}
	}

	char** getZones()
	{
		if (zones != nullptr && noZones >0) {
			char** copy = new char*[noZones];
			for (int i = 0; i < noZones; i++) {
				strcpy_s(copy[i],strlen(zones[i])+1,zones[i]);
			}
			return copy;
		}
		else return nullptr;
	}
	
	char* getZone(int i) {
		if (i >= 0 && i < noZones && zones != nullptr) {
			return zones[i];
		}
		else return nullptr;
	}

	void printZones()
	{
		if (noZones > 0 && zones != nullptr)
		{
			cout << "The zones are:" << endl;
			for (int i = 0; i < noZones; i++)
				cout << zones[i] << endl;
		}
		else
			cout << "The location has no zone";
	}

	//indexing operator
	char* operator[](int index)
	{
		if (index > 0 && index < noZones)
		{
			return zones[index];
		}
		
	}
	

	//create a matrix for every zone
	/*void availableSeats(const char* zone)
	{
		for(int k=0;k<noZones;k++)
		{ 
			string name = this->zones[k];
			if (strcmp(zone, name.c_str())==0)
			{
				int** availableSeats = new int*[NO_ROWS_PER_ZONE];
				for (int i = 0; i < NO_ROWS_PER_ZONE; i++)
				{
					availableSeats[i] = new int[NO_SEATS_PER_ROW];
				}
				for (int i = 0; i < NO_ROWS_PER_ZONE; i++)
				{
					for (int j = 0; j < NO_SEATS_PER_ROW; j++)
					{
						availableSeats[i][j] = 0;
					}
				}
			}
		}	
	}*/
	
	int TotalNoSeats(unsigned int noZones, unsigned int noRows, int noSeats)
	{
		if (noZones != 0 && noRows != 0 && noSeats != 0)
		{
			int totalSeats = noZones * noRows * noSeats;
			return totalSeats;
		}
		else
			return 0;
	}


	~Location()
	{
		if (zones != nullptr)
		{
			delete[] zones;
			this->zones = nullptr;
		}
	}

	friend ostream& operator<<(ostream&, Location);
	friend istream& operator>>(istream&, Location&);

};
ostream& operator<<(ostream& out, Location loc)
{
	out << "Nr zone: " << loc.noZones << endl;
	out << "Nume zone: ";
	for (int i = 0; i < loc.noZones; i++)
	{
		out << loc.zones[i] << " ";
	}
	out << endl;

	return out;
}
istream& operator>>(istream& in, Location& loc)
{
	
	cout << "Numar zone: ";
	in >> loc.noZones;

	if (loc.zones!= nullptr)
	{
		delete[] loc.zones;
		loc.zones = nullptr;
	}

	loc.zones = new char*[loc.noZones];
	cout << "Nume zone: ";
	/*for (int i = 0; i < loc.noZones; i++)
	{
		
		in >> loc.zones[i];
	}*/

	return in;
}

//UNFINISHED