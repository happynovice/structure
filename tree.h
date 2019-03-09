#pragma once
#include<iostream>
#include<algorithm>
#include"_stack.h"
typedef enum { RB_RED, RB_BLACK } RBColor;
template <typename T> struct BinNode {
	T data;
	BinNode<T> * parent;
	BinNode<T> * ln;
	BinNode<T> * rn;
	int height;
	int npl;
	RBColor color;
public:
	BinNode() :
		parent(NULL), ln(NULL), rn(NULL), height(0), npl(1), color(RB_RED) {};
	BinNode(T e, BinNode<T> * p = NULL, BinNode<T> * ln = NULL, BinNode<T> * rn = NULL, \
		int h = 0, int l = 1, RBColor c = RB_RED) :										\
		data(e),parent(p),ln(ln),rn(rn),height(h),npl(l),color(c) {};
	//int size();
	BinNode<T> * InsertAsLN(T const &);
	BinNode<T> * InsertAsRN(T const &);
	void succ(BinNode<T>* x);
	void travIn_I3(BinNode<T>* x);
	//BinNode<T> * succ();
	//template <typename VST> void travLevel(VST &);
	//template <typename VST> void travPre(VST &);
	//template <typename VST> void travIn(VST &);
	//template <typename VST> void travPost(VST &);
	bool operator < (BinNode const & bn) { return data < bn.data; }
	bool operator ==(BinNode const & bn) { return  data == bn.data; }
};
template <typename T > BinNode<T> * BinNode<T>::InsertAsLN(const T & e)
{
	return ln = new BinNode(e,(BinNode<T> *)this);
}
template <typename T> BinNode<T> *BinNode<T>::InsertAsRN(const T & e)
{
	return rn = new BinNode(e, (BinNode<T> *)this);
}
//template <typename T> template <typename VST>
//void BinNode<T>::travIn(VST &visit)
//{
//	switch ( rand() % 5 )
//	{
//		case 1:travIn_I1(this,visit); break;
//		case 2:travIn_I2(this,visit); break;
//		case 3:travIn_I3(this,visit); break;
//		case 4:travIn_I4(this,visit); break;
//		default:treaIn_R(this,visit); break;
//	}
//}

