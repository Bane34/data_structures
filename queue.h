#pragma once

struct NodeQueue;

void addQueue(NodeQueue *&, NodeQueue *&, int);
void removeQueue(NodeQueue *&, NodeQueue *&, int &);

bool emptyQueue(NodeQueue *);
void menuQueue(void);