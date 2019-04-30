#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <memory>
using std::shared_ptr;
typedef int ElemType;
struct TreeNode {
    ElemType data;
    TreeNode *L=NULL;
    TreeNode *R=NULL;
    //int testdata[1024*1024];
};
void Assign(TreeNode * &node, ElemType value)
{
    TreeNode *_root = new TreeNode[1];
    node = _root;
    memset(node, 0, sizeof(TreeNode));
    node->data = value;

}
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
    printf("node->value:%d\n", *data);
    _root[0]->data = *data++;
    int count = 0;
    
    while (data!= DataEnd)
    {
        TreeNode* node=q.front();
        
        node->L = NULL;
        node->R = NULL;
        if (*data++ != 0)
        {
            
            Assign(&(node->L), *--data);
            q.push(node->L);
            printf("node->value:%d\n", *data);
            data++;
            if (data == DataEnd) {
                break;
            }
        }
        if (*data++ != 30)
        {
            Assign(&(node->R), *--data);
            q.push(node->R);
            printf("node->value:%d\n", *data);
            data++;
        }
        q.pop();
    }
}
void visit(TreeNode * node)
{
    if (node != NULL)
    {
        printf("data: %d \n",node->data);
    }
}
void Travel_L(TreeNode * _root)
{
    if (_root == NULL)
    {
        return;
    }
    printf("Travel_L _root->value:%d\n",_root->data);
    Travel_L(_root->L);
    Travel_L(_root->R);
}
void Travel_M(TreeNode * _root)
{
    if (_root == NULL)
    {
        return;
    }
    
    Travel_M(_root->L);
    printf("Travel_M _root->value:%d\n", _root->data);
    Travel_M(_root->R);
}
void Travel_H(TreeNode * _root)
{
    if (_root == NULL)
    {
        return;
    }

    Travel_H(_root->L);
    Travel_H(_root->R);
    printf("Travel_H _root->value:%d\n", _root->data);
}
void Travel_L_Iteration(TreeNode * node)
{
    std::stack<TreeNode *> s;
    if (node == NULL){   return; }
    s.push(NULL);
    while (1)
    {
        visit(node);
        if (node->L != NULL && node->R != NULL) {
            s.push(node);
            node = node->L;
        }
        else{
            if (node->L != NULL) {  node = node->L;}
            else if (node->R != NULL) { node = node->R;}
            else{
                node = s.top();
                if (node == NULL){  break; }
                s.pop();
                node = node->R;
            }
        }
    }
}
void Travel_L_Iteration_2(TreeNode * node)
{
    std::stack<TreeNode *> s;
    if (node == NULL) { return; }
    while (!s.empty()||node!=NULL)
    {
        if (node != NULL ) {
            visit(node);
            s.push(node);
            node = node->L;
        }
        else {
            if (!s.empty()) { 
                node = s.top(); 
                node = node->R;
                s.pop();
            }
        }
    }
}
void Travel_M_Iteration(TreeNode * node)
{
    std::stack<TreeNode *> s;
    while (!s.empty() || node !=  NULL)
    {
        if (node != NULL)
        {
            s.push(node);
            node = node->L;
        }
        else
        {
            if (!s.empty())
            {
                node=s.top();
                visit(node);
                node = node->R;
                s.pop();
            }
        }
    }
}
void Travel_H_Iteration(TreeNode * node)
{
    std::stack<TreeNode *> s;
    TreeNode * buff = node;
    while(!s.empty()||node!=NULL){
        if (node != NULL){
            s.push(node);
            node = node->L;
        }
        else{
            if (!s.empty()){
                node=s.top();
                if (node->R == NULL || node->R == buff){
                    //visit(node);
                    buff = node;
                    s.pop();
                    node = NULL;
                }
                else{
                    node = node->R;
                }
            }
        }
    }
}
class context
{
public:
    int *data;
     ~context()
    {
         std::cout <<"data: "<<*data <<"\n";
    };
};

