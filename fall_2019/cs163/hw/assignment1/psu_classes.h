const int SIZE = 500;

struct node
{
		char *hint;
		int likes;
		int index;
		node *next;
};

class LLL 
{
		public:
				LLL();
				~LLL();
				void display_order();
				void display_like();
				void add_back();
				void get_hint(node *temp);
				void like(int max);

		private:
				node *head;

};

void print_menu(int &n);
void menu_switch(int n, bool &x, LLL &r, LLL &b, LLL &c);
void print_choice();


