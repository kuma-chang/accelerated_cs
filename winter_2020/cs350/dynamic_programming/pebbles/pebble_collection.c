#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int memoization_table[100000000];

int max(int a, int b)
{
	if(a >= b)
		return a;
	else
		return b;
}

int picking_pebble_tabular(int** pebble_table, int row, int column)
{
  int tabular_table[row][column];
	// initializing tabular_table
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
			tabular_table[i][j] = -1;

	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
		{
			if(j == 0)
			{
				if(i == 0)
					tabular_table[i][j] = pebble_table[i][j];
				else
					tabular_table[i][j] = tabular_table[i -1][j] + pebble_table[i][j];
			}
			else
				tabular_table[i][j] = max(tabular_table[i - 1][j], tabular_table[i][j - 1]) + pebble_table[i][j];

			// printing out the tabular_table
			printf("The max for each spot: \n");
			for(int i = 0; i < row; i++)
			{
				printf("%d: ", i);
				for(int j = 0; j < column; j++)
					printf("%d ", tabular_table[i][j]);
				printf("\n");
			}

		}
	return tabular_table[row][column];
}



int main()
{
	int row = 5;
	int column = 6;
  int pebble_table[row][column];

	// initializing pebble_table
	for(int i = 0; i < row; i++)
		for(int j = 0; j < column; j++)
			pebble_table[i][j] = 0;

	// placing the pebbles
	pebble_table[0][4] = 1;
	pebble_table[1][1] = 1;
	pebble_table[1][3] = 1;
	pebble_table[2][3] = 1;
	pebble_table[2][5] = 1;
	pebble_table[3][2] = 1;
	pebble_table[3][5] = 1;
	pebble_table[4][0] = 1;
	pebble_table[4][4] = 1;

	// printing out the pebble_table
  printf("The pebble placement: \n");
	for(int i = 0; i < row; i++)
	{
		printf("%d: ", i);
		for(int j = 0; j < column; j++)
			printf("%d ", pebble_table[i][j]);
		printf("\n");
	}



	printf("The max number of pebble you'll be able to collect is: %d\n", picking_pebble_tabular((int**)pebble_table, row, column));



	for(int i = 0; i < 100000000; i++)
	{
		memoization_table[i] = -1;
	}




	return 0;
}
