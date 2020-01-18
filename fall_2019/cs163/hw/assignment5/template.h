#ifndef template_h
#define template_h

using namespace std;


template <typename T>
struct node
{
		T data;
		node * next;
};



template <typename T>
class Account
{
		public:
				Account(T t);
				void display();
				Account(const Account &o);
				Account<T> & operator = (const Account<T> & o);
				Account<T> operator+(T add);
				void operator+=(T add);
				template <typename Type>
				friend ostream & operator << (ostream & os, const Account<Type> output);

				void push(T to_add);
				void push_end(T to_add);

		private:
				node<T> * head;
				T balance;

};






#include "template.cpp"

#endif


