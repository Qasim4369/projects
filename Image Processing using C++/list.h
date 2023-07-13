#pragma once
#include "node.h"

class List
{
private:
	Node* head;
	Node* current;
	Node* lastCurrent;
public:
	List();
	~List();
	Node* getCurrent();
	//void setCurrent(Node* newCurrent);
	void add(int data);
	bool find(int data);
	void IsEmpty();
	void size();
	void replace();
	void duplicate();
	void displayList();
	

};
#pragma once
