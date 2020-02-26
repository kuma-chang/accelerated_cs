#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int min(int a, int b)
{
	if(a < b)
		return a;
	else
		return b;
}

int min_sum_tabular(int n, int min_table[][n])
{
  int tabular_table[n][n];
	int result = 0;
	// initializing tabular_table
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			tabular_table[i][j] = -1;

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= i; j++)
			{
				if(j == 0)
				{
					if(i == 0)
						tabular_table[i][j] = min_table[i][j];
					else
						tabular_table[i][j] = min_table[i][j] + tabular_table[i-1][j];
				}
				else if(j == i)
					tabular_table[i][j] = min_table[i][j] + tabular_table[i-1][j-1];
				else
					tabular_table[i][j] = min_table[i][j] + min(tabular_table[i-1][j-1], tabular_table[i-1][j]);
			}

	result = tabular_table[n-1][0];
	for(int j = 0; j < n; j++)
		if(result > tabular_table[n-1][j])
			result = tabular_table[n-1][j];


	// printing out the tabular_table
	printf("\nThe min-sum for each spot: \n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
			printf("%d ", tabular_table[i][j]);
		printf("\n");
	}

	return result;
}


int main()
{
  char text[10000];
  int n;

  printf("enter N: ");
  scanf("%s", text) ;
  n = atoi(text);

	// initializing the min_table in to all 0
	int min_table[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			min_table[i][j] = 0;

	// get input for each levels
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
		{
			printf("enter %d-%d: ", i + 1, j + 1);
			printf("enter K: ");
			scanf("%s", text) ;
			min_table[i][j] = atoi(text);
		}

	printf("\nInput table: \n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
			printf("%d ", min_table[i][j]);
		printf("\n");
	}

	printf("\nMinimum-sum is: %d\n", min_sum_tabular(n, min_table));

	return 0;
}
