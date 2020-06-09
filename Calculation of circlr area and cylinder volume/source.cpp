/*
  * 定义一个类：圆，包含圆的半径；定义构造函数；计算圆的面积。 
  * 利用圆基类派生类：圆柱；定义构造函数；计算圆柱的体积。
 */

#include<iostream>
#include"class_def.h"
using namespace std;

enum  SHAPE { CIRCLE = 0, CYLINDER };
void  DisplayInformation() {
    cout << "Input  q/Q  to  quit,  otherwise  continue:" << endl;
}
int  main(void) {
    Circle<float>* ptr = nullptr;
    char  option;
    int  choice;
    DisplayInformation();
    while (std::cin >> option && option != 'q' && option != 'Q') {
        std::cout << "Please  choose  one  of  the  following  type:" << std::endl;
        std::cout << "  [0]  Circle" << std::endl;
        std::cout << "  [1]  Cylinder" << std::endl;
        std::cin >> choice;
        switch (choice) {
        case  CIRCLE:
            ptr = new  Circle<float>();
            break;
        case  CYLINDER:
            ptr = new  Cylinder<float>();
            break;
        default:
            ptr = nullptr;
            break;
        }
        if (ptr) {
            if (!ptr->input())  break;
            ptr->display();
            delete  ptr;
            ptr = nullptr;
        }
        DisplayInformation();
    }
    return  0;
}

/*
input:
c 0 1.5
c 1 1.5 1.5
q

output:
Input q/Q to quit, otherwise continue:
c
Please choose one of the following type:
 [0] Circle
 [1] Cylinder
0
Please enter the radius of Circle (type:f):
1.5
The area of Circle is: 7.06858
Input q/Q to quit, otherwise continue:
c
Please choose one of the following type:
 [0] Circle
 [1] Cylinder
1
Please enter the (radius, height) of Cylinder (type:f):
1.5 1.5
The surface area of Cylinder is: 21.2057
The volume of Cylinder is: 10.6029
Please enter the (radius, height) of Cylinder (type:f):
q
*/