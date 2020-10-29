#include<iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;
#define MAX 20			//多项式最多项数


typedef struct  	//定义存放多项式的数组类型
{
    double coef;		//系数
    int expn;			//指数
} PolyArray;

typedef struct pnode	//定义单链表结点类型，保存多项式中的一项，链表构成多项式
{
    double coef;		//系数
    int expn;			//指数
    struct pnode* next;
} PolyNode;

void PrintPoly(PolyNode* L)	//输出多项式
{
    bool first = true;		//first为true表示是第一项
    PolyNode* p = L->next;
    while (p != NULL)
    {
        if (first)
            first = false;
        else if (p->coef > 0||p->coef==0)
            cout << "+";
        if (p->coef != 0) {
            if (p->expn == 0)
                cout << p->coef;
            else if (p->expn == 1)
                cout << p->coef << "x";
            else
                cout << p->coef << "x^" << p->expn;
        }
        else cout << "0";
        p = p->next;
    } 
    cout << endl;
}

/*int GetLength(PolyNode& p) {
    int length = 1;
    while (p.next != nullptr)
        length++;
    return length;
}
*/

void DestroyList(PolyNode*& L)	//销毁单链表
{
    PolyNode* p = L, * q = p->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
}

void CreateListR(PolyNode*& L, PolyArray a[], int n) //尾插法建表
{
    PolyNode* s, * r;
    int i;
    L = (PolyNode*)malloc(sizeof(PolyNode));	//创建头结点
    L->next = NULL;
    r = L;						//r始终指向终端结点,开始时指向头结点
    for (i = 0; i < n; i++)
    {
        s = (PolyNode*)malloc(sizeof(PolyNode));//创建新结点
        s->coef = a[i].coef;
        s->expn = a[i].expn;
        r->next = s;				//将*s插入*r之后
        r = s;
    }
    r->next = NULL;				//终端结点next域置为NULL
}

void Sort(PolyNode*& head)		//按exp域递减排序
{
    PolyNode* p = head->next, * q, * r;
    if (p != NULL)				//若原单链表中有一个或以上的数据结点
    {
        r = p->next;				//r保存*p结点后继结点的指针
        p->next = NULL;			//构造只含一个数据结点的有序表
        p = r;
        while (p != NULL)
        {
            r = p->next;			//r保存*p结点后继结点的指针
            q = head;
            while (q->next != NULL && q->next->expn > p->expn)
                q = q->next;		//在有序表中找插入*p的前驱结点*q
            p->next = q->next;	//将*p插入到*q之后
            q->next = p;
            p = r;
        }
    }
}

void Check(PolyNode*& p) {
    for (PolyNode* i = p; i != NULL; i = i->next) {
        for (PolyNode* j = i->next; j != NULL; j = j->next) {
            if (i->expn == j->expn) {
                j->coef += i->coef;            //指数相同系数相加
                PolyNode* c = p;
                while (c->next && c->next != i)
                    c = c->next;                   //确定i的直接前驱
                c->next = c->next->next;
                c->next->next = NULL;    //从列表中删除i
            }
        }
    }
}

void AddPolyn(PolyNode* ha, PolyNode* hb, PolyNode*& hc)  //求两有序集合的并，完成加法
{
    PolyNode* pa = ha->next, * pb = hb->next, * s, * tc;
    double c;
    hc = (PolyNode*)malloc(sizeof(PolyNode));		//创建头结点
    tc = hc;
    while (pa != NULL && pb != NULL)
    {
        if (pa->expn > pb->expn)
        {
            s = (PolyNode*)malloc(sizeof(PolyNode));	//复制结点
            s->expn = pa->expn;
            s->coef = pa->coef;
            tc->next = s;
            tc = s;
            pa = pa->next;
        }
        else if (pa->expn < pb->expn)
        {
            s = (PolyNode*)malloc(sizeof(PolyNode));	//复制结点
            s->expn = pb->expn;
            s->coef = pb->coef;
            tc->next = s;
            tc = s;
            pb = pb->next;
        }
        else				//pa->exp=pb->exp
        {
            c = pa->coef + pb->coef;
            if (c != 0)		//系数之和不为0时创建新结点
            {
                s = (PolyNode*)malloc(sizeof(PolyNode));	//复制结点
                s->expn= pa->expn;
                s->coef = c;
                tc->next = s;
                tc = s;
            }
            pa = pa->next;
            pb = pb->next;
        }
    }
    if (pb != NULL) pa = pb;	//复制余下的结点
    while (pa != NULL)
    {
        s = (PolyNode*)malloc(sizeof(PolyNode));	//复制结点
        s->expn = pa->expn;
        s->coef = pa->coef;
        tc->next = s;
        tc = s;
        pa = pa->next;
    }
    tc->next = NULL;
}

