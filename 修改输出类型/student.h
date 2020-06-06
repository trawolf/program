#pragma once
#include "Person.h"
#include<string>
#include<iostream>

class Student :
	virtual public Person
{
protected:
    int  sID;  //学号  
public:
    Student(int  id = 0, std::string  name1 = "", char  s = 'M') :Person(name1, s)
    {
        sID = id;
    }
    virtual  void  ShowMe();
    friend  std::istream& operator>>(std::istream& in, Student& p);
};
void  Student::ShowMe() {
    std::cout << "姓名"<<this->name << std::endl;
    std::cout << "性别"<<this->sex << std::endl;
    std::cout << "学号"<<this->sID<< std::endl;
}
//完成cin输入的运算符重载  
std::istream& operator>>(std::istream& in, Student& p) {
    in >> p.name >> p.sex >> p.sID;
    return in;
}

