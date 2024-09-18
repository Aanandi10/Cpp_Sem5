#include <iostream>
int main()
{
    const char* str1 = "We love C++ programming\n";
    char str2[100];
    char *p = str2; /*name of an array is implicitly converted to pointer to the first element.*/
    while(*p++ = *str1++){}
    std::cout << str2;
}
/*
The output of the program is: We love C++ programming

#Detailed Explanation:

1. **String Initialization:**
   const char* str1 = "We love C++ programming\n";
   - `str1` points to a string literal `"We love C++ programming\n"`, stored in read-only memory. It points to the first character `'W'`.

2. **Array Declaration:**
   char str2[100];
   - `str2` is an array of 100 characters. It will store the copy of the string from `str1`.

3. **Pointer Initialization:**
   char *p = str2;
   - `p` is a pointer that points to the first element of `str2`. The name of the array `str2` is implicitly converted to a pointer to its first element, i.e., `p` now points to `str2[0]`.

4. **String Copying (Key Loop):**
   while(*p++ = *str1++){}
   - This loop copies each character from `str1` to `str2`. It works as follows:
     - `*str1` refers to the current character in `str1` and `*p` refers to the current position in `str2`.
     - `*p++ = *str1++`:
       - The current character from `str1` is assigned to `*p` in `str2`.
       - Then, both pointers `p` and `str1` are incremented (post-increment) to point to the next characters in their respective arrays.
     - This process continues until the null character (`'\0'`) is encountered in `str1`. When the null terminator is copied, the loop terminates.


*/