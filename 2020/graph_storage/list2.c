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

bool del_vertex(ListGraph* G, VertexType v)
{

    int loc = locate_vertex(G, v);
    if (loc == -1)
        return false;
    while (G->vertex[loc].firstarc) {
        ArcNode* p = G->vertex[loc].firstarc;
        if (p->nextarc) {
            ArcNode* pNode = p->nextarc;
            p->nextarc = pNode->nextarc;
            free(pNode);
            G->arcnum--;
        } else {
            free(p);
            G->vertex[loc].firstarc = NULL;
            G->arcnum--;
        }
    }

    for (int i = 0; i < G->vexnum; i++) {
        ArcNode* p = G->vertex[i].firstarc;
        ArcNode *temp = NULL, *pre = NULL; //temp表示要删除的结点
        while (p) {
            if (p->adjvex == loc) {
                if (!pre) {
                    temp = p;
                    G->vertex[i].firstarc = p->nextarc;
                    p = p->nextarc;
                } else {
                    pre->nextarc = p->nextarc;
                    temp = p;
                    p = p->nextarc;
                }
                free(temp);
                G->arcnum--;
            } else {
                pre = p;
                p = p->nextarc;
            }
        }
    }
    for (int i = loc; i < G->vexnum; i++) { //表头结点中，后面的向前移动
        G->vertex[i] = G->vertex[i + 1];
    }
    G->vexnum--;
    return true;
}