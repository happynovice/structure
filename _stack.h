#pragma once
#include"_vector.h"

template<typename T> class Stack :public Vector<T>
{
public:
	Stack()=default;
	void push(T const& e) { Vector<T>::insert(e, Vector<T>::size()); };
	T pop() { return Vector<T>::remove(Vector<T>::size() - 1); }
	T &top() { return (*this)[Vector<T>::size() - 1]; }
};
void convert(Stack<char> & s,int num,int base)
{
	int remainder = num % base;

	
	const char  data[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	s.push(data[remainder]);
	num/=base ;
	if (num == 0)
	{
		return;
	}
	convert(s,num,base);

}

