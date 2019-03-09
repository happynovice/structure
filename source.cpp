#include"_vector.h"

#include<stdio.h>
#include<iostream>
#include<vector>
#include"_list.h"
#include"_tree.h"
using std::cin;
using std::cout;
using std::endl;
// queue::push/pop

#include <queue>          // std::queue
using std::queue;
int main()
{

	
	BinTree<int> tree, tree1;
	BinNode<int> * num1=new BinNode<int>(2);
	BinNode<int> * num2 = new BinNode<int>(4);
	tree.InsertAsRoot(7);
	tree.root()->InsertAsRN(3);
	tree.root()->InsertAsLN(5);
	tree1.InsertAsRoot(9);
	tree1.root()->InsertAsRN(4);
	tree1.root()->InsertAsLN(6);
	BinTree<int> *tree1_Ptr = &tree1;
	tree.AttachAsLN(tree.root()->ln, tree1_Ptr);
	//tree.InsertAsRN(tree.root(),4);
	//cout<<"tree.InsertAsRN(num1,2); "<<"\n";
	//tree.travIn_R();
	cout << "tree.travPost_R(tree.root()); " << "\n";
	tree.travIn_I1(tree.root());
	//tree.travIn_R(tree.root());
	//tree.travPre_R(tree.root());
	while (1);
	return 0;
}
//int main()
//{
//	
//	//NodePtr->insertAsSucc(5);
//	List<int> ListPoint;
//	//ListPoint.init();
//	ListNode<int>  *NodePtr = ListPoint.Header();
//	//
//	const int NUM = 10;
//	int array[NUM] = { 11,17,2,3,6,5,7,4,14,1 };//};
//	for (int i = 0; i < NUM; i++)
//	{
//
//		ListPoint.insertA(NodePtr, array[i]);
//		//printf("array[%d] :%d ,_size:%d\n",i, array[i], ListPoint.Size());
//		//ListPoint.PrintData();
//	}
//	//cout << "before ListPoint.PrintData!" << endl;
//	ListPoint.PrintData();
//	//cout << "after ListPoint.PrintData!" << endl;
//	ListNode<int> *result=ListPoint.find(10);
//	if (result != NULL){
//		printf("data :%d\n", result->data);
//	}
//	else {
//		printf("not found \n");
//	}
//	//int ret=ListPoint.InsertSort();
//	int ret = ListPoint.SelectSort();
//	printf("ret :%d\n", ret);
//	ListPoint.PrintData();
//	
//	
//	//lscout << "hello world!" << endl;
//	while (1);
//	return 0;
//}
