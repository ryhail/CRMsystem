#pragma once
template<typename T>
class Filter {
	T Min_elem;
	T Max_elem;
public:
	void setMin(T&);
	void setMax(T&);
	bool isFiltered(T& obj);
};

template<typename T>
inline void Filter<T>::setMin(T& min)
{
	Min_elem = min;
}

template<typename T>
inline void Filter<T>::setMax(T& max)
{
	Max_elem = max;
}

template<typename T>
inline bool Filter<T>::isFiltered(T& obj)
{
	return (obj <= Max_elem && obj >= Min_elem);
}