struct node
{
		int value;
		node *next;
};

class linked_list
{
		public:
				linked_list();
				~linked_list();
				void add_front(int n);
				void add_back(int n);
				void display();
				void display_last();
				void display_odd();
				void insert_sort(int n);
				void remove(int n);
		private:
				node *head;

};
