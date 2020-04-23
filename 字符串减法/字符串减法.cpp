// 字符串减法  .cpp
/*
【问题描述】请你编写一个函数，对字符串A和字符串B进行减法操作，减法操作是将A中所有的B依次删除，
并返回做减法后的新字符串指针，
函数原型如下：char* func(char* A, char* B);
【输入形式】
字符串A
字符串B
【输出形式】
减法后的新字符串
【样例输入一】
aaabbb
bb
【样例输出一】
aaab
【样例输入二】
aabbababb
ab
【样例输出二】
abb
【样例说明】 测试用例中两个字符串的长度均小于20大于0
【评分标准】五个测试用例平均打分
【注意】可以使用strlen()函数strcpy()函数等，但是请不要直接使用查找字符串的函数
*/

#include<iostream>
#include<cstring>
using namespace std;

char* func(char* , char* );

int main() 
{
    char  a[20], b[20];
    cin >> a >> b;
    char* res = func(a, b);
    cout << res << endl;
	return 0;
}

char* func(char* A, char* B) {
    int steps = strlen(A);
    for (int i = 0; i <steps; i++) {
        int count = 0;
        for (int j = i; j <i+ strlen(B); j++) {
            if (A[j] == B[j - i]) {
                count++;
            }
            else { break; }
        }
        if (steps - i< strlen(B)) {
            break;
        }
        else {
            if (count == strlen(B)) {
                for (int m = i; m < steps - strlen(B); m++) {
                    A[m] = A[m + strlen(B)];
                }
                steps -= strlen(B);
                i--;
            }
            else { continue; }
        }
    }
    char* result = new char[steps];
    for (int i = 0; i < steps; i++) {
        result[i] = A[i];
    }
    result[steps] = '\0';
    return result; 
}