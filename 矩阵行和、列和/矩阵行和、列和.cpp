// 矩阵行和、列和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<math.h>
#include<cstring>
using std::endl;
using std::cin;
using std::cout;

void Print1DArray(const float* arr, int length) {
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Print2DArray(float** arr, int rows, int cols) {
    cout << rows << " " << cols << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << *(*(arr + i) + j) << " ";
            if ((j+1) % cols == 0) {
                cout << endl;
                cout << endl;
            }
        }
    }
}

float Matrix_RowCalculation(float** arr, int rows, int cols, float* pRowSum, float* pRowMean) {
    float sum=0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pRowSum[i] += *(*(arr + i) + j);
        }
    }
    for (int k = 0; k < rows; k++) {
        pRowMean[k] = pRowSum[k] / cols;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
};

float Matrix_ColumnCalculation(float** arr, int rows, int cols, float* pColumnSum, float* pColumnMean) {
    float sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += *(*(arr + i) + j);
        }
    }
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            pColumnSum[i] += *(*(arr + j) + i);
        }
    }
    for (int k = 0; k < cols; k++) {
        pColumnMean[k] = pColumnSum[k] / rows;
    }
    return sum;
};

int main(void) {
    int rows, cols;
    cin >> rows >> cols;
    float **arr,*pRowSum,*pColumnSum,*pRowMean,*pColumnMean;
    pRowSum = new float[rows];
    pColumnSum = new float[cols];
    pRowMean = new float[rows];
    pColumnMean = new float[cols];
    arr = new float*[rows];
    for (int i = 0; i < rows; i++) {
        pRowSum[i] = 0;
    }
    for (int i = 0; i < rows; i++) {
        pRowMean[i] = 0;
    }
    for (int i = 0; i < cols; i++) {
        pColumnSum[i] = 0;
    }
    for (int i = 0; i < cols; i++) {
        pColumnMean[i] = 0;
    }
    for (int i = 0; i < rows; i++) {
        arr[i] = new float[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> *(*(arr+i)+j);
        }
    }
    Print2DArray(arr, rows, cols);

    cout << "========================================" << endl << endl;


    cout << "==Row Calculation==" << endl

        << "All Sum:" << Matrix_RowCalculation(arr, rows, cols, pRowSum, pRowMean) << endl;

    cout << "Row Sum:" << endl;

    Print1DArray(pRowSum, rows);

    cout << "Row Mean:" << endl;

    Print1DArray(pRowMean, rows);


    cout << "========================================" << endl << endl;


    cout << "==Column Calculation==" << endl

        << "All Sum:" << Matrix_ColumnCalculation(arr, rows, cols, pColumnSum, pColumnMean) << endl;

    cout << "Column Sum:" << endl;

    Print1DArray(pColumnSum, cols);

    cout << "Column Mean:" << endl;

    Print1DArray(pColumnMean, cols);
    delete[] pRowSum;
    delete[] pColumnSum;
    delete[] pRowMean;
    delete[] pColumnMean;
    delete[] arr;
    return 0;
}