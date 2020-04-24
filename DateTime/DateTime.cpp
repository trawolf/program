#include"DateTimetype.h"
#include<iostream>
using namespace std;

int main()
{
	DateTimetype dttm1(1999, 12, 31, 23, 59, 59), dttm2;
	dttm1.printDate();  //直接调用基类的公有成员函数printDate
	dttm1.printDateTime();
	dttm2.printDateTime();
	dttm1.incrementSecond(30);
	dttm1.printDateTime();
	return 0;
}