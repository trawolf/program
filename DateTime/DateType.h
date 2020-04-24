#pragma once
class DateType
{
protected:
	int years, months, day;  //年，月，日
public:
	DateType(int  , int  , int  );  //构造函数1
	DateType();  //构造函数2
	int GetMonthDay(int , int);  //获得该月的天数
	bool equal(DateType );  //判断两日期是否相等
	void printDate();  //屏幕输出日期对象的有关数据（年、月、日）
};

