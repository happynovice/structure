#include <iostream>
#include <stdio.h>
#include <queue>
typedef int ElemType;
struct TreeNode {
    ElemType data;
    TreeNode *L=NULL;
    TreeNode *R=NULL;
};
void Assign(TreeNode **node, ElemType value)
{
    TreeNode *_root = new TreeNode[1];
    node[0]=_root;
    memset(node[0], 0, sizeof(TreeNode));
    
    node[0]->data = value;
    
}
void InitTree(ElemType *data, int size,TreeNode **_root)
{
    if (_root==NULL)
    {
        return;
    }
    ElemType * DataEnd = data + size;
    std::queue<TreeNode*> q;
    q.push(_root[0]);
    _root[0]->data = *data++;
    int count = 0;
    
    while (data!= DataEnd)
    {
        TreeNode* node=q.front();
        printf("node->value:%d\n", node->data);
        Assign(&(node->L), *data++);
        q.push(node->L);
        if (data == DataEnd){
            break;
        }
        Assign(&(node->R), *data++);
        q.push(node->R);
        q.pop();
        if (count++>10)
        {
            break;
        }
    }
}
void Travel_L(TreeNode * _root)
{
    if (_root == NULL)
    {
        return;
    }
    printf("_root->value:%d\n",_root->data);
    Travel_L(_root->L);
    Travel_L(_root->R);
}
int main()
{
    //TreeNode *_root = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode *_root = new TreeNode[1];
    memset(_root,0, sizeof(TreeNode));
    const int size = 10;
    ElemType data[size] = { 1,3,4,5,6,-3,15,20,25 };
    InitTree(data, size, &_root);
    Travel_L(_root);
   // TreeNode* node;
   // ElemType *dataPtr = data;
   // _root->data = *dataPtr++;
   // std::queue<TreeNode*> q;

   // q.push(_root);
   // node = q.back();
   // printf("node ->value %d:", node->data);
   // Assign(&(_root->L), *dataPtr++);
   // q.push(_root->L);
   // //node = q.back();
   // //printf("node ->value %d:", node->data);
   // Assign(&(_root->R), *dataPtr++);
   // q.push(_root->R);
   // //node = q.back();
   //// printf("node ->value %d:", node->data);
   // q.pop();
   // node = q.front();
   // printf("node ->value %d:", node->data);
    while (1);
    return 0;
}
