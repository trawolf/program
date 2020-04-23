#pragma once
#include "CBox2.h"
class CCandyBox :
	public CBox2
{
public:
    char* m_Contents;
    // Derived class function to calculate volume
    double volume() const;
    // Constructor to set dimensions & contents with explicit CBox constructor call
    CCandyBox(double lv, double wv, double hv, const char* str = "Candy");
    // Constructor to set contents - calls default CBox constructor automatically
    explicit CCandyBox(const char* str = "Candy");
    // Derived class copy constructor
    CCandyBox(const CCandyBox& box);
    CCandyBox& operator=(const CCandyBox& box) = delete; //Caution
    void Display(void) const;
    ~CCandyBox();
};

