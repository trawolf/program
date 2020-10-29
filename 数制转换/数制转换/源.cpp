#include<iostream>
#include<stack>
#include<fstream>
#define MAX 100000
using namespace std;

void conversion(int n, int d) {              //将十进制整数n转化为d进制整数
	stack<int>sq;
	int k;
	while (n > 0) {
		k = n % d;
		n /= d;
		sq.push(k);
	}
	while (!sq.empty()) {
		cout << sq.top();
		sq.pop();
	}
	cout << endl;
}

int main()
{
	ifstream infile1("C:\\Users\\59217\\Desktop\\常用\\数据结构基础\\第四次上机作业\\作业4数据集v0.2\\数制转换\\dec.txt");
	int* nums = new int[MAX];
	for (int i = 0; i < MAX; i++) {
		infile1 >> nums[i];
		cout << "待转换十进制数：";
		cout << nums[i] << endl;
		cout << "输出二进制数：";
		conversion(nums[i], 2);
		cout << "输出八进制数：";
		conversion(nums[i], 8);
		cout << "输出十六进制数：";
		conversion(nums[i], 16);
		cout << endl;
	}
	return 0;
}