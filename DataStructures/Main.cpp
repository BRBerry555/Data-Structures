#include <iostream>
#include "LinkedList.h"
//#include "DoublyLinkedList.h"

int main() {
	LinkedList<std::string> testList("9");

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
	std::cin.get();
	return 0;
}