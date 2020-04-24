#pragma once
#include"DateType.h"
#include"TimeType.h"
class DateTimetype :
	public TimeType, public DateType
{
public:
	DateTimetype(int, int, int, int, int, int);  //构造函数1
	DateTimetype();  //构造函数2
	void incrementSecond(int);  //增加若干秒
	void printDateTime();  //屏幕输出日期时间对象的有关数据
};

