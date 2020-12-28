#pragma once

struct NodeTree;
NodeTree *createNode(int);
NodeTree *tree = NULL;

void addTree(NodeTree *&, int);
void showTree(NodeTree *, int);

void menuTree(void);
void mainTree(void);

