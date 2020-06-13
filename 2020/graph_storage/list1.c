// 邻接表1

// 试在邻接表存储结构上实现图的基本操作 insert_vertex 和 insert_arc，相关定义如下：

// typedef int VertexType;

// typedef enum{
//     DG, UDG
// }GraphType;

// typedef struct ArcNode
// {
//     int adjvex;
//     InfoPtr *info;
//     struct ArcNode *nextarc;

// }ArcNode;

// typedef struct VNode
// {
//     VertexType data;
//     ArcNode *firstarc;
// }VNode;
// typedef struct
// {
//     VNode vertex[MAX_VERTEX_NUM];
//     int vexnum, arcnum;
//     GraphType type;
// }ListGraph;

// int locate_vertex(ListGraph* G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
// bool insert_vertex(ListGraph *G, VertexType v);
// bool insert_arc(ListGraph *G, VertexType v, VertexType w);
// 当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。
#include "graph.h" //请勿删除，否则检查不通过
#include <stdio.h>

bool insert_vertex(ListGraph* G, VertexType v)
{
    if (G->vexnum == MAX_VERTEX_NUM)
        return false;
    if (locate_vertex(G, v) == -1) {
        G->vertex[G->vexnum].data = v;
        G->vertex[G->vexnum].firstarc = NULL;
        G->vexnum++;
        return true;
    } else
        return false;
}

bool insert_arc(ListGraph* G, VertexType v, VertexType w)
{
    int m = locate_vertex(G, v);
    int n = locate_vertex(G, w);
    int flag = 0;
    ArcNode *p, *temp;
    if (m == -1 || n == -1)
        return false;
    for (p = G->vertex[m].firstarc; p; p = p->nextarc)
        if (p->adjvex == n)
            flag = 1;
    for (p = G->vertex[n].firstarc; p; p = p->nextarc)
        if (p->adjvex == m)
            flag *= flag;
    if (flag)
        return false;
    G->arcnum++;
    for (p = G->vertex[m].firstarc; p->nextarc; p = p->nextarc)
        ;
    temp = (ArcNode*)malloc(sizeof(ArcNode));
    p->nextarc = temp;
    temp->adjvex = n;
    temp->nextarc = NULL;
    temp->info = NULL;
    if (G->type == UDG) {
        for (p = G->vertex[n].firstarc; p->nextarc; p = p->nextarc)
            ;
        temp = (ArcNode*)malloc(sizeof(ArcNode));
        p->nextarc = temp;
        temp->adjvex = m;
        temp->nextarc = NULL;
        temp->info = NULL;
    }
    return true;
}