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

int n_choose_k_tabular(int n, int k)
{
  int tabular_table[n + 1][n + 1];
	// initializing tabular_table
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++)
			tabular_table[i][j] = -1;

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= i; j++)
			if(j <= k)
			{
				if(j == 0 || j == i)
					tabular_table[i][j] = 1;
				else
					tabular_table[i][j] = tabular_table[i-1][j-1] + tabular_table[i-1][j];
			}

	// printing out the tabular_table
	printf("The max for each spot: \n");
	for(int i = 0; i <= n; i++)
	{
		printf("%d: ", i);
		for(int j = 0; j <= n; j++)
			printf("%d ", tabular_table[i][j]);
		printf("\n");
	}

	return tabular_table[n][k];
}


int main()
{
  char text[10000];
  int n;
	int k;

  printf("enter N: ");
  scanf("%s", text) ;
  n = atoi(text);
  printf("enter K: ");
  scanf("%s", text) ;
  k = atoi(text);

	printf("\n%d choose %d is: %d\n", n, k, n_choose_k_tabular(n,k));

	return 0;
}
