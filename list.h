#pragma once

struct NodeList;

void addList(NodeList *&, int);
void showList(NodeList *);
void searchList(NodeList *, int);
void removeList(NodeList *&, int);

void menuList(void);
void mainList(void);