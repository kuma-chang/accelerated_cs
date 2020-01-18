#include <iostream>
#include "rational_number.h"
#include "template.h"

using namespace std;

int main(void)
{
		Account<int> my_int_account(80);

		for(int i = 0; i < 7; ++i)
		{
				my_int_account += 1;
		}
		my_int_account.display();
		

		Account<int> my_int_account_assignment_test(8);
		cout << "COPY!!!" << endl;
		Account<int> my_int_account_copy_test = my_int_account;
		my_int_account_copy_test.display();



		cout << "ASSIGN!!!" << endl;
		my_int_account_assignment_test = my_int_account;
		my_int_account_assignment_test.display();



		/*
		Rational_num a;
		Rational_num b(4,5);

		cout << "a: " << endl;
		a.display();
		cout << "b: " << endl;
		b.display();

		cout << "a is " ;
		a.display_num();
		cout << "b is " ;
		b.display_num();
		cout << endl;

		cout << "*****equal*****" << endl;
		Rational_num x(3,5);
		cout << "x is " ;
		x.display_num();
		a = x;
		cout << "a = x, now a is " ;
		a.display_num();
		cout << "b is " ;
		b.display_num();
		cout << endl;

		cout << "*****add*****" << endl;
		Rational_num c = a + b;
		cout << "a + b is " ;
		c.display_num();
		cout << endl;

		cout << "*****minus*****" << endl;
		Rational_num d = a - b;
		cout << "a - b is " ;
		d.display_num();
		cout << endl;

		cout << "*****time*****" << endl;
		Rational_num e = a * b;
		cout << "a * b is " ;
		e.display_num();
		cout << endl;

		cout << "*****divide*****" << endl;
		Rational_num f = a / b;
		cout << "a / b is " ;
		f.display_num();
		cout << endl;

		cout << "*****plus_equal*****" << endl;
		a += b;
		cout << "a += b, now a is " ;
		a.display_num();
		cout << endl;

		cout << "*****minus_equal*****" << endl;
		a -= b;
		cout << "a -= b, now a is " ;
		a.display_num();
		cout << endl;

		cout << "*****display*****" << endl;

		cout << "cout << a is " ;
		cout << a << endl;
		cout << "cout << b is " ;
		cout << b << endl;
		*/

		Rational_num a(3,5);
		Rational_num b(4,5);
		Rational_num c(0,5);

		c = 2 * (a+=b);

		cout << c << endl;


		return 0;
}
