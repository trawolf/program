// 计算两个日期之间的天数 .cpp
//

#include<iostream>
#include"Date.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int  year1, month1, day1;
    int  year2, month2, day2;
    cin >> year1 >> month1 >> day1;
    cin >> year2 >> month2 >> day2;

    Date  d1(year1, month1, day1);
    Date  d2(year2, month2, day2);
    cout << d1 - d2 << endl;
    system("pause");
    return  0;
}