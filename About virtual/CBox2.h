#pragma once
#include "CBox.h"
class CBox2 :
	public CBox
{
public:
    // Base class constructor
    explicit CBox2(double lv = 1.0, double wv = 1.0, double hv = 1.0);
    // Copy constructor
    CBox2(const CBox2& initB);
    virtual void Display(void) const;
    // CBox destructor - just to track calls
    ~CBox2();
};

