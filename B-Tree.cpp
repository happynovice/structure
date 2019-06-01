#include<iostream>
#include<stdio.h>
#include<vector>
#include <stdlib.h>
#include<math.h>
#define m 3
struct  BTreeNode {
    int KeyValue=0;
    const int M = 3;
    int CurrentNum=0;
    BTreeNode **Child=NULL;
    int *key = NULL;
    bool leaf=true;
} ;
void SplitChild(int i, BTreeNode *node,BTreeNode *node)
{
    BTreeNode *NewChild = (BTreeNode *)malloc(sizeof(BTreeNode));
    NewChild->key = (int *)malloc(sizeof(int)*NewChild->M - 1);
    NewChild->Child = (BTreeNode * *)malloc(sizeof(BTreeNode **)*NewChild->M);
    NewChild->leaf = node->leaf;
    NewChild->CurrentNum = node->Child[i + 1]->M - 1;
    int MinKeyNum = ceil(node->Child[i + 1]->M / 2) - 1;
    for (int j = 0; j < MinKeyNum; j++)
    {
        NewChild->key[j] = node->Child[i + 1]->key[j + MinKeyNum];
    }
    if (node->Child[i + 1]->leaf == false)
    {
        for (int j = 0; j < MinKeyNum + 1; j++)
        {
            NewChild->Child[j] = node->Child[i + 1]->Child[j + MinKeyNum];
        }
    }
    NewChild->CurrentNum = MinKeyNum;
    for (int j = node->CurrentNum; j >= i + 2; j--)
    {
        node->Child[j + 1] = node->Child[j];
    }
    node->Child[i + 1] = NewChild;
    for (int j = node->CurrentNum - 1; j >= i + 1; j--)
    {
        node->key[j + 1] = node->key[j];
    }
    node->key[i + 1] = NewChild->key[node->CurrentNum - 1];
    node->CurrentNum = node->CurrentNum + 1;
}
void insertNonFULL(BTreeNode **node,int k)
{
    int InsertNum = k;
    int num = node[0]->CurrentNum - 1;
    if (node[0]->leaf == true) {
        while (num >= 0 && node[0]->key[num]>InsertNum)
        {
            node[0]->key[num + 1] = node[0]->key[num];
            num--;
        }
        node[0]->key[num] = InsertNum;
        node[0]->CurrentNum += 1;
    }
    else {
        while (num >= 0 && node[0]->key[num]>InsertNum)
        {
            num--;
        }
        if (node[0]->Child[num + 1]->CurrentNum == node[0]->Child[num + 1]->M)
        {
            SplitChild(num+1, node[0]);
            if (node[0]->key[num + 1] < k)
            {
                num++;
            }
        }
        insertNonFULL(&(node[0]->Child[num + 1]),k);
    }
}
void insert(BTreeNode **node, int k)
{
    int InsertNum = k;
    if (node[0]->CurrentNum == node[0]->M - 1)
    {
        BTreeNode *NewChild = (BTreeNode *)malloc(sizeof(BTreeNode));
        NewChild->key = (int *)malloc(sizeof(int)*NewChild->M - 1);
        NewChild->Child = (BTreeNode * *)malloc(sizeof(BTreeNode **)*NewChild->M);
        NewChild->leaf = false;
        NewChild->Child[0] = *node;
        SplitChild(0,);
    }
    else
    {
        insertNonFULL(node, k);
    }
}
void initial(BTreeNode **root,int *data,int size,int TreeSize) {

    for (int i = 0; i < size; i++)
    {
        int InsertNum = data[i];
        if (root[0]->CurrentNum == root[0]->M-1)
        {

        }
        else
        {
            int num = root[0]->CurrentNum - 1;
            if (root[0]->leaf == true) {
                while (num >= 0 && root[0]->key[num]>InsertNum)
                {
                    root[0]->key[num + 1] = root[0]->key[num];
                    num--;
                }
                root[0]->key[num] = InsertNum;
                root[0]->CurrentNum += 1;
            }
            else {
                while (num >= 0 && root[0]->key[num]>InsertNum)
                {
                    num--;
                }
                if (root[0]->Child[num+1]->CurrentNum == root[0]->Child[num+1]->M)
                {
                    BTreeNode *NewChild = (BTreeNode *)malloc(sizeof(BTreeNode));
                    NewChild->CurrentNum = root[0]->Child[num + 1]->CurrentNum-1;
                }

            }
        }


        
    }
}
int main()
{
    int data[] = {5,6,7,8,9,10,12,14};
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->key = (int *)malloc(sizeof(int)*node->M-1);
    node->Child = (BTreeNode * *)malloc(sizeof(BTreeNode **)*node->M );
    node->leaf = true;
    initial(&node,data,8,3);

    std::vector<int> BTnode;
    while (1);
    return 0;
}
