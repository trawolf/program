#include<iostream>
#include <string>
#include <string.h>
#include <sstream>
#include"PalindromeJudge.h"
#include"IntegerPalindromeJudge.h"
#include"StringPalindromeJudge.h"
using namespace std;

int main(void) {
	const int LENGTH = 80;
	char str[LENGTH];
	unsigned int number;
	cin >> number;
	cin.getline(str, LENGTH);// for newline character
	cin.getline(str, LENGTH);
	// cout << number << std::endl
	// << str << std::endl;
	{
		IntegerPalindromeJudge integerJudge(number);
		PalindromeJudge& judger = integerJudge;
		std::cout << (judger.isPalindrome() ? 'Y' : 'N') << std::endl;
	}
	{
		StringPalindromeJudge stringJudge(str);
		PalindromeJudge& judger = stringJudge;
		std::cout << (judger.isPalindrome() ? 'Y' : 'N') << std::endl;
	}
	return 0;
}