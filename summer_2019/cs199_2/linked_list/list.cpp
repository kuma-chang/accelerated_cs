#include <iostream>
#include "list.h"

using namespace std;

linked_list::linked_list()
{
		head = NULL;
}

linked_list::~linked_list()
{
		node *temp;
		while(head)
		{
				temp = head;
				head = head->next;
				delete temp;
		}
}

void linked_list::add_front(int n)
{
		node *temp;
		if (!head)
		{
				head = new node;
				head->value = n;
				head->next = NULL;		
		}
		else
		{
				temp = new node;
				temp->value = n;
				temp->next = head;
				head = temp;
		}
}

void linked_list::add_back(int n)
{
		node *temp, *current;
		if (!head)
		{
				head = new node;
				head->value = n;
				head->next = NULL;
		}
		else
		{
				temp = new node;
				temp->value = n;
				temp->next = NULL;
				current = head;
				while (current->next)
				{
						current = current->next;
				}
				current->next = temp;
		}
}

void linked_list::display()
{
		node *current;
		current = head;
		while (current)
		{
				cout << current->value << " ";
				current = current->next;
		}
		cout << endl;
}

void linked_list::display_last()
{
		node *current;
		//check for empty list
		if (!head)
		{
				cout << "This list is empty" << endl;
				return;
		}


		current = head;
		while (current->next != NULL)
		{
				current = current->next;
		}
		cout << current->value << endl;
}

void linked_list::display_odd()
{
		node *current;
		current = head;
		while (current->next && current->next->next)
		{
				cout << current->value << " ";
				current = current->next->next;
		}
		cout << current->value << endl;
}

void linked_list::insert_sort(int n)
{
		node *temp, *current;
		current = head;
		if (!head)
		{
				head = new node;
				head->value = n;
				head->next = NULL;		
		}
		else if (head->value > n)
		{
				temp = new node;
				temp->value = n;
				temp->next = head;
				head = temp;
		}
		else
		{
				temp = new node;
				temp->value = n;
				current = head;
				while(current->next && current->next->value < temp->value)
				{
						current = current->next;
				}
				temp->next = current->next;
				current->next = temp;
		}
}

void linked_list::remove(int n)
{
		node *temp, *current, *previous;
		if (!head)
		{
				cout << "This list is empty" << endl;
				return;
		}
		else if(head->value == n)
		{
				temp = head;
				head = head->next;
				delete temp;
		}
		else
		{
				current = head->next;
				previous = head;
				while(current && current->value != n)
				{
						previous = current;
						current = current->next;
				}
				if(current)
				{
						previous->next = current->next;
						delete current;
				}
				else
				{
						cout << "nothing found" << endl;
				}
		}
}
