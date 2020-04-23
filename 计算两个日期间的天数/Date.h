#pragma once

#include<iostream>
using namespace std;

class  Date
{
private:
    int  _year;
    int  _month;
    int  _day;
public:
    int  GetMonthDay(int  year, int  month)
    {
        //用静态数组，避免每次调用的时候都开辟新的数组
        static  int  monthArray[13] = { 0,  31,  28,  31,  30,  31,  30,  31,  31,  30,  31,  30,  31 };
        //如果为闰年的话，2月为29天
        if ((month == 2) && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return  29;
        }
        else
            return  monthArray[month];
    }
    //构造函数
    Date(int  year = 2019, int  month = 1, int  day = 1)
    {
        if (year > 0 &&
            (month > 0 && month < 13) &&
            (day > 0 && day <= GetMonthDay(year, month)))
        {
            _year = year;
            _month = month;
            _day = day;
        }
        else
        {
            cout << "日期非法" << endl;
            cout << year << "-" << month << "-" << day << endl;
        }
    }
    bool  operator!=(const  Date& d)  const
    {
        if (this->_year == d._year && this->_month == d._month &&this->_day == d._day)
            return false;
        else { return true; }
    }
    Date& operator+=(int  day)
    {
        //先将要加的天数加上，判断是否合法，不合法就进月，月不合法就进年
        this->_day = this->_day+ day;
        if (this->_day > GetMonthDay(this->_year, this->_month)) {
            this->_month++;
            this->_day = 1;
        }
        if (this->_month > 12) {
            this->_year++;
            this->_month = 1;
        }
        return  *this;
    }
    //  重载-运算符，默认减数小于被减数
    int  operator-(const  Date& d)
    {
        Date  Max = (*this);
        Date  Min = d;
        int  day = 0;
        while (Max != Min)
        {
            day++;
            Min += 1;
        }
        return  day;
    }
};

