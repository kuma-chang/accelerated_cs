#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

Stack::Stack()
{
		head = NULL;
}

Stack::~Stack()
{
		car_node *temp;
		while(head)
		{
				temp = head;
				head = head->next;
				delete [] temp->brand;
				delete [] temp->model;
				for(int i = 0; i < 10; ++i)
						delete [] temp->feature_list[i];
				delete [] temp->feature_list;
				delete temp;
		}
}
void Stack::push(car_node *&reject_node)
{
		reject_node->next = head;
		head = reject_node;
}

void Stack::display()const
{
		car_node *current;
		current = head;
		while(current)
		{
				cout << "\n\n";
				cout << "Brand: " << current->brand << endl;
				cout << "Model: " << current->model << endl;
				for(int i = 0; i < 10; ++i)
				if(current->feature_list[i] != NULL)
						cout << "Car available feature: #" << i+1 << " " << current->feature_list[i] << endl;
				current = current->next;
		}
}


void Stack::display_last()const
{
		cout << "\n\n";
		cout << "Brand: " << head->brand << endl;
		cout << "Model: " << head->model << endl;
		for(int i = 0; i < 10; ++i)
				if(head->feature_list[i] != NULL)
						cout << "Car available feature: #" << i+1 << " " << head->feature_list[i] << endl;
}


