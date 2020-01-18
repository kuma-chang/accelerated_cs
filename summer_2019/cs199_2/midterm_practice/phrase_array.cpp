#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE = 100;

void get_input(char x[]);
void change_input(char x[], int y);

int main(void)
{
		char input[SIZE];
		int length;

		get_input(input);
		cout << input << endl;
		cout << strlen(input) << endl;
		length = strlen(input);
		change_input(input, length);
		cout << input << endl;


		return 0;
}


void get_input(char x[])
{
		cout << "Please enter a phrase: ";
		cin.get(x,100,'\n');
		return;
}

void change_input(char x[], int y)
{
		bool flag = true;
		
		for (int i = 0; i < y; ++i)
		{
				if (!isalpha(x[i-1]))
						flag = true;

				if (flag)
				{
						x[i] = toupper(x[i]);
						flag = false;
				}
				else
				{
						x[i] = tolower(x[i]);
				}
		}
}

