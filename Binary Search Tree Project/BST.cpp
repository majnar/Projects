#include "BST.h"
BST::BST()
{
	tree = NULL;
	id = 0;
}
void BST::destroyTree(BST* tree)
{
	if (tree != NULL)
	{
		destroyTree(tree->left);
		destroyTree(tree->right);
		delete tree;
	}
}
BST::~BST()
{
	destroyTree(tree);
}
void BST::insert(BST*& tree, int id)
{
	if (tree == NULL)
	{
		tree = new BST;
		tree->right = NULL;
		tree->left = NULL;
		tree->id = id;
	}
	else if (id < tree->id)
	{
		insert(tree->left, id);
	}
	else
	{
		insert(tree->right, id);
	}
}
void BST::searchToDelete(BST*& tree, int id)
{
	if (id < tree->id)
	{
		searchToDelete(tree->left, id);
	}
	else if (id > tree->id)
	{
		searchToDelete(tree->right, id);
	}
	else
	{
		deleteNode(tree);
	}
}
void BST::deleteNode(BST*& tree)
{
	int id;
	BST* temp;
	temp = tree;
	if (tree->left == NULL)
	{
		tree = tree->right;
		delete temp;
	}
	else if (tree->right == NULL)
	{
		tree = tree->left;
		delete temp;
	}
	else
	{
		getPredecessor(tree->left, id);
		tree->id = id;
		deleteNode(tree->left);
	}
}
void BST::getPredecessor(BST*& tree, int& id)
{
	while (tree->right != NULL)
	{
		tree = tree->right;
	}
	id = tree->id;
}
void BST::retrieveItem(int& id)
{
	retrieve(tree, id);
}
void BST::retrieve(BST* tree, int& id)
{
	if (tree == NULL)
	{
		cout << "" << id << " is not in the tree.\n\n";
	}
	else if (id < tree->id)
	{
		retrieve(tree->left, id);
	}
	else if (id > tree->id)
	{
		retrieve(tree->right, id);
	}
	else
	{
		cout << "" << id << " is in the tree.\n\n";
	}
}
void BST::printInOrder(BST* tree)
{
	if (tree != NULL)
	{
		printInOrder(tree->left);
		cout << tree->id << " --> ";
		printInOrder(tree->right);
	}
}
void BST::printPreOrder(BST* tree)
{
	if (tree)
	{
		cout << tree->tree << " ";
		printPreOrder(tree->left);
		printPreOrder(tree->right);
	}
}