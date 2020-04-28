#pragma once
#include "PalindromeJudge.h"
#include<iostream>
#include<string>
using namespace std;

class StringPalindromeJudge :
	virtual public PalindromeJudge
{
public:
	string str;
	StringPalindromeJudge(string input) {
		this->str;
	}
	bool isPalindrome() {
		string change = str;
		int len = str.size();
		char temp;
		for (int i = 0; i < len / 2; i++) {
			temp = str[i];
			str[i] = str[len - 1 - i];
			str[len - 1 - i] = temp;
		}
		if (change == str) {
			return true;
		}
		else return false;
	}
};
