#pragma once
#include"_vector.h"
#include <stdio.h>
template<typename T> class Stack :public Vector<T>
{
public:
	Stack()=default;
	void push(T const& e) { Vector<T>::insert(e, Vector<T>::size()); };
	T pop() { return Vector<T>::remove(Vector<T>::size() - 1); }
	T &top() { return (*this)[Vector<T>::size() - 1]; }
};
void convert(Stack<char> & s,int num,int base)
{
	int remainder = num % base;

	
	const char  data[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	s.push(data[remainder]);
	num/=base ;
	if (num == 0)
	{
		return;
	}
	convert(s,num,base);

}
void loop_convert(Stack<char >& s,int num,int base)
{
	const char  data[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	while (num > 0)
	{
		s.push(data[num % base]);
		num = num / base;
	}

}
bool paren(const char exp[],int lo,int hi)
{
	Stack<char> s;
	int result = 0;
	int NumCount = 0;
	
	for (int i = lo; i < hi; i++)
	{
		
		switch (exp[i])
		{
			
			case '(': case '{': case '[': s.push(exp[i]); NumCount++; break;
			case ')': if ('(' != s.pop()) { result = 1; } NumCount--; break;
			case '}': if ('{' != s.pop()) { result = 1; } NumCount--; break;
			case ']': if ('[' != s.pop()) { result = 1; } NumCount--; break;
			default: break;
		}
		if (1 == result)
		{
			break;
		}
	}
	return (!result)&&(!NumCount) ;
}
int ComputeRPN(const char* data,int num)
{
	Stack<char> s;
	int result = 0;
	int a = 0, b = 0;
	for(int i=0;i<num;i++)
	{
		
		if ('0' <= data[i] && data[i] <= '9')
		{
			s.push(data[i]);
		}
		
		else if (data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/')
		{
			
			switch (data[i]){
				case '+':
					 a = s.pop();
					 b = s.pop();
					result = (a - '0') + (b - '0') + '0';
					s.push(result);
					break;
				case '-':
					 a = s.pop();
					 b = s.pop();
					result = (a - '0') - (b - '0') + '0';
					s.push(result);
					break;
				case '*':
					 a = s.pop();
					 b = s.pop();
					result = (a - '0') * (b - '0') + '0';
					s.push(result);
					break;
				case '/':
					 a = s.pop();
					 b = s.pop();
					result = (a - '0') / (b - '0') + '0';
					s.push(result);
					break;
				defalut: break;
			}

		}
		printf("data[%d]:%c  result:%c\n",i, data[i], result);
	}
	result = s.pop()-'0';
	return result;
}
