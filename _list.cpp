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

			if ( ptr->data >= PtrBuff->data)
			{
				break;
			}
		}
		if (PtrBuff != header  )
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
