#include<iostream>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{
	int input;
	cin >> input;
	cout << setw(6*(input)) << "1" << endl;
	cout << setw(6 * (input-1)) << "1" << setw(6) << "1" << endl;
	int** num=new int*[1000];
	num[0] = new int;
	num[0][0] = 1;
	num[1] = new int[2];
	num[1][0] = 1; num[1][1] = 1;
	for (int i = 2; i < input; i++) {
		num[i] = new int[i+1];
		for (int j = 0; j < i + 1; j++) {
			if(j==0) num[i][j] = num[i - 1][0];
			else if(j==i) num[i][j] = num[i - 1][j - 1];
			else num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
		}
	}
	for (int i = 2; i < input; i++) {
		cout << setw(6 * (input - i )) << num[i][0];
		for (int j = 1; j < i + 1; j++) {
			cout << setw(6) << num[i][j];
		}
		cout << endl;
	}
	return 0;
}