#include <iostream>

int main() 
{
    // 1. Pointer to a character
    char ch = 'A';
    char* ptrToChar = &ch;
    std::cout << "Pointer to char: " << *ptrToChar << std::endl;

    // 2. Array of 10 integers
    int intArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Array of 10 integers: ";
    for (int i = 0; i < 10; i++) 
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // 3. Reference to an array of 10 integers
    int (&refToArray)[10] = intArray;
    std::cout << "Reference to array of 10 integers: ";
    for (int i = 0; i < 10; i++) 
    {
        std::cout << refToArray[i] << " ";
    }
    std::cout << std::endl;

    // 4. Pointer to an array of character strings 
    const char* strArray[3] = {"Hello", "OOP", "C++"};
    const char** ptrToStrArray = strArray;
    std::cout << "Pointer to array of Character strings: " << ptrToStrArray[0] << ", " << ptrToStrArray[1] << ", " << ptrToStrArray[2] << std::endl;

    // 5. Pointer to a pointer to a character
    char ch2 = 'X';
    char* ptrToChar2 = &ch2;
    char** ptrToPtrChar = &ptrToChar2;
    std::cout << "Pointer to pointer to char: " << **ptrToPtrChar << std::endl;

    // 6. Constant integer
    const int constInt = 42;
    std::cout << "Constant integer: " << constInt << std::endl;

    // 7. Pointer to a constant integer
    const int value = 100;
    const int* ptrToConstInt = &value;
    std::cout << "Pointer to constant integer: " << *ptrToConstInt << std::endl;

    // 8. Constant pointer to an integer
    int num = 50;
    int* const constPtrToInt = &num;
    std::cout << "Constant pointer to integer: " << *constPtrToInt << std::endl;

    // 9. Constant pointer to a constant double
    const double pi = 3.14159;
    const double* const constPtrToConstDouble = &pi;
    std::cout << "Constant pointer to constant double: " << *constPtrToConstDouble << std::endl;

    return 0;
}
