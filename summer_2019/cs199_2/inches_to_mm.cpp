/ Convert inches to mm

#include <iostream>
using namespace std;

const double INCH_TO_MM= 25.4;

int main(void)
{
		double inch, millimeter;
		cout << "Enter the number of inches: ";
		cin >> inch;
		millimeter = inch * INCH_TO_MM;
		cout << inch << " inches is " 
				<< millimeter << " millimeters." 
				<< endl;

		return 0;
}


