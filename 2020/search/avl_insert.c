// AVL添加

// 平衡二叉树，是一种二叉排序树，其中每个结点的左子树和右子树的高度差至多等于1。它是一种高度平衡的二叉排序树。现二叉平衡树结点定义如下：

// typedef struct node
// {
//     int val;
//     struct node *left;
//     struct node *right;
//     struct node *parent;
//     int height;
// } node_t;
// 请实现平衡二叉树的插入算法：

// //向根为 root 的平衡二叉树插入新元素 val，成功后返回新平衡二叉树根结点
// node_t *avl_insert(node_t *root, int val); 

#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

int getHeight(node_t *root){
    int height=0;
    if(root)
    height=root->height;
    return height;
}
int getMax(int a,int b){
    return a>b?a:b;
}
node_t *LL(node_t *root){
    node_t *child=root->left;
    root->left=child->right;
    child->right=root;
    root->height=getMax(getHeight(root->left),getHeight(root->right))+1;
    child->height=getMax(getHeight(child->left),root->height)+1;
    return child;
}
node_t *RR(node_t *root){
    node_t *child=root->right;
    root->right = child->left;
    child->left = root;
    root->height = getMax(getHeight(root->left), getHeight(root->right)) + 1;
    child->height = getMax(root->height, getHeight(child->right)) + 1;
    return child;
}
node_t *RL(node_t *root){
    root->right=LL(root->right);
    return RR(root);
}
node_t *LR(node_t *root){
    root->left=RR(root->left);
    return LL(root);
}
node_t *NewNode(int val){
    node_t *newnode=(node_t*)malloc(sizeof(node_t));
    newnode->val=val;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->parent=NULL;
    newnode->height=0;
    return newnode;
}
node_t* avl_insert(node_t *root, int val){
    if(!root)
    root=NewNode(val);
    else if(val<root->val){
        root->left=avl_insert(root->left,val);
        if(getHeight(root->left)-getHeight(root->right)==2){
            if(val<root->left->val)
            root=LL(root);
            else
            root=LR(root);
        }
    }else if(val>root->val){
        root->right=avl_insert(root->right,val);
        if(getHeight(root->right)-getHeight(root->left)==2){
            if(val>root->right->val)
            root=RR(root);
            else
            root=RL(root);
        }
    }
    root->height=getMax(getHeight(root->left),getHeight(root->right))+1;
    return root;
}