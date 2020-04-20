// 先序遍历

// 已知二叉树按照二叉链表方式存储，利用栈的基本操作写出先序遍历非递归形式的算法：

// void pre_order(BiTree root);
// 在遍历过程中，pre_order函数需要调用 visit_node 函数来实现对结点的访问，该函数声明如下：

// void visit_node(BiTNode *node);
// 二叉树的相关定义如下：

// typedef int DataType;

// typedef struct Node{
//     DataType data;
//     struct Node* left;
//     struct Node* right;
// }BiTNode, *BiTree;
// 遍历所使用栈的相关操作如下：

// #define Stack_Size 50
// typedef BiTNode* ElemType;
// typedef struct{
//     ElemType elem[Stack_Size];
//     int top;
// }Stack;

// void init_stack(Stack *S); // 初始化栈
// bool push(Stack* S, ElemType x); //x 入栈
// bool pop(Stack* S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
// bool top(Stack* S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
// bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 false
#include <stdlib.h>
#include <stdio.h>
#include "bitree.h" //请不要删除，否则检查不通过
void pre_order(BiTree root){
    BiTree tp=root;
    Stack *s;
    init_stack(s);
    while(tp||!is_empty(s))
    {
        if(tp!=NULL)
        {
            visit_node(tp);
            push(s,tp);
            tp=tp->left;
        }
        else
        {
            pop(s,tp);
            tp=tp->right;
        }
    }
}