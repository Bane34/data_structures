#include <iostream>
#include <stdlib.h>
#include "trees.h"
using namespace std;

struct NodeTree {
	int data;
	NodeTree* left;
	NodeTree* right;
};

void menuTree(void) {
	system("cls");
	cout << "\n---Tree methods, what do u want to do?" << endl;
	cout << "[1] Insert an element to the tree" << endl;
	cout << "[2] Remove an element from the tree" << endl;
	cout << "[99] Exit" << endl;
}

void mainTree(void) {
	cout << "Creating a tree" << endl;
	NodeTree* tree;
	cout << "Tree created succesfully!" << endl;

	int res, number;

	switch (res) {
		case 99:
			exit(0);
		default:
			cout << "Select a valid option" << endl;
			continue;
	}
}