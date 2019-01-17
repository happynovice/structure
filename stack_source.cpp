#include"_vector.h"

#include<stdio.h>
#include<iostream>
#include<vector>
#include"_list.h"
#include"_stack.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{

	Vector<int> StackPra(4,2,0);
	
	StackPra.insert(2,0);
	StackPra.PrintData();
	Stack<char> S;
	convert(S,1000,16);
	int size=S.size();
	for (int i = 0; i < size; i++)
	{
		printf("S.pop() :%c \n", S.pop());
	}
	//lscout << "hello world!" << endl;
	while (1);
	return 0;
}

