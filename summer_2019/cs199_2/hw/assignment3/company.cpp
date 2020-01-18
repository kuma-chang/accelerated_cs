#include <iostream>
#include <cstring>
#include "company.h"

using namespace std;

company::company()
{
		n_employees = 0;
}

company::~company()
{
		for(int i = 0; i < n_employees; ++i)
		{
				if(employees[i].name)
						delete [] employees[i].name;
				if(employees[i].job_title)
						delete [] employees[i].job_title;
				if(employees[i].job_description)
						delete [] employees[i].job_description;
				if(employees[i].pay_type)
						delete [] employees[i].pay_type;
				if(employees[i].pay_rate)
						delete [] employees[i].pay_rate;
				
				for(int n = 0; n < employees[i].followers_count; ++n)
						{
								delete [] employees[i].followers[n];
						}
				if(employees[i].followers)
						delete [] employees[i].followers;
				
			/*	
				if(employees[i].followers)
						delete [] employees[i].followers;
						*/
		}
}

void print_menu(int &n)
{
		cout << "Menu:" << endl;
		cout << "1. Hire new employees." << endl;
		cout << "2. Search for employee." << endl;
		cout << "3. Display the company directory." << endl;
		cout << "4. exit." << endl;
		cout << "Enter your choice: ";
		cin >> n;
		cin.ignore(SIZE, '\n');
		return;
}

void menu_switch(int n, bool &x, company &co)
{
		switch(n)
		{
				case 1:
						co.add_employee();
						break;
				case 2:
						co.search();
						break;
				case 3:
						co.display_dir();
						break;
				case 4:
						cout << "Bye~" << endl;
						x = false;
						break;
				default:
						cout << "Invalid choice." << endl;
						break;
		}
}

void company::add_employee()
{
		int temp;	
		char buffer[SIZE];
		bool f_repeat = true;
	
		employee *s = &employees[n_employees];

		cout << "Enter name: ";
		cin.get(buffer, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		s->name = new char [strlen(buffer) + 1];
		strcpy(s->name, buffer);

		cout << "Enter job title: ";
		cin.get(buffer, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		s->job_title = new char [strlen(buffer) + 1];
		strcpy(s->job_title, buffer);

		cout << "Enter jog description: ";
		cin.get(buffer, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		s->job_description = new char [strlen(buffer) + 1];
		strcpy(s->job_description, buffer);
	
		cout << "Enter pay type(salary or hourly): ";
		cin.get(buffer, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		s->pay_type = new char [strlen(buffer) + 1];
		strcpy(s->pay_type, buffer);

		cout << "Enter pay rate(annual salary or hourly rate): ";
		cin.get(buffer, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		s->pay_rate = new char [strlen(buffer) + 1];
		strcpy(s->pay_rate, buffer);

		cout << "How many followers does " << s->name << " have: ";
		cin >> temp;
		cin.ignore(SIZE, '\n');
		while(f_repeat)
		{
				if(temp == 0)
						f_repeat = false;
				else if(temp > 4)
				{
						cout << "There could only be 4 or less followers." << endl;
						cout << "How many followers does " << s->name << " have: ";
						cin >> temp;
						cin.ignore(SIZE, '\n');	
				}
				else
				{
						s->followers_count = temp;
						s->followers = new char *[s->followers_count];
						for(int i = 0; i < s->followers_count; ++i)
						{
								cout << "Enter follower " << i+1 << ": ";
								cin.get(buffer, SIZE, '\n');
								cin.ignore(SIZE, '\n');
								s->followers[i] = new char [strlen(buffer) + 1];
								strcpy(s->followers[i], buffer);
						}
						f_repeat = false;
				}
		}
		
		++n_employees;
}

void company::display_all()
{
		for(int i = 0; i < n_employees; ++i)
				display_employee(employees[i]);
}

void display_employee(employee &e)
{
		cout << "Name: " << e.name << endl;
		cout << "Job title: " << e.job_title << endl;
		cout << "Job description: " << e.job_description << endl;
		cout << "Pay type: " << e.pay_type << endl;
		cout << "Pay rate: " << e.pay_rate << endl;
		cout << "Followers count: " << e.followers_count << endl;
		cout << "Followers: ";
		for(int i = 0; i < e.followers_count; ++i)
				cout << e.followers[i] << " ";
		cout << endl;		
}

void company::search()
{
		char search[SIZE];
		int i = 0;

		cout << "Enter the name you want to search: ";
		cin.get(search, SIZE, '\n');
		cin.ignore(SIZE, '\n');

		while(strcmp(employees[i].name, search) != 0)
		{
				++i;
		}
		display_employee(employees[i]);

}
void company::display_dir()
{
		for(int i = 0; i < n_employees; ++i)
		{
				if(employees[i].followers_count != 0)
				{
						cout << employees[i].name << ": ";
						for(int n = 0; n < employees[i].followers_count; ++n)
						{
								cout << employees[i].followers[n] << " ";
						}
						cout << endl;
				}
		}
}
