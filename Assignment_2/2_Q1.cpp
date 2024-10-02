#include <iostream>

// Step 1: Define a typedef for the function type.
// A function accepting a character pointer and a reference to an integer, returning void.
typedef void FuncType(char*, int&);

// Step 2: Define a typedef for a pointer to the function described in Step 1.
typedef FuncType* FuncPointer;

// Sample function that matches the type specified in Step 1.
void demoFunction(char* charPtr, int& intRef) 
{
    std::cout << "Char value: " << *charPtr << ", Integer: " << intRef << std::endl;
    intRef += 80;  // Modifies the integer reference for demonstration purposes.
}

// Step 3: A function that takes a pointer to a function defined in Step 1.
void executeFunction(FuncPointer func) 
{
    char character = 'X';
    int number = 3;
    func(&character, number);  // Invokes the function via the pointer.
}

// Step 4: A function that returns a pointer to the function defined in Step 1.
FuncPointer getFunctionPointer() 
{
    return &demoFunction;
}

// Step 5: A function that takes a function pointer as an argument and returns the same pointer.
FuncPointer processFunctionPointer(FuncPointer func)
{
    return func;
}

int main() 
{
    // Demonstrating the usage of function pointers.
    FuncPointer functionPtr = &demoFunction;

    // Invoking the function that takes a function pointer.
    executeFunction(functionPtr);

    // Receiving a function pointer from a function and using it.
    FuncPointer receivedFunc = getFunctionPointer();
    char anotherChar = 'Y';
    int num = 15;
    receivedFunc(&anotherChar, num);

    // Using the function that returns its input pointer.
    FuncPointer sameFunc = processFunctionPointer(functionPtr);
    sameFunc(&anotherChar, num);

    return 0;
}
