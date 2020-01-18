#include <iostream>
#include <cstring>
#include "rational_number.h"

using namespace std;



Rational_num::Rational_num()
{
		p = 0;
		q = 0;
}

Rational_num::Rational_num(float x, float y)
{
		p = x;
		q = y;
}

void Rational_num::display()
{
		cout << "p = " << p << " ";
		cout << "q = " << q << endl;
}

void Rational_num::display_num()
{
		cout << p/q << endl;
}

void Rational_num::operator=(Rational_num o)
{
		p = o.p;
		q = o.q;
}

Rational_num Rational_num::operator+(Rational_num add)
{
		Rational_num summ;
		summ.p = (p*add.q) + (add.p*q);
		summ.q = q*add.q;
		return summ;
}

Rational_num Rational_num::operator-(Rational_num minus)
{
		Rational_num summ;
		summ.p = (p*minus.q) - (minus.p*q);
		summ.q = q*minus.q;
		return summ;
}

Rational_num Rational_num::operator*(Rational_num time)
{
		Rational_num product;
		product.p = p*time.p;
		product.q = q*time.q;
		return product;
}

Rational_num Rational_num::operator/(Rational_num divide)
{
		Rational_num quotient;
		quotient.p = p/divide.p;
		quotient.q = q/divide.q;
		return quotient;
}

void Rational_num::operator+=(Rational_num add)
{
		p = (p*add.q) + (add.p*q);
		q = q*add.q;
}

void Rational_num::operator-=(Rational_num minus)
{
		p = (p*minus.q) - (minus.p*q);
		q = q*minus.q;
}

ostream & operator << (ostream & os, const Rational_num output)
{
		os << output.p/output.q ;
		return os;
}
