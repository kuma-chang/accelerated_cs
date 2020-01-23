#include "monte_carlo_test.h"


float* monte_carlo_test(char** board, float* table, int column, int row,  int repeat)
{
		int current;
		for(int i = 0; i < repeat; i++)
		{

				//Get the start for test
				current = GetRandom(1, (column - 2)); 
				for(int i = 0; i < row; i++)
				{
						if(board[i][current] == '0')
								current = current;
						else
						{
								int l_or_r = GetRandom(0,1);
								if(l_or_r == 0) //try going left
								{
										if(board[i][current-1] == '0')
												current = current - 1;
										else
												current = current + 1;
								}
								else
								{
										if(board[i][current+1] == '0')
												current = current + 1;
										else
												current = current - 1;
								}
						}
				}
				table[current]++;
		}
		return table;
}


void test_with_graphic_path(char** board, float* table, int column, int row)
{
		int current;

		printf("Board(before): \n");
		for(int i = 0; i < row; i++)
				printf("%s", board[i]);
		printf("\n");

		//Get the start for test
		current = GetRandom(1, (column - 2)); 
		//printf("start: %d\n", current); //to print out the literal path
		for(int i = 0; i < row; i++)
		{
				//printf("\n%d: %d\n", i-1, current); //to print out the literal path
				if(board[i][current] == '0')
						current = current;
				else
				{
						int l_or_r = GetRandom(0,1);
						if(l_or_r == 0) //try going left
						{
								if(board[i][current-1] == '0')
										current = current - 1;
								else
										current = current + 1;
						}
						else
						{
								if(board[i][current+1] == '0')
										current = current + 1;
								else
										current = current - 1;
						}
				}
				board[i][current] = 'I'; 
		}
		//printf("\nend: %d\n", current); //to print out the literal path
		table[current]++;
		printf("Board(after): \n");
		for(int i = 0; i < row; i++)
				printf("%s", board[i]);
		printf("\n");
}



void print_table(float* table, int column, int repeat)
{
		printf("\nTABLE: ");
		for(int i = 0; i < column; i++)
				printf("\nSlot %d: %.3f", i, table[i]/repeat);
		printf("\n");
}


