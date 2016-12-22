#ifndef STACK
#define STACK

#include <iostream>
#include "LinkedList.h"

template <class T>
class Stack :public LinkedList<T> {
public:
	Stack() {}
	Stack(T data);
	void push(T data);
	T peek();
	void pop();
	bool empty();
};

#endif // !STACK

template<class T>
Stack<T>::Stack(T data) {
	push(data);
}
template<class T>
void Stack<T>::push(T data) {
	addFront(data);
}
template<class T>
T Stack<T>::peek() {
	if (empty())
		return NULL;
	else {
		return this->Head->Data;
	}
}
template<class T>
void Stack<T>::pop() {
	if (empty())
		std::cout << "The stack is empty!" << std::endl;
	else {
		Node<T>* delPtr = Head;
		Head = Head->Next;
		delete delPtr;
	}
}
template <class T>
bool Stack<T>::empty() {
	if (Head == NULL)
		return true;
	else return false;
}