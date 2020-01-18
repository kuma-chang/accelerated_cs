/* *****************************************
 * Michael Chang
 * Program Number: cs199_assignment1_Multiplecation_Game
 * This is a Multiplecation Game
 * *****************************************/
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <cmath>

using namespace std;

void welcome()
{
		cout << "Welcom!\n"
			 <<	"This is a Multiplecation Game.\n" 
			 << "In this Game you will have a total of five questions.\n"
			 << "If you got the last question correct, "
			 << "and your guess was with in +-5 of the answer, you'll get a second chance.\n"
			 << "If your second guess was even closer than you'll get a third and final chance.\n"
			 << "For each question, you'll get to choose difficulty level from 1 to 3, 3 being the hardest.\n"
			 << "The score is as following\n"
			 << "Level --> Score\n"
			 << "1 --> 1 point\n"
			 << "2 --> 2 point\n"
			 << "3 --> 3 point\n"
			 << endl;
}

int get_level(int i)
{
		int n;
		cout << "Please choose the diffculty level for question " << i << ": ";
		cin >> n;
		return n;
}

int get_guess()
{
		int n;
		cout << "Please enter your guess: ";
		cin >> n;
		return n;
}


int main(void)
{
		int level;
		bool level_flag = 1;
		int num_range;
		int num_1;
		int num_2;
		int answer;
		int guess_1;
		int guess_2;
		int guess_3;
		int diff_1;
		int diff_2;
		int diff_3;
		int point_counter = 0;

		srand(time(0));

		welcome();
		for (int i = 0; i < 5; ++i)
		{
			level_flag = 1;
			level = get_level(i + 1);
			while (level_flag)
			{
					switch (level)
					{
							case 1:
								num_range = 10;
								level_flag = 0;
								break;
							case 2:
								num_range = 100;
								level_flag = 0;
								break;
							case 3:
								num_range = 1000;
								level_flag = 0;
								break;
							default:
								cout << "Invalid level, please only enter level 1, 2 or 3." << endl;
								level = get_level(i + 1);
								break;
					}
			}

			num_1 = rand() % num_range;
			num_2 = rand() % num_range;
			answer = num_1 * num_2; 
			

			cout << "Question " << i+1 << endl;
			cout << "What is the answer for: " << num_1 << " * "<< num_2 << endl;

			guess_1 = get_guess();
			
			diff_1 = abs(guess_1 - answer);
			if (diff_1 == 0)
			{
					cout << "Correct! You got " << level << " point(s)!" << endl;
					point_counter = point_counter + level;

			}
			else if (diff_1 <= 5)
			{
					cout << "That was close, try again" << endl;
					guess_2 = get_guess();
					diff_2 = abs(guess_2 - answer);
					if (diff_2 == 0)
					{
							cout << "Correct! You got " << level << " point(s)!" << endl;
							point_counter = point_counter + level;	
					}
					else if (diff_2 < diff_1)
					{
							cout << "So close! One last try" << endl;
							guess_3 = get_guess();
							diff_3 = abs(guess_3 - answer);
							if (diff_3 == 0)
							{
									cout << "Correct! You got " << level << " point(s)!" << endl;
									point_counter = point_counter + level;	
							}
							else
							{
									cout << "Sorry, the answer was: " << answer << endl;
							}
					}
					else
					{
							cout << "Sorry, the answer was: " << answer << endl;
					}
			}
			else
			{
					cout << "Sorry, the answer was: " << answer << endl;
			}
			cout << endl;
		}

		cout << "Yout total score is: " << point_counter << "!" << endl;
		return 0;
}





