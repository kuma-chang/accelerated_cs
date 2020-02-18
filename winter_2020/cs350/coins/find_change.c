#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int min(int num1, int num2)
{
    return (num1 > num2 ) ? num2 : num1;
}


int find_chang(int p)
{
	if(p == 0)
		return 0;
	else if(p < 0)
		return 1000000000;
	else
	{
		a = find_chang(p - 4);
		b = find_chang(p - 3);
		c = find_chang(p - 1);

		

		return 1 + min(find_chang(p - 4), min(find_chang(p - 3), find_chang(p - 1)));
	}
}


int main()
{
	int p = 12;


	printf("How many coins: %d\n", find_chang(p));


	return 0;
}
