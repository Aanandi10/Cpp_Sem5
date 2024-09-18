#include <iostream>

// Step 1: Define a typedef for the function type.
// A function taking arguments of type pointer to character and reference to integer, and returning no value.
typedef void Func(char*, int&);

// Step 2: Define a typedef for a pointer to the function defined in Step 1.
typedef Func* FuncPtr;

// A sample function matching the type defined in Step 1.
void sampleFunction(char* c, int& i) {
    std::cout << "Character: " << *c << ", Integer: " << i << std::endl;
    i += 10;  // Modify the integer reference for demonstration.
}

// Step 3: Define a function that takes a pointer to the function defined in Step 1 as an argument.
void functionTakingPointer(FuncPtr fp) {
    char c = 'A';
    int i = 5;
    fp(&c, i);  // Call the function through the pointer.
}

// Step 4: Define a function that returns a pointer to the function defined in Step 1.
FuncPtr functionReturningPointer() {
    return &sampleFunction;
}

// Step 5: Define a function that takes a function pointer as an argument and returns the same pointer.
FuncPtr functionWithPointerArgument(FuncPtr fp) {
    return fp;
}

int main() {
    // Demonstrate usage of the functions defined.
    FuncPtr fp = &sampleFunction;

    // Call the function that takes a function pointer.
    functionTakingPointer(fp);

    // Get a function pointer from a function and call it.
    FuncPtr returnedFp = functionReturningPointer();
    char c = 'B';
    int j = 20;
    returnedFp(&c, j);

    // Use the function that returns its argument as a return value.
    FuncPtr sameFp = functionWithPointerArgument(fp);
    sameFp(&c, j);

    return 0;
}