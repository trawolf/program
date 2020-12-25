#include<iostream>
#define MAX_SIZE 100
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

using namespace std;

typedef struct BiTNode {
	char data;
	struct BiTNode* rChild, * lChild;
}BiTNode, * BiTree;

bool Creat_BiTree(BiTree& T) {
	char ch;
	cout << "输入字符：" << endl;
	cin >> ch;
	if (ch == '0')
		T = nullptr;
	else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))
			return false;
		T->data = ch;
		Creat_BiTree(T->lChild);                            //构造左子树
		Creat_BiTree(T->rChild);                            //构造右子树
	}
	return true;
}

struct SqStack {
	BiTree* base;
	BiTree* top;
	int stack_size;
};

bool Init_Stack( SqStack s){
	s.base = (BiTree*)malloc(STACK_INIT_SIZE * sizeof(BiTree));
	if(!s.base)
		return false;
	s.top = s.base;
	s.stack_size = STACK_INIT_SIZE;
	return true;
}

bool Push(SqStack& s, BiTree e) {
	if (s.top - s.base >= s.stack_size) {
		s.base= (BiTree*)realloc(s.base ,(s.stack_size+STACKINCREMENT) * sizeof(BiTree));
		if (!s.base)
			return false;
		s.top = s.base + s.stack_size;
		s.stack_size += STACKINCREMENT;
	}
	*s.top++ = e;
	return true;
}

bool Pop(SqStack& s, BiTree& e) {
	if (s.top == s.base)
		return false;
	e = *--s.top;
	return true;
}

bool Stack_Empty(SqStack s) {
	if (s.base == s.top)
		return true;
	else 
		return false;
}

bool Visit(BiTree e) {
	cout << e->data;
	return true;
}

SqStack s;

int main() {
	bool(*point)(BiTree e);
	point = Visit;
	BiTree T;
	Creat_BiTree(T);
	cout << "二叉树构造完成" << endl;
	return 0;
}