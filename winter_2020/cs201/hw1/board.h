#ifndef board_h
#define board_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void get_row_n_column(int *column, int *row, char *buffer);
char** creat_board(int column, int row, FILE *fp);
void print_board(char** board, int row);



#endif
