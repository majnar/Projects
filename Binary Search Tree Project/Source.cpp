#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
	BST bst;
	BST* root = NULL;
	// ---- insert ----------------------------
	cout << "Insert numbers\n";
	bst.insert(root, 7);
	bst.insert(root, 5);
	bst.insert(root, 9);
	bst.insert(root, 8);
	bst.insert(root, 2);
	bst.insert(root, 3);
	// ---- print -----------------------------
	bst.printInOrder(root);
	cout << "\n\nDelete 8\n";
	bst.searchToDelete(root, 8);
	bst.printInOrder(root);
	// ---- retrieve --------------------------
	int id = 4;
	cout << "\n\nRetrieve 4\n";
	bst.retrieve(root, id);
	// ----------------------------------------
	cout << endl << endl;
	return 0;
}