#pragma once
/*
|----------------------|
|Circle                |
|----------------------|
|+ bool input()        |
|+ double area()       |
|+ void display()      |
|-----------------------|
          ¡ý
          ¡ý
          ¡ý
|----------------------|
|Cylinder              |
|----------------------|
|+ bool input()        |
|+ double area()       |
|+ double volume()     |
|+ void display()      |
|----------------------|
*/

#include<iostream>
#include<typeinfo>
using namespace std;

const  float  PI = 3.1415926;
template<class  T>
class  Circle {
protected:
    T radius;
public:
    Circle() { T a; print(); cin >> a; radius = a; }
    Circle(T a) { radius = a; }
    virtual void print(){ cout << "Please enter the radius of Circle (type:f):" << endl; }
    bool input() { return true; }
    virtual double area(){ return PI * radius * radius; }
    virtual void display(){ cout << "The area of Circle is: " << area() << endl; }
};

template<class  T>
class  Cylinder : public  Circle<T> {
private:
    T height, r;
public:
    T c, b;
    void print() { cout << "Please enter the (radius, height) of Cylinder (type:f):" << endl; }
    Cylinder() :Circle<T>(c){
        print();
        cin >> c >> b;
        r = c;
        height = b;
    }
    double area() { return 2*PI * r * r+2*PI*r*height; }
    double volume(){ return PI*r*r* height; }
    void display()
    {
        cout << "The surface area of Cylinder is: " << this->area() << endl;
        cout << "The volume of Cylinder is: " << this->volume() << endl;
    }
};


