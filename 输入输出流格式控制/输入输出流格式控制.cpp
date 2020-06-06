//给定10个浮点数，以小数点对齐输出。
/*
把输入的浮点数据分成整数部分和小数部分，其中，整数部分右对齐，使用'>'填充，并且，输出宽度比所有的整数部分的最长值还要大3位。
然后输出「空格+空格」，紧接着输出小数部分。
*/
#include  <iostream>
#include  <iomanip>
#include  <cmath>
#include  <float.h>
//  #include  <string>
using  std::cout;
using  std::cin;
using  std::endl;
using  std::setw;
using  std::setfill;
using  std::right;
using  std::left;
//  using  std::string;
//  using  std::getline;
//enter your code here 


int main(void)
{
    const  int  LENGTH = 10;
    double  arrFloat[LENGTH];
    //  int  arrDigits[LENGTH];
    for (int i = 0; i < LENGTH; ++i) {
        cin >> arrFloat[i];
    }
    //enter your code here
    for (int i = 0; i < LENGTH; i++) {
        double ints;
        double floats = modf(arrFloat[i], &ints);
        cout.fill('>');
        cout << setw(6) << ints << " + " << floats;
        cout << endl;
    }
    return 0;
}