#include<iostream>
#include<fstream>
#include<string>
#define Max_Strlen 1024
using namespace std;

ifstream infile1("C:\\Users\\59217\\source\\repos\\Empty_Project\\test_data\\String.txt");                               //主串
ifstream infile2("C:\\Users\\59217\\source\\repos\\Empty_Project\\test_data\\Template.txt");                               //模式串

int IndexString(string pa, string pb) {                   //暴力匹配算法
	if (pa.size() < pb.size())
		return -1;
	else {
		for (int i = 0; i <= pa.size() - pb.size(); i++) {
			int count = 0;
			for (int j = 0; j < pb.size(); j++) {
				if (pa[i + j] == pb[j])
					count++;
				else break;
			}
			if (count == pb.size()) {
				return i;
				break;
			}
		}
		return -1;
	}
}

void Get_next(string str, int* next, int len) {                   //求解next数组
	next[0] = -1;
	int i = 0, j = -1;
	while (i < len-1) {
		if (j == -1 || str[i] == str[j])
			next[++i] = ++j;
		else j = next[j];
	}
	cout << endl;
}

int KMP_index(string pa, string pb){
		int i = 0, j = 0; 
		int* next = new int[Max_Strlen];
		Get_next(pb, next, pb.length());
		while (i < pa.length() && j < pb.length())
		{
			if (pa[i] == pb[j])
			{
				i++; j++;
			}
			else j = next[j];
			if (j == -1) {
				i++;
				j++;
			}
		}
		if (j >= pb.length()) 
			return i - pb.length();
		else return -1;
}

int main()
{
	string* pa = new string[100000];              //主串
	string* pb = new string[100000];               //模式串
	for (int i = 0; i < 100000; i++) {
		cout << "输出主串：";
		infile1 >> pa[i];
		cout << pa[i] << endl;
		cout << "输出模式串：";
		infile2 >> pb[i];
		cout << pb[i] << endl;
		cout << "模式串的位置：" << IndexString(pa[i], pb[i]);
		cout << "模式串的位置：" << KMP_index(pa[i], pb[i]) << endl;
		cout << endl;
	}
	return 0;
}