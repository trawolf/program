#include "CCandyBox.h"
#include<iostream>
using namespace std;

double CCandyBox::volume() const {
    return m_Length * m_Width * m_Height;
}

CCandyBox::CCandyBox(double lv, double wv, double hv,
    const char* str = "Candy")
    : CBox2{ lv, wv, hv } {
    cout << "CCandyBox constructor2 called" << endl;
    size_t length{ strlen(str) + 1 };
    m_Contents = new char[length];
    strcpy_s(m_Contents, length, str);
}

explicit CCandyBox::CCandyBox(const char* str = "Candy") {
    cout << "CCandyBox constructor1 called" << endl;
    size_t length{ strlen(str) + 1 };
    m_Contents = new char[length];
    strcpy_s(m_Contents, length, str);
}

CCandyBox::CCandyBox(const CCandyBox& initCB) {
    cout << "CCandyBox copy constructor called" << endl;
    size_t length{ strlen(initCB.m_Contents) + 1 };
    m_Contents = new char[length];                       // Get new memory
    strcpy_s(m_Contents, length, initCB.m_Contents);     // Copy string
}

void CCandyBox::Display(void) const { // Caution
    cout << "a CCandyBox with (height, width, length, contents) = " // Caution
        "(" << m_Height << ", " << m_Width << ", " << m_Length << ", " << m_Contents << ")"
        << endl;
}

CCandyBox::~CCandyBox() {
    cout << "CCandyBox destructor called" << endl;
    delete[] m_Contents;
}
