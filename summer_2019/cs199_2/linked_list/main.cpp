#include "list.h"

int main(void)
{
		linked_list l;
		for (int i = 1; i < 11; ++i)
		{
				l.add_back(i);
		}


		l.insert_sort(0);
		l.insert_sort(20);

		l.remove(4);
		l.remove(90);

		l.display();
		l.display_last();
		l.display_odd();

		return 0;
}

