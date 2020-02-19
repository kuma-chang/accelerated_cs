#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int fib(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return fib(n-1) + fib(n-2);
	}
}


int main()
{
  char text[10000];
  int n;

  printf("enter which nth fibonacci number do you want to search: ");
  scanf("%s", text) ;

  n = atoi(text) - 1;


	printf("The %dth fibonacci number is: %d\n", n + 1, fib(n));


	return 0;
}
