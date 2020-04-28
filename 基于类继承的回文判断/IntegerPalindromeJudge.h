#pragma once
#include "PalindromeJudge.h"
#include<iostream>
#include<string>
using namespace std;

class IntegerPalindromeJudge :
	virtual public PalindromeJudge
{
public:
	int num;
	IntegerPalindromeJudge(int input) {
		this->num = input;
	}
	bool isPalindrome() {
		string str = to_string(num);
		int count=0;
		for (int i = 0; i < str.length() ; i++) {
			if (str[i] != str[str.length() - i-1]) {
				break;
			}
			else count++;
		}
		if (count == str.length() ) {
			return true;
		}
		else return false;
	}
};

