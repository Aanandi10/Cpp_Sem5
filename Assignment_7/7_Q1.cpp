#include <iostream>
using namespace std;

struct X
 {
    int i;

    // Constructor for initializing X with an integer
    X(int a) : i(a) {}

    // Overload the + operator for X + int
    X operator+(int a) { return X(a + i); }
};

struct Y 
{
    int i;

    // Constructor for initializing Y (needed to avoid uninitialized values)
    Y(int a = 0) : i(a) {}

    // Overload the + operator for Y + X
    Y operator+(X x)
     {
        Y y;
        y.i = x.i + i;
        return y;
    }

    // Conversion operator to int
    operator int() { return i; }
};

// Overload << for outputting X
ostream& operator<<(ostream& os, X x)
 {
    os << x.i;
    return os;
}

// Overload * operator for X * Y
X operator*(X x, Y y) { return X(x.i * y.i); }

// Sample function f taking X and returning an int
int f(X x) { return x.i; }

// Global variables
X x = 1;
Y y = y + x; // Sets y based on x
int i = 2;

int main()
 {
    cout << i + 10 << endl;              // i + 10
    cout << y + X(10) << endl;           // y + 10 (where X(10) is passed as X)
    cout << y + X(10) * y << endl;       // y + (X(10) * y)
    cout << x + y + i << endl;           // x + y + i
    cout << f(x) * f(x) + i << endl;     // f(x) * f(x) + i
    cout << f(7) << endl;                // f(7), where 7 converts to X
    cout << f(int(y)) << endl;           // f(y) where y is converted to int
    cout << y + y << endl;               // y + y
    cout << 106 + int(y) << endl;        // 106 + y where y is converted to int

    return 0;
}
