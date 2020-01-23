#ifndef monte_carlo_test_h
#define monte_carlo_test_h

#include <stdio.h>
#include <string.h>


float* monte_carlo_test(char** board, float* table, int column, int row,  int repeat);
void test_with_graphic_path(char** board, float* table, int column, int row);
void print_table(float* table, int column, int repeat);


#endif
