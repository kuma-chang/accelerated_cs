#ifndef queue_h
#define queue_h

struct car_node
{
		char *brand;
		char *model;
		char **feature_list;
		car_node *next;
};

class Queue
{
		public:
				Queue();
				~Queue();
				
				void enqueue(car_node *node_to_add); 
				void dequeue(car_node *&reject_node);
				void display()const;
				void display_next()const;


		private:
				car_node *tail;
};

#endif

