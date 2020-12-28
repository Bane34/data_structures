#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "trees.h"
using namespace std;

/*
* Note: this code is for a search binary tree (ABB)
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
	
}

void menuTree(void) {
	system("cls");
	cout << "\n---Tree methods, what do u want to do?" << endl;
	cout << "[1] Insert an element to the tree" << endl;
	cout << "[2] Remove an element from the tree" << endl;
	cout << "[99] Exit" << endl;
}

void mainTree(void) {
	int res, number;

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
			case 99:
				exit(0);
				break;
			default:
				cout << "Select a valid option" << endl;
				continue;
		}
	}
}