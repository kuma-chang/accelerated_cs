#ifndef cards_players_h
#define cards_players_h

using namespace std;



struct card
{
		int id;
		int number;
		char *color;
		card *next;
		card(int i);
		void print();
		void change_color(int i);
};

class Card_holder //This is the base class for all class that would hold cards.
{
		public:
				Card_holder();
				virtual ~Card_holder();
				int push(card *to_add);
				card* pop();
				card* pop(int i);
				void check_top(card *& table);
				void check_choice(card *& card_want_to_play, int choice);
				int check_left_cards();
				virtual void display();
				virtual bool check_bot();

		private:
				int count;
				card *head;
};

class Deck : public Card_holder //This would be the deck where the players draw from
{
		public:
				Deck();
				~Deck();
		private:
				void swap(int *a, int *b);
				void randomize(int arr[], int n);

};

class Stack : public Card_holder //This is where the cards have been played
{
		public:
				//Stack();
				//~Stack();
};

class Player : public Card_holder
{
		public:
				Player(int num, int i); //Bot: i = 1; normal_player: i = 0
				//~Player();
				void display();
				bool check_bot();
		private:
				int player_num;
				bool bot_flag;
};






#endif
