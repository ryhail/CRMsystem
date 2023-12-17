#include "Stack.h"

template<typename T>
Stack<T>::Stack()
{
	head = nullptr;
}

template<typename T>
Stack<T>::Stack(const Stack& st) {
	node<T>* ptr = st.head;
	node<T>* bufPtr;
	node<T>* copyPtr;
	while (ptr != nullptr) {
		bufPtr = new node<T>;

		bufPtr->item = ptr->item;
		bufPtr->next = nullptr;

		if (head == nullptr) {
			head = bufPtr;
			copyPtr = bufPtr;
		}
		else {
			copyPtr->next = bufPtr;
			copyPtr = copyPtr->next;
		}

		ptr = ptr->next;
	}
}

template<typename T>
inline Stack<T>::~Stack()
{
	delStack();
}

template<typename T>
void Stack<T>::push(T val)
{
	node<T>* buf;
	buf = new node<T>;
	buf->item = val;
	buf->next = head;
	head = buf;
}

template<typename T>
T Stack<T>::pop()
{
	T value = head->item;
	node<T>* buf = head;
	head = head->next;
	delete buf;
	return value;
}

template<typename T>
int Stack<T>::size()
{
	int size = 0;
	node<T>* ptr = head;
	while (ptr != nullptr) {
		size++;
		ptr = ptr->next;
	}
	return size++;
}

template<typename T>
bool Stack<T>::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

template<typename T>
void Stack<T>::delStack()
{
	node<T>* ptr = head;
	node<T>* buf = nullptr;

	while (ptr != nullptr) {
		buf = ptr;
		ptr = ptr->next;
		delete buf;
	}

	head = nullptr;
}

template<typename T>
inline T Stack<T>::pop_bottom()
{
	node<T>* ptr = head;
	T buf;
	while (ptr->next != nullptr) {
		ptr = ptr->next;
	}
	buf = ptr->next->item;
	delete[] ptr->next;
	return buf;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& st)
{
	if (head != nullptr)
		delStack();

	node<T>* ptr = st.head;
	node<T>* bufPtr;
	node<T>* copyPtr;
	while (ptr != nullptr) {
		bufPtr = new node<T>;

		bufPtr->item = ptr->item;
		bufPtr->next = nullptr;

		if (head == nullptr) {
			head = bufPtr;
			copyPtr = bufPtr;
		}
		else {
			copyPtr->next = bufPtr;
			copyPtr = copyPtr->next;
		}

		ptr = ptr->next;
	}
	return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Stack<T>& St)
{
	node<T>* ptr = St.head;
	while (ptr != nullptr) {
		out.width(5);
		out << ptr->item;
		ptr = ptr->next;
	}
	return out;
}
