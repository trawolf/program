#pragma once
#include "Person.h"
#include<iostream>
class Staff :
	virtual public Person
{
protected:
    int  wID;  //工作号  
public:
    Staff(int  id = 0, std:: string  name1 = "", char  s = 'M') :Person(name1, s)
    {wID = id;}
    virtual    void  ShowMe();
    friend  std::istream& operator>>(std::istream& in, Staff& p);
};
void  Staff::ShowMe() {
    std::cout <<"姓名"<< this->name << std::endl;
    std::cout << "性别"<<this->sex << std::endl;
    std::cout << "工号"<<this->wID << std::endl;
}
//完成cin输入的运算符重载  
std::istream& operator>>(std::istream& in, Staff& p) {
    in >> p.name >> p.sex >> p.wID;
    return in;
}
