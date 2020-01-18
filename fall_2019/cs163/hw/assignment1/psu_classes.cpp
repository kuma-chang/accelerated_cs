#include <iostream>
#include <cstring>
#include "psu_classes.h"

using namespace std;

LLL::LLL()
{
		head = NULL;
}

LLL::~LLL()
{
		node *temp;
		while(head)
		{
				temp = head;
				head = head->next;
				delete temp->next;
				delete temp;
		}
}

void print_menu(int &n)
{
		cout << "Pick which categorie you want to look into:" << endl;
		cout << "1. Registering" << endl;
		cout << "2. Buying materials" << endl;
		cout << "3. Completing homework" << endl;
		cout << "4. exit." << endl;
		cout << "Enter your choice: ";
		cin >> n;
		cin.ignore(SIZE, '\n');
		return;
}

void print_choice()
{
		cout << "Choose: " << endl;
		cout << "1. Display all hint" << endl;
		cout << "2. Add a new hint" << endl;
		cout << "3. Like a hint." << endl;
		cout << "4. Go back to chosing categories" << endl;
		cout << "Please enter your choice: ";
}

void menu_switch(int n, bool &x, LLL &l_r, LLL &l_b, LLL &l_c)
{
		int choice;
		bool repeat = true;
		switch(n)
		{
				case 1:
						cout << "You've chose [Registering]" << endl;
						while(repeat)
						{
								print_choice();
								cin >> choice;
								cin.clear();
								cin.ignore();
								if(choice == 1)
										l_r.display_order();
								else if(choice == 2)
										l_r.add_back();
								else if(choice == 3)
										l_r.display_like();
								else if(choice == 4)
										repeat = false;
								else
										cout << "Invalid choice." << endl;
						}

						break;
				case 2:
						cout << "You've chose [Buying materials]" << endl;
						while(repeat)
						{
								print_choice();
								cin >> choice;
								cin.clear();
								cin.ignore();
								if(choice == 1)
										l_b.display_order();
								else if(choice == 2)
										l_b.add_back();
								else if(choice == 3)
										l_b.display_like();
								else if(choice == 4)
										repeat = false;
								else
										cout << "Invalid choice." << endl;
						}
						break;
				case 3:
						cout << "You've chose [Completing homewor]" << endl;
						while(repeat)
						{
								print_choice();
								cin >> choice;
								cin.clear();
								cin.ignore();
								if(choice == 1)
										l_c.display_order();
								else if(choice == 2)
										l_c.add_back();
								else if(choice == 3)
										l_c.display_like();
								else if(choice == 4)
										repeat = false;
								else
										cout << "Invalid choice." << endl;
						}
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

void LLL::display_order()
{
		node *current;
		current = head;
		int max = 0;
		if(!head)
				cout << "The list is empty." << endl;
		else
		{
				current = head;
				while(current)
				{
						if(max < current->likes)
								max = current->likes;
						current = current->next;
				}
		}
		for(int i = 0; i <= max; i += 1)
		{
				current = head;
				while(current)
				{
						if(current->likes == max - i)
						{
								cout << "--------------------" << endl;
								cout << "Index: " << current->index << endl;
								cout << "Likes: " << current->likes << endl;
								cout << current->hint << endl;
								cout << "--------------------" << endl;
						}
						current = current->next;
					
				}
		}


}

void LLL::display_like()
{
		node *current = NULL;
		int count = 0;
		if(!head)
				cout << "The list is empty." << endl;
		else
		{
				current = head;
				while(current)
				{
						
						cout << "--------------------" << endl;
						cout << "Index: " << current->index << endl;
						cout << "Likes: " << current->likes << endl;
						cout << current->hint << endl;
						cout << "--------------------" << endl;
						count += 1;
						current = current->next;
				}
				like(count);
		}
}

void LLL::like(int max)
{
		int hint_to_like;
		node *current;
		bool repeat;

		while(repeat)
		{
				cout << "Please enter the index for the hint you want to like: ";
				cin >> hint_to_like;
				cin.clear();
				cin.ignore();
				if(hint_to_like > max)
						cout << "Out of range, hint does not exist." << endl;
				else
				{
						current = head;
						while(current->index != hint_to_like and current->next)
						{
								current = current->next;
						}
						if(current->index == hint_to_like)
						{
								current->likes += 1;
								repeat = false;
						}
						else
						{
								cout << "Hint not found." << endl;
								repeat = false;
						}
						
				}


		}


}

void LLL::add_back()
{
		int i = 1;
		node *temp, *current;
		if(!head)
		{
				head = new node;
				get_hint(head);
				head->index = i;
				head->next = NULL;
		}
		else
		{
				temp = new node;
				get_hint(temp);
				i += 1;
				current = head;
				while(current->next)
				{
						current = current->next;
						i += 1;
				}
				current->next = temp;
				temp->index = i;
				temp->next = NULL;
		}
}


void LLL::get_hint(node *temp)
{
		char buffer[500];

		cout << "Enter your hint: " << endl;
		cin.get(buffer, 500, '\n');
		cin.ignore(100, '\n');
		temp->hint = new char[strlen(buffer) + 1];
		strcpy(temp->hint, buffer);
		cout << endl;
}


