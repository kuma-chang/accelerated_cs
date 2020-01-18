#include <iostream>
#include <cstring>
#include "ordered_list.h"

using namespace std;


void ol_test()
{
		cout << "OL Test worked!" << endl;
}

Ordered_list::Ordered_list(int size)
{
		size_of_list = size;
		list = new char *[size_of_list];
		for(int i =0; i < size_of_list; i++)
		{
				list[i] = NULL;
		}
}

Ordered_list::~Ordered_list()
{
		for(int i = 0; i < size_of_list; i++)
				delete [] list[i];
		delete [] list;
}

int Ordered_list::display() const
{
		bool all_null = true;
		for(int i=0; i < size_of_list; i++)
		{
				if(list[i] != NULL)
				{
						cout << "Wanted feature: #" << i+1 << " " << list[i] << endl;
						all_null = false;
				}
		}
		if(all_null)
		{
				return 0;
		}
		return 1;
}
int Ordered_list::insert(int position, const char *product_info)
{
		if(position > size_of_list)
				return 0;
		if(list[position - 1] != NULL)
				delete [] list[position - 1];
		list[position - 1] = new char[sizeof(product_info)];
		strcpy(list[position - 1], product_info);
		return 1;
}

int Ordered_list::remove(int position)
{
		if(position > size_of_list || list[position - 1] == NULL)
				return 0;
		delete [] list[position - 1];
		list[position - 1] = NULL;
		return 1;
}



