#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
using namespace std;
#define ElemType int
#define maxsize 100
#define InfoType int
#define MAXV 100
#define MaxSize 100
#define INF 214748364 
#define INFINITE INF

typedef struct ANode
{
    int adjvex;            //该边的邻接点的编号，即有向边指向的顶点编号
    struct ANode* nextarc; //指向下一条边的指针
    int weight;            //边的相关的信息，如权值
} ArcNode;                 //边节点的类型

typedef struct Vnode
{
    InfoType info;     //顶点的其他信息
    int count;         //存放顶点入度
    ArcNode* firstarc; //指向第一个边节点
} VNode;               //邻接表的头节点的结构体类型

typedef struct
{
    VNode adjlist[MAXV]; //头节点的数组
    int n, e;            //图的顶点数和边数
} AdjGraph;              //整个邻接表的数据结构体类型

typedef struct SSS
{
    ElemType data[maxsize];
    int front;
    int rear;
} SqQueue; //队列的结构体

typedef struct head
{
    int u; //边的起始顶点
    int v; //边的终止顶点
    int w; //边的权值
} Edge;

int visited[MAXV] = { 0 };

void InitQueue(SqQueue*& q);
void DestoryQueue(SqQueue*& q);
bool QueueEmpty(SqQueue* q);
bool enQueue(SqQueue*& q, ElemType e);
bool deQueue(SqQueue*& q, ElemType& e);

void InitQueue(SqQueue*& q)
{
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

void DestoryQueue(SqQueue*& q)
{
    free(q);
}

bool QueueEmpty(SqQueue* q)
{
    return (q->front == q->rear);
}

bool enQueue(SqQueue*& q, ElemType e)
{
    if ((q->rear + 1) % maxsize == q->front)
        return false;
    q->rear = (q->rear + 1) % maxsize;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue*& q, ElemType& e)
{
    if (q->front == q->rear)
        return false;
    q->front = (q->front + 1) % maxsize;
    e = q->data[q->front];
    return true;
}

void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    ArcNode* p;
    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++) {
        G->adjlist[i].firstarc = NULL;
    }
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= 0; j--) {
            if (A[i][j] != 0 && A[i][j] != INF)
            {
                p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

void DispAdj(AdjGraph* G) //输出邻接表G
{
    int i;
    ArcNode* p;
    for (i = 0; i < G->n; i++){
        p = G->adjlist[i].firstarc;
        cout << i << ":   ";
        while (p != NULL)
        {
            if (p->weight != 2147483647) 
                cout<<p->adjvex<<'['<<p->weight<<']'<<" ";
            p = p->nextarc;
        }
        cout << endl;
    }
}

void DestroyAdj(AdjGraph*& G) //销毁邻接表
{
    int i;
    ArcNode* pre, * p;
    for (i = 0; i < G->n; i++) {
        pre = G->adjlist[i].firstarc; 
        if (pre != NULL)
        {
            p = pre->nextarc;
            while (p != NULL) 
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}

void DFS(AdjGraph* G, int v)
{
    ArcNode* p;
    visited[v] = 1;
    cout << v<<" ";
    p = G->adjlist[v].firstarc;
    while (p != NULL) 
    {
        if (visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

void BFS(AdjGraph* G, int v)
{
    int w, i;
    ArcNode* p;
    SqQueue* qu;
    InitQueue(qu);
    int visited[MAXV];
    for (i = 0; i < G->n; i++)
        visited[i] = 0;
    cout << v<<" ";
    visited[v] = 1;
    enQueue(qu, v);
    while (!QueueEmpty(qu))
    {
        deQueue(qu, w);
        p = G->adjlist[w].firstarc;
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0)
            {
                cout<<p->adjvex<<" ";
                visited[p->adjvex] = 1;
                enQueue(qu, p->adjvex);
            }
            p = p->nextarc;
        }
    }
    cout << endl;
}

int main()
{
    int a[4][MAXV] = { {0, 1, 1, 1},{1, 0, 1, 1},{1, 1, 0, 0},{1, 1, 0, 0} };
    AdjGraph* g;
    CreateAdj(g, a, 4, 5);
    cout << "这是原始邻接表的结构:"<<endl;
    DispAdj(g);
    cout << "this is the Deep fist search (from '0'):" << endl;
    DFS(g, 0);
    cout << endl;
    cout<<"this is the Broad fist search (from '0): "<<endl;
    BFS(g, 0);
    system("pause");
    return 0;
}
