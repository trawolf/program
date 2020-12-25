#include<iostream>
#define MAX_QUEUE_SIZE 10
using namespace std;

typedef struct QNode {
	int data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct {
	QueuePtr front;                                       //头指针
	QueuePtr rear;                                          //尾指针
}LinkQueue;

void InitQueue(LinkQueue *ptr) {
	ptr->front = new QNode;                                //创建一个头节点
    ptr->rear = ptr->front;                                           //头尾指针都指向头节点
	ptr->front->next = nullptr;
}

void EnQueue(LinkQueue* ptr, int e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = nullptr;
	ptr->rear->next = p;
	ptr->rear = p;
}

void DeQueue(LinkQueue* ptr) {
	if (ptr->front == ptr->rear)
		cout << "队列为空！" << endl;
	else{
		QNode* p = ptr->front->next;
		ptr->front->next = p->next;
		if (ptr->rear = p)
			ptr->rear = ptr->front;
		delete p;
	}
}

void Display(LinkQueue* ptr) {
	QNode* p = ptr->front->next;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	LinkQueue* Q=new LinkQueue;
	int e;
	InitQueue(Q);
	cin >> e;
	while (e != -1) {
		EnQueue(Q, e);
		cin >> e;
	}
	Display(Q);
	DeQueue(Q);
	Display(Q);
	cout << "取队头元素：" << Q->front->next->data<<" "<< endl;
	return 0;
}