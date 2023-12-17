#pragma once
#include <iostream>
template<typename T>
struct node {
public:
	T item;
	node<T>* next;
};

template<typename T>
class Stack
{
protected:
	node<T>* head;
public:
	Stack();                   
	Stack(const Stack&);
	~Stack();
	void push(T);
	T pop();
	int size();
	bool isEmpty();
	void delStack();
	T pop_bottom();
	Stack<T>& operator=(const Stack<T>&);
	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, const Stack<T>&);
};


#include "Stack.inl"                       