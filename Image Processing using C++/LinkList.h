#pragma once
#pragma once
#include<iostream>
#include<conio.h>

using namespace std;
template <class T>
class node
{
public:
	T data;
	node* next;

	node()
	{
		data = 0;
		next = NULL;
	}

	node(T d, node* n)
	{
		n->data = d;
	}

	node(T d)
	{
		data = d;
	}


};

template <class T>
class SLinkedList {

public:

	node<T>* head;
	SLinkedList()
	{
		head = NULL;
	}

	void insert(T val)
	{

		node<T>* new_node = new node<T>(val);
		new_node->next = NULL;

		if (head == NULL)
		{
			head = new node<T>(val);
			head->next = NULL;

		}
		else
		{
			node<T>* current_node = head;

			while (current_node->next != NULL)
			{
				current_node = current_node->next;
			}
			current_node->next = new_node;

		}
	}
	void display()
	{
		node<T>* current_node = head;

		while (current_node->next != NULL)
		{
			cout << current_node->data << " ";

			if (current_node->data == -1)
			{
				cout << endl;
			}
			current_node = current_node->next;
		}
	}
};
