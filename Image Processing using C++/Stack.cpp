#include <iostream>
#include "Header.h"
using namespace std;

StackWithArray::StackWithArray(int capacity) {
	if (capacity <= 0) capacity = 50;
	data = new int[capacity];
	size = 0;
	this->capacity = capacity;
}

StackWithArray::~StackWithArray() {
	delete[] data;
}

void StackWithArray::push(int newElement) {
	if (size < capacity)
		data[size++] = newElement;
}

int StackWithArray::pop() {
	return data[--size];
}

int StackWithArray::top() {
	return data[size - 1];
}

bool StackWithArray::isEmpty() {
	return size == 0;
}

bool StackWithArray::isFull() {
	return size == capacity;
}

void StackWithArray::print() {
	for (int i = size - 1; i >= 0; --i)
		std::cout << data[i] << std::endl;
}

int StackWithArray::getCapacity() {
	return capacity;
}
void StackWithArray::display() {
	for (int i = 0; i < size; i++) {
		cout << char(data[i]);
	}
}
int* StackWithArray::getArr() {
	return data;
}

int StackWithArray::getsize() {
	return size;
}