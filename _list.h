#pragma once
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
	void init();
	int clear();
	void merge();
	T remove(ListNode<T>* p);
	
	ListNode<T>* insertAsFirst(T const & e);
	ListNode<T>* first() { return header->succ; };
	ListNode<T>* last() { return trailer->pred; };
	T& operator[] (Rank r) const;
	int deduplicate();
	
public:
	List() { init(); };
	~List();
	ListNode<T>* find(T const &e, int n, ListNode<T>* p);
	ListNode<T> * find(T const e) {
		find(e, _size,trailer);
	};
};
