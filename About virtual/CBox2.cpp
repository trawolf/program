#include "CBox2.h"
#include<iostream>
using namespace std;

explicit CBox2::CBox2(double lv = 1.0, double wv = 1.0, double hv = 1.0)
    : CBox(lv, wv, hv) {
    std::cout << "CBox2 constructor called" << std::endl;
}

CBox2::CBox2(const CBox2& initB)   :CBox(initB) {
    std::cout << "CBox2 copy constructor called" << std::endl;
    m_Length = initB.m_Length;
    m_Width = initB.m_Width;
    m_Height = initB.m_Height;
}

void CBox2::Display(void) const { // Caution
    std::cout << "a CBox2 with (height, width, length) = " // Caution
        "(" << m_Height << ", " << m_Width << ", " << m_Length << ")"
        << std::endl;
}

CBox2::~CBox2() {
    std::cout << "CBox2 destructor called" << std::endl;
}
