#ifndef uno_h
#define uno_h

#include "cards_players.h"

using namespace std;

void welcome();

void table_status_print(card *table);
void played_card_print(card *table);

void display_hand_count(int p1, int p2, int p3, int p4);


int get_player_choice();
int get_color_choice();
int get_draw_or_play_choice();
bool card_match_check(card* table, Card_holder * player, int player_choice);


void wait(int s);




#endif
