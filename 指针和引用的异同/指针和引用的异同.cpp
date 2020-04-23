// 指针和引用的异同.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int main()
{
    int v = 63;       //声明一整型v，并赋值为63；
    const int cv = 62;        //声明一常量整型cv，并赋值为62；

    //int *ptr_v = &v;      //声明一指向v的整型指针ptr_v，并修改其值为1，运行并简单分析结果；
    //* ptr_v = 1;      true

    //const int * const_ptr_v = &v;        //声明一指向v的整型常量指针const_ptr_v，并修改其值为2，运行并简单分析结果；
    //* const_ptr_v = 2;      false//左值不可修改

    //int* const ptr_const_v = &v;           //声明一指向cv的整型指针常量ptr_const_v，并修改其值为2，运行并简单分析结果；
    //*ptr_const_v = 2;    true

    //const int *const const_ptr_const_v = &v;           //声明一指向v的整型常量指针常量const_ptr_const_v，并修改其值为2，运行并简单分析结果；
    //* const_ptr_const_v = 2;       false//左值不可修改

    //const int* const_ptr_cv = &cv;          //声明一指向cv的整型常量指针const_ptr_cv，并修改其值为3，运行并简单分析结果;
    //* const_ptr_cv = 3;        false//左值不可修改
    
    //int* const ptr_const_cv = &cv;        //声明一指向cv的整型指针常量ptr_const_cv，并修改其值为3，运行并简单分析结果；
    //* ptr_const_cv = 3;          false//左值不可修改

    //const int* const const_ptr_const_cv = &cv;          //声明一指向cv的整型常量指针常量const_ptr_const_cv，并修改其值为4，运行并简单分析结果；
    //*const_ptr_const_cv = 4;          false//左值不可修改

    //int& ref_v = v;          //声明一指向v的整型引用ref_v，并修改其值为5，运行并简单分析结果；
    //ref_v = 5;             true

    //const int& const_ref_v = v;          //声明一指向v的整型常量引用const_ref_v，并修改其值为6，运行并简单分析结果；
    //const_ref_v = 6;             false//左值不可修改

    //int& ref_cv = cv;        //声明一指向cv的整型引用ref_cv，并修改其值为7，运行并简单分析结果；
    //ref_cv = 7;            false//引用一般不可用于常量

    //const int& const_ref_cv = cv;      //声明一指向cv的整型常量引用const_ref_cv，并修改其值为8，运行并简单分析结果；
    //const_ref_cv = 8;           false//左值不可修改

    cout<< v<<" "<<cv;
}

//横向比较上述运行结果，并简单分析。