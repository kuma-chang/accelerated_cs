#ifndef bst_h
#define bst_h

struct tree_node
{
		tree_node *left_children;
		tree_node *right_children;
		tree_node *parent;
		int key;
		char *song_title, *artist, *album_name;
		float length;
		int num_re;
		tree_node();
};

class BST
{
		public:
				BST();
				//~BST();
				void insert_bst(tree_node *to_add); //The wrapper function for inserting
				void display_all(); //The wrapper function for displaay all
				void display_node(tree_node *current); 
				int retrieve(tree_node *to_search); //The wrapper function for retrieve
				int remove(tree_node *to_delete);


		private:
				tree_node *root;

				void insert_bst_r(tree_node *&current, tree_node *to_add); //The recursive function for inserting
				void display_all_r(tree_node *current); //The recursive function for display all
				int retrieve_r(tree_node *&current, tree_node *to_search); //The recursive function for retrieve
				int remove_r(tree_node *&current, tree_node *to_delete);
				void delete_tree_node(tree_node *to_delete);
				void copy_tree_node(tree_node *copy_to, tree_node *copy_from);
				struct tree_node* find_successor(tree_node *current);
};







#endif
