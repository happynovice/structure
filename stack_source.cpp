#include"_vector.h"

#include<stdio.h>
#include<iostream>
#include<vector>
#include"_list.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{

	Vector<int> StackPra(4,2,0);
	
	StackPra.insert(2,0);
	StackPra.PrintData();
	//lscout << "hello world!" << endl;
	while (1);
	return 0;
}
