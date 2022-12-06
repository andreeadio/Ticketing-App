#include <iostream>
#include <string>
#include <string.h>
#include "Event.h"
using namespace std;



int main()
{
	Event e1("Concert Andra", 24, December, 2022, "19:00");
	cout<<e1.getEventName();
	
	cout << endl;
	
	e1.setEventType(concert);
	cout << e1.getEventType();
	cout << endl;

	Event e2(e1);
	cout << e2.getMonth();
	cout << endl;

	Event e3("Movie", 4, January, 2024, "17:00");
	cout << e3.getMonth();
	cout << endl;

	e2 = e3;
	cout << e2.getYear();
	cout << endl;

	cout << e2;
}
