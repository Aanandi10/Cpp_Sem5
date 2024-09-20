#include <iostream>

// Function returning a string literal (valid)
const char* generateString() {
    return "Consistency leads to success";
}

// Function returning an invalid pointer (to a local variable)
int* generateInt() {
    int num = 500;
    return &num;  // Warning: returning address of a local variable
}

int main() {
    const char *message = generateString();
    std::cout << "Message = " << message << std::endl;

    int *intPtr = generateInt();
    std::cout << "Integer = " << *intPtr << std::endl;  // Undefined behavior
}

/* Output: warning: address of local variable 'num' returned [-Wreturn-local-addr]
     int num = 500;
         ^

Message = Consistency leads to success

#Explanation:

1) No issue in the `generateString()` function:
   - String literals like `"Consistency leads to success"` have static storage duration, so they remain valid for the entire program's execution.

2) Issue in the `generateInt()` function:
   - The function `generateInt()` returns a pointer to a local variable `num`, which becomes invalid after the function ends.

- **Why is this a problem?**
   - Local variables like `num` are stored in the stack frame of the function. When the function exits, the stack frame is removed, making the memory for `num` invalid.
   - Dereferencing the pointer `intPtr` results in undefined behavior. Depending on your compiler or environment, it might give garbage data, a runtime error, or seem to work inconsistently.

#Solution:
- To fix this, we should either:
  1. Return the variable by value instead of returning a pointer to it.
  2. Use dynamic memory allocation (`new` or `malloc`).

Corrected `generateInt()` function:
```cpp
int generateInt() {
    int num = 500;
    return num;  // Return by value to avoid issues with local variables
}
