#include <iostream>
#include <stdlib.h>
//#include "stack.h"
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
    pila = aux -> next;
    delete aux;
}