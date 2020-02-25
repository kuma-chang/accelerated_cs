#include <iostream>

int* f(int* x, int y)
{
	*x = y;
	std::cout << "x is now: " << *x << '\n';
	return x;
}

void l_or_r_f(int* i, int* j)
{
	int a = *i + *j;

	std::cout << "a(x + x) is now: " << a << '\n';
	if(a == 4)
	{
		std::cout << "left-to-right" << '\n';
	}
	else if (a == 2)
		std::cout << "right-to-left" << '\n';
}

void l_or_r(int i, int j)
{
	int x = 0;
	int * ptr = &x;
	l_or_r_f(f(ptr, i), f(ptr, j));
	return;
}

int main ()
{
	l_or_r(1, 2);
	return 0;
}
