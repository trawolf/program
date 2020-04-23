#include "CBox.h"
#include<iostream>
using namespace std;

explicit CBox::CBox(double lv =1.0 , double wv = 1.0 , double hv = 1.0 ) :
    m_Length{ lv }, m_Width{ wv }, m_Height{ hv } {
    cout << "CBox constructor called" <<endl;
}

CBox::CBox(const CBox& initB) {
    cout << "CBox copy constructor called" << endl;
    m_Length = initB.m_Length;
    m_Width = initB.m_Width;
    m_Height = initB.m_Height;
}

void CBox::Display(void) const { // Caution
    cout << "a CBox with (height, width, length) = " // Caution
        <<"(" << m_Height << ", " << m_Width << ", " << m_Length << ")"
        << endl;
}

CBox::~CBox() {
    cout << "CBox destructor called" << endl;
}