void MultiplyPolyn(PolyNode* ha, PolyNode* hb, PolyNode*& hc) {
    PolyNode* pa = ha->next, * pb = hb->next, * tc, * s;
    hc = (PolyNode*)malloc(sizeof(PolyNode));		//创建头结点
    tc = hc;
   while(pa!=NULL){
       while ( pb != NULL) {
           s = (PolyNode*)malloc(sizeof(PolyNode));	//复制结点
           s->coef = pa->coef * pb->coef;
           s->expn = pa->expn + pb->expn;
           tc->next = s;
           tc = s;
           pb = pb->next;
       }
       pa = pa->next;
       pb = hb->next;
    }
   tc->next = NULL;
   Sort(hc);
   Check(hc);
}

void ParPolyn(PolyNode* ha, PolyNode*& hc) {
    PolyNode* pa = ha->next, *s, * tc;
    hc = (PolyNode*)malloc(sizeof(PolyNode));
    tc = hc;
    while (pa != NULL) {
        s = (PolyNode*)malloc(sizeof(PolyNode));
        s->coef = pa->coef * pa->expn;
        s->expn = pa->expn - 1;
        tc->next = s;
        tc = s;
        pa = pa->next;
    }
    tc->next = NULL;
}

int main()
{
    PolyNode* ha, * hb, * hc, * hd, * he;
    PolyArray* a = new PolyArray[MAX];
    PolyArray * b=new PolyArray[MAX];

    cout << "输入第一个多项式的参数: "<<endl ;
    int judge1 = 0, count1 = 0;
    while (judge1 == 0) {
        int coef, expn;
        cin >> coef >> expn;
        a[count1].coef = coef;
        a[count1].expn = expn;
        count1++;
        char YesorNo;
        cout << "是否继续输入";
        cin >> YesorNo;
        if (YesorNo == 'y')
            judge1 = 0;
        else judge1 = 1;
    }

    cout << "输入第二个多项式的参数："<<endl ;
    int judge2 = 0, count2 = 0;
    while (judge2 == 0) {
        int coef, expn;
        cin >> coef >> expn;
        b[count2].coef = coef;
        b[count2].expn = expn;
        count2++;
        char YesorNo;
        cout << "是否继续输入";
        cin >> YesorNo;
        if (YesorNo == 'y')
            judge2 = 0;
        else judge2 = 1;
    }
   
    CreateListR(ha, a, count1);
    CreateListR(hb, b, count2);
    cout << "原多项式A:   ";
    PrintPoly(ha);
    cout << "原多项式B:   ";
    PrintPoly(hb);

    Sort(ha);
    Check(ha);
    cout << "有序多项式A: ";
    PrintPoly(ha);
    Sort(hb);
    Check(hb);
    cout << "有序多项式B: ";
    PrintPoly(hb);

    AddPolyn(ha, hb, hc);
    cout << "多项式相加:  ";
    PrintPoly(hc);

    MultiplyPolyn(ha, hb, hd);
    cout << "多项式相乘：";
    PrintPoly(hd);

    ParPolyn(ha, he);
    cout << "第一个多项式的一阶导：";
    PrintPoly(he);

    DestroyList(ha);
    DestroyList(hb);
    DestroyList(hc);
    DestroyList(hd);
    DestroyList(he);
    return 0;
}