template<typename T> class BinTree {
protected:
	int _size;
	BinNode<T> * _root;
	virtual int updateHeight(BinNode<T> * x);
	void updateHeightAbove(BinNode<T> *x);
public:
	BinTree() :_size(0), _root(NULL) {};
	~BinTree() { if (0 < _size) remove(_root); };
	int size() const { return _size; }
	bool empty() const { return !_root; }
	BinNode<T> * root() const { return _root; }
	BinNode<T> * InsertAsLN(BinNode<T> * x, T const & e);
	BinNode<T> * InsertAsRN(BinNode<T> * x, T const & e);
	BinNode<T> * InsertAsRoot(T const & e);
	BinNode<T> * AttachAsLN(BinNode<T> * x, BinTree<T> * &T );
	BinNode<T> * AttachAsRN(BinNode<T> * x, BinTree<T> * &T );
	void visitAlongLeftBrath(BinNode<T> * x);
	void travIn_I1(BinNode<T>* x);
	void travIn_I2(BinNode<T>* x);
	int remove(BinNode<T> * x);
	BinTree<T> * secede(BinNode<T> * x);
	template<typename VST>
	void travLevel(VST & visit) { if (_root) _root->travLevel(visit); }
	template<typename VST>
	void travPre(VST & visit) { if (_root) _root->travPre(visit); }

	template<typename T>
	static int removeAt(BinNode<T> * x)
	{
		if (!x) return 0;
		int n = 1 + removeAt(x->ln) + removeAt(x->rn);
		//release(x->data);
		//release(x);
		return n;
	}


	template<typename T>
	void travPre_R(BinNode<T>* x)
	{
		if (!x) { return; }
		//visit(x->data);
		std::cout << "x->data: " << x->data << "\n";

		travPre_R(x->ln);
		travPre_R(x->rn);

	}

	template<typename T>
	void travPost_R(BinNode<T>* x)
	{
		if (!x) { 
			std::cout << " !x \n";
			return;
		}
		
		travPost_R(x->ln);
		travPost_R(x->rn);
		std::cout << "x->data: " << x->data << "\n";
		//visit(x->data);
	}
	template<typename T>
	void travIn_R(BinNode<T>* x)
	{
		if (!x) {
			std::cout << " !x \n";
			return;
		}
		//std::cout << "F x->data: " << x->data << "\n";
		travIn_R(x->ln);
		std::cout << "x->data: " << x->data << "\n";
		travIn_R(x->rn);
		
	}

};
template<typename T>
BinTree<T> * BinTree<T>::secede(BinNode<T> * x)
{
	FromParentTo(*x) = NULL;
	updateHeightAbove(x->parent);
	BinTree<T> *s = new BinTree<T>;
	s->_root = x;
	x->parent = NULL;
	s->_size = x->size();
	_size -= s->_size;
	return s;
}
template <typename T> int stature(BinNode<T> *x)
{
	if (!x)
	{
		return 1;
	}
	return  std::max(stature(x->ln), stature(x->rn))+1;
}
template <typename T> int BinTree<T>::updateHeight(BinNode<T> * x)
{
	//return 0;//
	return x->height = 1 + std::max(stature(x->ln), stature(x->rn));
}
template <typename T> void BinTree<T>::updateHeightAbove(BinNode<T> * x)
{
	while (x) {
		updateHeight(x);
		x = x->parent;
	}
}
template <typename T> BinNode<T> * BinTree<T>::InsertAsRoot(T const &e)
{
	_size = 1;
	return _root = new BinNode<T>(e);
}
template <typename T> BinNode<T> * BinTree<T>::InsertAsLN(BinNode<T> * x, T const &e)
{
	_size++;
	x->InsertAsLN(e);
	updateHeightAbove(x);
	return x->ln;
}
template <typename T> BinNode<T> * BinTree<T>::InsertAsRN(BinNode<T> * x, T const &e)
{
	_size++;
	x->InsertAsRN(e);
	updateHeightAbove(x);
	return x->rn;
}
template<typename T>
BinNode<T> * BinTree<T>::AttachAsLN(BinNode<T> * x, BinTree<T> * &s) {
	//std::cout << "x->ln = s->_root;" << std::endl;
	x->ln = s->_root;
	//std::cout << "s->_root"<<std::endl;
	x->ln->parent = x;
	_size += s->size();
	updateHeightAbove(x);
	s->_root = NULL;
	s->_size = 0;
	//release(s);
	s = NULL;
	return x;
}
template<typename T>
BinNode<T> * BinTree<T>::AttachAsRN(BinNode<T> * x, BinTree<T> * &s) {
	x->rn = s->_root;
	x->rn->parent = x;
	_size += s->_size;
	updateHeightAbove(x);
	s->_root = NULL;
	s->_size = 0;
	release(s);
	s = NULL;
	return x;
}
template<typename T>
int BinTree<T>::remove(BinNode<T> * x)
{
	//FromParentTo(*x) = NULL;
	updateHeightAbove(x);
	int n = removeAt(x);
	_size -= n;
	return n;
}
template <typename T>
void visit(BinNode<T> * x)
{
	std::cout << "x->data:"<<x->data<<"\n";
}
template <typename T>
void visitAlongLeftBranch(BinNode<T> * x, Stack<BinNode<T> *> &s)
{
	while (true)
	{
		if (nullptr != x->rn)
		{
			s.push(x->rn);
		}
		visit(x);
		x = x->ln;
		
		if (nullptr == x)
		{
			break;
		}
		
	}
}
template <typename T>
void BinTree<T>::visitAlongLeftBrath(BinNode<T> * x)
{
	Stack<BinNode<T> *> s;
	while (true)
	{
		visitAlongLeftBranch(x,s);
		if (s.empty())
		{
			break;
		}
		x = s.pop();
	}
}
template <typename T>
static void goAlongLeftBranch(BinNode<T> * x, Stack<BinNode<T> *> &s)
{
	while (x)
	{
		s.push(x);
		x = x->ln;
	}
}
template <typename T>
void BinTree<T>::travIn_I1(BinNode<T> * x)
{
	Stack<BinNode<T> *> s;
	while (true)
	{
		goAlongLeftBranch(x, s);
		if (s.empty())
		{
			break;
		}
		x = s.pop();
		visit(x);
		x = x->rn;
	}
}
template <typename T>
void BinNode<T>::succ(BinNode<T> * x)
{
	BinNode<T> * s=this;
	if (rn)
	{
		s = rn;
		while (s->ln != nullptr)
		{
			s = s->ln;
		}
	}
	else
	{
		while (s->rn != nullptr)
		{
			s = s->parent;
		}
		s = s->parent;
	}
	return s;
}
template <typename T>
void BinNode<T>::travIn_I3(BinNode<T> * x)
{
	bool backtrack = false;
	while (true)
	{
		if (false==backtrack && x->ln != nullptr)
		{
			x = x->ln;
		}
		else {
			visit(x);
			if (x->rn != nullptr){
				x = x->rn;
				backtrack = false;
			}
			else{
				x = x->succ();
				if (!x)
				{
					break;
				}
				backtrack = true;
			}
		}

	}
}
