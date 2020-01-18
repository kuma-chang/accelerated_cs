#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 6;


struct menu_item
{
		char name[SIZE];
		char sugar[SIZE];
		char ice[SIZE];
		int price;
};

void get_order(menu_item &arg)
{
		cout << "What drink do you want today: ";
		cin.get(arg.name, 100, '\n');

}

void print_bill(menu_item arg)
{
		int i;
		cout << "Your drink is " << arg.name << endl;
		i = strlen(arg.name);
		cout << "The length is " << i << endl;
		for ( int i = 0; i < 3; ++i)
		{
				cout << arg.name[0] << endl;
		}
}

int main(void)
{
		menu_item order[SIZE];
		
		cout << "Welcome to 功夫茶！" << endl;

		get_order(order[0]);

		print_bill(order[0]);



		return 0;
}

