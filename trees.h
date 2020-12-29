#pragma once

struct NodeTree;
NodeTree *createNode(int);

void addTree(NodeTree *&, int);
void removeTree(NodeTree *&, int);
void showTree(NodeTree *, int);
bool searchTree(NodeTree *, int);
void preOrder(NodeTree *);
void inOrder(NodeTree *);

void menuTree(void);
void mainTree(void);

