#ifndef stack_h
#define stack_h

#include "queue.h"


class Stack
{
		public:
				Stack();
				~Stack();

				void push(car_node *&reject_node);
				void display()const;
				void display_last()const;

		private:
				car_node *head;



};



















#endif
