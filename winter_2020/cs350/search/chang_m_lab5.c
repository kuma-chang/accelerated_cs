#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Find the location of the first occurrence of pattern in text
// or say that it does not occur if that is the case.
// If you find the pattern in the text, output the index of the
// first letter in text where the pattern first occurs.

// You must also print the total number of character compairsons that
// the program made.

// If the number of unchecked characters in the text is ever less than
// the length of the pattern the algorithm must stop.

// NOTE:  All test texts and patterns should not contain any white space
//        (e.g. blank space character, newline, tab, etc.) as scanf
//        will stop on such an input character.

int boyer_moore_search_f(char pattern[], int m, char text[], int n, int* compare_count)
{
	int result = -1;
	int ascii_table[128];
	int pointer = m - 1;
	int count = 0;
	bool shift_flag = false; //turn true whenever compare is different and needs to shift
	bool found_flag = false; //turn true when found pattern
	for(int i = 0; i < 128; i++) // initialization for the ascii table all to pattern size m
		ascii_table[i] = m;
	for(int i = 0; i < m; i++)
	{
		ascii_table[pattern[i]] = m-((i + 1)%m);
		// printf("%c --> %d switch from %d to %d\n", pattern[i], pattern[i], m, m-((i + 1)%m)); // for checking setting up the table
	}
	while(pointer < n && !found_flag)
	{
		count = 0;
		shift_flag = false;
		while(count < m && !shift_flag)
		{
			if(pattern[m-1-count] == text[pointer-count])
			{
				if(count == m-1)
					found_flag = true;
				count++;
			}
			else
				shift_flag = true;
			*compare_count += 1;
		}
		if(shift_flag)
			pointer = pointer + ascii_table[text[pointer-count]];
	}

	if(found_flag)
		result = pointer - (m - 1);

	/* print table for checking
	for(int i = 0; i < 128; i++)
		printf("%d: %d\n", i, ascii_table[i]);
	*/
	
	return result;
}


void boyer_moore_search(char pattern[], int m, char text[], int n)
{
	int compare_count;
	int result = boyer_moore_search_f(pattern, m, text, n, &compare_count);
	if(result == -1)
		printf("Pattern could not be found in text.\n");
	else
		printf("Have found pattern starting at index: %d\n", result);
	printf("Total number of character compairsons: %d\n", compare_count);

}



int main()
{
  char text[10000] ;
  char pattern[200] ;
  int m,n ;

  printf("enter text : ") ;
  scanf("%s", text) ;
  printf("enter pattern you are searching for : ") ;
  scanf("%s", pattern) ;

  m = strlen(pattern) ;
  n = strlen(text) ;
  printf("The pattern has %d characters and the text has %d characters.\n", m,n) ;

	boyer_moore_search(pattern, m, text, n);

}


