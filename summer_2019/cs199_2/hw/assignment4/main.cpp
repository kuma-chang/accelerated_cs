#include <iostream>
#include "activity_tracker.h"

using namespace std;


int main()
{
		int menu_choice = 0;
		Linked_list l;
		bool repeat = true;

		cout << "This is a Activity Tracker!" << endl;
		while(repeat)
		{
				menu_print(menu_choice);
				menu_switch(menu_choice, repeat, l);
		}
		return 0;
}
