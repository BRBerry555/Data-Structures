#ifndef LINKEDLIST
#define LINKEDLIST

#include<iostream>
#include "Node.h"

template <class T>
class LinkedList :public Node<T> {
protected:
	Node *Head;
private:
	void insert(T Data, Node<T> *ptr);
public:
	LinkedList() :Head(NULL) {}
	LinkedList(T Data);
	void addEnd(T Data);
	void addFront(T Data);
	void deleteNode(T search);
	void insertAfter(T search, T Data);
	void insertBefore(T search, T Data);
	void printList();
	int size();
};
#endif // !LINKEDLIST

template <class T>
LinkedList<T>::LinkedList(T data) {
	this->Head = new Node<T>();
	Head->Data = data;
	Head->Next = NULL;
}
template <class T>
void LinkedList<T>::addEnd(T data) {
	if (Head == NULL) {
		//Add new node to head
		Head = new Node<T>();
		Head->Data = data;
		//Since this is the first node
		//next is NULL
		Head->Next = NULL;
	} else {

		//Set a pointer equal to the head
		Node<T> *p = Head;

		//Traverse to the end of the list
		while (p->Next != NULL)
			p = p->Next;

		insert(data, p);
	}
}
template <class T>
void LinkedList<T>::addFront(T data) {
	if (Head == NULL) {
		Head = new Node<T>();
		Head->Data = data;
		Head->Next = NULL;
	} else {
		Node<T> *n = new Node<T>;
		n->Data = data;
		n->Next = Head;
		Head = n;
	}
}
template <class T>
void LinkedList<T>::deleteNode(T search) {
	Node<T> *p = Head;
	while ((p->Next->Data != search) && (p->Next != NULL))
		p = p->Next;
	//Set pointer equal to what p Next is pointing at
	Node<T> *delPtr = p->Next;
	//Assign p Next to the Node after the one being deleted
	p->Next = p->Next->Next;

	delete delPtr;
}
template <class T>
void LinkedList<T>::insertAfter(T search, T data) {
	Node<T> *p = Head;
	while ((p->Data != search) && (p->Next != NULL))
		p = p->Next;
	insert(data, p);
}
template <class T>
void LinkedList<T>::insertBefore(T search, T data) {
	Node<T> *p = Head;
	while ((p->Next->Data != search) && (p->Next != NULL)) {
		p = p->Next;
	}
	insert(data, p);
}
template <class T>
void LinkedList<T>::printList() {
	Node<T> *p = Head;
	while (p != NULL) {
		std::cout << p->Data.c_str() << std::endl;
		p = p->Next;
	}
}
template <class T>
int LinkedList<T>::size() {
	int size = 0;
	Node<T> *p = Head;
	while (p != NULL) {
		size++;
		p = p->Next;
	}
	return size;
}
//Private Functions
template <class T>
void LinkedList<T>::insert(T data, Node<T> *ptr) {
	Node<T> *n = new Node<T>;
	n->Data = data;
	n->Next = ptr->Next;
	ptr->Next = n;
}

