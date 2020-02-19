#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int memoization_table[100000000];

int find_chang(int p)
{
	int a, b, c, min;
	if(p == 0)
		return 0;
	else if(p < 0)
		return 1000000000;
	else
	{
		///*
		if(p - 4 < 0){a = 100000000;}
		else if(memoization_table[p-4] != -1){a = memoization_table[p-4];}
		else
		{
			a = find_chang(p - 4);
			memoization_table[p-4] = a;
		}
		if(p - 3 < 0){a = 100000000;}
		else if(memoization_table[p-3] != -1){b = memoization_table[p-3];}
		else
		{
			b = find_chang(p - 3);
			memoization_table[p-3] = b;
		}
		if(p - 1 < 0){a = 100000000;}
		else if(memoization_table[p-1] != -1){c = memoization_table[p-1];}
		else
		{
			c = find_chang(p - 1);
			memoization_table[p-1] = c;
		}
		//*/
		/*
	  a = find_chang(p - 4);
	  b = find_chang(p - 3);
	  c = find_chang(p - 1);
		*/

		min = a;
		if(b < min){min = b;}
		if(c < min){min = c;}

		return 1 + min;
	}
}


int main()
{
	int p = 50;

	for(int i = 0; i < 100000000; i++)
	{
		memoization_table[i] = -1;
	}

	printf("How many coins: %d\n", find_chang(p));


	return 0;
}
