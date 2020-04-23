#pragma once
class CBox
{
protected:
    double m_Length;
    double m_Width;
    double m_Height;
public:
    // Base class constructor
    explicit CBox(double , double , double );
    // Copy constructor
    CBox(const CBox& initB);
    void Display(void) const;
    // CBox destructor - just to track calls
    ~CBox();
};

