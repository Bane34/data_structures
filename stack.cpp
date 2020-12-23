#include <iostream>
#include <stdlib.h>
#include "stack.h"
using namespace std;

struct Node {
    int data;
    Node *next;
};

void addStack(Node *&stack, int n){
    Node *new_node = new Node();
    new_node -> data = n;
    new_node -> next = stack;
    stack = new_node;

    cout << "\n " << n << " added to the stack" << endl;
}