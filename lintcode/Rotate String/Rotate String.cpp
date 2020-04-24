// Rotate String.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<math.h>
#include<string>
#include<cstring>
using namespace std;

class Solution {
public:
    void rotateString(char str[100], int offset) {
        // write your code here
        int counter = strlen(str);
        string result[1000];
        for (int i = 0; i < counter; i++) {
            result[i] = str[i];
        }
        for (int j = 0; j < counter - offset; j++) {
            result[counter + j] = str[j];
        }
        for (int k = counter - offset; k < 2*counter - offset; k++) {
            cout << result[k];
        }
    }
};

int main()
{
    char str[100];
    cin >> str;
    int offset;
    cin >> offset;
    Solution solution;
    solution.rotateString(str, offset);
    return 0;
}

