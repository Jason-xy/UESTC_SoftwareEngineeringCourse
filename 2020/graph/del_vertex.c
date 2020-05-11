// 邻接表2

// 试在邻接表存储结构上实现图的基本操作 del_vertex，相关定义如下：

// typedef int VertexType;

// typedef enum{
//     DG, UDG
// }GraphType;

// typedef struct ArcNode{
//     int adjvex;
//     InfoPtr info;
//     struct ArcNode nextarc;
// }ArcNode;

// typedef struct VNode{
//     VertexType data;
//     ArcNode firstarc;
// }VNode;
// typedef struct{
//     VNode vertex[MAX_VERTEX_NUM];
//     int vexnum, arcnum;
//     GraphType type;
// }ListGraph;

// int locate_vertex(ListGraph *G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
// bool del_vertex(ListGraph *G, VertexType v); //删除顶点 v
// 当成功删除顶点或边时，函数返回true，否则（如顶点或边不存在、删除边时顶点v或w不存在）返回false。

#include "graph.h" //请勿删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

bool del_vertex(ListGraph* G, VertexType v)
{
    int del_v = locate_vertex(G, v);
    ArcNode *p1, *p2, *temp;
    if (del_v == -1)
        return false;
    for (p1 = G->vertex[del_v].firstarc; p1 != NULL;) {
        p2 = p1->nextarc;
        free(p1);
        p1 = p2;
    }
    G->vexnum--;
    for (int i = del_v; i < G->vexnum; i++) {
        G->vertex[i] = G->vertex[i + 1];
    }
    for (int i = 0; i < 0; i++) {
        p1 = G->vertex[i].firstarc;
        if (p1->adjvex == del_v) {
            p1 = G->vertex[i].firstarc->nextarc;
            temp = G->vertex[i].firstarc;
            free(temp);
            G->arcnum--;
            G->vertex[i].firstarc = p1;
        }
        for (p1 = G->vertex[i].firstarc; p1 != NULL; p1 = p1->nextarc) {
            if (p1->nextarc->adjvex == del_v) {
                p2 = p1->nextarc->nextarc;
                temp = p1->nextarc;
                free(temp);
                G->arcnum--;
                p1->nextarc = p2;
            } else {
                if (p1->adjvex > del_v)
                    p1->adjvex--;
            }
        }
    }
    return true;
}
