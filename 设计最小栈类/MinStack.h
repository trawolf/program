#pragma once
#include<iostream>

const int length = 100;
class MinStack
{
private:
	int* xx;
	int count = 0;
public:
	MinStack() {
		xx = new int[length];
	}
	//将元素x推入栈中
	void push(int x) {
		xx[count] = x;
		count++;
	}
	//删除栈顶的元素
	void pop() {
		count--;
	}
	//获取栈顶元素
	int top() {
		return xx[count-1];
	}
	//检索栈中的最小元素
	int getMin() {
		int min = xx[0];
		for (int i = 1; i < count; i++) {
			if (min >= xx[i]) {
				min = xx[i];
			}
		}
		return min;
	}
};

