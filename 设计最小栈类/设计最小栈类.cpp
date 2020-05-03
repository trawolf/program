#include<iostream>
#include"MinStack.h"
using namespace std;


int main()
{
	int x;
	cin >> x;
	MinStack* obj = new MinStack();
	obj->push(x);
	cin >> x;
	obj->push(x);
	cin >> x;
	obj->push(x);
	cout << "getMin():" << obj->getMin() << endl;
	obj->pop();
	cout << "top():" << obj->top() << endl;
	cout << "getMin():" << obj->getMin() << endl;
	system("pause");
	return 0;
}

/*
【样例输入】 
- 2
0
- 3
【样例输出】
getMin() :-3
top() : 0
getMin() : -2
*/