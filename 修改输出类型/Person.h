#pragma once
#include<iostream>
#include<string>
class Person
{
public:
    Person(std::string  name1 = "", char  s = 'M')
    {
        name = name1;
        sex = s;
    }
    virtual  void  ShowMe();
    friend  std::istream& operator>>(std::istream& in, Person& p);
protected:
    char  sex;
    std::string  name;
};
void  Person::ShowMe() {
    std::cout <<"姓名"<< this->name << std::endl;
    std::cout << "性别"<<this->sex << std::endl;
}
//完成cin输入的运算符重载 
std::istream& operator>>(std::istream& in, Person& p) {
    in >> p.name >> p.sex;
    return in;
}
