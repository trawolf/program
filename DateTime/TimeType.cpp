#include<iostream>
#include"TimeType.h"
using namespace std;

TimeType::TimeType(int h0, int m0, int s0 ) {
	this->hours = h0 ; this->minuts = m0; this->seconds = s0;
}
TimeType::TimeType() {
	this->hours = 0; this->minuts = 0; this->seconds = 0;
}
bool TimeType::equal(TimeType t2) {
	if (this->hours == t2.hours && this->minuts == t2.minuts && this->seconds == t2.seconds) {
		return true;
	}
	else { return false; }
}
void TimeType::printTime() {
	cout << this->hours << ":" << this->minuts << ":" << this->seconds << endl;
}