#include"_vector.h"

#include<stdio.h>
#include<iostream>
#include<vector>
#include"_list.cpp"
using std::cin;
using std::cout;
using std::endl;
int main()
{
	
	//NodePtr->insertAsSucc(5);
	List<int> ListPoint;
	//ListPoint.init();
	ListNode<int>  *NodePtr = ListPoint.Header();
	//
	const int NUM = 10;
	int array[NUM] = { 11,17,2,3,6,5,7,4,14,1 };//};
	for (int i = 0; i < NUM; i++)
	{

		ListPoint.insertA(NodePtr, array[i]);
		//printf("array[%d] :%d ,_size:%d\n",i, array[i], ListPoint.Size());
		//ListPoint.PrintData();
	}
	//cout << "before ListPoint.PrintData!" << endl;
	ListPoint.PrintData();
	//cout << "after ListPoint.PrintData!" << endl;
	ListNode<int> *result=ListPoint.find(10);
	if (result != NULL){
		printf("data :%d\n", result->data);
	}
	else {
		printf("not found \n");
	}
	int ret=ListPoint.InsertSort();
	printf("ret :%d\n", ret);
	ListPoint.PrintData();
	
	
	//lscout << "hello world!" << endl;
	while (1);
	return 0;
}
