#include <iostream>

int main()
{
    // Declare a pointer to a constant C-style string
    const char* str1 = "We love C++ programming\n";  // Points to a string literal stored in read-only memory
    
    // Declare an uninitialized character array with 100 elements
    char str2[100];  // This will store a copy of the string from str1

    // Declare a pointer 'p' and initialize it to point to the first element of str2
    char *p = str2;  // 'p' points to str2[0], the start of the array
    
    // Copy the string from str1 to str2 using a while loop
    // The loop continues until the null terminator '\0' is copied
    while(*p++ = *str1++){}

    // Output the contents of str2, which now holds a copy of the string from str1
    std::cout << str2;  // Prints "We love C++ programming" followed by a newline

    return 0;
}

/*
Explanation of the output:

1. The string "We love C++ programming\n" is pointed to by 'str1'.
   It includes the newline character '\n' at the end.

2. A character array 'str2' is declared with enough space (100 elements) to store the copied string.

3. A pointer 'p' is used to point to the start of the array 'str2'. 
   The pointer 'str1' and 'p' move through their respective arrays 
   and copy the characters one by one until the null terminator '\0' is reached.

4. Once the null terminator '\0' is copied, the loop stops, and 'str2' contains the 
   entire string "We love C++ programming\n" followed by the null terminator '\0'.

5. The 'std::cout' statement then prints the string stored in 'str2', 
   which is the same as the string originally pointed to by 'str1'.

6. The final output will be:
   We love C++ programming
   (followed by a newline due to '\n' in the original string).
*/