int GetTreeHeight(TreeNode * node)
{
    if (node == NULL)
    {
        return -1;
    }
    std::stack<TreeNode *> s;
    TreeNode * buff = NULL;
    //s.push(node);
    int max = 1;
    while (!s.empty()||node!=NULL)
    {
        if (node != NULL )
        {
            s.push(node);
            node = node->L;
        }
        else
        {
            node = s.top();
            
            if (node->R == NULL || node->R == buff)
            {
                visit(node);
                buff = node;
                s.pop();
                node = NULL;
            }
            else
            {
                node = node->R;
            }
        }
        if ((int)s.size() > max)
        {
            max = s.size();
        }
    }
    return max;
}
int GetTreeHeight2(TreeNode * node)
{
    if (node == NULL)
    {
        return -1;
    }
    std::queue<TreeNode *>q;
    q.push(node);
    int height = 0;
    while (q.size() != 0)
    {
        height++;
        int size = q.size();
        int i = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *buff =q.front() ;
            if(buff->L!=NULL)
            {
                q.push(buff->L);
            }
            if (buff->R != NULL)
            {
                q.push(buff->R);
            }
            q.pop();
        }
    }
    return height;
}
int MapVector[256] = {0};
void MapData(int size, ElemType *In)
{
    for (int i = 0; i < size; i++)
    {
        MapVector[In[i]] = i;
    }
}
struct DataInfo {
    ElemType *PtrValue;
    int size;
};
int  FindRoot(ElemType num, DataInfo data)
{
    for (int i = 0; i < data.size; i++)
    {
        if (data.PtrValue[i] == num)
        {
            return i;
        }
    }
    return -1;
}
TreeNode * CreateTree(ElemType * root,int ChlidSize,int offsetL, DataInfo Data)
{
    if (ChlidSize == 0)
    {
        return NULL;
    }
    int offsetN = FindRoot(root[0], Data) - offsetL;
    TreeNode *node = new TreeNode[1];
    memset(node,0,sizeof(TreeNode));
    node->data = root[0];
    node->L = CreateTree(root+1, offsetN, offsetL, Data);
    node->R = CreateTree(root+ offsetN +1, ChlidSize - offsetN -1, offsetL + offsetN +1, Data);
    return node;
}
void CreateTreeBy_PreIn()
{
    ElemType Pre[] = {1,2,4,5,8,9,3,6,7};
    ElemType In[] = {4,2,8,5,9,1,6,3,7};
    
    ElemType offset = 0;
    ElemType *root = Pre;
    int size = sizeof(Pre) / sizeof(Pre[0]);
    //MapData(size, In);
    std::cout << "size:"<<size<<"\n";
    DataInfo Data;
    Data.PtrValue = In;
    Data.size = size;
    TreeNode *_root = CreateTree(root, size, offset, Data);
    Travel_L(_root);
    Travel_M(_root);
    std::cout<<GetTreeHeight2(_root);
}
bool Judge_CompleteBinTree(TreeNode *_root)
{
    if (_root == NULL)
    {
        return false;
    }
    int flag = 0;
    std::queue<TreeNode *>q;
    q.push(_root);
    while (q.size()!=0)
    {
        TreeNode * node = q.front();
        if (flag == 1){
            if (node->L != NULL || node->R != NULL){
                return false;
            }
        }
        if (node->L != NULL){
            q.push(node->L);
        }
        else
        {
            flag = 1;
            if (node->L == NULL && node->R != NULL)
            {
                return false;
            }
        }
        if (node->R != NULL)
        {
            q.push(node->R);
        }
        else
        {
            flag = 1;
        }
        q.pop();
    }
    return true;
}
int CountDoubleChild(TreeNode *node)
{
    if (node == NULL)
    {
        return -1;
    }
    std::queue<TreeNode *>q;
    q.push(node);
    int DoubleChildNum = 0;
    while (q.size() != 0)
    {
        node = q.front();
        if (node->L != NULL && node->R != NULL)
        {
            DoubleChildNum++;
        }
        if (node->L != NULL)
        {
            q.push(node->L);
        }
        if (node->R != NULL)
        {
            q.push(node->R);
        }
        q.pop();
    }
    return DoubleChildNum;
}
void SwapChild(TreeNode *node)
{
    if (node == NULL)
    {
        return ;
    }
    std::queue<TreeNode *>q;
    q.push(node);
    int DoubleChildNum = 0;
    TreeNode *buff = NULL;
    while (q.size() != 0)
    {
        node = q.front();
        visit(node);
        buff = node->L;
        node->L = node->R;
        node->R = buff;
        
        if (node->L != NULL)
        {
            q.push(node->L);
        }
        if (node->R != NULL)
        {
            q.push(node->R);
        }
        q.pop();
    }
}
int Find_K_LTravel(TreeNode * node,int num)
{
    static int k = 0;
    if (node == NULL){
        return -1;
    }
    std::stack<TreeNode *> s;
    s.push(node);
    while (s.size() != NULL)
    {
        if (node != NULL){
            k++;
            if (k == num){
                //return node->data;
            }
            visit(node);
            s.push(node);
            node = node->L;
        }
        else{
            node=s.top();
            node = node->R;
            s.pop();
        }
    }
    return 0;
}
void TreeDestory(TreeNode * &node)
{
    if (node == NULL)
    {
        return;
    }
    TreeDestory(node->L);
    TreeDestory(node->R);
    delete node;
    node = NULL;
}
void DeleteNumAndChildTree(TreeNode * &node,int num)
{
    if (node == NULL)
    {
        return;
    }
    if (node->data == num)
    {
        std::cout << "TreeDestory(node); \n";
        TreeDestory(node);
        //node = NULL;
        return;
    }
    DeleteNumAndChildTree(node->L,num);
    DeleteNumAndChildTree(node->R,num);

}
void Travel_H_Visit_Parent(TreeNode * node,int num)
{
    static int flag = 0;
    if (node == NULL)
    {
        return;
    }
    if (flag == 1)
    {
        visit(node);
        return;
    }
    Travel_H_Visit_Parent(node->L,num);
    if (flag == 1)
    {
        visit(node);
        return;
    }
    Travel_H_Visit_Parent(node->R,num);
    if (node->data==num||flag==1)
    {
        visit(node);
        flag = 1;
    }
}
void VisitNumParent(TreeNode * node)
{
    if (node == NULL)
    {
        return;
    }
    std::stack<TreeNode*>s;
    TreeNode* buff = NULL;
    //s.push(node);
    static int i = 0;
    while (s.size() != 0 ||node!=NULL)
    {
        if (node != NULL)
        {
            s.push(node);
            node = node->L;
        }
        else
        {
            node = s.top();
            if (node->R == NULL||buff==node->R)
            {
                visit(node);
                s.pop();
                buff = node;
                node = NULL;
            }
            else
            {
                node = node->R;
            }
        }
        if (i++ > 20)
        {
            break;
        }
    }
}
void StoreParentNode(TreeNode * _root,TreeNode * node,std::queue<TreeNode*> & ParentStack)
{
    if (_root == NULL)
    {
        std::cout << "node == NULL \n";
        return;
    }
    std::stack<TreeNode*>s;
    TreeNode* buff = NULL;
    //s.push(node);
    static int i = 0;
    while (s.size() != 0 || _root != NULL)
    {
        if (_root != NULL)
        {
            s.push(_root);
            _root = _root->L;
        }
        else
        {
            _root = s.top();
            if (_root == node)
            {
                break;
            }
            if (_root->R == NULL || buff == _root->R)
            {
                visit(_root);
                
                s.pop();
                buff = _root;
                _root = NULL;
            }
            else
            {
                _root = _root->R;
            }
        }

    }
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        ParentStack.push(s.top());
        s.pop();
    }
    
}
TreeNode * FindParentNode(TreeNode * _root,TreeNode * node1, TreeNode * node2)
{
    std::queue<TreeNode*> ParentStack1, ParentStack2;
    StoreParentNode(_root,node1, ParentStack1);
    StoreParentNode(_root,node2, ParentStack2);
    TreeNode* buff1;
    TreeNode* buff2;
    std::cout << "ParentStack1.size():"<<ParentStack1.size()<<" ParentStack2.size():"<< ParentStack2.size()<<"\n";
    while(ParentStack1.size()!=0 && ParentStack2.size() != 0)
    {
        if (ParentStack1.size() > ParentStack2.size())
        {
            ParentStack1.pop();
        }
        else if(ParentStack1.size() < ParentStack2.size())
        {
            ParentStack2.pop();
        }
        else
        {
            buff1 = ParentStack1.front();
            buff2 = ParentStack2.front();
            std::cout << "buff1 node value:" << buff1->data<<" ParentStack1.size():" << ParentStack1.size() << "\n";
            std::cout << "buff2 node value:" << buff2->data << " ParentStack2.size():" << ParentStack2.size()<<"\n";
            if (buff1 == buff2)
            {
                std::cout << "parent node value:"<< buff2->data<<"\n";
                return buff2;
            }
            ParentStack1.pop();
            ParentStack2.pop();
        }
    }
    return NULL;
}
int GetTreeWidth(TreeNode * node)
{
    if (node == NULL)
    {
        return -1;
    }
    std::queue<TreeNode *> s;
    TreeNode * buff = NULL;
    s.push(node);
    int MaxSize = 1;
    while (s.size() != 0 )
    {
            int size = s.size();
            MaxSize = MaxSize > size ? MaxSize : size;
            while (size!=0)
            {
                size--;
                node = s.front();
                s.pop();
                visit(node);
                if (node->L != NULL) { s.push(node->L); }
                if (node->R != NULL) { s.push(node->R); }
            }
    }
    return MaxSize;
}
void PreToPost(int *Pre,int l1,int h1,int *Post,int l2,int h2)
{
    if (l1 <= h1)
    {
        Post[h2] = Pre[l1];
        int half = (h1 - l1) / 2;
        PreToPost(Pre, l1 + 1, l1 + half, Post, l2, l2 + half - 1);
        PreToPost(Pre, l1 + half + 1, h1, Post, l2 + half, h2 - 1);
    }
}
void TestPreToPost()
{
    const int Num = 7;
    int Pre[Num] = {1,2,4,5,3,6,7};
    int Post[Num] = { 0 };
    int l1 = 0;
    int h1 = 6;
    int l2 = 0;
    int h2 = 6;
    PreToPost(Pre,l1,h1,Post,l2,h2);
    //std::cout << "Post[" << 0 << "] :"  << "\n";
    for (int i = 0; i < Num; i++)
    {
        std::cout << "Post["<<i<<"] :"<<Post[i]<<"\n";
    }
}
void visitLeafNode(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    if (node->L == NULL && node->R == NULL)
    {
        
        visit(node);
    }
    visitLeafNode(node->L);
    visitLeafNode(node->R);
}
int JudgeSilmar(TreeNode *node1, TreeNode *node2)
{
    if (node1 == NULL && node2 == NULL)
    {
        return 1;
    }
    if ((node1 == NULL && node2 != NULL)||(node2 == NULL && node1 != NULL))
    {
        return 0;
    }
    int L=JudgeSilmar(node1->L, node2->L);
    int R=JudgeSilmar(node1->R, node2->R);
    return L && R;
}
int main()
{
    
    //TestPreToPost();
    //CreateTreeBy_PreIn();
    TreeNode *_root = new TreeNode[1];
    memset(_root,0, sizeof(TreeNode));
    TreeNode *_root2 = new TreeNode[1];
    memset(_root2, 0, sizeof(TreeNode));
    const int size = 10;
    const int size2 = 10;
    ElemType data[size] =  {  1,2,3,4, 5, 6, 7, 8, 12, 9 };
    ElemType data2[size2] = { 5,6,7,8, 9, 6, 7, 8, 12,3  };
    //ElemType data[size] = { 1,3,4,5,6,-3,15,20,25 };
    InitTree(data, size, &_root);
    InitTree(data2, size2, &_root2);
    std::cout<<"JudgeSilmar: "<<JudgeSilmar(_root, _root2)<<"\n";
    std::cout << "value: \n";
    //visitLeafNode(_root);
    std::cout << "value: \n";
    //std::cout<<" result:"<<Judge_CompleteBinTree(_root)<<"\n";
    //std::cout << "CountDoubleChild:"<<CountDoubleChild(_root)<<"\n";
    //Travel_L(_root);
    //Travel_L(_root);
    
    //Travel_H_Visit_Parent(_root,7);
    //DeleteNumAndChildTree(_root,2);
    
    //SwapChild(_root);
    //Travel_M(_root);
    int value = 0;
    TreeNode *node1 = _root->L->L->L;
    TreeNode *node2 = _root->R->R;
    std::cout<<"Tree Width: "<<GetTreeWidth(_root)<<"\n";
    //value=FindParentNode(_root,node1, node2)->data;
    //VisitNumParent(_root);
    //Find_K_LTravel(_root, 5);
    std::cout << "Find_K_LTravel: value:"<< value<<"\n";
    //Find_K_LTravel(_root,5, value);
    //std::cout << "value:"<< Find_K_LTravel(_root, 5) <<"\n";
    //Travel_L(_root);
    //printf(" _root->R->data:%d \n",_root->R->data);
    //Travel_L(_root);
    //Travel_M(_root);
    //std::cout<<"GetTreeHeight(_root):"<<GetTreeHeight(_root);
   // Travel_H_Iteration(_root);
   // Travel_L_Iteration_2(_root);
   // Travel_L(_root);
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
void printInfo2(shared_ptr<context> &var)
{
    std::cout << "printInfo2 var.use_count():" << var.use_count() << "\n";
}
void printInfo(shared_ptr<context> &var)
{
    shared_ptr<context> var4(new(context));
    var4->data = new int[1];
    *(var4->data) = 4;
    std::cout << "printInfo var.use_count():" << var.use_count() << " *(var->data)" << *(var->data) << "\n";
    var = var4;
    std::cout << "printInfo var.use_count():" << var.use_count() << " *(var->data)" << *(var->data) << "\n";
    printInfo2(var);
    std::cout << "printInfo var.use_count():" << var.use_count() << " *(var->data)" << *(var->data) << "\n";

}
void smart_ptr()
{
    {
        shared_ptr<context> var(new(context));
        shared_ptr<context> var2(new(context));
        shared_ptr<context> var3(new(context));
        const int size = 64 * 1024 * 1024;
        var->data = new int[size];
        var2->data = new int[size];
        var3->data = new int[size];
        *(var->data) = 1;
        *(var2->data) = 2;
        *(var3->data) = 3;

        std::cout << "var.use_count():" << var.use_count() << "\n";
        std::cout << "var2.use_count():" << var2.use_count() << "\n";
        std::cout << "var3.use_count():" << var3.use_count() << "\n";
        var3 = var;
        std::cout << "\n \n";
        std::cout << "var.use_count():" << var.use_count() << "\n";
        std::cout << "var2.use_count():" << var2.use_count() << "\n";
        std::cout << "var3.use_count():" << var3.use_count() << "\n";
        var2 = var;
        std::cout << "\n \n";
        std::cout << "var.use_count():" << var.use_count() << " *(var->data)" << *(var->data) << "\n";
        std::cout << "var2.use_count():" << var2.use_count() << " *(var2->data)" << *(var2->data) << "\n";
        std::cout << "var3.use_count():" << var3.use_count() << " *(var3->data)" << *(var3->data) << "\n";


        printInfo(var);
        std::cout << "var.use_count():" << var.use_count() << " *(var->data)" << *(var->data) << "\n";
        std::cout << "var.use_count():" << var.use_count() << "\n";
        std::cout << "var2.use_count():" << var2.use_count() << " *(var2->data)" << *(var2->data) << "\n";
        std::cout << "var3.use_count():" << var3.use_count() << "\n";
    }
}
