#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST

#include <iostream>
template<class T>
struct Node {
	T Data;
	//Linked section
	Node *Next;
	Node *Prev;
};

template <class T>
class DoublyLinkedList :public Node<T> {
private:
	Node *Head;
	void insert(T Data, Node<T> *ptr);
public:
	DoublyLinkedList() :Head(NULL) {}
	DoublyLinkedList(T Data);
	void addEnd(T Data);
};


#endif // !DOUBLYLINKEDLIST

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(T data) {
	Head = new Node<T>;
	Head->Data = data;
	Head->Next = NULL;
	Head->Prev = NULL;
}
template <class T>
DoublyLinkedList<T>::addEnd(T data) {
	if (Head == NULL) {
		Head = new Node<T>;
		Head->Data = data;
		Head->Next = NULL;
		Head->Prev = NULL;
	}
	Node<T> *p = Head;
	while (p->Next != NULL)
		p = p->Next;

}
//Private functions
template <class T>
DoublyLinkedList<T>::insert(T data, Node<T> ptr) {
	Node *n = new Node;
	n->Data = data;
	n->Next = ptr->Next;
}
