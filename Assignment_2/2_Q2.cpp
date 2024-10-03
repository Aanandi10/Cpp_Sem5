/*
The statement `typedef int (&rifii)(int, int);` defines a new alias `rifii` for a reference 
to any function that takes two integers as arguments and returns an integer.

- `int` represents the return type of the function.
- `&` means that `rifii` is a reference, specifically to a function.
- `(int, int)` describes the function's parameters, in this case, two `int` values.
*/

/*
This is useful in several scenarios:

1. Simplifying function references: It allows a clear and concise way to declare 
references to functions with a particular signature without repeating it.

2. Safe function references: Unlike function pointers, references guarantee that 
they will always point to a valid function, avoiding null pointer issues.

Below is a simple program that demonstrates its utility.
*/

#include <iostream>
using namespace std;

typedef int (&rifii)(int, int);  // Define a reference type for functions with the signature int(int, int)

int addition(int a, int b) 
{
    return a + b;
}

int multiplication(int a, int b) {
    return a * b;
}

// A function that takes a function reference as an argument
int operate(rifii operation, int x, int y) {
    return operation(x, y);
}

int main() {
    cout << "Sum is : " << operate(addition, 13, 2) << endl;
    cout << "Product is : " << operate(multiplication, 13, 2) << endl;
    return 0;
}
