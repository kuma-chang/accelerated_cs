const int SIZE = 500;


struct activity
{
		char *what;
		char *type;
		char *where;
		char *when;
		char *time;
		char *duration;
};

struct node
{
		activity *data;
		node *next;
};

class Linked_list
{
		public:
				Linked_list();
				~Linked_list();
				void add_back();
				void display_all();
				void search();
				void search_add(node *s);
				void remove_act();


		private:
				node *head;


};


void menu_print(int &n);
void menu_switch(int n, bool &x, Linked_list &l);
void input_activity(node *a);
void display_act(node *current);
