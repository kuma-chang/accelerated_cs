#include <iostream>
#include <cstring>
#include "queue.h"

using namespace std;

Queue::Queue()
{
		tail = NULL;
}

Queue::~Queue()
{
		car_node *temp;
		temp = tail;
		tail = tail->next;
		temp->next = NULL;
		while(tail)
		{
				temp = tail;
				tail = tail->next;
				delete [] temp->brand;
				delete [] temp->model;
				for(int i = 0; i < 10; ++i)
						delete [] temp->feature_list[i];
				delete [] temp->feature_list;
				delete temp;
		}
}






void Queue::enqueue(car_node *node_to_add)
{
		if(!tail)
		{
				tail = node_to_add;
				tail->next = tail;
		}
		else
		{
				node_to_add->next = tail->next;
				tail->next = node_to_add;
				tail = node_to_add;
		}
}

void Queue::display()const
{
		car_node *current = tail->next;
		do
		{
				cout << "\n\n";
				cout << "Brand: " << current->brand << endl;
				cout << "Model: " << current->model << endl;
				for(int i = 0; i < 10; ++i)
						if(current->feature_list[i] != NULL)
								cout << "Car available feature: #" << i+1 << " " << current->feature_list[i] << endl;
				current = current->next;

		}while(current != tail->next);
		
}

void Queue::dequeue(car_node *&reject_node)
{
		reject_node = tail->next;
		tail->next = tail->next->next;
}

void Queue::display_next()const
{
		car_node *current = tail->next;
		cout << "\n\n";
		cout << "Brand: " << current->brand << endl;
		cout << "Model: " << current->model << endl;
		for(int i = 0; i < 10; ++i)
				if(current->feature_list[i] != NULL)
						cout << "Car available feature: #" << i+1 << " " << current->feature_list[i] << endl;
		current = current->next;
}
