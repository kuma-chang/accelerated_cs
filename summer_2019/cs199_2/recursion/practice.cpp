#include <iostream>

using namespace std;


void print_digit(int n);




int main(void)
{
		int x = 12345;

		cout << x << endl;
		print_digit(x);
		cout << endl;


		return 0;
}



void print_digit(int n)
{
		if(n < 10)
		{
				cout << n << ' ';
				return;
		}
		cout << n % 10 << ' ';  // print backwards
		print_digit(n / 10);
		cout << n % 10 << ' ';  // print forwards
}
