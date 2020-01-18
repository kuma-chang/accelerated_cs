#include <iostream>
#include <cstring>
#include <cctype>
#include "activity_tracker.h"

using namespace std;

Linked_list::Linked_list()
{
		head = NULL;
}

Linked_list::~Linked_list()
{
		node *temp;
		while(head)
		{
				temp = head;
				head = head->next;
				delete temp->data->what;
				delete temp->data->type;
				delete temp->data->where;
				delete temp->data->when;
				delete temp->data->time;
				delete temp->data->duration;
				delete temp->data;
				delete temp; 
		}
}

void menu_print(int &n)
{
		cout << "Menu: " << endl;
		cout << "1. Add a new activities." << endl;
		cout << "2. Display all activities." << endl;
		cout << "3. Search for an activity." << endl;
		cout << "4. Remove an activity." << endl;
		cout << "5. Exit." << endl;
		cout << "Enter your choice: ";
		cin >> n;
		cin.clear();
		cin.ignore();
		cout << endl;
		return;
}

void menu_switch(int n, bool &x, Linked_list &l)
{
		switch(n)
		{
				case 1:
						l.add_back();	
						break;
				case 2:
						l.display_all();
						break;
				case 3:
						l.search();
						break;
				case 4:
						l.remove_act();
						break;				
				case 5:
						cout << "bye~" << endl;
						x = false;
						break;
				default:
						cout << "Invalid choice" << endl;
						cout << endl;
						break;
		}
}

void Linked_list::add_back()
{
		node *temp, *current;

		if(!head)
		{
				head = new node;
				input_activity(head);
				head->next = NULL;
		}
		else
		{
				temp = new node;
				input_activity(temp);
				temp->next = NULL;
				current = head;
				while(current->next)
				{
						current = current->next;
				}
				current->next = temp;
		}
}

void Linked_list::display_all()
{
		node *current;

		if(!head)
		{
				cout << "This list is empty." << endl;
				return;
		}

		current = head;
		while(current)
		{
				cout << "------------------------------" << endl;
				cout << "The event: " << current->data->what << endl;
				cout << "Type: " << current->data->type << endl;
				cout << "Where: " << current->data->where << endl;
				cout << "When: " << current->data->when << endl;
				cout << "Time: " << current->data->time << endl;
				cout << "Duration: " << current->data->duration << endl;
				cout << "------------------------------" << endl;
				current = current->next;
		}
		cout << endl;
}

void display_act(node *current)
{
				cout << "------------------------------" << endl;
				cout << "The event: " << current->data->what << endl;
				cout << "Type: " << current->data->type << endl;
				cout << "Where: " << current->data->where << endl;
				cout << "When: " << current->data->when << endl;
				cout << "Time: " << current->data->time << endl;
				cout << "Duration: " << current->data->duration << endl;
				cout << "------------------------------" << endl;

}

void input_activity(node *a)
{
		char buffer[SIZE];

		a->data = new activity;

		cout << "Enter the data for the activity." << endl;

		cout << "What is it: ";
		cin.get(buffer, SIZE, '\n');
		cin.clear();
		cin.ignore(SIZE, '\n');
		a->data->what = new char [strlen(buffer) + 1];
		strcpy(a->data->what, buffer);

		cout << "What type is it: ";
		cin.get(buffer, SIZE, '\n');
		cin.clear();
		cin.ignore(SIZE, '\n');
		a->data->type = new char [strlen(buffer) + 1];
		strcpy(a->data->type, buffer);
		
		cout << "Where is it: ";
		cin.get(buffer, SIZE, '\n');
		cin.clear();
		cin.ignore(SIZE, '\n');
		a->data->where = new char [strlen(buffer) + 1];
		strcpy(a->data->where, buffer);

		cout << "When is it(date): ";
		cin.get(buffer, SIZE, '\n');
		cin.clear();
		cin.ignore(SIZE, '\n');
		a->data->when = new char [strlen(buffer) + 1];
		strcpy(a->data->when, buffer);

		cout << "When is it(time): ";
		cin.get(buffer, SIZE, '\n');
		cin.clear();
		cin.ignore(SIZE, '\n');
		a->data->time = new char [strlen(buffer) + 1];
		strcpy(a->data->time, buffer);

		cout << "How long would it take: ";
		cin.get(buffer, SIZE, '\n');
		cin.clear();
		cin.ignore(SIZE, '\n');
		a->data->duration = new char [strlen(buffer) + 1];
		strcpy(a->data->duration, buffer);
		
		cout << endl;
}


void Linked_list::search()
{
		node *current;
		char search[SIZE];
		char sort = 'a';

		cout << "Enter type to search: ";
		cin.get(search, SIZE, '\n');
		cin.clear();
		cin.ignore(SIZE, '\n');

		if(!head)
		{
				cout << "This list is empty." << endl;
				return;
		}
		

		for(int i = 0; i < 26; ++i)
		{
				current = head;
				while(current)
				{

						if(strcmp(current->data->type, search) == 0 && tolower(current->data->what[0]) == (sort + i))
						{
								display_act(current);
						}
				current = current->next;
				}

		}


		
}

/*
void Linked_list::search_add(node *s)
{
		node *temp, *current, *input = s;
		
		if(!head)
		{
				head = new node;
				head->data  = new activity;
				*head->data = *input->data;
				head->next = NULL;
				cout << input->data << endl;
				cout << head->data << endl;
		}
		else
		{
				temp = new node;
				temp->data = new activity;
				*temp->data = *input->data;
				temp->next = NULL;
				current = head;
				while(current->next)
				{
						current = current->next;
				}
				current->next = temp;

				cout << input->data->what << endl;
				cout << input->data->type << endl;

		}
}
*/


void Linked_list::remove_act()
{
		node *temp, *current, *previous;
		char search[SIZE];

		cout << "Enter what activity to remove: ";
		cin.get(search, SIZE, '\n');
		cin.clear();
		cin.ignore(SIZE, '\n');

		if(!head)
		{
				cout << "This list is empty." << endl;
				return;
		}
		
		current = head;
		while(current)
		{
				if(strcmp(head->data->what, search) == 0)
				{
						temp = head;
						head = head->next;
						current = head;
						delete temp;
				}
				else if(strcmp(current->data->what, search) == 0)
				{
						temp = current;
						previous->next = current->next;
						current = current->next;
						delete temp;

				}
				previous = current;
				current = current->next;
		}
}














