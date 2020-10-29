#include<iostream>
#include<stack>
#include<fstream>
#include<string>
#define MAX 100000
#define TRUE 0;
#define FALSE -1;
using namespace std;

int Match_Brackets(string p) {
	stack<char>sq;                //创建字符型栈
	if (!sq.empty())
		sq.pop();
	int len = p.length(), flag = 1;
	for (int i = 0; i < len; i++) {
		if (p[i] == '(' || p[i] == '[' || p[i] == '{')
			sq.push(p[i]);                            //将左括号压入栈
		else {
			if (p[i] == ')' ) {
				if (sq.empty()) {
					flag = 0;
					break;
				}
				else {
					char t = sq.top();
					sq.pop();
					if (t != '(') {
						flag = 0;
						break;
					}
				}
			}
			else if (p[i] == ']') {
				if (sq.empty()) {
					flag = 0;
					break;
				}
				else {
					char t = sq.top();
					sq.pop();
					if (t != '[') {
						flag = 0;
						break;
					}
				}
			}
			else if (p[i] == '}') {
				if (sq.empty()) {
					flag = 0;
					break;
				}
				else {
					char t = sq.top();
					sq.pop();
					if (t != '{') {
						flag = 0;
						break;
					}
				}
			}
		}
	}
	if (!sq.empty())
		flag = 0;
	if (flag == 1) {
		return TRUE;
	}
	return FALSE; 
}

int main()
{
	string* strs = new string[MAX];
	ifstream infile("C:\\Users\\59217\\Desktop\\常用\\数据结构基础\\第四次上机作业\\作业4数据集v0.2\\括号匹配\\string.txt");
	for (int i = 0; i < MAX; i++) {
		infile >> strs[i];
		cout << strs[i] << endl;
		cout<<Match_Brackets(strs[i]) << endl ;
	}
	return 0;
}