#include <iostream>
#include <stdlib.h>
#include "stack.h"
using namespace std;

struct Node {
    int data;
    Node *next;
};

void createStack(void){
    Node *stack = NULL;
    return;
}

void addStack(Node *&stack, int n){
    Node *new_node = new Node();
    new_node -> data = n;
    new_node -> next = stack;
    stack = new_node;

    cout << "\n " << n << " added to the stack" << endl;
}

void deleteStack(Node *&stack, int &n){
    Node *aux = stack;
    n = aux -> data;
    stack = aux -> next;
    delete aux;
}

void menu(void){
    cout << "---stack methods, what do u want to do?---" << endl;
    cout << "[1] Create stack" << endl;
    cout << "[2] Add an element to the stack" << endl;
    cout << "[3] Delete an element from the stack" << endl;
    cout << "[99] Exit" << endl; 
    return;
}