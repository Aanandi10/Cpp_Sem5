#include <iostream>
using namespace std;

class Base 
{
public:
    // Declare iam() as virtual to enable polymorphism
    virtual void iam() { cout << "Base\n"; }
    virtual ~Base() = default;  // Virtual destructor for safe polymorphic deletion
};

class D1 : public Base
 {
public:
    void iam() override { cout << "D1\n"; }  // Override iam() for D1
};

class D2 : public Base
 {
public:
    void iam() override { cout << "D2\n"; }  // Override iam() for D2
};

// Print function that calls iam() based on the dynamic type of bptr
void print(Base* bptr) 
{
    bptr->iam();  // Calls the appropriate iam() function based on actual type
}

int main()
 {
    Base b;
    D1 d1;
    D2 d2;

    print(&b);   // Outputs "Base"
    print(&d1);  // Outputs "D1"
    print(&d2);  // Outputs "D2"

    return 0;
}
