#include  <iostream>
#include  <cmath>
using  std::cin;
using  std::cout;
using  std::endl;
using  std::istream;

const  float  PI = 3.1415926;
class  Shape {
public:
    virtual  Shape& Input() = 0;
    virtual  float  SurfaceAera()    const = 0;
    virtual  float  Volume()    const = 0;
};
class  Prism : public  Shape {  //棱柱
    //请补充虚基类相关函数
    virtual Shape& Input() =0;
    virtual  float  SurfaceAera()    const = 0;
    virtual  float  Volume()    const = 0;
};
class  RTPrism : public  Prism {  //正三棱柱
public:
    Shape& Input() {
        //请补充输入函数
        cin >> a >> h;
        return *this;
    }
    float  SurfaceAera()  const {
        //请补充表面积计算函数
        return sqrt(3) * a * a / 4 + 3 * a * sqrt(a * a / 12 + h * h) / 2;
    }
    float  Volume()  const {
        //请补充体积计算函数
        return sqrt(3) * a * a * h / 12;
    }
private:
    //请补充相应成员变量
    float a, h;  //边长和高
};
class  RCone : public  Prism {  //正圆锥体
    //请补充RCone类的成员函数和成员变量
    float r, h;  //半径和高
public:
    Shape& Input() {
        cin >> r >> h;
        return *this;
    }
    float  SurfaceAera()  const {
        return PI * r * r + PI * r * sqrt(r * r + h * h);
    }
    float  Volume()  const {
        return PI * r * r * h / 3;
    }
};
//请补充其他派生类相关代码
class Cuboid :public Shape {
private:
    float a, b, h;  //长,宽,高
public:
    Shape& Input() {
        cin >> a >> b>>h;
        return *this;
    }
    float SurfaceAera() const {
        return (a * b + a * h + b * h) * 2;
    }
    float Volume() const {
        return a * b * h;
    }
};
class Cube :public Cuboid {
private:
    float c;
public:
    Shape& Input() {
        cin >> c;
        return *this;
    }
    float SurfaceAera() const {
        return 6 * c * c;
    }
    float Volume() const {
        return c * c * c;
    }
};
class Sphere :public Shape {
private:
    float r;
public:
    Shape& Input() {
        cin >> r;
        return *this;
    }
    float SurfaceAera() const{
        return 4 * PI * r * r;
    }
    float Volume() const{
        return 4 * PI * r * r * r / 3;
    }
};


void  Display(const  Shape& sp) {
    std::cout << "SurfaceAera  =  " << sp.SurfaceAera() << std::endl
        << "Volume  =  " << sp.Volume() << std::endl;
}
void  DisplayCategory() {
    std::cout << "==================================================" <<
        std::endl;
    std::cout << "Please  input  one  of  the  following  choice:" << std::endl;
    std::cout << "\tCUBOID:    1" << std::endl;
    std::cout << "\tCUBE:        2" << std::endl;
    std::cout << "\tRTPRISM:  3" << std::endl;
    std::cout << "\tRCONE:      4" << std::endl;
    std::cout << "\tSPHERE:    5" << std::endl;
}
enum  CATEGORY { CUBOID = 1, CUBE, RTPRISM, RCONE, SPHERE }  category;
istream& operator  >>  (istream& in, CATEGORY& cat) {
    int  n = 0;
    in >> n;
    cat = static_cast<CATEGORY>(n);
    return  in;
}

int  main() {
    Cuboid  cuboid;
    Cube  cube;
    RTPrism  rtprism;
    RCone  rcone;
    Sphere  sphere;
    DisplayCategory();
    cin >> category;
    switch (category) {
    case  CUBOID:
        cout << "Please  input  (a,  b,  c)  in  order:" << endl;
        Display(cuboid.Input());
        break;
    case  CUBE:
        cout << "Please  input  (a):" << endl;
        Display(cube.Input());
        break;
    case  RTPRISM:
        cout << "Please  input  (a,  h)  in  order:" << endl;
        Display(rtprism.Input());
        break;
    case  RCONE:
        cout << "Please  input  (r,  h)  in  order:" << endl;
        Display(rcone.Input());
        break;
    case  SPHERE:
        cout << "Please  input  (r):" << endl;
        Display(sphere.Input());
        break;
    defalut:
        break;
    }
    return  0;
}