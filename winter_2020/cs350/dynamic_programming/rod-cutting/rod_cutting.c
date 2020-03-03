#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int rod_cutting_tabular(int rod_length, int* price_table)
{
  int tabular_table[rod_length];
	// initializing tabular_table
	for(int i = 0; i < rod_length; i++)
		tabular_table[i] = -1;

	for(int i = 0; i < rod_length; i++)
	{
		if(i == 0)
			tabular_table[i] = price_table[0];
		else
			for(int j = 0; j <= i; j++)
			{
				if(j == 0)
					tabular_table[i] = price_table[i-j];
				else
					tabular_table[i] = max(tabular_table[i], tabular_table[i-j] + tabular_table[j-1]);
			}
	}

	printf("Sale price tabel:\n");
	for(int i = 0; i < rod_length; i++)
		printf("%d: %d\n", i + 1, tabular_table[i]);

	return tabular_table[rod_length-1];
}


int main()
{
  int rod_length;
	rod_length = 9;
	
	int price_table[rod_length];
	for(int i = 0; i < rod_length; i++)
		price_table[i] = 0;
	price_table[0] = 10;
	price_table[5] = 10000;


	printf("Price tabel:\n");
	for(int i = 0; i < rod_length; i++)
		printf("%d: %d\n", i + 1, price_table[i]);

	printf("The maximum total sale price for %d long rod is: %d\n", rod_length, rod_cutting_tabular(rod_length, price_table));

	return 0;
}
