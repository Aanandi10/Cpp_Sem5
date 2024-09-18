#include <iostream>
const char* createString(){
    return "Practice makes a man perfect";
}
int* createInt(){
    int x = 100;
    return &x;
}
int main(){
    const char *str = createString();
    std::cout << "string = " << str << std::endl;
    int *ip = createInt();
    std::cout << "integer = " << *ip << std::endl;
}
/* Output: warning: address of local variable 'x' returned [-Wreturn-local-addr]
     int x = 100;
         ^
string = Practice makes a man perfect */

/*
Errors:
1) No error in the createString() function because string literals have static storage duration.

2)Error in the createInt() function:
---The function returns a pointer to a local variable, which leads to undefined behavior when dereferenced.

---createInt() defines a local variable x with the value 100, then returns a pointer to x.

Problem: The variable x is local to the createInt() function, and once the function returns, the memory for x is
deallocated. The returned pointer &x now points to a location in memory that is no longer valid.

Undefined behavior: Dereferencing *ip (trying to access the value) may result in garbage or a runtime error, 
depending on the compiler and environment. It might not always crash, but it will give unpredictable results.

Fix: To avoid this issue, We should either:
--Return a pointer to dynamically allocated memory (new or malloc), or
--Return the variable by value instead of by pointer.

Corrected createInt() function:
int createInt(){
    int x = 100;
    return x;  // Return by value instead of returning a pointer to a local variable
}
*/