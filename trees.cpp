#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "trees.h"
using namespace std;

/*
* Note: this code is for a search binary tree (ABB)
* This means that the values higher than the root value will be at the right 
* And the values lower than the root value will be at the left				 
*/

struct NodeTree {
	int data;
	NodeTree* right;
	NodeTree* left;
};

NodeTree *createNode(int n){
	NodeTree *new_node = new NodeTree();

	new_node -> data = n;
	new_node -> right = NULL;
	new_node -> left = NULL;

	return new_node;
}

void addTree(NodeTree *&tree, int n){
	if(tree == NULL){
		NodeTree *new_node = createNode(n);
		tree = new_node;
	}
	else{
		int rootValue = tree -> data;
		if(n < rootValue)
			addTree(tree -> left, n);
		else
			addTree(tree -> right, n);
	}
}

void showTree(NodeTree *tree, int counter){
	if (tree == NULL)
		return;
	else{
		showTree(tree -> right, counter + 1);
		for(int i = 0; i < counter; i++)
			cout << "   ";
		
		cout << tree -> data << endl;
		showTree(tree -> left, counter + 1);
 	}
}

bool searchTree(NodeTree *tree, int n){
	if (tree == NULL)
		return false;
	else if (tree -> data == n)
		return true;
	else if (n < tree -> data)
		return searchTree(tree -> left, n);
	else
		return searchTree(tree -> right, n);
}

void menuTree(void) {
	system("cls");
	cout << "\n---Tree methods, what do u want to do?" << endl;
	cout << "[1] Insert an element to the tree" << endl;
	cout << "[2] Remove an element from the tree" << endl;
	cout << "[3] Show the tree" << endl;
	cout << "[4] Find an element in the tree" << endl;
	cout << "[99] Exit" << endl;
}

void mainTree(void) {
	NodeTree *tree = NULL;

	int res, number, count = 0;

	while (true){
		menuTree();
		cout << "Option: ";
		cin >> res;
		
		switch (res) {
			case 1:
				cout << "What value do u want to insert: ";
				cin >> number;
				addTree(tree, number);
				cout << number << " added to the tree" << endl;
				getch();
				break;
			case 2:
				break;
			case 3:
				showTree(tree, count);
				getch();
				break;
			case 4:
				cout << "What number do u want to search: ";
				cin >> number;
				if (searchTree(tree, number))
					cout << number << " found in the tree" << endl;
				else
					cout << number << " not found in the tree" << endl;
				getch();
				break;
			case 99:
				exit(0);
				break;
			default:
				cout << "Select a valid option" << endl;
				continue;
		}
	}
}