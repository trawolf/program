// Binary Number with Alternating Bits .cpp
//Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

#include<iostream>
#include<cmath>
using namespace std;

int  main() 
{
	int* num2 = new int;
	int count1 = 0;
	int num1;
	cin >> num1;
	while(num1>=2){
		num2[count1] = num1 % 2;
		num1 = num1 / 2;
		count1++;
	}
	if (num1 == 1) {
		num2[count1 ] = 1;
	}
	/*for (int i = count1; i >=0; i--) {
		cout << num2[i] ;
	}
	cout << endl;*/
	int count2 = 0;
	for (int i = 0; i < count1-1; i++) {
		if (num2[i] == num2[i + 1]) {
			count2++;
			//cout << count2;
			break;
		}
	}
	if (count2 == 0) {
		cout << "Yes!";
	}
	else { cout << "No!"; }
	return 0;
}