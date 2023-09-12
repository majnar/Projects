#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class BST
{
private:
	int id;
	BST* left;
	BST* right;
	BST* tree;
public:
	BST();
	~BST();
	void destroyTree(BST* tree);
	void insert(BST*& tree, int id);
	void searchToDelete(BST*& tree, int id);
	void deleteNode(BST*& tree);
	void getPredecessor(BST*& tree, int& id);
	void retrieveItem(int& id);
	void retrieve(BST* tree, int& id);
	void printInOrder(BST* tree);
	void printPreOrder(BST* tree);
	void printPostOrder(BST* tree);
};