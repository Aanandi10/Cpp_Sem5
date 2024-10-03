#include <iostream>
using namespace std;

int main() 
{
    // Problem 1: Modifying a string literal
    // Original: char *str = "India vs Pakistan, Asia Cup 2023";
    // Fix: Use a modifiable array instead of a string literal
    char str[] = "India vs Pakistan, Asia Cup 2023";
    str[7] = 'V';  // Safe to modify since it's now an array
    cout << "Modified string = " << str << endl;

    // Problem 2: Array out of bounds access
    double darr[] = {2.3, 4.5, 5.5};
    darr[2] = 6.5;  // Fix: Ensure we modify within the bounds of the array
    cout << "Updated darr[2] = " << darr[2] << endl;

    // Problem 3: Use of `extern` without definition
    // Original: extern float f;  // This would cause a linker error
    // Fix: Either remove or define `f`
    float f = 1.5;  // Defining `f` here to avoid the extern issue
    float g = f * 100.5;
    cout << "g = " << g << endl;

    // Problem 4: Invalid casting from void* to int*
    short int i = 89;
    void *v = &i;  // v points to a short int
    short int *ip = static_cast<short int*>(v);  // Fix: Proper casting to short int*
    cout << "integer = " << *ip << endl;

    return 0;
}

/*
Explanation of Changes:
1. **String Literal Modification**: String literals are stored in read-only memory, so attempting to modify them will cause a runtime error. 
   - Solution: Declare `str` as a character array, allowing modifications.
   
2. **Array Out of Bounds**: The original program attempted to access an out-of-bounds element of `darr[]`, which causes undefined behavior.
   - Solution: Modify an element within the valid index range.

3. **Use of `extern` without Definition**: The original program declared `extern float f;` but never defined `f`, causing a linker error.
   - Solution: Define the variable `f` within the program.

4. **Invalid Casting from `void*` to `int*`**: The original program tried to cast a `void*` holding a `short int` address to an `int*`, which leads to invalid memory access due to size differences.
   - Solution: Properly cast the `void*` back to a `short int*` before dereferencing it.
*/
