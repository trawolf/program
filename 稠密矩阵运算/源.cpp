#include<iostream>
#include<fstream>
#define MAX_SIZE 10000
#define MAX_COL 50
#define MAX_ROW 50
using namespace std;

struct Matrix {
	int col;                                //行下标
	int row;                                //列下标
	int** matrix;
	Matrix() {
		col = MAX_COL;
		row = MAX_ROW;
		matrix = new int* [col];
		for (int i = 0; i < col; i++) {
			matrix[i] = new int[row];
		}
	}
	Matrix(int col, int row) {
	    this->col= col;
		this->row = row;
		matrix = new int* [col];
		for (int i = 0; i < col; i++) {
			matrix[i] = new int[row];
		}
	}
};
Matrix Add(Matrix pa, Matrix pb) {
	int ecol = pa.col, erow = pa.row;
	Matrix result(ecol,erow);
	for (int i = 0; i < ecol; i++) {
		for (int j = 0; j < erow; j++) {
			result.matrix[i][j] = pa.matrix[i][j] + pb.matrix[i][j];
		}
	}
	return result;
}

Matrix Min(Matrix pa, Matrix pb){
	int ecol = pa.col, erow = pa.row;
	Matrix result(ecol, erow);
	for (int i = 0; i < ecol; i++) {
		for (int j = 0; j < erow; j++) {
			result.matrix[i][j] = pa.matrix[i][j] - pb.matrix[i][j];
		}
	}
	return result;
}
Matrix Mul(Matrix pa, Matrix pb) {
	int ecol = pa.col, erow = pb.row;             //pa.row=pb.col
	Matrix result(ecol, erow);
	for (int i = 0; i < ecol; i++) {
		for (int j = 0; j < erow; j++) {
			result.matrix [i][j] = 0;
		}
	}
	for (int i = 0; i < ecol; i++) {
		for (int j = 0; j < erow; j++) {
			for (int m = 0; m < pa.row; m++) {
				result.matrix[i][j] += pa.matrix[i][m] * pb.matrix[m][j];
			}
		}
	}
	return result;
}
Matrix Tra(Matrix &p) {
	Matrix result(p.row, p.col);
	for (int i = 0; i < p.col; i++) {
		for (int j = 0; j < p.row; j++) {
			result.matrix[j][i] = p.matrix[i][j];
		}
	}
	return result;
}
void Display(Matrix p) {
	for (int i = 0; i < p.col; i++) {
		for (int j = 0; j < p.row; j++) {
			cout.setf(ios::right);
			cout.width(3);
			if ((j + 1) % p.row == 0) {
				cout << p.matrix[i][j] << endl;
			}
			else cout << p.matrix[i][j] ;
		}
	}
	cout << endl;
}

int main()
{
	Matrix* pa = new Matrix[MAX_SIZE];
	ifstream infile1("C:\\Users\\59217\\Desktop\\常用\\数据结构基础\\第六次上机作业\\数据结构第6测试样例\\dense\\dense_a.txt");
	for (int i = 0; i < MAX_SIZE; i++) {
		infile1 >> pa[i].col >> pa[i].row;
		for (int m = 0; m < pa[i].col; m++) {
			for (int n = 0; n < pa[i].row; n++) {
				infile1 >> pa[i].matrix[m][n];
			}
		}
	}
	Matrix* pb = new Matrix[MAX_SIZE];
	ifstream infile2("C:\\Users\\59217\\Desktop\\常用\\数据结构基础\\第六次上机作业\\数据结构第6测试样例\\dense\\dense_b.txt");
	for (int i = 0; i < MAX_SIZE; i++) {
		infile2 >> pb[i].col >> pb[i].row;
		for (int m = 0; m < pb[i].col; m++) {
			for (int n = 0; n < pb[i].row; n++) {
				infile2 >> pb[i].matrix[m][n];
			}
		}
	}
	Matrix* pc = new Matrix[MAX_SIZE];
	ifstream infile3("C:\\Users\\59217\\Desktop\\常用\\数据结构基础\\第六次上机作业\\数据结构第6测试样例\\dense\\dense_c.txt");
	for (int i = 0; i < MAX_SIZE; i++) {
		infile3 >> pc[i].col >> pc[i].row;
		for (int m = 0; m < pc[i].col; m++) {
			for (int n = 0; n < pc[i].row; n++) {
				infile3 >> pc[i].matrix[m][n];
			}
		}
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		Display(Add(pa[i], pb[i]));
		Display(Min(pa[i],pb[i]));
		Display(Mul(pa[i], pc[i]));
		Display(Tra(pa[i]));
	}
	return 0;
}