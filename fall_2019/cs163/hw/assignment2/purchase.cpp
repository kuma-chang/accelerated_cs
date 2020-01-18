#include <iostream>
#include <cstring>
#include "purchase.h"

using namespace std;


void ol_display(Ordered_list &ol)
{
		int ol_empty_check;
		cout << "\n\n[Feature List]" << endl;
		ol_empty_check = ol.display();
		if(ol_empty_check == 0)
				cout << "The list is EMPTY!" << endl;
		return;
}

int feature_list(char *product_info)
{
		int feature_choice;
		cout << "\n\n";
		cout << "1. Remote Keyless Entry" << endl;
		cout << "2. Anti-Lock Brakes(ABS)" << endl;
		cout << "3. Electronic Stability System" << endl;
		cout << "4. Adjustable Pedals" << endl;
		cout << "5. Rear-Seat DVD Player" << endl;
		cout << "6. GPS" << endl;
		cout << "7. Side Airbags" << endl;
		cout << "8. Center Console With a Power Outlet" << endl;
		cout << "9. Roadside Assistance" << endl;
		cout << "10. 4-Wheel Drive" << endl;
		cout << "Please enter the feature you want to add: ";
		cin >> feature_choice;
		cin.clear();
		cin.ignore();
		switch(feature_choice)
		{
				case 1:
						strcpy(product_info, "Remote Keyless Entry");
						break;
				case 2:
						strcpy(product_info, "Anti-Lock Brakes(ABS)");
						break;
				case 3:
						strcpy(product_info, "Electronic Stability System");
						break;
				case 4:
						strcpy(product_info, "Adjustable Pedals");
						break;
				case 5:
						strcpy(product_info, "Rear-Seat DVD Player");
						break;
				case 6:
						strcpy(product_info, "GPS");
						break;
				case 7:
						strcpy(product_info, "Side Airbags");
						break;
				case 8:
						strcpy(product_info, "Center Console With a Power Outlet");
						break;
				case 9:
						strcpy(product_info, "Roadside Assistance");
						break;
				case 10:
						strcpy(product_info, "4-Wheel Drive");
						break;
				default:
						cout << "Invalid choice." <<endl;
						break;
		}
		return feature_choice;
}

bool again()
{
		char again;
		cout << "Again? y/n: ";
		cin >> again;
		if(tolower(again) == 'y')
				return true;
		else
				return false;
}

void add_feature_to_wanted_list(Ordered_list &wanted_features)
{
		int position; 
		char feature_to_add[SIZE];
		do
		{
				position = feature_list(feature_to_add);
				wanted_features.insert(position, feature_to_add);
		}while(again());

}

void remove_feature_from_the_wanted_list(Ordered_list &wanted_features)
{
		int position;
		do
		{
				cout << "Please enter the features' number you want to remove: ";
				cin >> position;
				cin.clear();
				cin.ignore();
				wanted_features.remove(position);
		}while(again());
}

void get_car_node(car_node *node_to_add)
{
		char buffer[SIZE];
		int position;
		char feature_to_add[SIZE];

		cout << endl;
		cout << "Enter brand: ";
		cin.get(buffer, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		node_to_add->brand = new char[sizeof(buffer)];
		strcpy(node_to_add->brand, buffer);

		cout << "Enter model: ";
		cin.get(buffer, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		node_to_add->model = new char[sizeof(buffer)];
		strcpy(node_to_add->model, buffer);

		node_to_add->feature_list = new char *[10];
		for(int i = 0; i < 10; ++i)
				node_to_add->feature_list[i] = NULL;

		do
		{
				position = feature_list(feature_to_add);
				node_to_add->feature_list[position - 1] = new char[sizeof(feature_to_add)];
				strcpy(node_to_add->feature_list[position - 1], feature_to_add);
		}while(again());
		node_to_add->next = NULL;
}

void add_new_car(Queue &car_list)
{
		car_node *node_to_add = new car_node;
		get_car_node(node_to_add);
		car_list.enqueue(node_to_add);
}

void push_to_reject(Queue &car_list, Stack &reject_list)
{
		car_node *reject_node;
		car_list.dequeue(reject_node);
		reject_list.push(reject_node);
}

void compare(Ordered_list &wanted_features, Queue &car_list, Stack &reject_list)
{
		char reject;
		ol_display(wanted_features);
		car_list.display_next();

		cout << "Reject? y/n: ";
		cin >> reject;
		if(tolower(reject) == 'y')
				push_to_reject(car_list, reject_list);
}
