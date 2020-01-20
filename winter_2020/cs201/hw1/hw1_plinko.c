#include "hw1_plinko.h"

//include the .h that were given
#include "hw1given.h"



int main(int argc, char* argv[])
{
		InitRandom(); //enable GetRandom()

		//Test GetRandom()
		//let i & j be between 1 and 5
		/*
		   int i,j;
		   i = GetRandom(1,5);
		   j = GetRandom(1,5);
		   printf("i = %d, j = %d\n", i, j);
		   */

		//Test for argc & argv
		for(int i = 0; i < argc; i++)
		{
				printf("Argument %d: %s\n", i, argv[i]);
		}


		printf("hello, world\n");
		return 0;
}
