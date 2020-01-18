#include <unistd.h>
#include <iostream>
#include <cstring>
#include "uno.h"


void welcome()
{
		cout << "______________________________________" << endl;
		cout << "|   ***   ***  ***   ***     ***      |" << endl;
		cout << "|   ***   ***  ****  ***   *******    |" << endl;
		cout << "|   ***   ***  ***** ***  ***   ***   |" << endl;
		cout << "|   ***   ***  *** *****  ***   ***   |" << endl;
		cout << "|    *******   ***  ****   *******    |" << endl;
		cout << "|     *****    ***   ***     ***      |" << endl;
		cout << "|                                     |_____________________________________________________________________________________" << endl;
		cout << "|                                                                                                                           |" << endl;
		cout << "|  Welcome!                                                                                                                 |" << endl;
		cout << "|  This is a UNO game!                                                                                                      |" << endl;
		cout << "|  At the begining of the game, each player would be deal 7 cards each                                                      |" << endl;
		cout << "|  Than the deck would give out the first card for the game to start                                                        |" << endl;
		cout << "|  You would be player 1                                                                                                    |" << endl;
		cout << "|  Each players turn could only play a card that:                                                                           |" << endl;
		cout << "|      1. maches the table's color or number                                                                                |" << endl;
		cout << "|      2. wild card                                                                                                         |" << endl;
		cout << "|  If you couldn't play any cards you'll have to draw one card                                                              |" << endl;
		cout << "|  If you could play the card you draw, you may choose to play                                                              |" << endl;
		cout << "|  To win the game is to be the first to play all the cards!                                                                |" << endl;
		cout << "|  But!!!!!                                                                                                                 |" << endl;
		cout << "|  Remember to yell(type): uno, when you're ending a tern with only one card                                                |" << endl;
		cout << "|  Or you would need to draw four cards                                                                                     |" << endl;
		cout << "|___________________________________________________________________________________________________________________________|" << endl;
		cout << "                                     **********************" << endl;
		cout << "                                       Now let's start!!!" << endl;
		cout << "                                     **********************" << endl;

}




void table_status_print(card *table)
{
		cout << "*Table Status*" << endl;
		cout << "「COLOR: " << table->color;
		if(table->number >= 0)
				cout << " | NUMBER: " << table->number << "」" << endl;
		else if(table->number == -1)
				cout << " | " << "REVERSE" << "」" << endl;
		else if(table->number == -2)
				cout << " | " << "+2" << "」" << endl;
		else if(table->number == -3)
				cout << " | " << "SKIP" << "」" << endl;
		else if(table->number == -4)
				cout << "」" << endl;
		else if(table->number == -5)
				cout << " | " << "+4" << "」" << endl;
}

void played_card_print(card *table)
{
		cout << "「COLOR: " << table->color;
		if(table->number >= 0)
				cout << " | NUMBER: " << table->number << "」" << endl;
		else if(table->number == -1)
				cout << " | " << "REVERSE" << "」" << endl;
		else if(table->number == -2)
				cout << " | " << "+2" << "」" << endl;
		else if(table->number == -3)
				cout << " | " << "SKIP" << "」" << endl;
		else if(table->number == -4)
				cout << "」" << endl;
		else if(table->number == -5)
				cout << " | " << "+4" << "」" << endl;
}

void display_hand_count(int p1, int p2, int p3, int p4)
{
		cout << "*Hand Count*" << endl;
		cout << "Player 1: " << p1 << endl;
		cout << "Player 2: " << p2 << endl;
		cout << "Player 3: " << p3 << endl;
		cout << "Player 4: " << p4 << endl;
}


int get_player_choice()
{
		int player_choice;
		cout << "Choose the card you want to play: ";
		cin >> player_choice;
		cin.clear();
		cin.ignore();
		return player_choice;
}

bool card_match_check(card* table, Card_holder * player, int player_choice)
{
		card *card_want_to_play;
		player->check_choice(card_want_to_play, player_choice);

		if(!strcmp(card_want_to_play->color,"Wild"))
				return true;
		else
		{
				if(!strcmp(table->color,card_want_to_play->color))
						return true;
				else if(table->number == card_want_to_play->number)
						return true;
				else
						return false;
		}
}

int get_color_choice()
{
		int change_color_choice;
		bool flag = true;
		while(flag)
		{
				cout << "Choose color for the wild card!!" << endl;
				cout << "1. Blue" << endl;
				cout << "2. Green" << endl;
				cout << "3. Red" << endl;
				cout << "4. Yellow" << endl;
				cout << "Please enter your choice: " ;
				cin >> change_color_choice;
				cin.clear();
				cin.ignore();
				if(change_color_choice > 0 && change_color_choice < 5)
						flag = false;
				else
						cout << "Invalid choice" << endl;
		}
		return change_color_choice;

}

int get_draw_or_play_choice()
{
		int draw_or_play_choice;
		bool flag = true;
		while(flag)
		{
				cout << "1. Draw a card" << endl;
				cout << "2. Play a card" << endl;
				cout << "Please enter your choice: " ;
				cin >> draw_or_play_choice;
				cin.clear();
				cin.ignore();
				if(draw_or_play_choice > 0 && draw_or_play_choice < 3)
						flag = false;
				else
						cout << "Invalid choice" << endl;
		}
		return draw_or_play_choice;
}

void wait(int s)
{
		for(int i = 0; i< s; ++i)
		{
				///*
				fflush(stdout);
				sleep(1);
				//*/
		}
}










