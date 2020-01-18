#include <iostream>
#include "purchase.h"
#include "ordered_list.h"
#include "queue.h"
#include "stack.h"

using namespace std;

int main(void)
{
		char char_test[SIZE];
		int menu_choice;
		int sub_menu_choice;
		bool menu_repeat = true;
		bool sub_menu_repeat;
		
		Ordered_list wanted_features;
		Queue car_list;
		Stack reject_list;

		cout << "Welcome!" << endl;
		cout << "This is a program aim to help you find the best car suitable for you." << endl;
		
		while(menu_repeat)
		{
				cout << "\n\n";
				cout << "1. Add/edit [Wanted features]" << endl;
				cout << "2. Add/edit [Available car list]" << endl;
				cout << "3. Look through and compare available cars" << endl;
				cout << "4. Exit" << endl;
				cout << "Please enter your choice: ";
				cin >> menu_choice;
				cin.clear();
				cin.ignore();
				switch(menu_choice)
				{
						case 1:
								sub_menu_repeat = true;
								while(sub_menu_repeat)
								{
										cout << "\n\n[Wanted features]" << endl;
										cout << "1. Add wanted features" << endl;
										cout << "2. Remove wanted features" << endl;
										cout << "3. Display wanted features list" << endl;
										cout << "4. Back" << endl;
										cout << "Please enter your choice: ";
										cin >> sub_menu_choice;
										cin.clear();
										cin.ignore();
										switch(sub_menu_choice)
										{
												case 1:
														add_feature_to_wanted_list(wanted_features);
														break;
												case 2:
														remove_feature_from_the_wanted_list(wanted_features);
														break;
												case 3:
														ol_display(wanted_features);
														break;
												case 4:
														sub_menu_repeat = false;
														break;
												default:
														cout << "Invalid choice." << endl;
														break;
										}


								}
								break;
						case 2:
								sub_menu_repeat = true;
								while(sub_menu_repeat)
								{
										cout << "\n\n[Available car list]" << endl;
										cout << "1. Add new car" << endl;
										cout << "2. Display car list" << endl;
										cout << "3. Back" << endl;
										cout << "Please enter your choice: ";
										cin >> sub_menu_choice;
										cin.clear();
										cin.ignore();
										switch(sub_menu_choice)
										{
												case 1:
														add_new_car(car_list);
														break;
												case 2:
														car_list.display();
														break;
												case 3:
														sub_menu_repeat = false;
														break;
												default:
														cout << "Invalid choice." << endl;
														break;
										}

								}
								break;
						case 3:
								sub_menu_repeat = true;
								while(sub_menu_repeat)
								{
										cout << "\n\n[Compare car]" << endl;
										cout << "1. Compare next car in queu" << endl;
										cout << "2. Display last car got rejected" << endl;
										cout << "3. Display rejected car list" << endl;
										cout << "4. Back" << endl;
										cout << "Please enter your choice: ";
										cin >> sub_menu_choice;
										cin.clear();
										cin.ignore();
										switch(sub_menu_choice)
										{
												case 1:
														compare(wanted_features, car_list, reject_list);
														break;
												case 2:
														reject_list.display_last();
														break;
												case 3:
														reject_list.display();
														break;
												case 4:
														sub_menu_repeat = false;
														break;
												default:
														cout << "Invalid choice." << endl;
														break;
										}

								}
								break;
						case 4:
								cout << "Bye~" << endl;
								menu_repeat = false;
								break;
						default:
								cout << "Invalid choice." << endl;
									
				}
		}
		return 0;
}
