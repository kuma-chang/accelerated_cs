#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 50;


void welcome()
{
		cout << "This is a Hangman Game." << endl;
}



int main(void)
{
		char answer[SIZE];
		
		welcome();
		cout << "Enter a word: ";
		cin.get(answer, SIZE, '\n');
		


		cout << "The answer is: " << answer << endl;
		
		return 0;

}


