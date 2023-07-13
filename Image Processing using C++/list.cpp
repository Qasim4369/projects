#include <iostream>
#include "list.h"
using namespace std;

List::List() {
	head = nullptr;
	current = nullptr;
	lastCurrent = nullptr;
	// lastNode = nullptr;
	size = 0;
}


List::~List() {
	Node* temp = head;
	while (temp != nullptr) {
		head = head->getNext();
		delete temp;
		temp = head;
		size = 0;
	}
}

Node* List::getCurrent() {
	return current;
}


void List::add(int data) {
	Node* newNode = new Node(data);

	if (current != nullptr) {
		newNode->setNext(current->getNext());
		current->setNext(newNode);
		lastCurrent = current;
		current = newNode;
		size++;
	}
	else {
		newNode->setNext(nullptr);
		head = newNode;
		lastCurrent = head;
		current = head;
		size++;
	}
}

void List :: size() {
	cout<< size;
}


bool List::find(int data) {
	Node* iterator = head;
	lastCurrent = nullptr;
	current = head;
	while (iterator != nullptr) {
		if (iterator->getData() == data) {
			lastCurrent = current;
			current = iterator;
			return true;
		}
		iterator = iterator->getNext();
		lastCurrent = current;
		current = iterator;
	}
	return false;
}

void List::displayList() {
	Node* iterator = head;
	//int i = 0 ;
	while (iterator != nullptr) {
		//System.out.printf("|%d:%d|",++i,iterator.getData());
		std::cout << "|" << iterator->getData() << "|";
		iterator = iterator->getNext();
		if (iterator != nullptr)
			std::cout << " -> ";
	}
	std::cout << std::endl;
}

