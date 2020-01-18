#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include "music_search.h"


const int SIZE = 500;


using namespace std;

int main(void)
{
		BST my_bst;
		tree_node *test;
		int menu_choice;
		bool menu_repeat = true;


		cout << "Welcome!" << endl;
		cout << "This is a music search system." << endl;


		while(menu_repeat)
		{
				cout << "\n\n";
				cout << "1. Add new song" << endl;
				cout << "2. Search for a song" << endl;
				cout << "3. Display all songs" << endl;
				cout << "4. Remove songs" << endl;
				cout << "5. Load file" << endl;
				cout << "6. Exit" << endl;
				cout << "Please enter your choice: ";
				cin >> menu_choice;
				cin.clear();
				cin.ignore();
				switch(menu_choice)
				{
						case 1:
								cout << "Adding new song" << endl;
								do
								{
										my_bst.insert_bst(get_tree_node());
								}while(again());

								break;

						case 2:
								do
								{
										my_bst.retrieve(get_search());
								}while(again());
								break;

						case 3:
								my_bst.display_all();
								break;

						case 4:
								do
								{
										my_bst.remove(get_delete());
								}while(again());
								break;

						case 5:
								do
								{
										ifstream fin;
										tree_node *to_add = new tree_node;
										char filename[SIZE];
										char buffer[SIZE];

										cout << "Enter the name of the songs database file: ";
										cin.get(filename, SIZE, '\n');
										cin.clear();
										cin.ignore();
										fin.open(filename);

										if (!fin)
										{
												cout << "File not found!" << endl;
										}

										while (!fin.eof())
										{
												fin.get(buffer, SIZE, '\n');
												to_add->song_title = new char[strlen(buffer) + 1];
												strcpy(to_add->song_title, buffer);
												fin.ignore();

												to_add->key = toupper(buffer[0]);

												fin.get(buffer, SIZE, '\n');
												to_add->artist = new char[strlen(buffer) + 1];
												strcpy(to_add->artist, buffer);
												fin.ignore();

												fin.get(buffer, SIZE, '\n');
												to_add->album_name = new char[strlen(buffer) + 1];
												strcpy(to_add->album_name, buffer);
												fin.ignore();

												fin >> to_add->length;
												fin.ignore(SIZE, '\n');

												my_bst.insert_bst(to_add);

										}
										fin.close();
								}while(again());
								break;

						case 6:
								cout << "Bye~" << endl;
								menu_repeat = false;
								break;

						default:
								cout << "Invalid choice." << endl;
								break;


				}
		}







		return 0;
}
