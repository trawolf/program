#include<iostream>
#include<fstream>
#define MAX_SIZE 10000
#define MIN_COL 10
#define MAX_COL 1000
#define MIN_ROW 10
#define MAX_ROW 1000
#define SPARSITY_FACTOR 0.0001
using namespace std;

struct Triple {
	int col;
	int row;
	int value;
};
struct TMatrix {
	int cn;                                 //行数
	int rn;                               //列数
	int tn;                             //非零元素的个数
	Triple *data;
	TMatrix() {
		this->cn = MAX_COL;
		this->rn = MAX_ROW;
		this->tn = 0;
		this->data = new Triple[MAX_SIZE];
	}
	TMatrix(int col, int row) {
		this->cn = col;
		this->rn = row;
		this->tn = 0;
		this->data = new Triple[MAX_SIZE];
	}
};

TMatrix Add(TMatrix pa, TMatrix pb) {
	int col = pa.cn, row = pa.rn;
	TMatrix result(col, row);
	int i = 0, j = 0;
	while (i<pa.tn||j<pb.tn) {
		if (pa.data[i].col < pb.data[j].col) {
			result.data[i + j].col = pa.data[i].col;
			result.data[i + j].row = pa.data[i].row;
			result.data[i + j].value = pa.data[i].value;
			i++;
		}
		else if (pa.data[i].col > pb.data[j].col) {
			result.data[i + j].col = pb.data[j].col;
			result.data[i + j].row = pb.data[j].row;
			result.data[i + j].value = pb.data[j].value;
			j++;
		}
		else if (pa.data[i].row < pb.data[j].row) {
			result.data[i + j].col = pa.data[i].col;
			result.data[i + j].row = pa.data[i].row;
			result.data[i + j].value = pa.data[i].value;
			i++;
		}
		else if (pa.data[i].row > pb.data[j].row) {
			result.data[i + j].col = pb.data[j].col;
			result.data[i + j].row = pb.data[j].row;
			result.data[i + j].value = pb.data[j].value;
			j++;
		}
		else {
			result.data[i + j].col = pa.data[i].col;
			result.data[i + j].row = pa.data[i].row;
			result.data[i + j].value = pa.data[i].value + pb.data[j].value;
			i++;
			j++;
		}
	}
	return result;
}
TMatrix Min(TMatrix pa, TMatrix pb) {
	int col = pa.cn, row = pa.rn;
	TMatrix result(col, row);
	int i = 0, j = 0;
	while (i < pa.tn || j < pb.tn) {
		if (pa.data[i].col < pb.data[j].col) {
			result.data[i + j].col = pa.data[i].col;
			result.data[i + j].row = pa.data[i].row;
			result.data[i + j].value = pa.data[i].value;
			i++;
		}
		else if (pa.data[i].col > pb.data[j].col) {
			result.data[i + j].col = pb.data[j].col;
			result.data[i + j].row = pb.data[j].row;
			result.data[i + j].value = pb.data[j].value;
			j++;
		}
		else if (pa.data[i].row < pb.data[j].row) {
			result.data[i + j].col = pa.data[i].col;
			result.data[i + j].row = pa.data[i].row;
			result.data[i + j].value = pa.data[i].value;
			i++;
		}
		else if (pa.data[i].row > pb.data[j].row) {
			result.data[i + j].col = pb.data[j].col;
			result.data[i + j].row = pb.data[j].row;
			result.data[i + j].value = pb.data[j].value;
			j++;
		}
		else {
			result.data[i + j].col = pa.data[i].col;
			result.data[i + j].row = pa.data[i].row;
			result.data[i + j].value = pa.data[i].value - pb.data[j].value;
			i++;
			j++;
		}
	}
	return result;
}
TMatrix Mul(TMatrix pa, TMatrix pb) {
	TMatrix result(pa.cn, pb.rn);
	int en = pa.rn;
	int count = 0;
	 
}
TMatrix Tra(TMatrix p) {
	TMatrix result(p.rn, p.cn);
	result.tn = p.tn;
	int count = 0;
	for (int i = 0; i < p.rn; i++) {
		for (int j = 0; j < p.tn; j++) {
			if (i == p.data[j].row) {
				result.data[count].col = p.data[j].row;
				result.data[count].row = p.data[j].col;
				result.data[count].value = p.data[j].value;
				count++;
			}
		}
	}
	return result;
}

int main()
{

	return 0;
}