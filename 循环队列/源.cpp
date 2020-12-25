#include<iostream>
using namespace std;
#define MAX_QUEUE_SIZE 10

typedef struct queue{
	int count;                                              //队列长度
	int* base;                                             //初始化的动态分配存储空间
	int front;                                             //头指针，若队列不空，指向队列头元素
	int rear;                                               //尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;

void InitQueue(SqQueue* ptr) {
	ptr->front = ptr->rear =ptr->count = 0;
	ptr->base = new int[MAX_QUEUE_SIZE];
}

int QueueLength(SqQueue *Q) {                           //返回Q的元素个数，即队列长度
	return Q->count;
}

bool QueueFull(SqQueue *Q) {                                 //判断Q是否满
	return QueueLength(Q) >= MAX_QUEUE_SIZE;
}
bool QueueEmpty(SqQueue *Q) {                              //判断Q是否为空
	return QueueLength(Q) <= 0;
}

void EnQueue(SqQueue* Q, int e) {                             //入队
	if (QueueFull(Q))
		cout << "队列满了!" << endl;
	else {
		Q->count++;
		Q->base[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
	}
}

void DeQueue(SqQueue* Q) {                           //出队
	if (QueueEmpty(Q))
		cout << "队列为空!" << endl;
	else {
		Q->count--;
		Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;
	}
}

void Display(SqQueue* ptr) {
	if (QueueEmpty(ptr))
		cout << "队列为空！" << endl;
	else {
		int i = ptr->front;
		while (i != ptr->rear) {
			cout << ptr->base[i] << " ";
			i++;
			i = i % MAX_QUEUE_SIZE;
		}
	}
	cout << endl;
}

int main()
{
	SqQueue* input = (SqQueue*)malloc(sizeof(int));
	InitQueue(input);
	EnQueue(input, 11);
	EnQueue(input, 5);
	EnQueue(input, 23);
	EnQueue(input,18);
	DeQueue(input);
	Display(input);
	EnQueue(input,33);
	DeQueue(input);
	Display(input);
	EnQueue(input, 77);
	Display(input);
	return 0;
}