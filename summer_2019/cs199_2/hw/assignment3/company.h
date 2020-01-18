const int SIZE = 500;


struct employee
{

		char *name;
		char *job_title;
		char *job_description;
		char *pay_type;
		char *pay_rate;
		int followers_count;
		char **followers;
		
};

class company
{
		public:
				company();
				~company();
				void add_employee();
				void display(int n);
				void display_test();
				void display_all();
				void search();
				void display_dir();
		private:
				employee employees[SIZE];
				int n_employees;
};


void print_menu(int &n);
void menu_switch(int n, bool &x, company &co);
void display_employee(employee &e);

