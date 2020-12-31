#pragma once

struct NodeTree;
NodeTree *createNode(NodeTree *, int);
NodeTree *minimun(NodeTree *);

void addTree(NodeTree *&, NodeTree *, int);
void destroyNode(NodeTree *);
void replace(NodeTree *, NodeTree *);
void removeTree(NodeTree *, int);
void removeNode(NodeTree *);
void showTree(NodeTree *, int);
bool searchTree(NodeTree *, int);
void preOrder(NodeTree *);
void inOrder(NodeTree *);

void menuTree(void);
void mainTree(void);

