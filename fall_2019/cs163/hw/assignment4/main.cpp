#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include "uno.h"
#include "cards_players.h"

using namespace std;

int main(void)
{
		welcome();
		cout << "Deck shuffling" ;
		for(int i = 0; i < 4; ++i)
		{
				wait(1);
				cout << "." ;
		}

		Card_holder *deck = new Deck;
		Card_holder *stack = new Stack;
		Card_holder *players[4];
		char uno_input[4];
		char play_draw_card_choice;
		int player_choice = 0;
		int bot_choice = 0;
		int change_color_choice = 0;
		int bot_change_color_choice = 0;
		int draw_or_play_choice = 0;
		int round = 60; //Leave room for the reverse
		int p1,p2,p3,p4;
		int round_count = 1; 
		card *table;
		card *draw;
		bool game_flag = true;
		bool plus_draw_falg = false; //Turn true when someone played +2 or +4
		bool player_choice_flag = true; //Turn true when the card being play is valid
		bool card_played_flag = false; //Turn true whenever a card been played
		bool draw_or_play_flag = true; //Turn false after the player have choose to draw or play
		bool uno_check_flag = true; //Turn false after the player have input yes or uno
		bool no_cards_to_play_flag = false; //Turn true when the player actually don't have any card could be played

		//Set up the players
		for(int i = 0; i < 4; ++i)
		{
				if(i == 0)
						players[i] = new Player(i+1, 0);
				else
						players[i] = new Player(i+1, 1);
		}
		
		//Deal 7 cards to each player
		for(int i = 0; i < 7; ++ i)
		{
				for(int j = 0; j < 4; ++j)
						players[j]->push(deck->pop());
		}
		wait(1);
		cout << "Cards dealing" ;
		for(int i = 0; i < 4; ++i)
		{
				wait(1);
				cout << "." ;

		}
		cout << "Cards dealed" << endl;
		wait(1);

		/*
		//Testing area, to modify the startig hand count
		stack->push(players[round % 4]->pop(1));
		stack->push(players[round % 4]->pop(1));
		stack->push(players[round % 4]->pop(1));
		stack->push(players[round % 4]->pop(1));
		stack->push(players[round % 4]->pop(1));
		*/

		//Initiate each player's cards in hand
		p1 = players[0]->check_left_cards();
		p2 = players[1]->check_left_cards();
		p3 = players[2]->check_left_cards();
		p4 = players[3]->check_left_cards();

		//Draw the first card to start the game
		stack->push(deck->pop());


		while(game_flag)
		{
				cout << "******************************************************" << endl;

				//Enter game loop
				stack->check_top(table);
				cout << "<=<=<=<==>=>=>=>" << endl;
				table_status_print(table);
				wait(1);

				//Check need to draw cards or not
				if(plus_draw_falg)
				{
						if(table->number == -2)
						{
								for(int i = 0; i < 2; i++)  //Draw 2 cards
										players[round % 4]->push(deck->pop()); 
						}
						if(table->number == -5)
						{
								for(int i = 0; i < 4; i++)  //Draw 4 cards
										players[round % 4]->push(deck->pop()); 
						}
						plus_draw_falg = false;
				}

				//Initiate each player's cards in hand
				p1 = players[0]->check_left_cards();
				p2 = players[1]->check_left_cards();
				p3 = players[2]->check_left_cards();
				p4 = players[3]->check_left_cards();

				//Display which player's turn it is
				cout << endl;
				cout << "Player " << round % 4 + 1 << " it's now your turn" << endl;
				wait(1);


				//check player
				if(!players[round % 4]->check_bot())   //This is regular player playing
				{
						//Display everyone's hand count
						cout << endl;
						display_hand_count(p1, p2, p3, p4);	

						//Display the player's hand
						players[round % 4]->display();

						//Let player choose to draw or play card
						draw_or_play_flag = true; //Reset the draw_or_play_flag

						while(draw_or_play_flag)
						{
								draw_or_play_choice = get_draw_or_play_choice();
								switch(draw_or_play_choice)
								{
										case 1:
												{
														players[round % 4]->push(deck->pop());  //Draw a card

														//Display the card being drawed
														cout << endl;
														cout << "You've drawed: " << endl;
														players[round % 4]->check_top(draw);
														cout << endl;
														played_card_print(draw);
														player_choice = 1;
														if(card_match_check(table, players[round % 4], player_choice))
														{
																cout << "You could play this card, do you want to? (y/n): " ;
																cin >> play_draw_card_choice;
																cin.clear();
																cin.ignore();
																if(play_draw_card_choice == 'y')
																{
																		card_played_flag = true;
																}
																if(card_played_flag)
																{
																		//Push the card from player hand to Stack
																		stack->push(players[round % 4]->pop(player_choice));
																		stack->check_top(table);

																		//Display the card being played
																		cout << endl;
																		cout << "Player" << round % 4 + 1 << " has played: " << endl;
																		stack->check_top(table);
																		cout << endl;
																		played_card_print(table);

																		//Run the effect for each card
																		if(!strcmp(table->color, "Wild"))
																		{
																				change_color_choice = get_color_choice();
																				table->change_color(change_color_choice);
																				if(table->number == -5)
																						plus_draw_falg = true;
																		}
																		else if(table->number == -1)
																				round_count = round_count * -1;
																		else if(table->number == -2)
																				plus_draw_falg = true;
																		else if(table->number == -3)
																				round += round_count;

																}

																card_played_flag = false; //Reset card_played_flag after effect ran
														}
															


														draw_or_play_flag = false;
														break;
												}
										case 2:
												{
														no_cards_to_play_flag = false; //Reset no_cards_to_play_flag
														
														//Use the bot check card to check if the player have any playable card
														bot_choice = 1; //reset the bot_choice
														while(!no_cards_to_play_flag && bot_choice <= players[round % 4]->check_left_cards())
														{
																if(card_match_check(table, players[round % 4], bot_choice))
																		no_cards_to_play_flag = true;
																else
																		bot_choice += 1;
														}

														if(!no_cards_to_play_flag)
														{
																cout << "But you don't have any playable cards :)" << endl;
														}
														else
														{
																//Get the players choice
																player_choice = get_player_choice();

																//Check choice
																player_choice_flag = true; //Reset the player choice flag
																while(player_choice_flag)
																{
																		if(player_choice < 1 || player_choice > p1)
																		{
																				cout << "Invalid choice" << endl;
																				player_choice = get_player_choice();
																		}
																		else if(!card_match_check(table, players[round % 4], player_choice))
																		{
																				cout << "Card choice don't match table!" << endl;
																				stack->check_top(table);
																				cout << endl;
																				table_status_print(table);
																				player_choice = get_player_choice();
																		}
																		else
																		{
																				card_played_flag = true;
																				player_choice_flag = false;
																		}

																}

																if(card_played_flag)
																{
																		//Push the card from player hand to Stack
																		stack->push(players[round % 4]->pop(player_choice));
																		stack->check_top(table);

																		//Display the card being played
																		cout << endl;
																		cout << "Player" << round % 4 + 1 << " has played: " << endl;
																		stack->check_top(table);
																		cout << endl;
																		played_card_print(table);

																		//Run the effect for each card
																		if(!strcmp(table->color, "Wild"))
																		{
																				change_color_choice = get_color_choice();
																				table->change_color(change_color_choice);
																				if(table->number == -5)
																						plus_draw_falg = true;
																		}
																		else if(table->number == -1)
																				round_count = round_count * -1;
																		else if(table->number == -2)
																				plus_draw_falg = true;
																		else if(table->number == -3)
																				round += round_count;

																}

																card_played_flag = false; //Reset card_played_flag after effect ran
																draw_or_play_flag = false;
														}
														break;
												}
										default:
												cout << "Invalid choice" << endl;
												break;

								}
						}


						//Check UNO!!!!
						uno_check_flag = true; //Reset the uno_check_flag
						while(uno_check_flag)
						{
								cout << "Type [yes] to confirm end turn: " ;
								cin.get(uno_input, 4, '\n');
								cin.ignore(4, '\n');
								if(!strcmp(uno_input, "yes"))
								{
										if(players[round % 4]->check_left_cards() == 1)
										{
												cout << "YOU FORGOT TO YELL UNO!!!!!" << endl;
												cout << "draw four cards" << endl;
												for(int i = 0; i < 4; i++)  //Draw 4 cards
														players[round % 4]->push(deck->pop()); 
										}

										uno_check_flag = false;
								}
								else if(!strcmp(uno_input, "uno"))
										uno_check_flag = false;
						}




				}
				else                                   //This is BOT playing
				{
						/*
						//Display the player's hand
						players[round % 4]->display();
						*/


						// Pick out the first card the bot could play
						bot_choice = 1; //reset the bot_choice
						while(!card_played_flag && bot_choice <= players[round % 4]->check_left_cards())
						{
								if(card_match_check(table, players[round % 4], bot_choice))
										card_played_flag = true;
								else
										bot_choice += 1;
						}

						if(card_played_flag)
						{
								//Push the card from player hand to Stack
								stack->push(players[round % 4]->pop(bot_choice));

								//Display the card being played
								cout << endl;
								cout << "Player " << round % 4 + 1 << " has played: " << endl;
								stack->check_top(table);
								cout << endl;
								played_card_print(table);
								wait(2);

								//Run the effect for each card
								if(!strcmp(table->color, "Wild"))
								{
										srand (time(NULL));  
										bot_change_color_choice = (rand() % 4) + 1;  
										change_color_choice = bot_change_color_choice;
										table->change_color(change_color_choice);
										if(table->number == -5)
												plus_draw_falg = true;
								}
								else if(table->number == -1)
										round_count = round_count * -1;
								else if(table->number == -2)
										plus_draw_falg = true;
								else if(table->number == -3)
										round += round_count;

								//BOT yells uno check
								if(players[round % 4]->check_left_cards() == 1)
								{
										cout << "UNO!!!!!" << endl;
								}
						}
						else
						{
								players[round % 4]->push(deck->pop());
								cout << "Player" << round % 4 + 1 << " has drawn a card" << endl;

						}

						card_played_flag = false; //Reset card_played_flag after effect runed


				}





				//update each player's hand count
				p1 = players[0]->check_left_cards();
				p2 = players[1]->check_left_cards();
				p3 = players[2]->check_left_cards();
				p4 = players[3]->check_left_cards();

				//Check if anyone won
				if(p1 == 0 || p2 == 0 || p3 == 0 ||p4 == 0)
				{
						game_flag = false;
						cout << "Player" << round % 4 + 1 << " WON!!!" << endl;
				}
				else if(deck->check_left_cards() == 0)
				{

						game_flag = false;
						cout << "Ran out of cards, this is a draw~" << endl;
				}


				//Add round and go to next round
				round += round_count;
				cout << "******************************************************" << endl;

		}



		//Free the upcasting variables
		delete deck;
		delete stack;
		for(int i = 0; i < 4; ++i)
				delete players[i];
		

		return 0;
}
