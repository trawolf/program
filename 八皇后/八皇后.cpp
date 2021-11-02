#include<iostream>

using std::cin;
using std::cout;
using std::endl;

static int count = 0;

void Print(int num, int**chess) {
	for ( int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++) {
			if (chess[i][j] == 1) {
				cout << "#";
			}
			else
			{
				cout << "0";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int NotDanger(int row, int col, int num, int** chess) {
	int i, j;

	for ( i = 0; i <= row; i++)
	{
		if (chess[i][col] == 1) {
			return 0;
		}
	}

	for (i = row, j = col; i >= 0&& j >= 0; i--, j--) {
		if (chess[i][j] == 1) {
			return 0;
		}
	}
	
	for (i = row, j = col; i >= 0 && j < num; i--, j++) {
		if (chess[i][j]==1)
		{
			return 0;
		}
	}
	return 1;
}

void EightQueen(int row, int num, int** chess) {
	int col;
	if (row > num-1) {
		Print(num, chess);
		count++;
		return;
	}

	for (col = 0; col < num; col++) {
		if (NotDanger(row, col, num, chess)) {
			chess[row][col] = 1;
			EightQueen(row + 1, num, chess);

			chess[row][col] = 0;
		}
	}
}

int main() {
	cout << "请输入n：";
	int num;
	cin >> num;
	cout << endl;
	int **chess = new int* [num];
	for (int i = 0; i < num; i++) {
		chess[i] = new int[num];
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			chess[i][j] = 0;
		}
	}
	EightQueen(0, num, chess);
	cout << count << "种方案" << endl;
	system("pause");
	return 0;
}

