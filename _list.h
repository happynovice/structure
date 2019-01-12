#pragma once
#include<stdio.h>


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
	void PrintData();

};

//#include"_list.cpp"





