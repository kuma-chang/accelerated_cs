#include <iostream>
#include <cstring>

using namespace std;



template <typename T>
Account<T>::Account(T t)
{
		balance = t;
		head = NULL;
		push(t);
}

template <typename T>
Account<T>::Account(const Account &o)
{
		cout << "Copy constructor called" << endl;
		balance = o.balance;
		head = NULL;
		node<T> * current = o.head; 
		while(current)
		{
				push_end(current->data);
				current = current->next;
		}
}


template <typename T>
void Account<T>::display()
{
		cout << "Balance history: " ;
		node<T> * current = head; 
		while(current)
		{
				cout << current->data << " ";
				current = current->next;
		}
		cout << endl;
}

template <typename T>
Account<T> & Account<T>::operator = (const Account<T> & o)
{
		cout << "Assignment constructor called" << endl;
		balance = o.balance;
		head = NULL;
		node<T> * current = o.head; 
		while(current)
		{
				push_end(current->data);
				current = current->next;
		}
		return * this;
}

template <typename T>
Account<T> Account<T>::operator+(T add)
{
		Account<T> summ(balance + add);
		return summ;
}

template <typename T>
void Account<T>::operator+=(T add)
{
		balance = balance + add;
		push(balance);
}

template <typename T>
ostream & operator << (ostream & os, const Account<T> output)
{

		os << output.balance;
		return os;
}

template <typename T>
void Account<T>::push(T to_add)
{
		node<T> * temp;
		temp = new node<T>;
		temp->data = to_add;
		temp->next = head;
		head = temp;
}

template <typename T>
void Account<T>::push_end(T to_add)
{
		if(!head)
		{
				head = new node<T>;
				head->data = to_add;
				head->next = NULL;
		}
		else
		{
				node<T> * temp = head;
				while(temp->next)
						temp = temp->next;
				temp->next = new node<T>;
				temp->next->data = to_add;
				temp->next->next = NULL;
		}


}
				
