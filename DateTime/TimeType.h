//#ifdef TIMETYPE_H
#define TIMETYPE_H
#pragma once
class TimeType
{
protected:
	int hours, minuts, seconds;  //时，分，秒
public:
	TimeType(int , int , int );  //构造函数1
	TimeType();  //构造函数2
	bool equal(TimeType );  //判断两时间是否相等
	void printTime();  //屏幕输出时间对象的有关数据（时、分、秒）
};

//#endif
