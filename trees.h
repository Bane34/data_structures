#pragma once

struct NodeTree;
NodeTree *createNode(int);

void addTree(NodeTree *&, int);
void showTree(NodeTree *, int);

void menuTree(void);
void mainTree(void);

