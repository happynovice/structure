#pragma once
template<typename T> class Stack: Vector<T>
{
public:
	Stack()=default;
	void push(T const& e) { insert(e,size())};
	T pop() { return remove[size()-1]}
	T &top() {return (this*)[size()-1]}
};
