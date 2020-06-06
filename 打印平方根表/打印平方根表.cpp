/*
打印row行row列的数的平方根：在行方面首先设置"|"字符前的域宽为5，行号之间域宽为5，行与表格之间的虚线为七个"-"字符；
在列方面，列号域宽为2，"|"字符域宽为3；平方根输出域宽为7，按三位浮点数打印。
*/
/*
cout<<setw(5)<<"|";
for(i=0;i<row;i++) cout<<setw(5)<<i<<"  "; //2个空格
cout<<endl<<"----+";
for(i=0;i<row;i++) cout<<"-------"; //7个“-”字符
*/

#include<iostream>
#include<iomanip>
#include<math.h>
using std::cout;
using std::setw;

int main()
{
	int row;
	std::cin >> row;
	cout << setw(5) << "|";
	for (int i = 0; i < row; i++) cout << setw(5) << i << "  "; //2个空格
	cout << std::endl << "----+";
	for (int i = 0; i < row; i++) cout << "-------"; //7个“-”字符
	for (int i = 0; i < row; i++) {
		cout << std::endl<< setw(2) << i << "  |";
		cout.setf(std::ios::fixed, std::ios::floatfield);//设置定点格式
		cout.precision(3);
		for (int j = 0; j < row; j++)cout << setw(7) << sqrt(i * 10 + j);
	}
	return 0;
}