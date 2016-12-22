#ifndef NODE
#define NODE

#include <iostream>

template <class T>
struct Node {
	T Data;
	Node *Next;
	Node *Prev = NULL;
};

#endif
