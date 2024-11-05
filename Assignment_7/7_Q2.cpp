#include <iostream>
#include <stdexcept>

class Tiny 
{
    char v; // 6-bit non-negative integer, stored in a char

    // Range-check and assign function
    void assign(int i) {
        if (i & ~077) // Check if i is within the 6-bit range (0 to 63)
            throw Bad_range();
        v = i;
    }

public:
    class Bad_range { }; // Exception class for out-of-range values

    // Constructor from int, with range check
    Tiny(int i = 0) { assign(i); }

    // Conversion operator to int
    operator int() const { return v; }

    // Overloaded assignment operator for int with range check
    Tiny& operator=(int i) 
    {
        assign(i);
        return *this;
    }

    // Overload arithmetic operators for Tiny objects

    Tiny operator+(int i) const 
    {
        Tiny result(*this);
        result.assign(v + i); // range-checked addition
        return result;
    }

    Tiny operator-(int i) const 
    {
        Tiny result(*this);
        result.assign(v - i); // range-checked subtraction
        return result;
    }

    Tiny& operator+=(int i) 
    {
        assign(v + i); // range-checked in-place addition
        return *this;
    }

    Tiny& operator-=(int i) 
    {
        assign(v - i); // range-checked in-place subtraction
        return *this;
    }

    // Overload arithmetic operators for operations between two Tiny objects
    Tiny operator+(const Tiny& other) const 
    {
        return *this + static_cast<int>(other.v);
    }

    Tiny operator-(const Tiny& other) const 
    {
        return *this - static_cast<int>(other.v);
    }

    Tiny& operator+=(const Tiny& other) 
    {
        return *this += static_cast<int>(other.v);
    }

    Tiny& operator-=(const Tiny& other) 
    {
        return *this -= static_cast<int>(other.v);
    }
};

int main()
 {
    try {
        Tiny c1 = 2;           // Initialize with range check
        Tiny c2 = 62;          // Initialize with range check
        Tiny c3 = c2 - c1;     // c3 = 60
        Tiny c4 = c3;          // Copy, no range check required
        int i = c1 + c2;       // i = 64
        c1 = c1 + c2;          // Range error: c1 can't be 64
        i = c3 - 64;           // i = -4
        c2 = c3 - 64;          // Range error: c2 can't be -4
        c3 = c4;               // No range check required
    } catch (const Tiny::Bad_range&)
     {
        std::cerr << "Range error: value out of bounds for Tiny object." << std::endl;
     }

    return 0;
}
