#pragma once
#include <iostream>
#include <list>
#include "Filter.h"
using namespace std;
class Algorithm_custom
{	
	
public:

	template <typename iterator>
	static void quickSort(iterator first, iterator last, bool (*comp)(iterator, iterator, int&), int& num);
	template <typename T>
	static list<T> searchRelevant(list<T>& lst);

};

template <typename iterator>
static void Algorithm_custom::quickSort(iterator first, iterator last, bool (*comp)(iterator, iterator, int&), int& num)
{
	auto numElements = std::distance(first, last);
	if (numElements <= 1)
		return;

	auto pivot = last;
	pivot--;

	if (numElements > 2)
	{
		auto middle = first;
		std::advance(middle, numElements / 2);
		std::iter_swap(middle, pivot);
	}
	auto left = first;
	auto right = pivot;
	while (left != right)
	{
		while (!comp(pivot, left, num) && left != right)
			++left;
		while (!comp(right, pivot, num) && left != right)
			--right;
		if (left != right)
			std::iter_swap(left, right);
	}

	if (pivot != left && comp(pivot, left, num))
		std::iter_swap(pivot, left);

	quickSort(first, left, comp, num);
	quickSort(++left, last, comp, num); 
}


template <typename T>
inline static list<T> Algorithm_custom::searchRelevant(list<T>& lst) {
	list<T> out;
	Filter<T> MyFilter;
	T input1;
	T input2;
	cout << "Set min values" << endl;
	input1.setCertainValues();
	MyFilter.setMin(input1);
	system("cls");
	cout << "Set max values" << endl;
	input2.setCertainValues();
	MyFilter.setMax(input2);
	for (auto& obj : lst) {
		if (MyFilter.isFiltered(obj)) {
			out.push_back(obj);
		}
	}
	return out;
}
