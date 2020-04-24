// 12314.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

class Solution {
public:
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    int reverseInteger(int number) {
        // write your code here
        int a, b, c, output;
        a = number % 10;
        b = number / 100;
        c = number % 100 - a;
        output = a * 100 + b + c;
        return output;
    }
};
int main() {
    int number;
    cin >> number;
    if (number >= 100 && number <= 1000) {
        Solution result;
        cout << result.reverseInteger(number);
        return 0;
    }
}
