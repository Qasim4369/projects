#include <iostream>
#include "Header.h"
using namespace std;

Queue::Queue(int capacity)
{
	if (capacity <= 0) capacity = 50;
	data = new int[capacity];
	size = 0;
	this->capacity = capacity;
}

Queue::~Queue()
{
	delete[] data;
}

void Queue::enqueue(int newElement)
{
	if (size < capacity)
		data[size++] = newElement;
}

int Queue::dequeue()
{
	return data[--size];
}

int Queue::top()
{
	return data[size - 1];
}

bool Queue::isEmpty()
{
	return size == 0;
}

bool Queue::isFull()
{
	return size == capacity;
}

void Queue::print()
{
	for (int i = size - 1; i >= 0; --i)
		std::cout << data[i] << std::endl;
}

int Queue::getCapacity()
{
	return capacity;
}

void Queue::display()
{
	for (int i = 0; i < size; i++)
	{
		cout << char(data[i]);
	}
}

int* Queue::getArr()
{
	return data;
}

int Queue::getsize()
{
	return size;
}