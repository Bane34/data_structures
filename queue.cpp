#include <iostream>
#include <stdlib.h>
#include "queue.h"
using namespace std;

struct NodeQueue{
    int data;
    NodeQueue *next;
};

void addQueue(NodeQueue *&top, NodeQueue *&end, int n){
    NodeQueue *new_node = new NodeQueue();
    new_node -> data = n;
    new_node -> next = NULL;

    if(emptyQueue(top))
        top = new_node;
    else
        end -> next = new_node;

    end = new_node;
}

void removeQueue(NodeQueue *&top, NodeQueue *&end, int &n){
    n = top -> data;
    NodeQueue *aux = top;
    
    if(top == end){
        top = NULL;
        end = NULL;
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
    cout << "[1] Add an element to the queue" << endl;
    cout << "[2] Delete an element from the queue" << endl;
    cout << "[99] Exit" << endl; 
}

void mainQueue(void){
    cout << "Creating a queue data structure" << endl;
    NodeQueue *top = NULL;
    NodeQueue *end = NULL;
    cout << "Queue created succesfully!\n" << endl;
    
    int res, number;

    while(true){
        menuQueue();
        cout << "Option: ";
        cin >> res;
        switch (res){
            case 1:
                cout << "What number do you want to insert: ";
                cin >> number;
                addQueue(top, end, res);
                cout << "Number: " << number << " added to the queue";
                break;
            case 2:
                cout << "What number do you want to remove: ";
                cin >> number;
                removeQueue(top, end, res);
                cout << "Number: " << number << " added to the queue";
                break;
            default:
                cout << "Introduce a valid option" << endl;
                continue;
        }
    }
}