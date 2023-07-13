#include<iostream>
#pragma once
using namespace std;
class Image {
	unsigned char* data;
	unsigned char type;
	int height;
	int width;
	int channels;
	int img;

	Image(const char* filename);
	~Image();      
	bool read(const char* filename);
	bool write(const char* filename, int img);
	int GetPixel();
	void SetPixel(int col, int row, int n);
	int Getsize();
	void ConvertToNegative();
};
class Queue
{
private:
	int* data;
	int capacity;
	int size;

public:
	Queue(int capacity);
	~Queue();
	void enqueue(int);
	int dequeue();
	int top();
	bool isEmpty();
	bool isFull();
	int getCapacity();
	void display();
	void print();
	int* getArr();
	int getsize();
};
class StackWithArray {
private:
	int* data;
	int capacity;
	int size;
public:
	StackWithArray(int capacity);
	~StackWithArray();
	void push(int);
	int pop();
	int top();
	bool isEmpty();
	bool isFull();
	void print();
	int getCapacity();
	void display();
	int* getArr();
	int getsize();
};

