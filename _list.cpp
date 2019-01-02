#include"_list.h"
template <typename T> 
ListNode<T> * ListNode<T>::insertAsPred(T const & e)
{
	ListNode<T> * x = new ListNode(e,pred,this);
	pred->succ = x;
	pred = x;
	return x;
}
template<typename T>
ListNode<T> *ListNode<T>::insertAsSucc(T const &e)
{
	ListNode<T> *x = new ListNode(e,this,this->succ);
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
template <typename T>void List<T>::init()
{
	header = new ListNode<T>;
	tariler = new ListNode<T>;
	header->succ = trailer;
	header->pred = NULL;
	tariler->Pred = header;
	tariler->succ = NULL;
	_size = 0;
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
ListNode<T> * List<T>::find(T const &e,int n,ListNode<T>* p )
{
	while (n--)
	{
		if (e == (p=p->pred)->data)
		{
			return p;
		}
	}
	return NULL;
}
template <typename T> ListNode<T>* 
List<T>::insertAsFirst(T const & e)
{
	_size++;
	return head->insertAsSucc(e);
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
	while (trailer!= (p=p->succ))
	{
		int e = p->data;
		ListNode<T> *ret= find(e, _size, p);
		if (NULL != ret)
		{
			remove(p);
		}
		
	}
	return (OldSize - _size);
}


