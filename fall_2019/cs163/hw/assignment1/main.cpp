#include <iostream>
#include "psu_classes.h"

using namespace std;

int main(void)
{
		int menu_choice = 0;
		bool repeat = true;
		LLL l_r, l_b, l_c;

		cout << "Welcome to the PSU class assist." << endl;
		while(repeat)
		{
				print_menu(menu_choice);
				menu_switch(menu_choice, repeat, l_r, l_b, l_c);	
		
		}
		return 0;
}
