#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST

#include <iostream>
#include "Node.h"

template <class T>
class DoublyLinkedList :public Node<T> {
private:
	Node *Head;
	Node *Tail;
public:
	DoublyLinkedList() :Head(NULL),Tail(NULL) {}
	DoublyLinkedList(T Data);
	void addEnd(T Data);
	void addFront(T Data);
	void deleteNode(T search);
	void insertAfter(T search, T Data);
	void insertBefore(T search, T Data);
	void printListReverse();
	void printList();
	int size();
	void printTail();
};


#endif // !DOUBLYLINKEDLIST

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(T data) {
	Head = new Node<T>;
	Head->Data = data;
	Head->Next = NULL;
	Head->Prev = NULL;
	Tail = Head;
}
template <class T>
void DoublyLinkedList<T>::addEnd(T data) {
	if (Head == NULL) {
		Head = new Node<T>;
		Head->Data = data;
		Head->Next = NULL;
		Head->Prev = NULL;
	} else {
		Node<T> *p = Head;
		while (p->Next != NULL)
			p = p->Next;
		Node<T> *n = new Node;
		n->Data = data;
		n->Next = NULL;
		p->Next = n;
		n->Prev = p;
		Tail = n;
	}
}
template<class T>
void DoublyLinkedList<T>::addFront(T data) {
	if (Head == NULL) {
		Head = new Node<T>;
		Head->Data = data;
		Head->Next = NULL;
		Head->Prev = NULL;
	}
	else {
		Node<T> *p = Head;
		Node<T> *n = new Node<T>;
		n->Data = data;
		n->Next = Head;
		n->Prev = NULL;
		p->Prev = n;
	}
}
template <class T>
void DoublyLinkedList<T>::deleteNode(T search) {
	Node<T> *p = Head;
	if (Tail->Data == search) {
		Node<T> *delPtr = Tail;
		Node<T> *prev = Tail->Prev;
		prev->Next = NULL;
		Tail = prev;

		delete delPtr;
	} else {
		while ((p->Next->Data != search) && (p->Next != NULL))
			p = p->Next;
		//*tmp is the Node after the one being deleted
		Node<T> *tmp = p->Next->Next;
		Node<T> *delPtr = p->Next;
		p->Next = tmp;
		tmp->Prev = p;
		delete delPtr;
	}
}
template <class T>
void DoublyLinkedList<T>::insertAfter(T search, T data) {
	Node<T> *p = Head;
	while ((p->Next->Data != search) && (p->Next != NULL))
		p = p->Next;
	Node<T> *tmp = p->Next;
	Node<T> *n = new Node;
	n->Data = data;
	n->Next = tmp;
	p->Next = n;
	n->Prev = p;
	tmp->Prev = n;

}
template <class T>
void DoublyLinkedList<T>::insertBefore(T search, T data) {

}
template <class T>
void DoublyLinkedList<T>::printList() {
	Node<T> *p = Head;
	while (p != NULL) {
		std::cout << p->Data.c_str() << std::endl;
		p = p->Next;
	}
}
template <class T>
void DoublyLinkedList<T>::printListReverse() {
	Node<T> *p = Head;
	while (p->Next != NULL)
		p = p->Next;
	while (p != NULL) {
		std::cout << p->Data.c_str() << std::endl;
		p = p->Prev;
	}
}
template <class T>
int DoublyLinkedList<T>::size() {
	int size = 0;
	Node<T> *p = Head;
	while (p != NULL) {
		size++;
		p = p->Next;
	}
	return size;
}
template <class T>
void DoublyLinkedList<T>::printTail() {
	std::cout << Tail->Data.c_str() << std::endl;
}