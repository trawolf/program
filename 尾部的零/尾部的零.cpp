// 尾部的零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int func(int number,int counter) {
    int add=0;
    if (func(number,counter) % 5 == 0) {
        number = number / 5;
        add++;
        counter ++;
    }
    cout << add;
    return number;
}

int main()
{
    int n;
    cin >> n;
    int counter = 0;
    for (int i = 1; i <= n; i++) {
        func(i,counter);
    }
    cout << counter;
    return 0;
}
