#include <iostream>
using namespace std;

const int SIZE = 100;


void get_array(int array[], int& length)
{
		int i = 0;
		cout << "Enter a number(terminate with -1): ";
		cin >> i;
		while ( i != -1 )
		{
				array[length] = i;
				++length;
				cout << "Enter a number(terminate with -1): ";
				cin >> i;
		}
	
}


int main(void)
{
		int array[SIZE] = {0};
		int length = 0;
		int sum = 0;

		get_array(array, length);	

		for (int i = 0; i < length; ++i)
		{
				sum = sum + array[i];
				cout << "array[" << i << "] is: " << array[i] << endl;
		}

		cout << "The sum is: " << sum << endl;

		return 0;
}
