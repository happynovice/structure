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
#endif