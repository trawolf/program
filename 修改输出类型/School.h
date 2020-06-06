#pragma once
#include<iostream>
#include"Person.h"
class School
{
private:
    Person* p[100];
    int  size;
public:
    School();
    ~School() { };
    void  append(Person&);
    void  display();
};
School::School()
{size = 0;}
void  School::display()
{
    int  i;
    for (i = 0; i < size; i++)
        p[i]->ShowMe();
}
void  School::append(Person& p1) {
    p[size] = &p1;
    size++;
}

