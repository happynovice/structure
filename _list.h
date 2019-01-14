#pragma once
#include<stdio.h>
#include"_list.h"

typedef int Rank;
template <typename T> struct ListNode {
	T data;
	ListNode<T> *pred;
	ListNode<T> *succ;
	ListNode() {};
	ListNode(T e, ListNode<T>* p = NULL, ListNode<T> * s = NULL)
	:data(e),pred(p),succ(s){}
	ListNode<T> * insertAsPred(T const& e);
	ListNode<T> * insertAsSucc(T const& e);
	
};
template <typename T> class List {
private:
	int _size;
	ListNode<T>* header;
	ListNode<T>* trailer;
protected:
	
	int clear();
	T remove(ListNode<T>* p);
	ListNode<T>* insertAsFirst(T const & e);
	ListNode<T>* first() { return header->succ; };
	ListNode<T>* last() { return trailer->pred; };
	T& operator[] (Rank r) const;
	int deduplicate();
	
public:
	//List() = default;
	void init();
	List() ;
	List(ListNode<T>* p, int n);
	~List();
	
	ListNode<T>* find(T const &e, int n, ListNode<T>* p);
	ListNode<T> * find(T const e) {
		return find(e, _size, trailer);
	};
	ListNode<T>* insertA(ListNode<T>* p,T const &e);
	ListNode<T>* insertB(ListNode<T>* p, T const &e);
	ListNode<T>* Header() { return header; };
	ListNode<T>* Trailer() { return trailer; };
	int Size() { return _size; };
	int InsertSort();
	int SelectSort();
	void merge(ListNode<T> * &PtrL, ListNode<T> *PtrR, List<T> &L, int middle, int total);
	int MergeSort(ListNode<T> * ptr, int position);
	void mergesort();
	void PrintData();

};
////////////////////////////////////////////////

#include"_list.h"
#include<iostream>
#include<stdio.h>
template <typename T>
ListNode<T> * ListNode<T>::insertAsPred(T const & e)
{
	ListNode<T> * x = new ListNode(e, pred, this);
	pred->succ = x;
	pred = x;

	return x;

}
template<typename T>
ListNode<T>* ListNode<T>::insertAsSucc(T const &e)
{
	ListNode<T> *x = new ListNode(e, this, this->succ);
	//cout << x << endl;
	succ->pred = x;
	succ = x;
	return x;
}
template <typename T>
T List<T>::remove(ListNode<T> *p)
{
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}
template<typename T>
int List<T>::clear()
{
	int OldSize = _size;
	while (0 < _size)
	{
		remove(header->succ);
	}
	//delete header;
	//delete trailer;
	return OldSize;
}
template <typename T>
void List<T>::init()
{
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer;
	header->pred = NULL;
	trailer->pred = header;
	trailer->succ = NULL;
	_size = 0;
}
template <typename T>
List<T>::List(void)
{
	printf("hello init \n");
	init();
}
template<typename T>
List<T>::List(ListNode<T> *p, int n)
{
	printf("hello init (ListNode<T> *p, int n) \n");
}
template<typename T>
List<T>::~List()
{
	clear();
	delete header;
	delete trailer;
}
template <typename T>
T& List<T>::operator[] (Rank r) const
{
	ListNode<T> *p = first();
	while (0 < r--) p = p->succ;
	return p->data;
}
template <typename T>
ListNode<T> * List<T>::find(T const &e, int n, ListNode<T>* p)
{
	while (n--)
	{
		if (e == (p = p->pred)->data)
		{
			return p;
		}
	}
	return NULL;
}
template <typename T>
ListNode<T>* List<T>::insertAsFirst(T const & e)
{
	_size++;
	return head->insertAsSucc(e);
}
template <typename T>
ListNode<T>* List<T>::insertB(ListNode<T>* p, T const &e)
{

	p->insertAsPred(e);
	_size++;
	return p->pred;
}
template <typename T> ListNode<T> *
List<T>::insertA(ListNode<T> *p, T const &e)
{

	p->insertAsSucc(e);
	_size++;
	return p->succ;
}
template <typename T>
int List<T>::deduplicate()
{
	if (_size < 2)
	{
		return 0;
	}
	ListNode<T> *p = header;

	int OldSize = _size;
	while (trailer != (p = p->succ))
	{
		int e = p->data;
		ListNode<T> *ret = find(e, _size, p);
		if (NULL != ret)
		{
			remove(p);
		}

	}
	return (OldSize - _size);
}
template <typename T>
void List<T>::PrintData()
{
	for (ListNode<T>* ptr = header->succ; ptr != trailer; ptr = ptr->succ)
	{
		printf("ptr->data :%d\n", ptr->data);
	}
}

