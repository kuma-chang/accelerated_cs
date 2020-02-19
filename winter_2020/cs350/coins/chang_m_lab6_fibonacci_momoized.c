#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int memoization_table[100000000];

int fib(int n)
{
	int a,b;
	if(n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		if(memoization_table[n-1] != -1){a = memoization_table[n-1];}
		else
		{
			a = fib(n-1);
			memoization_table[n-1] = a;
		}
		if(memoization_table[n-2] != -1){b = memoization_table[n-2];}
		else
		{
			b = fib(n-2);
			memoization_table[n-2] = b;
		}
		return a + b;
	}
}


int main()
{
  char text[10000];
  int n;

  printf("enter which nth fibonacci number do you want to search: ");
  scanf("%s", text) ;

  n = atoi(text) - 1;

	for(int i = 0; i < 100000000; i++)
	{
		memoization_table[i] = -1;
	}


	printf("The %dth fibonacci number is: %d\n", n + 1, fib(n));


	return 0;
}
