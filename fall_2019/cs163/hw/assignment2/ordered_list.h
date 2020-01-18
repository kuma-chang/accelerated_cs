#ifndef ordered_list_h
#define ordered_list_h

class Ordered_list 
{
		public:
				Ordered_list(int size = 10);
				~Ordered_list();
				int display() const;
				int insert(int position, const char *product_info); 
				int remove(int position);

		private:
				int size_of_list;
				char **list;

};



#endif
