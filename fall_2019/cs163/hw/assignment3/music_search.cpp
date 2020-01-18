#include <iostream>
#include <cstring>
#include "music_search.h"

using namespace std;

const int SIZE = 500;

bool again()
{
		char again;
		cout << "again? y/n: ";
		cin >> again;
		cin.clear();
		cin.ignore(SIZE, '\n');
		if(tolower(again) == 'y')
				return true;
		else
				return false;
}

tree_node * get_tree_node()
{
		char buffer[SIZE];
		int key_value;
		tree_node *to_add = new tree_node;

		cout << "Please enter the song title: ";
		cin.get(buffer, SIZE, '\n');
		cin.clear();
		cin.ignore(SIZE, '\n');
		to_add->song_title = new char[strlen(buffer) + 1];
		strcpy(to_add->song_title, buffer);

		to_add->key = toupper(buffer[0]);
		
		cout << "Please enter the artist: ";
		cin.get(buffer, SIZE, '\n');
		cin.clear();
		cin.ignore(SIZE, '\n');
		to_add->artist = new char[strlen(buffer) + 1];
		strcpy(to_add->artist, buffer);

		cout << "Please enter the album name: ";
		cin.get(buffer, SIZE, '\n');
		cin.clear();
		cin.ignore(SIZE, '\n');
		to_add->album_name = new char[strlen(buffer) + 1];
		strcpy(to_add->album_name, buffer);

		cout << "Please enter the length(in min): ";
		cin >> to_add->length;
		cin.clear();
		cin.ignore();

		return to_add;
}


tree_node * get_search()
{
		char buffer[SIZE];
		int key_value;
		tree_node *to_add = new tree_node;

		cout << "Please enter the song title you want to search: ";
		cin.get(buffer, SIZE, '\n');
		cin.ignore();
		to_add->song_title = new char[strlen(buffer) + 1];
		strcpy(to_add->song_title, buffer);

		to_add->key = toupper(buffer[0]);

}

tree_node * get_delete()
{
		char buffer[SIZE];
		int key_value;
		tree_node *to_add = new tree_node;

		cout << "Please enter the song title you want to delete: ";
		cin.get(buffer, SIZE, '\n');
		cin.ignore();
		to_add->song_title = new char[strlen(buffer) + 1];
		strcpy(to_add->song_title, buffer);

		to_add->key = toupper(buffer[0]);

}






