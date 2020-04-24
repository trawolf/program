#include "DateTimeType.h"
#include<iostream>
using namespace std;

DateTimetype::DateTimetype(int y0, int m0, int d0, int h0, int min0, int s0)
	:DateType(y0, m0, d0), TimeType(h0, min0, s0) {}
DateTimetype::DateTimetype() :DateType(),TimeType(){}
void DateTimetype::incrementSecond(int sec) {
	this->seconds += sec;
	if (this->seconds >= 60) {this->minuts++; this->seconds -= 60;}
	if (this->minuts >= 60) {this->hours++; this->minuts -= 60;}
	if (this->hours >= 24) { this->day++; this->hours -= 24; }
	if (this->day > this->GetMonthDay(this->years, this->months))
	{
		this->months++;
		if (this->months > 12) {this->months -= 12; this->years++;
		    this->day = this->day - GetMonthDay(this->years, this->months);}
		else { this->day -= GetMonthDay(this->years, this->months);}
	}
	if (this->months > 12) { this->months -= 12; this->years++; }
}
void DateTimetype::printDateTime() {
	cout << this->years << "-" << this->months << "-" << this->day << endl;
	cout << this->hours << ":" << this->minuts << ":" << this->seconds << endl;
}