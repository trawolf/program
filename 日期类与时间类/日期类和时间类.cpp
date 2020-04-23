// 日期类和时间类.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;

class Time;
class Date;

class Date {
private:
    int year, month, day;
public:
    friend void display(Date d, Time t);
    Date(int, int, int);
};
Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

class Time {
private:
    int hour, minute, second;
public:
    friend void display(Date d, Time t);
    Time(int, int, int);
};
Time::Time(int hour, int minute, int second) {
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

void display(Date date,Time time) {
    cout << date.year << "/" << date.month << "/" << date.day<<endl;
    cout << time.hour << ":" << time.minute << ":" << time.second<<endl;
}

int main()
{
    int  year, month, day;
    cin >> year >> month >> day;
    Date  d1(year, month, day);

    int  hour, minute, second;
    cin >> hour >> minute >> second;
    Time  t1(hour, minute, second);

    display(d1, t1);
    system("pause");
    return  0;
}

