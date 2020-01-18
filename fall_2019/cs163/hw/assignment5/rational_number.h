#ifndef rational_number_h
#define rational_number_h

using namespace std;

class Rational_num
{
		public:
				Rational_num();
				Rational_num(float x, float y); //p = x, q = y
				void display();
				void display_num();
				Rational_num operator+(Rational_num add);
				Rational_num operator-(Rational_num minus);
				void operator=(Rational_num o);
				Rational_num operator*(Rational_num time);
				Rational_num operator/(Rational_num divide);
				void operator+=(Rational_num add);
				void operator-=(Rational_num minus);
				friend ostream & operator << (ostream & os, const Rational_num output);


		private:
				float p; //Numerator
				float q; //Denominator

};

#endif

