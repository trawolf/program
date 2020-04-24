// Merge Two Sorted Arrays.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<math.h>
#include<cstring>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int>& A, vector<int>& B)
    {
        // write your code here
        int a = A.size() + B.size();
        vector<int> C(a);
        int i = 0;
        int j = 0;
        int k = 0;
        //cout << "1" << i << endl;
        //cout << A[i];
        //cout << "2" << endl;

        while (i < A.size() and j < B.size())
        {
            //cout << A.size() << B.size();
            if (A[i] > B[j])
            {
                //cout << "ai" << A[i] << endl << i <<endl;
                //cout << "ai" << A[i];
                C[k] = B[j];
                k = k + 1;
                j = j + 1;
                //cout << "ai" << A[i] << "j" << j << k << endl;
            }
            //cout << "ai" << A[i];
            if (A[i] == B[j])
            {
                C[k] = B[j];
                k = k + 1;
                j = j + 1;
                C[k] = A[i];
                k = k + 1;
                i = i + 1;
            }
            if (A[i] < B[j])
            {
                C[k] = A[i];
                k = k + 1;
                i = i + 1;
            }
        }
        cout << A[i] << endl;
        cout << i << endl;
        cout << j << endl;
        cout << k << endl;
        cout << C[k] << endl;
        if (A.size() - i >= 1)
        {
            while (i < A.size())
            {
                //cout << A[0] << i << endl;
                C[k] = A[i];
                k = k + 1;
                i = i + 1;
            }
        }
        if (B.size() - j >= 1)
        {
            while (j < B.size())
            {
                C[k] = B[j];
                k = k + 1;
                j = j + 1;
            }
        }
        return C;
    }
};


    /**int* mergeSortedArray(int* A, int* B) {
        // write your code here
        int* ptr_C = new int[];
        for (int i = 0; i < (sizeof(A) / 4); i++) {
            ptr_C[i] = A[i];
        }
        int counter = 0;
        for (int i = 0; i < sizeof(B) / 4; i++) {
            counter++;
            for (int j = 0; j < sizeof(A) / 4 + counter; j++) {
                if (B[i] <= ptr_C[j]) {
                    for (int k = sizeof(A) / 4 + counter; k > j; j--) {
                        ptr_C[k] = ptr_C[k - 1];
                    }
                    ptr_C[j] = B[i];
                }
                if (B[i] > ptr_C[sizeof(A) / 4 - 1 + counter]) {
                    ptr_C[sizeof(A) + counter] = B[i];
                }
            }
        }
        return ptr_C;
    }*/


int main()
{
    vector <int>A;
    vector <int>B;
    for (int i = 0;; i++) {
        cin >> A[i];
    }
    for (int j = 0;; j++) {
        cin >> B[j];
    }
    Solution solution;
    cout<<solution.mergeSortedArray(  A,  B);
    return 0;
}

