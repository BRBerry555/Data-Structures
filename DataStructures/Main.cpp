#include <iostream>
#include "DoublyLinkedList.h"
#include "Stack.h"

void linkedListTest();
void doublyLinkedListTest();
void stackTest();

int main() {
	stackTest();

	std::cin.get();
	return 0;
}
void linkedListTest() {
	//Actually testing linkedlist class
	Stack<std::string> testList("9");

	testList.addFront("A");
	testList.addFront("B");
	testList.addFront("C");
	testList.addFront("D");
	testList.addFront("E");
	testList.addFront("F");
	testList.printList();
	std::cout << testList.size() << std::endl;
	testList.insertBefore("D", "bar");
	testList.printList();
	std::cout << "Size: " << testList.size() << std::endl;
}
void doublyLinkedListTest() {
	DoublyLinkedList<std::string> testList;

	testList.addEnd("A");
	testList.addEnd("B");
	testList.addEnd("C");
	testList.addEnd("D");
	testList.addEnd("E");
	testList.addEnd("F");
	testList.printList();
	testList.deleteNode("F");
	testList.insertAfter("B", "insert test");
	std::cout << "*---------*" << std::endl;
	testList.printList();
	std::cout << "*---------*" << std::endl;
	testList.printListReverse();
	std::cout << "Size: " << testList.size() << std::endl;
	
}
void stackTest() {
	Stack<int> testStack;
	testStack.push(1);
	testStack.push(2);
	std::cout << testStack.peek() << std::endl;
	testStack.pop();
	std::cout << testStack.peek() << std::endl;
	testStack.pop();
	testStack.pop();
}