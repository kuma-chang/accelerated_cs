#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE = 100;

void get_input(char x[]);
void reverse(char x[], char y[], int length);

int main(void)
{
		char input[SIZE];
		char output[SIZE];
		int length;
		
		get_input(input);
		length = strlen(input);
		reverse(input, output, length);
		cout << output << endl;
		
		return 0;
}

void get_input(char x[])
{
		cout << "Please enter a string: ";
		cin.get(x, SIZE, '\n');
		return;
}

void reverse(char x[], char y[], int length)
{
		for(int i = 0; i < length; ++i)
		{
				y[i] = x[length - 1 - i];
		}
		return;
}

