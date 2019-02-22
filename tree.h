#pragma once
#include<iostream>
typedef enum { RB_RED, RB_BLACK }RBColor;
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
		parent(NULL), ln(NULL), rn(NULL), height(0), npl(1), color(RB_RED) {}
	BinNode(T e, BinCode<T> * p = NULL, BinCode<T> * ln = NULL, BinCode<T> * rn = NULL,
		int h = 0,int l=1,BRColor c=RB_RED ): 
		data(e), parent(p),ln(ln),rn(rn),height(h),npl(l),color,(c){}
	int size();
	BinNode<T> * InsertAsLN(T const &);
	BinNode<T> * InsertAsRN(T const &);
	BinNode<T> * succ();
	template <typename VST> void travLevel(VST &);
	template <typename VST> void travPre(VST &);
	template <typename VST> void travIn(VST &);
	template <typename VST> void travPost(VST &);
	bool operator < (BinNode const & bn) { return data < bn.data; }
	bool operator ==(BinNode const & bn) { return  data == bn.data; }
};
template <typename T > BinNode<T> * BinNode<T>::InsertAsLN(const T & e)
{
	return ln = new BinNode(e,this);
}
template <typename T> BinNode<T> *BinNode<T>::InsertAsRN(const T & e)
{
	return rn = new BinNode(e,this);
}
template <typename T> template <typename VST>
void BinNode<T>::travIn(VST &visit)
{
	switch ( rand() % 5 )
	{
		case 1:travIn_I1(this,visit); break;
		case 2:travIn_I2(this,visit); break;
		case 3:travIn_I3(this,visit); break;
		case 4:travIn_I4(this,visit); break;
		default:treaIn_R(this,visit); break;
	}
}

template<typename T> class BinTree {
protect:
	int _size;
	BinNode<T> * _root;
	virtual int updateHeight(BinNode<T> * x);
	void updateHeightAbove(BinNode<T> *x);
public:
	BinTree() :_size(0), _root(NULL) {};
	~BinTree() { if (0 < _size) remove(_root); };
	int size() const { return _size };
	bool empty() const {return !_root};
	BinNode<T> *root() const { return root; }
	BinNode<T> * InsertAsLN(BinNode<T> * x, T const & e);
	BinNode<T> * InsertAsRN(BinNode<T> * x, T const & e);
	BinNode<T> * AttachAsLN(BinNode<T> * x, BinTree<T> * &T );
	BinNode<T> * AttachAsRN(BinNode<T> * x, BinTree<T> * &T );
	int remove(BinNode<T> * x);
	BinTree<T> * secede(BinNode<T> * x);
	template<typename VST>
	void travLevel(VST & visit) { if (_root) _root->travLevel(visit); }
	template<typename VST>
	void travPre(VST & visit) { if (_root) _root->travPre(visit); }
	template <typename T> int BinTree<T>::updateHeight(BinNode<T> * x)
	{
		return x->height = 1 + max(stature(x->ln), stature(x->rn));
	}
	template <typename T> int BinTree<T>::updateHeightAbove(BinNode<T> * x)
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
	template <typename T> BinNode<T> * BinTree<T>::InsertAsLn(BinNode<T> * x,T const &e)
	{
		_size++;
		x->InsertAsLN(e);
		updateHeightAbove(x);
		return x->ln;
	}
	template <typename T> BinNode<T> * BinTree<T>::InsertAsRn(BinNode<T> * x, T const &e)
	{
		_size++;
		x->InsertAsRN(e);
		updateHeightAbove(x);
		return x->rn;
	}
	template<typename T>
	BinNode<T> * BinTree<T>::AttachAsLn(BinNode<T> * x,BinTree<T> * &s) {
		x->ln = s->_root;
		x->ln->parent = x;
		_size += s->_size;
		updateHeightAbove(x);
		s->_root = NULL;
		s->_size = 0;
		release(s);
		s = NULL;
		return x;
	}
	template<typename T>
	BinNode<T> * BinTree<T>::AttachAsRn(BinNode<T> * x, BinTree<T> * &s) {
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
		FromParentTo(*x) = NULL;
		updateHeightAbove(x);
		int n = removeAt(x);
		_size -= n;
		return n;
	}
	template<typename T>
	static int removeAt(BinNode<T> * x)
	{
		if (!x) return 0;
		int n = 1 + removeAt(x->ln) + removeAt(x->rn);
		release(x->data);
		release(x);
		return n;
	}
	template<typename T>
	static int secede(BinNode<T> * x)
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
	template<typename T>
	static int secede(BinNode<T> * x)
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
	template<typename T,typename VST>
	void travPre_R(BinNode<T>* x,VST &visit)
	{
		if (!x) { return; }
		visit(x->data);
		travPre_R(x->ln, visit);
		travPre_R(x->rn, visit);
	}
	template<typename T, typename VST>
	void travPost_R(BinNode<T>* x, VST &visit)
	{
		if (!x) { return; }
		
		travPost_R(x->ln, visit);
		travPost_R(x->rn, visit);
		visit(x->data);
	}
	template<typename T, typename VST>
	void travPost_R(BinNode<T>* x, VST &visit)
	{
		if (!x) { return; }

		travPost_R(x->ln, visit);
		travPost_R(x->rn, visit);
		visit(x->data);
	}
	template<typename T, typename VST>
	void travIn_R(BinNode<T>* x, VST &visit)
	{
		if (!x) { return; }
		traPost_R(x->ln, visit);
		visit(x->data);
		traPost_R(x->rn, visit);
	}

};
