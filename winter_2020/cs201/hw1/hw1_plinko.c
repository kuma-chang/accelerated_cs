#include "hw1_plinko.h"

//include the .h that were given
#include "hw1given.h"



int main(int argc, char* argv[])
{
		InitRandom(); //enable GetRandom()
		FILE *fp = NULL; //file pointer for the board
		const int SIZE = 500;
		int row = 0;
		int column = 0;
		int repeat = 10000; //to control howmany repeat the test goes
		int current = 0; //to keep track of the ball's position
		float *table;  //to keep track of each result
		char buffer[SIZE];
		char **board;


		/*
		//Test for argc & argv
		for(int i = 0; i < argc; i++)
		{
				printf("Argument %d: %s\n", i, argv[i]);
		}
		   */

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

		for(int i = 0; i < 2; i++)
		{
				if(i == 0)
						column = strtol(strtok(buffer, ","), NULL, 10);
				else if(i == 1)
						row = strtol(strtok(NULL, ","), NULL, 10);
		}
		printf("column: %d\n", column);
		printf("row: %d\n", row);

		//Read in board
		board = (char**)malloc(sizeof(char*)*row);
		for(int i = 0; i < row; i++)
		{
				board[i] = (char*)malloc(sizeof(char)*column);
				fgets(board[i], SIZE, fp);
		}


		//Creat the table
		table = (float*)malloc(sizeof(float)*column);
		for(int i = 0; i < column; i++)
				table[i] = 0; //initializing the table to all 0

		//Print out the board
		printf("Board: \n");
		for(int i = 0; i < row; i++)
				printf("%s", board[i]);
		printf("\n");

		//Close the file after we got the board
		fclose(fp);


		//Test GetRandom()
		//let i & j be between 1 and 5
		/*
		   int i,j;
		   i = GetRandom(1,5);
		   j = GetRandom(1,5);
		   printf("i = %d, j = %d\n", i, j);
		   */

		//Enter the loop for testing
		for(int i = 0; i < repeat; i++)
		{

				//Get the start for test
				current = GetRandom(1, (column - 2)); 
				//printf("start: %d\n", current); //to print out the path
				for(int i = 0; i < row; i++)
				{
						//printf("\n%d: %d\n", i-1, current); //to print out the path
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
						//board[i][current] = 'I'; //For printing out the path (remember to switch the repeat = 1)
				}
				//printf("\nend: %d\n", current); //to print out the path
				table[current]++;
		}

		//Print out the table
		printf("\nTABLE: ");
		for(int i = 0; i < column; i++)
				printf("\nSlot %d: %.3f", i, table[i]/repeat);
		printf("\n");

		/*
		//Print out the board with the path
		//remember to switch the repeat = 1
		printf("Board: \n");
		for(int i = 0; i < row; i++)
				printf("%s", board[i]);
		printf("\n");
		*/


		//free the board
		for(int i = 0; i < row; i++)
				free(board[i]);
		free(board);
		free(table);

		return 0;
}
