#include <iostream>
#include <string>
#include <string.h>
#include "Event.h"
#include "Ticket.h"
#include "Location.h"
#include "Date.h"
#include "IDGenerator.h"
using namespace std;

////Issuing football tickets in a stadium with two stands(Stand 1 and Stand 2).
//Issuance of movie tickets in the Normal or VIP categories.
//Issuance of theater tickets from the Category 1, Category 2 and Box categories.

//void options()
//{
//	//create the events
//	//locations
//
//	const char* zones1[2] = { "Stand 1", "Stand 2" };
//	const char* zones2[2] = { "Normal", "VIP" };
//	const char* zones3[3] = { "Category 1", "Category 2", "Box" };
//	Location stadium(2, zones1, 25, 12);
//	Location cinema(2, zones2, 10, 15);
//	Location theater(3, zones3, 5, 10);
//	//dates
//	Date d1(2023, month::February, 28, "19:30");
//	Date d2(2024, month::April, 1, "20:45");
//	Date d3(2023, month::July, 5, "18:00");
//	//events
//	Event football("Romania Cup", d1, stadium);
//	Event movie("Avatar 3", d2, cinema);
//	Event play("Hamlet", d3, theater);
//
//	cout << endl << "***********************************";
//	cout << endl << "       TICKETING APPLICATION       ";
//	cout << endl << "***********************************";
//	cout << endl << "Welcome to my ticketing app!";
//	cout << endl << "Choose from the following options: ";
//	int option = 0;
//	while (option != 4) {
//		cout << endl<< "( 1 ) See the list of events";
//		cout << endl<< "( 2 ) Buy a ticket";
//		cout << endl<< "( 3 ) Validate a ticket";
//		cout << endl<< "( 4 ) Close the application\n"<< endl;
//
//		cin >> option;
//		//menu(option, fileName);
//	}
//
//}

void menu(int option, Event e1,Event e2,Event e3)
{
	switch (option)
	{
	case 1:
	{
		cout << endl << "\nThe events are: " << endl;
			cout << endl;
			cout << endl << "***********************************";
			cout << e1;
			cout << endl << "***********************************";
			cout << e2;
			cout << endl << "***********************************";
			cout << e3;
			cout << endl << "***********************************";
		break;
	}
	case 2:
	{
		cout <<endl<< "Here are the events: ";
		menu(1, e1, e2, e3);

		cout << endl << "Choose for which event you what to buy a ticket: ";
		cout << endl << "Write the number(1->3): "<<endl;
		cin >> option;
		switch (option)
		{
			case 1:
			{
				cout << "Row: ";
				int r;
				cin >> r;
				cout << "Seat: ";
				int s;
				cin >> s;
				Ticket t1(e1, 0, r, s);
				t1.serialize();

				cout << "\nTicket created! ";
				cout << endl << "***********************************" << endl;
				cout << t1;
				cout << endl << "***********************************" << endl;
				cout << endl << "ATTENTION! Save the ticket id in order to validate the ticket" << endl;

				break;
			
			}
			case 2:
			{
				cout << "Row: ";
				int r;
				cin >> r;
				cout << "Seat: ";
				int s;
				cin >> s;
				Ticket t2(e2, 0, r, s);
				t2.serialize();

				cout << "\nTicket created! ";
				cout << endl << "***********************************" << endl;
				cout << t2;
				cout << endl << "***********************************" << endl;
				cout << endl << "ATTENTION! Save the ticket id in order to validate the ticket" << endl;
				break;
			}
			case 3:
			{

				cout << "Row: ";
				int r;
				cin >> r;
				cout << "Seat: ";
				int s;
				cin >> s;
				Ticket t3(e3, 0, r, s);
				t3.serialize();

				cout << "\nTicket created! " ;
				cout << endl << "***********************************"<<endl;
				cout << t3;
				cout << endl << "***********************************"<<endl;
				cout << endl << "ATTENTION! Save the ticket id in order to validate the ticket" << endl;
				break;
			}
			default:
				cout << endl << "\nChoose a valid event number!";
				menu(2, e1, e2, e3);
				break;
		}
		
		
		
		break;
	}
	case 3:
	{
		
		cout << "\nValidate the ticket : " << endl;
		cout << "\nWrite the id of the ticket: "<<endl;
		int i;
		cin >> i;
		if (Ticket::validate(i) == 0)
			cout << "\nThe ticket is valid"<<endl;
		else
			cout << "\nThe ticket is not valid"<<endl;

		break;
		
	}
	case 4:
	{
		cout << endl << "Close";
		break;

	}
	default:
	{
		cout << endl<< "Choose a valid option: \n"<< endl;
		cin >> option;
		menu(option, e1,e2,e3);
		break;
	}
	}

};

int main()
{

	//create the events
	//locations

	const char* zones1[2] = { "Stand 1", "Stand 2" };
	const char* zones2[2] = { "Normal", "VIP" };
	const char* zones3[3] = { "Category 1", "Category 2", "Box" };
	Location stadium(2, zones1, 25, 12);
	Location cinema(2, zones2, 10, 15);
	Location theater(3, zones3, 5, 10);
	//dates
	Date d1(2023, month::February, 28, "19:30");
	Date d2(2024, month::April, 1, "20:45");
	Date d3(2023, month::July, 5, "18:00");
	//events

	Event football("Romania Cup", d1, stadium);
	Event movie("Avatar 3", d2, cinema);
	Event play("Hamlet", d3, theater);
	
	
	/*e[0]->("Romania Cup", d1, stadium);
	Event e[1](movie);
	Event e[2](play);*/

	cout << endl << "***********************************";
	cout << endl << "       TICKETING APPLICATION       ";
	cout << endl << "***********************************";
	cout << endl << "Welcome to my ticketing app!";
	cout << endl << "Choose from the following options: ";
	int option = 0;
	while (option != 4) {
		cout << endl << "( 1 ) See the list of events";
		cout << endl << "( 2 ) Buy a ticket";
		cout << endl << "( 3 ) Validate a ticket";
		cout << endl << "( 4 ) Close the application\n" << endl;

		cin >> option;
		menu(option, football, movie, play);
	}

	
}