template<typename T>
int List<T>::InsertSort()
{
	if (_size <1)
	{
		printf("size error ! \n");
		return -1;
	}
	ListNode<T> * ptr = header->succ;
	ListNode<T> * PtrBack = ptr;
	ListNode<T> * PtrBuff = ptr;
	ListNode<T> * PtrBack2 = ptr;
	int i = 0;
	for (int i = 0; i < _size; i++)
	{
		for (PtrBuff = PtrBuff->pred; PtrBuff != header; PtrBuff = PtrBuff->pred)
		{

			if (ptr->data >= PtrBuff->data)
			{
				break;
			}
		}
		if (PtrBuff != header)
		{
			PtrBack->succ->pred = PtrBack->pred;
			PtrBack->pred->succ = PtrBack->succ;
			PtrBuff->succ->pred = PtrBack;
			PtrBack->succ = PtrBuff->succ;
			PtrBuff->succ = PtrBack;
			PtrBack->pred = PtrBuff;
			//PrintData();
		}
		ptr = header->succ;
		for (int j = 0; j <= i; j++)
		{
			ptr = ptr->succ;
		}
		if (ptr == trailer)
		{
			break;
		}
		PtrBuff = ptr;
		PtrBack = ptr;
	}
	return 0;
}
template<typename T>
int List<T>::SelectSort()
{
	ListNode<T> * PtrSort = trailer;
	ListNode<T> * PtrBack = header->succ;
	ListNode<T> * PtrBuff = PtrBack;
	ListNode<T> * PtrBack2 = PtrBack;
	for (int i = _size; i > 0; i--)
	{
		int MaxValue = 0;
		PtrBuff = header->succ;
		PtrBack = PtrBuff;
		for (int j = 0; j<i; j++)
		{
			if (PtrBuff->data > MaxValue)
			{
				MaxValue = PtrBuff->data;
				PtrBack = PtrBuff;
			}
			PtrBuff = PtrBuff->succ;
		}
		PtrBack->pred->succ = PtrBack->succ;
		PtrBack->succ->pred = PtrBack->pred;

		PtrSort->pred->succ = PtrBack;
		PtrBack->pred = PtrSort->pred;
		PtrSort->pred = PtrBack;
		PtrBack->succ = PtrSort;

		PtrSort = trailer;
		for (int k = 0; k <= _size - i; k++)
		{
			PtrSort = PtrSort->pred;
		}


	}

	return 0;
}
template <typename T>
void List<T>::merge(ListNode<T> * &PtrL, ListNode<T> *PtrR,List<T> &L,int middle,int total)
{
	//ListNode<T> *PtrBuffL= PtrL, *PtrBuffR= PtrR, *PtrSuccR=NULL;
	int LeftCount = middle;
	int RightCount = total - middle;
	
	ListNode<T> *PtrBuffBack1 = PtrL->pred;
	while(0 < RightCount)
	{ 

		//
		
		//PtrSuccR = PtrR->succ;
		//printf("PtrSuccR:%d \n", PtrSuccR->data);
		if ((LeftCount >0) && PtrL->data <= PtrR->data)
		{
			PtrL = PtrL->succ;
			if (PtrR == PtrL)
			{
				break;
			}
			LeftCount--;
		}
		else
		{
			int BuffData= PtrR->data  ;
			//PtrBuffR->succ->pred = PtrBuffR->pred;
			//PtrBuffR->pred->succ = PtrBuffR->succ;
			//delete PtrBuffR->succ->pred;
			//_size--;

			//PtrBuffL->pred->succ = PtrBuffR;
			//PtrBuffR->pred = PtrBuffL->pred;
			//PtrBuffL->pred = PtrBuffR;
			//PtrBuffR->succ = PtrBuffL;
			L.remove((PtrR=PtrR->succ)->pred);
			//PtrBuffR=PtrR;
			insertB(PtrL, BuffData);

			
			printf("PtrR:%d \n", PtrR->data);
			RightCount--;
		}
	}
	PtrL = PtrBuffBack1->succ;
}

//template <typename T>
//void List<T>::merge(ListNode<T> *PtrL, ListNode<T> *PtrR,int middle,int total)
//{
//	ListNode<T> *PtrBuffL= PtrL, *PtrBuffR= PtrR, *PtrSuccR=NULL;
//	int LeftCount = 0;
//	int RightCount = 0;
//
//	for(int i=0;i<total;i++)
//	{ 
//		PtrBuffL = PtrL;
//		PtrBuffR = PtrR;
//
//		PtrSuccR = PtrR->succ;
//
//		printf("PtrBuffL->data :%d\n", PtrBuffL->data);
//		printf("PtrBuffR->data :%d\n",PtrBuffR->data);
//		printf("total :%d\n", total);
//		if ((PtrBuffL->data >= PtrBuffR->data && RightCount <= (total-middle)))
//		{
//
//				PtrBuffR->succ->pred = PtrBuffR->pred;
//				PtrBuffR->pred->succ = PtrBuffR->succ;
//
//				PtrBuffL->pred->succ = PtrBuffR;
//				PtrBuffR->pred = PtrBuffL->pred;
//				PtrBuffL->pred = PtrBuffR;
//				PtrBuffR->succ = PtrBuffL;
//
//				PtrR = PtrSuccR;
//				RightCount++;
//			
//		}
//		else if(PtrBuffL->data <= PtrBuffR->data&& LeftCount <= ( middle))
//		{
//			PtrL = PtrL->succ;
//			LeftCount++;
//		}	
//	}
//	if (PtrBuffR->data == 11 || PtrBuffL->data == 11)
//	{
//		//while (1);
//	}
//	printf("PrintData \n");
//	PrintData();
//}

template <typename T>
int List<T>::MergeSort(ListNode<T> * ptr,int position)
{
	int middle = position / 2;
	//ListNode<T> * ptr = header->succ;
	if (middle < 1) { return 0; }
	ListNode<T> * PtrL = ptr;
	ListNode<T> * PtrR = ptr;
	for (int i = 0; i < middle; i++)
	{
		PtrR = PtrR->succ;
	}
	printf("middle :%d position :%d\n",middle, position);
	MergeSort(PtrL,middle);
	MergeSort(PtrR, position-middle);
	merge( PtrL, PtrR,*this ,middle, position);

	
	return 0;
}
template <typename T>
void List<T>::mergesort()
{
	
	MergeSort(header->succ, _size);
}
//#include"_list.cpp"

