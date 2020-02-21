#include <iostream>

int f(int x)
{
	std::cout << x << '\n';
	return x;
}

void l_or_r(int i, int j)
{
	std::cout << i + j << '\n';
}



int main ()
{

	l_or_r(f(1), f(2));

	return 0;
}
