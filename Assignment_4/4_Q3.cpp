#include <iostream>

const char* createString() {
    // This function works correctly because the string literal "Practice makes a man perfect"
    // is stored in a read-only section of memory and returns a pointer to that string.
    return "Practice makes a man perfect";
}

int* createInt() {
    int x = 100;
    // Error: x is a local variable, which will go out of scope after this function returns.
    // Returning the address of a local variable leads to undefined behavior, as the memory 
    // for x will no longer be valid after the function ends.
    return &x; 
}

int main() {
    const char *str = createString();
    std::cout << "string = " << str << std::endl;
    
    int *ip = createInt();
    // Error: createInt() returns a pointer to a local variable, which is no longer valid.
    // Dereferencing *ip here leads to undefined behavior because the memory for x has
    // already been deallocated.
    std::cout << "integer = " << *ip << std::endl;
}

/*
Summary of Errors:
1. Returning a pointer to a local variable (createInt):
The local variable x is stored on the stack and is destroyed once the function createInt() returns. Dereferencing this invalid pointer in the main function results in undefined behavior.

2. The string literal in createString:
This function works because string literals have static storage duration, meaning the string exists for the lifetime of the program. 
There are no issues here.
/*
