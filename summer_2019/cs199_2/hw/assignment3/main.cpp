#include <iostream>
#include "company.h"

using namespace std;

int main(void)
{
		int menu_choice = 0;
		int employee_count = 0;
		bool repeat = true;
		company co;


		cout << "This is a company management system." << endl;
		while(repeat)
		{
				print_menu(menu_choice);
				menu_switch(menu_choice, repeat, co);
		}
		return 0;
}
