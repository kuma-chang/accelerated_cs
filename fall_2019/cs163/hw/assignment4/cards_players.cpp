#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include "cards_players.h"


/**************************
 *card functions
 **************************/
card::card(int i)
{
		id = i;
		next = NULL;
		
		//Assigning number
		int num = id % 25;

		//number = num;
		if(id < 100)
		{
				if(num == 0)
						number = 0;
				else if(num >= 1 && num < 3)
						number = 1;
				else if(num >= 3 && num < 5)
						number = 2;
				else if(num >= 5 && num < 7)
						number = 3;
				else if(num >= 7 && num < 9)
						number = 4;
				else if(num >= 9 && num < 11)
						number = 5;
				else if(num >= 11 && num < 13)
						number = 6;
				else if(num >= 13 && num < 15)
						number = 7;
				else if(num >= 15 && num < 17)
						number = 8;
				else if(num >= 17 && num < 19)
						number = 9;
				else if(num >= 19 && num < 21)
						number = -1; //this is reverse
				else if(num >= 21 && num < 23)
						number = -2; //this is +2
				else if(num >= 23 && num < 25)
						number = -3; //this is skip 
		}
		else
		{
				if(id < 104)
						number = -4;
				else
						number = -5;
		}

		//Assigning color
		if(id >= 0 && id < 25)
		{
				color = new char[strlen("Blue")+1];
				strcpy(color,"Blue");
		}
		else if(id >= 25 && id < 50)
		{
				color = new char[strlen("Green")+1];
				strcpy(color,"Green");
		}
		else if(id >= 50 && id < 75)
		{
				color = new char[strlen("Red")+1];
				strcpy(color,"Red");
		}
		else if(id >= 75 && id < 100)
		{
				color = new char[strlen("Yellow")+1];
				strcpy(color,"Yellow");
		}
		else if(id >= 100 && id < 108)
		{
				color = new char[strlen("Wild")+1];
				strcpy(color,"Wild");
		}
}

void card::print()
{
		//cout << "Card id: " << id;
		cout << "「color: " << color;
		if(number >= 0)
				cout << " | number: " << number << "」" << endl;
		else if(number == -1)
				cout << " | " << "REVERSE" << "」" << endl;
		else if(number == -2)
				cout << " | " << "+2" << "」" << endl;
		else if(number == -3)
				cout << " | " << "SKIP" << "」" << endl;
		else if(number == -4)
				cout << "」" << endl;
		else if(number == -5)
				cout << " | " << "+4" << "」" << endl;

		cout << endl;
}

void card::change_color(int i)
{
		delete [] color;
		switch(i)
		{
				case 1:
						{
								color = new char[strlen("Blue")+1];
								strcpy(color,"Blue");
								break;
						}
				case 2:
						{
								color = new char[strlen("Green")+1];
								strcpy(color,"Green");
								break;
						}
				case 3:
						{
								color = new char[strlen("Red")+1];
								strcpy(color,"Red");
								break;
						}
				case 4:
						{
								color = new char[strlen("Yellow")+1];
								strcpy(color,"Yellow");
								break;
						}
				default:
						break;
		}
}





/**************************
 *Card_holder functions
 **************************/
Card_holder::Card_holder()
{
		head = NULL;
		count = 0;
}

Card_holder::~Card_holder()
{
		while(head)
		{
				card *temp = head;
				head = head->next;
				delete [] temp->color;
				delete temp;
		}
}

int Card_holder::push(card *to_add)
{
		to_add->next = head;
		head = to_add;
		count += 1;
}

card* Card_holder::pop()
{
		card *temp;
		temp = head;
		head = head->next;
		temp->next = NULL;
		count -= 1;
		return temp;
}

card* Card_holder::pop(int i)
{
		card *temp, *current;
		if(i-1 == 0)
		{
				temp = head;
				head = head->next;
				temp->next = NULL;
				count -= 1;
				return temp;
		}
		else
		{
				current = head;
				for(int x = 0; x < i-2; ++x)
						current = current->next;
				temp = current->next;
				current->next = current->next->next;
				temp->next = NULL;
				count -= 1;
				return temp;
		}
}

void Card_holder::check_choice(card *& card_want_to_play, int choice)
{
		card *current;
		current = head;
		for(int i = 0; i < choice - 1; ++i)
				current = current->next;
		card_want_to_play = current;
}

void Card_holder::check_top(card *&table)
{
		table = head;
}

void Card_holder::display()
{
		int index = 1;
		card *current = head;
		while(current)
		{
				cout << index << ": ";
				current->print();
				current = current->next;
				index += 1;
		}
}

bool Card_holder::check_bot()
{
		cout << "EMPTY" << endl;
}

int Card_holder::check_left_cards()
{
		return count;
}




/**************************
 *Deck functions
 **************************/
//function for shuffle
void Deck::swap(int *a, int *b)
{
		int temp = *a;  
		*a = *b;  
		*b = temp;  
}

void Deck::randomize(int arr[], int n)
{
		srand (time(NULL));  
		for (int i = n - 1; i > 0; i--)  
		{  
				int j = rand() % (i + 1);  
				swap(&arr[i], &arr[j]);  
		} 
}

Deck::Deck()
{
		int arr_test[108];
		for(int i = 0; i < 108; ++i)
				arr_test[i] = i;
		randomize(arr_test, 108);
		for(int i = 0; i < 108; ++i)
		{
				card *to_add = new card(arr_test[i]);
				push(to_add);
		}
		cout << "Deck shuffled" << endl;
}

Deck::~Deck()
{
}




/**************************
 *Stack functions
 **************************/





/**************************
 *Player functions
 **************************/
Player::Player(int num, int i)
{
		player_num = num;
		
		if(i == 1)
				bot_flag = true;
		else
				bot_flag = false;
}

void Player::display()
{
		if(player_num == 1)
				cout << "Your hand" << endl;
		else
				cout << "Player " << player_num << "'s hand";
		if(bot_flag)
				cout << "[BOT]";
		cout << endl;
		Card_holder::display();
}

bool Player::check_bot()
{
		return bot_flag;
}



