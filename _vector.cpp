#include"_vector.h"
#include<iostream>
template<typename T>
void ISF::_vector<T>::merge(rank lo, rank mi, rank hi)
{
	int temp = 0;




	for (int i = lo; i < hi; i++)
	{
		temp = data[i] ;
		for (int j = i + 1; j < hi; i++)
		{
			if(temp>data[j])
				temp =data[j];
		}
		data[i] = temp;
	}
	
}
template<typename T>
void ISF::_vector<T>::mergeSort(rank lo, rank hi)
{
	if (hi <= lo){
		return;
	}
	int mi = (lo + hi) / 2;
	mergeSort(lo,mi);
	mergeSort(mi,hi);
	merge(lo,mi,hi);

}
