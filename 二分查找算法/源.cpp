#include<iostream>
#include<algorithm>
using namespace std;

int Bin_Search(int* table,int length, int key) {
	int Low = 1, High = length, Mid;
	while (Low <= High) {
		Mid = (Low + High) / 2;
		if (table[Mid] == key)
			return Mid;
		else if (key > table[Mid])
			Low = Mid + 1;
		else
			High = Mid - 1;
	}
	return 0;
}

int main() 
{
	cout << "输入数组长度：" << endl;
	int length;
	cin >> length;
	cout << "输入数组元素：" << endl;
	int* p = new int[length];
	for (int i = 0; i < length; i++) {
		cin >> p[i];
	}
	sort(p, p + length);
	cout << "输入待查找元素：" << endl;
	int key;
	cin >> key;
	cout << "二分查找：" << endl;
	cout << Bin_Search(p, length, key) << endl;
	return 0;
}