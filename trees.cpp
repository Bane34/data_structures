#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "trees.h"
using namespace std;

/*
* Disclaimer: this code is for a search binary tree (ABB)
* This means that the values higher than the root value will be at the right 
* And the values lower than the root value will be at the left
*
* Note: to remove a node in the binary tree you need to do a lot of shit
* I recomend you to investigate how to do it because if I try to explain it
* I will fuck up
*/

struct NodeTree {
	int data;
	NodeTree* right;
	NodeTree* left;
	NodeTree* father;
};

NodeTree *createNode(NodeTree *father, int n){
	NodeTree *new_node = new NodeTree();

	new_node -> data = n;
	new_node -> right = NULL;
	new_node -> left = NULL;
	new_node -> father = father;

	return new_node;
}

NodeTree *minimun(NodeTree* tree) {
	if (tree == NULL)
		return NULL;
	if (tree -> right)
		return minimun(tree -> right);
	else
		return tree;
}

void addTree(NodeTree *&tree, NodeTree *father, int n){
	if(tree == NULL){
		NodeTree *new_node = createNode(father, n);
		tree = new_node;
	}
	else{
		int rootValue = tree -> data;
		if(n < rootValue)
			addTree(tree -> left, tree, n);
		else
			addTree(tree -> right, tree, n);
	}
}

void destroyNode(NodeTree *node) {
	node -> left = NULL;
	node -> right = NULL;

	delete node;
}

void replace(NodeTree *tree, NodeTree *newNode) {
	if (tree -> father) {
		if (tree -> data == tree -> father -> left -> data) {
			tree -> father -> left = newNode;
		}
		else if (tree ->data == tree-> father -> right -> data) {
			tree -> father -> right = newNode;
		}
	}
	if (newNode) {
		newNode -> father = tree -> father;
	}
}

void removeTree(NodeTree *tree, int n){
	//with this function we search the node with the element in the tree
	if (tree == NULL)
		return;
	else if (n < tree -> data)
		removeTree(tree -> left, n);
	else if (n > tree -> data)
		removeTree(tree -> right, n);
	else
		removeNode(tree);
}

void removeNode(NodeTree *removedNode) {
	//With this function we remove the node previously found by the removeTree function
	if (removedNode -> left && removedNode -> right) {
		NodeTree *min = minimun(removedNode -> right);
		removedNode -> data = min -> data;
		removeNode(min);
	}
	else if (removedNode -> left) {
		replace(removedNode, removedNode -> left);
		destroyNode(removedNode);
	}
	else if (removedNode -> right) {
		replace(removedNode, removedNode -> right);
		destroyNode(removedNode);
	}
	else { //If the node isnt a father node, we just replace the node by NULL
		replace(removedNode, NULL);
		destroyNode(removedNode);
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

void preOrder(NodeTree *tree){
	//First we start in the root node, then we go to the left, and eventually, the right
	if(tree == NULL)
		return;
	else{
		cout << tree -> data << " - ";
		preOrder(tree -> left);
		preOrder(tree -> right);
	}
}

void inOrder(NodeTree *tree){
	//First we start at the left, then we continue to the root node, and finally we display the right nodes
	if(tree == NULL)
		return;
	else{
		inOrder(tree -> left);
		cout << tree -> data << " - ";
		inOrder(tree -> right);
	}
}

void menuTree(void) {
	system("cls");
	cout << "\n---Tree methods, what do u want to do?" << endl;
	cout << "[1] Insert an element to the tree" << endl;
	cout << "[2] Remove an element from the tree" << endl;
	cout << "[3] Show the tree" << endl;
	cout << "[4] Find an element in the tree" << endl;
	cout << "[5] Go trhough the tree in pre order" << endl;
	cout << "[6] Go trhough the tree in order" << endl;
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
				addTree(tree, NULL, number);
				cout << number << " added to the tree" << endl;
				getch();
				break;
			case 2:
				cout << "What number do u want to remove";
				cin >> number;
				if (searchTree(tree, number))
					removeTree(tree, number);
				else
					cout << n << " not found in the tree" << endl;
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
			case 5:
				cout << "\nPath preOrder:" << endl;
				preOrder(tree);
				getch();
				break;
			case 6:
				cout << "\nPath inOrder" << endl;
				inOrder(tree);
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