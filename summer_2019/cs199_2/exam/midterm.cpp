#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 500;

void get_input(char x[]);
void get_key(int &x);
void ciphering(char x[], char y[], int length, int key);

int main(void)
{
		char input[SIZE];
		char output[SIZE];
		int key = 0;
		int length = 0;

		get_input(input);
		get_key(key);
		length = strlen(input);
		ciphering(input,output,length,key);
		cout << "Original Message: " << input << endl;
		cout << "Ciphered Message: " << output << endl;


		return 0;
}

void get_input(char x[])
{
		cout << "Enter the secret message: ";
		cin.get(x, SIZE, '\n');
		cin.ignore();
		return;
}

void get_key(int &x)
{
		cout << "Enter a non-zero shift value (-25 ~ 25): ";
		cin >> x;
		cin.ignore(SIZE, '\n');
		return;
}

void ciphering(char x[], char y[], int length, int key)
{
		int n = 0;

		for (int i = 0; i < length; ++i)
		{
				if (isalpha(x[i]))
				{
						if (isupper(x[i]))
						{
								if (x[i]+key > 'Z')
										n = x[i] + key - 26;
								else if (x[i]+key >= 'A')
										n = x[i] + key;
								else if (x[i]+key < 'A')
										n = x[i] + key + 26;
								y[i] = n;
							
						}
						else if (islower(x[i]))
						{
								if (x[i]+key > 'z')
										n = x[i] + key - 26;
								else if (x[i]+key >= 'a')
										n = x[i] + key;
								else if (x[i]+key < 'a')
										n = x[i] + key + 26;
								y[i] = n;
						}
				}
				else
				{
						y[i] = x[i];
				}
			

		}




		return;
}


