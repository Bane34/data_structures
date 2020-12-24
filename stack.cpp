#include <iostream>
#include <stdlib.h>
#include "stack.h"
using namespace std;

struct NodeStack {
    int data;
    NodeStack *next;
};

void createStack(void){
    NodeStack *stack = NULL;
    return
}

void addStack(NodeStack *&stack, int n){
    NodeStack *new_node = new NodeStack();
    new_node -> data = n;
    new_node -> next = stack;
    stack = new_node;

    cout << "\n " << n << " added to the stack" << endl;
}

void removeStack(NodeStack *&stack, int &n){
    NodeStack *aux = stack;
    n = aux -> data;
    stack = aux -> next;
    delete aux;
}

void menuStack(void){
    cout << "---stack methods, what do u want to do?---" << endl;
    cout << "[1] Create stack" << endl;
    cout << "[2] Add an element to the stack" << endl;
    cout << "[3] Delete an element from the stack" << endl;
    cout << "[99] Exit" << endl; 
    return;
}