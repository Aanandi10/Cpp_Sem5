#include <iostream>

int main()
{
    const char* sourceStr = "C++ programming is fun!\n";
    char destinationStr[100];
    char* destPtr = destinationStr;  // Array name decays to a pointer to the first element
    while(*destPtr++ = *sourceStr++) {}  // Copy each character from source to destination
    std::cout << destinationStr;
}

/*
The output of the program is: C++ programming is fun!

#Explanation:

1. **Pointer to String:**
   const char* sourceStr = "C++ programming is fun!\n";
   - `sourceStr` is a pointer to a string literal stored in read-only memory. It points to the first character, `'C'`, in the string `"C++ programming is fun!\n"`.

2. **Character Array Declaration:**
   char destinationStr[100];
   - `destinationStr` is an array of 100 characters, which will store the copied version of the string.

3. **Pointer Initialization:**
   char* destPtr = destinationStr;
   - `destPtr` points to the first element of `destinationStr`. The array name `destinationStr` decays into a pointer to its first element, meaning `destPtr` now references `destinationStr[0]`.

4. **Character Copying (Loop):**
   while(*destPtr++ = *sourceStr++) {}
   - This loop copies characters one by one from `sourceStr` to `destinationStr`:
     - `*sourceStr` refers to the current character in the string, and `*destPtr` refers to the current position in the destination array.
     - `*destPtr++ = *sourceStr++` copies the character from `sourceStr` to `destinationStr`, then both pointers increment to the next character.
     - The loop continues until the null terminator (`'\0'`) is copied, at which point the loop stops.
*/

