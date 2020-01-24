#include "hw1_plinko.h"
#include "board.h"
#include "monte_carlo_test.h"




int main(int argc, char* argv[])
{
		InitRandom(); //enable GetRandom()
		FILE *fp = NULL; //file pointer for the board
		const int SIZE = 500;
		int *row = (int*)malloc(sizeof(int));
		int *column = (int*)malloc(sizeof(int));
		int repeat = 10000; //to control howmany repeat the test goes
		//int current = 0; //to keep track of the ball's position
		float *table;  //to keep track of each result
		char buffer[SIZE];
		char **board;


		//Open file to get the board
		if(argc > 1)
		{
				fp = fopen(argv[1], "r");
				if(fp)
						printf("file opened\n");
		}
		else
		{
				printf("Please enter the board's file name (ex:./hw_plinko board_file_name)\n");
				return -1;
		}

		//Get the row and column by parsing the first line
		fgets(buffer, SIZE, fp);
		printf("The board size is: %s\n", buffer);
		get_row_n_column(column, row, buffer);



		//Read in board
		board = creat_board(*column, *row, fp);



		//Creat the table
		table = (float*)malloc(sizeof(float)* *column);
		for(int i = 0; i < *column; i++)
				table[i] = 0; //initializing the table to all 0



		//Print out the board
		print_board(board, *row);



		//Close the file after we got the board
		fclose(fp);



		//Enter the loop for testing
		table = monte_carlo_test(board, table, *column, *row, repeat);

		//Print out the board with the graphical path
		//test_with_graphic_path(board, table, *column, *row);



		//Print out the table
		print_table(table, *column, repeat);



		//free the board
		for(int i = 0; i < *row; i++)
				free(board[i]);
		free(board);
		free(table);
		free(row);
		free(column);

		/*
		//Test for argc & argv
		for(int i = 0; i < argc; i++)
		{
				printf("Argument %d: %s\n", i, argv[i]);
		}
		   */

		//Test GetRandom()
		//let i & j be between 1 and 5
		/*
		   int i,j;
		   i = GetRandom(1,5);
		   j = GetRandom(1,5);
		   printf("i = %d, j = %d\n", i, j);
		   */

		return 0;
}
