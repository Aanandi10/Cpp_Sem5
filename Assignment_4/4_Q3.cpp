#include <iostream>

const char* createString() {
    // This function works correctly because the string literal "Practice makes a man perfect"
    // is stored in a read-only section of memory and returns a pointer to that string.
    return "Practice makes a man perfect";
}

int createInt() {
    int x = 100;
    // The integer value x is returned by value. This avoids the issue of returning a pointer
    // to a local variable, which would result in undefined behavior.
    return x;  // Return the integer value instead of its address
}

int main() {
    // Calling createString() returns a pointer to a string literal.
    // The string literal has static storage duration and remains valid throughout the program's execution.
    const char *str = createString();
    std::cout << "string = " << str << std::endl;

    // Calling createInt() returns the value of the integer (not a pointer).
    int val = createInt();  // Store the returned value in a variable
    std::cout << "integer = " << val << std::endl;

    /*
    Output Explanation:
    - When you call createString(), it returns a pointer to the string literal "Practice makes a man perfect".
      This string is stored in a read-only section of memory and remains valid throughout the program's execution.
      Therefore, the line `std::cout << "string = " << str << std::endl;` outputs:
      string = Practice makes a man perfect

    - When you call createInt(), it returns the integer value 100 (not a pointer).
      Since the value is returned directly, there are no issues with scope or memory deallocation, and the value
      is safely stored in the variable `val`. The line `std::cout << "integer = " << val << std::endl;` outputs:
      integer = 100

    Fixing the Original Issue:
    - The original version attempted to return a pointer to a local variable in createInt(), which would result in
      undefined behavior since the local variable's memory is deallocated after the function returns.
    - In the updated version, returning the integer by value avoids the issue of memory deallocation and ensures
      the program runs safely and correctly.
    */
}
