#ifndef _VECTOR_H
#define _VECTOR_H

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


template <typename T> class _vector
{
protected:
	T * data;
	rank _size;
	int capacity;
public:
	int insert(T e, int position);
	void merge(rank lo, rank mi, rank hi);

	void mergeSort(rank lo, rank hi);

};

template <typename T> 
int _vector<T>::insert(T e, int position)
{
	if (position > _size)
	{
		return -1;
	}
	for (; position <= _size; position++)
	{
		data[position] = data[position-1];
	}
	data[position - 1] = e;
	_size++;
	return 0;
}
#endif
