/*
求a,b两序列(链表)交集，存于a
*/
#include <iostream>
#include <stdio.h>
void swap(int low, int high, int *data)
{
	int middle = (low + high) / 2;
	for (int i = low; i <= middle; i++)
	{
		int buff = data[i];
		data[i] = data[high - (i - low)];
		data[high - (i - low)] = buff;
	}
}
void SortNum(int *data, int p, int n)
{
	swap(0, p - 1, data);
	swap(p, n - 1, data);
	swap(0, n - 1, data);

}
int middleNum(int *data1, int length1, int *data2, int length2)
{
	int L1 = 0;
	int L2 = 0;
	int middle = (length1 + length2) / 2;
	int buff = 0;
	std::cout << "length1: " << length1 << " length2: " << length2 << " \n";
	for (int i = 0; i < middle; i++)
	{

		if ((data1[L1] < data2[L2] || L2>length2) && L1 <= length1)
		{
			buff = data1[L1];
			//std::cout << "data1[L1] :";
			//std::cout << "buff: "<< buff <<"\n";
			L1++;
		}
		else if ((data1[L1] > data2[L2] || L1>length1) && (L2 <= length2))
		{
			buff = data2[L2];
			std::cout << "L2: " << L2 << "data1[L2] :" << data2[L2] << "  ";
			std::cout << "buff: " << buff << "\n";
			L2++;
		}
		else if (data1[L1] == data2[L2])
		{
			buff = data1[L1];
			//std::cout << "data1[L1] :  ";
			//std::cout << "data1[L2] :  ";
			//std::cout << "buff: " << buff << "\n";
			L1++;
			L2++;
			i++;
		}
		std::cout << "buff: " << buff << "\n";
	}
	return buff;
}
struct _List {
	int value;
	_List *next;
};
struct _List2 {
	int data;
	int freq;
	_List2 *pred;
	_List2 *next;
};
void deleteNum(_List * pList, int x)
{
	_List * buff = pList;
	pList = pList->next;
	while (pList != NULL)
	{
		if (pList->value == x)
		{
			buff->next = pList->next;
			free(pList);
			pList = buff->next;
		}
		else
		{
			buff = pList;
			pList = pList->next;
		}
	}

}
void deleteNumRecursion(_List * pList, _List * pListPre, int x)
{
	if (pList == NULL)
	{
		return;
	}
	if (pList->value == x)
	{
		_List *buff = pList;
		pListPre->next = pList->next;
		pList = pList->next;
		free(buff);
	}
	else
	{
		pListPre = pList;
		pList = pList->next;
	}

	deleteNumRecursion(pList, pListPre, x);
}
void TraversalListReverse(_List * ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	TraversalListReverse(ptr->next);
	std::cout << "ptr->value:" << ptr->value << "\n";
}
void deleteMin(_List *ptr)
{
	_List *buff = ptr;
	ptr = ptr->next;
	_List * Min = buff;
	Min->value = ptr->value;
	while (ptr != NULL)
	{
		if (ptr->value < Min->value)
		{
			Min = buff;
		}
		buff = ptr;
		ptr = ptr->next;
	}
	_List *deleteBuff = Min->next;
	Min->next = Min->next->next;
	free(deleteBuff);
}
void ReverseList(_List * ptr)
{
	_List *pre = ptr;
	_List *middle = ptr->next;
	ptr->next = NULL;
	_List *buff = middle;
	while (buff != NULL) {
		buff = middle->next;
		middle->next = pre;
		pre = middle;
		middle = buff;
	}
}
void SortList(_List * ptr)
{
	_List * ptr1 = ptr;
	_List * buff = ptr;
	while (ptr != NULL)
	{
		buff = ptr1;
		ptr = ptr->next;

		while (buff->next != NULL)
		{
			if (buff->value > buff->next->value)
			{
				int tmp = buff->value;
				buff->value = buff->next->value;
				buff->next->value = tmp;
			}
			buff = buff->next;
		}
	}

}
void deleteIntervalNum(_List * pList, int low, int high)
{
	_List *buff = pList;
	pList = pList->next;
	while (pList != NULL)
	{
		if (pList->value <= high && pList->value >= low)
		{
			buff->next = pList->next;
			free(pList);
			pList = buff->next;
		}
		else
		{
			buff = pList;
			pList = pList->next;
		}

	}
}
bool findSameNode(_List *pList1, _List *pList2)
{
	while (pList1->next != NULL)
	{
		pList1 = pList1->next;
	}
	while (pList2->next != NULL)
	{
		pList2 = pList2->next;
	}
	if (pList2 == pList1) {
		return true;
	}
	else {
		return false;
	}
}
void SortListMin(_List * ptr)
{
	_List *buff = ptr;
	_List *buff1 = ptr;
	while (buff1 != NULL)
	{
		buff = ptr;
		while (buff->next != NULL)
		{
			if (buff->value > buff->next->value)
			{
				int buffNum = buff->next->value;
				buff->next->value = buff->value;
				buff->value = buffNum;
			}
			buff = buff->next;
		}
		buff1 = buff1->next;
	}

}
void segmentation(_List * ptr, _List * list1, _List * list2)
{
	while (ptr != NULL)
	{
		list1->next = ptr;
		list1 = list1->next;
		ptr = ptr->next;
		if (ptr != NULL)
		{
			list2->next = ptr;
			list2 = list2->next;
			ptr = ptr->next;
		}

	}
}
void segmentation2(_List * ptr, _List * list1, _List * list2)
{
	_List *buff1 = NULL;
	_List *buff2 = NULL;
	while (ptr != NULL)
	{
		list1->next = ptr;
		list1 = list1->next;
		ptr = ptr->next;
		if (ptr != NULL)
		{
			list2->next = ptr;
			buff2 = ptr->next;
			ptr->next = buff1;
			buff1 = ptr;
			ptr = buff2;
		}
	}
}
void deleteSortSameNum(_List * ptr, int value)
{
	_List * buff = ptr;
	ptr = ptr->next;
	//std::cout << "value:" << value << "\n";
	while (ptr != NULL)
	{
		if (ptr->value == value)
		{
			std::cout << "ptr->value == value   value:" << value << "\n";
			buff->next = ptr->next;
			free(ptr);
			ptr = buff->next;
		}
		else
		{

			value = ptr->value;
			buff = ptr;
			ptr = ptr->next;

		}
	}
}
void combineList(_List *list, _List * list1, _List *list2)
{
	_List * buff1 = NULL;
	_List * buff2 = NULL;
	list->next = NULL;
	while (list1 != NULL || list2 != NULL)
	{
		if (list1 != NULL && list2 != NULL)
		{
			if (list1->value<list2->value)
			{
				buff1 = list->next;
				list->next = list1;
				buff2 = list1->next;
				list1->next = buff1;
				list1 = buff2;
			}
			else
			{
				buff1 = list->next;
				list->next = list2;
				buff2 = list2->next;
				list2->next = buff1;
				list2 = buff2;
			}
		}
		else
		{
			if (list2 == NULL)
			{
				buff1 = list->next;
				list->next = list1;
				buff2 = list1->next;
				list1->next = buff1;
				list1 = buff2;
			}
			else
			{
				buff1 = list->next;
				list->next = list2;
				buff2 = list2->next;
				list2->next = buff1;
				list2 = buff2;
			}
		}
	}
}
void SelectSameNumFromList(_List *list, _List * list1, _List *list2)
{
	_List *buff = NULL;
	_List * listBuff = list;
	while (list1 != NULL && list2 != NULL)
	{
		if (list1->value < list2->value) {
			list1 = list1->next;
			continue;
		}
		else if (list1->value > list2->value) {
			list2 = list2->next;
			continue;
		}
		else {
			buff = listBuff;
			listBuff = (_List *)malloc(sizeof(_List));
			listBuff->value = list1->value;
			buff->next = listBuff;
			list1 = list1->next;
			list2 = list2->next;
		}
	}
	listBuff->next = NULL;
}
void SelectSameNumFromList2(_List * list1, _List *list2)
{
	_List *buff = list1;
	list1 = list1->next;
	while (list1 != NULL)
	{
		if (list2 != NULL)
		{
			if (list1->value < list2->value) {
				buff->next = list1->next;
				free(list1);
				list1 = buff->next;
				continue;
			}
			else if (list1->value > list2->value) {
				list2 = list2->next;
				continue;
			}
			else {
				buff = list1;
				list1 = list1->next;
				list2 = list2->next;
			}
		}
		else
		{
			buff->next = list1->next;
			free(list1);
			list1 = buff->next;

		}

	}
}
bool judgeChildList(_List * list1, _List *list2)
{
	_List *buff = list2;
	while (list1 != NULL)
	{
		if (list2 != NULL)
		{
			if (list1->value != list2->value)
			{
				list2 = buff;
			}
			else {
				list2 = list2->next;
			}
			list1 = list1->next;
		}
		else
		{
			return true;
		}
	}
	if (list2 != NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void DeleteMinNum(_List * list)
{
	_List * buff = list;
	_List * buffPrior = buff;
	int buffValue = list->next->value;
	while (buff->next != NULL)
	{
		list = buff;
		buffPrior = buff;
		buffValue = list->next->value;
		while (list->next != NULL)
		{
			if (list->next->value<buffValue)
			{
				buffValue = list->next->value;
				buffPrior = list;
			}

			list = list->next;
		}
		_List * buffFree = buffPrior->next;
		buffPrior->next = buffPrior->next->next;
		std::cout << "buffFree->value:" << buffFree->value << "\n";
		free(buffFree);
	}
	free(buff);
}
void Locate(_List2 * list, int x)
{
	_List2 *buffBack = list;
	_List2 *buff = list->next;
	list = list->next;
	while (list != NULL)
	{
		if (list->data == x)
		{
			list->freq++;
			buff = list;
			break;
		}
		list = list->next;
	}
	if (list == NULL) {
		return;
	}
	list = buffBack->next;
	while (list->freq > buff->freq)
	{
		list = list->next;
	}
	buff->next->pred = buff->pred;
	buff->pred->next = buff->next;
	buff->next = list;
	list->pred->next = buff;
	buff->pred = list->pred;
	list->pred = buff;
}
void CreateList2(_List2 * list)
{
	int data[10] = { 1,3,4,5,6,7,15,20,25 };
	for (auto a : data)
	{
		_List2 * buff = (_List2 *)malloc(sizeof(_List2));
		buff->data = a;
		buff->freq = 0;
		buff->pred = list;
		list->next = buff;
		list = list->next;
	}
	list->next = NULL;
}
void PrintList2(_List2 * list)
{
	_List2 * ptr = list;
	while (ptr != NULL)
	{
		static int i = 0;
		std::cout << "i:" << ++i << " ptr->value:" << ptr->data << " \n";
		ptr = ptr->next;
	}
}
int FindLastKNode(_List *list, int k)
{
	_List *list1 = list;
	_List *list2 = list;
	for (int i = 0; i < k; i++) {
		if (list1 != NULL) {
			list1 = list1->next;
		}
	}
	while (list1 != NULL)
	{
		list1 = list1->next;
		list2 = list2->next;
	}
	return list2->value;
}
_List * FinfSameNode(_List *list1, _List *list2)
{
	_List *buff1 = list1;
	int Num1 = 0;
	while (buff1 != NULL) {
		buff1 = buff1->next;
		Num1++;
	}
	_List *buff2 = list2;
	int Num2 = 0;
	while (buff2 != NULL) {
		buff2 = buff2->next;
		Num2++;
	}
	buff2 = list2;
	buff1 = list1;

	if (Num1 > Num2) {
		for (int i = 0; i < Num1 - Num2; i++)
		{
			buff1 = buff1->next;
		}
	}
	else if (Num1 < Num2) {
		for (int i = 0; i < Num2 - Num1; i++)
		{
			buff2 = buff2->next;
		}
	}

	while (buff1 != NULL) {
		if (buff1 != buff2) {
			buff1 = buff1->next;
			buff2 = buff2->next;
		}
		else { return buff1; }
	}
	return NULL;
}
void DeleteRepeatNum(_List *list)
{
	_List * buff = list->next;
	_List *buffLib = list;
	_List * buffPre = list;
	while (buff!=NULL)
	{
		buffLib = list->next;
		while (buffLib != buff)
		{
			if (buffLib->value == buff->value || (buffLib->value + buff->value) == 0)
			{
				buffPre->next = buff->next;
				free(buff);
				buff = buffPre->next;
			}
			else
			{
				buffLib = buffLib->next;
			}
		}
		buffPre = buff;
		buff = buff->next;
	}
}
void DeleteRepeatNum2(_List *list,int n)
{
	int *pLib=(int *)malloc((n+1)*sizeof(int));
	for (int i = 0; i < n + 1; i++)
	{
		pLib[i] = 0;
	}
	_List * buff = list->next;
	_List *buffLib = list;
	_List * buffPre = list;
	while (buff != NULL)
	{
		int num = buff->value>0? buff->value:-buff->value;
		if (pLib[num] == 0)
		{
			pLib[num] = 1;
			buffPre = buff;
			buff = buff->next;
		}
		else
		{
			buffPre->next = buff->next;
			free(buff);
			buff = buffPre->next;
		}
	}
	free(pLib);
}
int main()
{
	int data[10] = { 5,6,7,15 };
	//int data[10] = { 1,1,2,3,4,5,6,7,9,20  };
	int data2[10] = { 1,3,4,5,6,-3,15,20,25 };
	//SortNum(data, 4, 9);
	_List *ptr = (_List *)malloc(sizeof(_List));
	_List *head = ptr;
	_List * buff = NULL;
	for (auto a : data)
	{
		if (a != 0)
		{
			buff = ptr;
			ptr = (_List *)malloc(sizeof(_List));
			ptr->value = a;
			buff->next = ptr;
		}
	}

	ptr->next = NULL;
	_List *ptr2 = (_List *)malloc(sizeof(_List));
	_List *head2 = ptr2;
	for (auto a : data2)
	{
		if (a != 0)
		{
			buff = ptr2;
			ptr2 = (_List *)malloc(sizeof(_List));
			ptr2->value = a;
			buff->next = ptr2;
		}
	}
	ptr2->next = NULL;
	//ptr2->next = head->next;
	//std::cout << "findSameNode(head, head2) : " << findSameNode(head, head2) << "\n";
	//SortListMin(head->next);
	std::cout << "FindLastKNode(head2,3): " << FindLastKNode(head2, 3) << "\n";
	_List *list = (_List *)malloc(sizeof(_List));
	_List *list1 = (_List *)malloc(sizeof(_List));
	_List *list2 = (_List *)malloc(sizeof(_List));
	DeleteRepeatNum2(head2,25);
	//DeleteRepeatNum(head2);
	//list1->next = head;
	//list2->next = head->next->next;
	//_List *result = FinfSameNode(list1->next, list2->next);
	//if (result != NULL)
	//{
	//	std::cout << "result: " << result->value;
	//}
	//else
	//{
	//	std::cout << "result: NULL";
	//}
	//CreateList2(list2);
	//Locate(list2, 5);
	//PrintList2(list2->next);
	//Locate(list2, 1);
	//PrintList2(list2->next);
	//bool ret = judgeChildList(head2->next, head->next);
	//std::cout << "ret: " << ret << "\n";
	//DeleteMinNum(head);

	//SelectSameNumFromList2(head2, head->next);
	//SelectSameNumFromList(list, head2->next, head->next);
	//combineList(list, head2->next, head->next);
	//SortList(head->next);
	//deleteSortSameNum(head, 2);
	//segmentation2(head->next, list1, list2);
	//deleteIntervalNum(head, 3, 5);
	//SortList(head->next);                                                      
	//ReverseList(head->next);
	//deleteMin(head);
	//TraversalListReverse(head->next);
	//deleteNumRecursion(head->next, head,5);
	//deleteNum(head, 5);
	//ptr = head->next;
	ptr = head2->next;
	while (ptr != NULL)
	{
		static int i = 0;
		std::cout << "i:" << ++i << " ptr->value:" << ptr->value << " \n";
		ptr = ptr->next;
	}
	while (1);
	return 0;
};