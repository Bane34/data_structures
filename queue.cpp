#include <iostream>
#include <stdlib.h>
#include "queue.h"
using namespace std;

struct NodeQueue{
    int data;
    NodeQueue *next;
};

void createQueue(void){
    NodeQueue *top = NULL;
    NodeQueue *end = NULL;
    return;
}

void addQueue(NodeQueue *&top, NodeQueue *&end, int n){
    NodeQueue *new_node = new NodeQueue();
    new_node -> data = n;
    new_node -> next = NULL;

    if(emptyQueue(top))
        frente = new_node;
    else
        end -> next = new_node;

    end = new_node;
}

void removeQueue(NodeQueue *&top, NodeQueue *&end, int &n){
    n = top -> data;
    NodeQueue *aux = top;
    
    if(top == end){
        top = NULL;
        end == NULL;
    }
    else
        top = top -> next;

    delete aux;
}

bool emptyQueue(NodeQueue *top){
    return(top == NULL)? true:false;
}

void menuQueue(void){
    cout << "---stack methods, what do u want to do?---" << endl;
    cout << "[1] Add an element to the stack" << endl;
    cout << "[2] Delete an element from the stack" << endl;
    cout << "[99] Exit" << endl; 
}

void mainQueue(void){
    cout << "Creating a queue data structure" << endl;
    createQueue();
    cout << "Queue created succesfully!\n" << endl;
    menuQueue();

}