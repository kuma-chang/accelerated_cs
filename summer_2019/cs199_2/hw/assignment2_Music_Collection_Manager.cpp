/* ************************************************************
 * Michael Chang
 * Program Number: cs199_assignment2_Music_collection_Manager
 * This is a music collection database program
 * ***********************************************************/
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

const int SIZE = 100;

struct song
{
	char name[SIZE];
	char singer[SIZE];
	char country[SIZE];
	int year;
};

// Function Protypes
int menu_print(void);
int load(song s[], char filename[]);
int search(song s[], int length);
void save(song s[], int length, char filename[]);
void add_song (song &s);
void print_song(song &s);

int main(void)
{
		song songs[SIZE];
		char filename[SIZE] = {};
		char load_flag;
		int menu_choice;
		int num_songs = 0;
		int search_result = 0;
		bool repeat = true;
		bool file_open_flag = true;


		cout << "Would you like to load an existing music collection(Y/N): ";
		cin >> load_flag;
		cin.ignore();
		if(toupper(load_flag) == 'Y')
		{
				while (file_open_flag)
				{
						num_songs = load(songs, filename);
						if (num_songs == -1)
						{
								cout << "Unable to load file. Try again? (Y/N): ";
								cin >> load_flag;
								cin.ignore();
								if (toupper(load_flag) == 'N')
								{
										num_songs = 0;
										file_open_flag = false;
								}
								else
								{
										num_songs = load(songs, filename);
								}
						}
						else
						{
								cout << "File loaded!" << endl;
								file_open_flag = false;
						}
				}
		
		}


		while (repeat)
		{
				menu_choice = menu_print();
				switch (menu_choice)
				{
						// Add a new song
						case 1:
								add_song(songs[num_songs++]);
								break;
						// Edit a song
						case 2:
								for ( int i=0; i < num_songs; ++i )
										print_song(songs[i]);
								break;
						// Search for a song
						case 3:
								search_result = search(songs,num_songs);
								if (search_result == -1)
										cout << "Song not found!" << endl;
								else
										print_song(songs[search_result]);
								break;
						// Quit
						case 4:
								save(songs, num_songs, filename);
								break;
						case 5:
								repeat = false;
								break;						
						default:
								cout << "Invalid choice." << endl;
								break;
				}
		}



		return 0;
}

// Print out the menu for user to choose
int menu_print(void)
{
		int n;

		cout << "1. Add a new song." << endl;
		cout << "2. Display all songs." << endl;
		cout << "3. Search for a song." << endl;
		cout << "4. Save." << endl;
		cout << "5. Quit." << endl;
		cout << "Enter an option: ";
		cin >> n;
		cin.clear();
		cin.ignore();
		return n;
}

void print_song(song &s)
{
		cout << "------------------------------------------" << endl;
		cout << "Name: " << s.name << endl;
		cout << "Singer: " << s.singer << endl;
		cout << "Country: " << s.country << endl;
		cout << "Year: " << s.year << endl;
		cout << "------------------------------------------" << endl;
}

void add_song (song &s)
{
		cout << "What is the song's name: ";
		cin.get(s.name, SIZE, '\n');
		cin.ignore();
		
		cout << "Enter the singer: ";
		cin.get(s.singer, SIZE, '\n');
		cin.ignore();

		cout << "Enter the country the song was from: ";
		cin.get(s.country, SIZE, '\n');
		cin.ignore();

		cout << "What year was the song published: ";
		cin >> s.year;
		cin.clear();
		cin.ignore();
}

int load(song s[], char filename[])
{
		int i = 0; // tracks the number of songs
		ifstream fin;

		cout << "Enter the name of the songs database file: ";
		cin.get(filename, SIZE, '\n');
		cin.ignore();
		fin.open(filename);

		if (!fin)
		{
				cout << "File not found!" << endl;
				return -1;
		}

		fin.get(s[i].name, SIZE, '\n');
		fin.ignore();
		while (!fin.eof())
		{
				fin.get(s[i].singer, SIZE, '\n');
				fin.ignore();
				fin.get(s[i].country, SIZE, '\t');
				fin.ignore();
				fin >> s[i].year;
				fin.ignore(SIZE, '\n');
				++i;
				fin.get(s[i].name, SIZE, '\n');
				fin.ignore();
		}
		fin.close();
		return i;
}

int search(song s[], int length)
{
		int index = -1;
		char name[SIZE];

		cout << "Enter the song's name you want to search: ";
		cin.get(name, SIZE, '\n');
		cin.ignore();
		
		for(int i = 0; i < length; ++i)
		{
				if (strcmp(name, s[i].name) == 0)
						index = i;
		}
		return index;
}

void save(song s[], int length, char filename[])
{
		ofstream fout;

		if(strcmp(filename, "") == 0)
		{
				cout << "Enter a file to save your music: ";
				cin >> filename;
				cin.ignore();
		}
		fout.open(filename);
		if (!fout)
		{
				cout << "Error opening file!" << endl;
				return;
		}
		
		for (int i = 0; i < length; ++i)
		{
				fout << s[i].name << '\n';
				fout << s[i].singer << '\n';
				fout << s[i].country << '\t'
					 << s[i].year << '\n';
		}
		fout.close();
		cout << "File: " << filename << " have been saved." << endl;
		return;
}


