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

    cout << '\n' << n << " added to the queue" << endl;
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
    system("cls");
    cout << "---Queue methods, what do u want to do?---" << endl;
    cout << "[1] Add an element to the queue" << endl;
    cout << "[2] Delete the elements from the queue" << endl;
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
                break;
            case 2:
                cout << "Removing elements from the queue" << endl;
                while(top != NULL){
                    removeQueue(top, end, number);

                    if(top != NULL){
                        cout << number << ", ";
                    }
                    else{
                        cout << number << '.' << endl;
                    }
                }
                break;
            case 99:
                exit(0);
                break;
            default:
                cout << "Introduce a valid option" << endl;
                continue;
        }
    }
}