/*
建立一个简单的学校人员管理系统，包括对学生、员工和在职学生（既是员工又是学生）的管理。需要完成如下功能：
1、建立一个School类,在其中定义增加人员的Append函数。
2、建立一个基类Person类，要具有姓名和性别的属性，并把输出函数ShowMe()定义为虚函数；
3、建立一个员工Staff类和一个学生类Student，均由Person继承而来。要求可以输出员工类（学生类）对象的属性（姓名、性别和工作证号码（或学生学号），分别写出对ShowMe()函数的具体实现。
4、建立一个在职学生类Staff_Student类，由员工类和学生类继承而来。写出对ShowMe()函数的具体实现，可以输出对象属性，。
5、重载，实现用cin为员工类、学生类和在职学生类对象赋值。
6、编写main（）主函数，测试上述功能。
*/

/*
【样例输入】
Tom M 101
Andy F 10002
Jesson M 10003 102
【样例输出】
姓名:Tom
性别:M
工号:101

姓名:Andy
性别:F
学号:10002

姓名:Jesson
性别:M
学号:10003
工号:102
*/

#include<iostream>
#include"School.h"
#include"Staff.h"
#include"Staff_Student.h"
#include"student.h"

int  main()
{
	School  sch;
	Staff  s1;
	std::cin >> s1;
	sch.append(s1);
	Student  st1;
	std::cin >> st1;
	sch.append(st1);
	Staff_Student  ss1("SS1", 'F', 1001, 1003);
	std::cin >> ss1;
	sch.append(ss1);
	sch.display();
	return  0;
}