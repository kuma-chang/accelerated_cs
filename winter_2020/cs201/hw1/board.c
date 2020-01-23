#include "board.h"





void get_row_n_column(int *column, int *row, char *buffer)
{
		for(int i = 0; i < 2; i++)
		{
				if(i == 0)
						*column = strtol(strtok(buffer, ","), NULL, 10);
				else if(i == 1)
						*row = strtol(strtok(NULL, ","), NULL, 10);
		}
}


char** creat_board(int column, int row, FILE *fp)
{
		char** board;
		board = (char**)malloc(sizeof(char*) * row);
		for(int i = 0; i < row; i++)
		{
				board[i] = (char*)malloc(sizeof(char) * column);
				fgets(board[i], 500, fp);
		}
		return board;
}

		
void print_board(char** board, int row)
{
		printf("Board: \n");
		for(int i = 0; i < row; i++)
				printf("%s", board[i]);
		printf("\n");
}




