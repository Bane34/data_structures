#include <iostream>
#include <stdlib.h>
#include "stack.h"
using namespace std;

struct NodeStack {
    int data;
    NodeStack *next;
};

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
    cout << "\n---Stack methods, what do u want to do?---" << endl;
    cout << "[1] Add an element to the stack" << endl;
    cout << "[2] Delete an element from the stack" << endl;
    cout << "[99] Exit" << endl; 
}

void mainStack(void){
    cout << "Creating stack data structure" << endl;
    NodeStack *stack = NULL;
    cout << "Stack created succesfully!\n" << endl;

    int res, number;

    while(true){
        menuStack();
        cout << "Option: ";
        cin >> res;
        switch (res){
            case 1:
                cout << "What number do you want to insert: ";
                cin >> number;
                addStack(stack, number);
                system("cls");
                break;
            case 2:
                cout << "Removing elements from the stack" << endl;
                while (stack != NULL){
                    removeStack(stack, number);

                    if(stack != NULL){
                        cout << number << ", ";
                    }
                    else{
                        cout << number << '.' << endl;
                    }
                }
                return;
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