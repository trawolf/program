// Add Digits .cpp
// Given a non-negative integer num, 
// repeatedly add all its digits until the result has only one digit.



#include<iostream>
using namespace std;

int getcount(int num) {
	int count = 1;
	for (int i = 10;; i = i * 10) {
		if (num / i >= 1) {
			count++;
		}
		else break;
	}
	return count;
}

int main() 
{
	int num;
	cin >> num;
	cout << getcount(num)<<endl;
	for (int i = 0; ; i++) {
		int sum = 0;
		if (num < 10) { 
			cout << num; 
			break; 
		}
		else {
			int j;
			for (int k=0,j=10; k < getcount(num); j=j*10,k++) {
				sum += (num % j) * 10 / j;
			}
			num = sum;
		}
	}
	return 0;
}