#include <iostream>
#include <cstring>
#include "bst.h"

using namespace std;


BST::BST()
{
		root = NULL;
}

tree_node::tree_node()
{
		left_children = NULL;
		right_children = NULL;
		parent = NULL;
		key = 0;
		song_title = NULL;
		artist = NULL;
		album_name = NULL;
		length = 0;
		num_re = 0;
}

void BST::insert_bst_r(tree_node *&current, tree_node *to_add)
{
		if(!current)
		{
				current = new tree_node;
				copy_tree_node(current, to_add);
		}
		else if(current->key > to_add->key)
		{
				insert_bst_r(current->left_children, to_add);
				current->left_children->parent = current;
		}
		else
		{
				insert_bst_r(current->right_children, to_add);
				current->right_children->parent = current;
		}
}

void BST::insert_bst(tree_node *to_add)
{
		insert_bst_r(root, to_add);
}

void BST::display_node(tree_node *current)
{
		cout << "________________________" << endl;
		cout << "Key: " << current->key << endl;
		if(current->parent)
				cout << "Parent: " << current->parent->key << endl;
		else
				cout << "ROOT" << endl;
		cout << "Song: " << current->song_title << endl;
		cout << "Artist: " << current->artist << endl;
		cout << "Album name: " << current->album_name << endl;
		cout << "Length: " << current->length << endl;
		cout << "________________________" << endl;
		cout << endl;
}

void BST::display_all_r(tree_node *current)
{
		if(current)
		{
				display_all_r(current->left_children);
				display_node(current);
				display_all_r(current->right_children);
		}
}

void BST::display_all()
{
		display_all_r(root);
}

int BST::retrieve_r(tree_node *&current, tree_node *to_search)
{
		if(!current)
				return 0;
		else if(current->key == to_search->key)
		{
				display_node(current);
				return 1 + retrieve_r(current->right_children, to_search);
		}
		else if(current->key > to_search->key)
				return retrieve_r(current->left_children, to_search);
		else
				return retrieve_r(current->right_children, to_search);
}

int BST::retrieve(tree_node *to_search)
{
		return retrieve_r(root, to_search);
}

int BST::remove_r(tree_node *&current, tree_node *to_delete)
{
		if(!current)
				return 0;
		else if(current->key > to_delete->key)
				return remove_r(current->left_children, to_delete);
		else if(current->key < to_delete->key)
				return remove_r(current->right_children, to_delete);
		else // There is a match
		{
				tree_node *temp;
				if(!current->left_children) // Current's left is empty
				{
						temp = current;
						if(current->right_children)
								current->right_children->parent = current->parent;
						if(current->parent->key > current->key) // Current is on it's parrent's left
								current->parent->left_children = current->right_children;
						else								 // Current is on it's parrent's right
								current->parent->right_children = current->right_children;
						remove_r(current, to_delete);
						delete_tree_node(temp);
				}
				else if(!current->right_children) // Current's right is empty
				{
						temp = current;
						if(current->left_children)
								current->left_children->parent = current->parent;
						if(current->parent->key > current->key) // Current is on it's parrent's left
								current->parent->left_children = current->left_children;
						else							 	 // Current is on it's parrent's right	
								current->parent->right_children = current->left_children;
						remove_r(current, to_delete);
						delete_tree_node(temp);
				}
				else   // Current's both side have children 
				{
						temp = find_successor(current);
						copy_tree_node(current, temp);
						remove_r(temp, temp);
				}
				return 1;
		}
}

void BST::delete_tree_node(tree_node *to_delete)
{
		delete to_delete;
}

void BST::copy_tree_node(tree_node *copy_to, tree_node *copy_from)
{
		copy_to->key = copy_from->key;

		copy_to->song_title = new char[strlen(copy_from->song_title) + 1];
		strcpy(copy_to->song_title, copy_from->song_title);

		copy_to->artist = new char[strlen(copy_from->artist) + 1];
		strcpy(copy_to->artist, copy_from->artist);

		copy_to->album_name = new char[strlen(copy_from->album_name) + 1];
		strcpy(copy_to->album_name, copy_from->album_name);

		copy_to->length = copy_from->length;
}

struct tree_node* BST::find_successor(tree_node *current)
{
		current = current->right_children;
		while(current->left_children)
				current = current->left_children;
		return current;
}

int BST::remove(tree_node *to_delete)
{
		return remove_r(root, to_delete);
}









