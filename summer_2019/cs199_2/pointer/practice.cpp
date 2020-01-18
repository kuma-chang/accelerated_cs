#include <iostream>
#include <cstring>

using namespace std;


int main(void)
{
		char s[] = "hello world";
		char *p;
		p = s;

		do
		{
				*p -= 32;
				cout << *p;		
		}while(*p++);

		cout << endl;


		return 0;
}
