#include <iostream>
#include <string>
#include <string.h>
#include "Event.h"
#include "Ticket.h"
#include "Location.h"
#include "Date.h"
using namespace std;


//
//int main()
//{
//	//testing
//	
//	Event e1("Concert Andra", 24, December, 2022, "19:00");
//	cout<<e1.getEventName();
//	
//	cout << endl;
//	
//	e1.setEventType(concert);
//	cout << e1.getEventType();
//	cout << e1.getTime();
//	cout << endl;
//
//	Event e2(e1);
//	cout << e2.getMonth();
//	cout << endl;
//
//	Event e3("Movie", 4, January, 2024, "17:00");
//	cout << e3.getMonth()<<endl;
//
//
//	cout << endl<<"---Event 3: " << endl;
//	cout << e3;
//	cout << endl;
//	e2 = e3;
//	cout << e2.getYear();
//	cout << endl;
//
//	cout << endl << "---Event 2: " << endl;
//	cout << e2;
//
//	e1 = e2 = e3;
//	cout << endl;
//	cout << endl << "---Event 1: " << endl;
//	cout << e1;
//
//	Event e5;
//	//cin >> e5;
//	cout << endl;
//	cout <<  endl << "---Event 5: " << endl << e5;
//	cout << endl;
//
//	
//	Event e6("Movie X", 4, January, 2024, "170:00");
//	cout << endl << "---Event 6: " << endl;
//	cout << e6;
//
//	int rows[] = {5,10,15};
//	
//	Location theater(300, 3, rows, 10);
//
//	cout << endl;
//	theater.printNoOfRowsPerZone();
//
//
//	Event e7("Movie X", 32, January, 2024, "21:00");
//	e7.setMonth(February);
//	cout << endl << "---Event 7: " << endl<<e7;
//	cin >> e5;
//	cout << endl << "---Event 5: " << endl << e5;
//}

int main()
{
	Date date1(2023, February, 23, "12:00");
	cout << date1;
	/*Date d;
	cin >> d;
	cout << d;*/

	Event e("Concert Andra", date1);
	cout << e;
	Event e1;
	cin >> e1;
	cout << e1;
}
