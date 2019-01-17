#pragma once

#include<iostream>
namespace ISF {
	typedef int rank;
	template <typename T> class _vector
	{
	protected:
		T * data;
		rank _size;
		int capacity;
	public:
		
		void merge(rank lo, rank mi, rank hi);
		
		void mergeSort(rank lo, rank hi);

	};
}
typedef int rank;
#define  DefaultCapaticy 3
template <typename T> class Vector
{
protected:
	T * data;
	rank _size;
	int _capacity;
public:
	Vector(int c = DefaultCapaticy, int s = 0, T v = 0)
	{
		_capacity = c;
		data = new T[_capacity];
		for (_size = 0; _size < s; data[_size++] = v);
		

	}
	int insert(T e, int position);
	T remove(int position);
	int size() { return _size; };
	int capacity() { return _capacity; };
	void PrintData();
};

template <typename T> 
int Vector<T>::insert(T e, int position)
{
	if (position > _size )
	{
		printf("Vector<T>::insert   position > _size \n");
		return -1;
	}
	for (int i= _size; i > position; i--)
	{
		data[i] = data[i-1];
	}
	data[position] = e;
	_size++;
	return 0;
}
template <typename T>
void Vector<T>::PrintData()
{
	for (int i = 0; i < _size; i++)
	{
		printf("data[%d]:%d \n",i,data[i]);
	}
}

template<typename T>
T Vector<T>::remove(int position)
{
	T buff = data[position];
	for (int i = position; i < _size-1; i++)
	{
		data[position] = data[position+1];
	}
	_size--;
	return buff;
}

