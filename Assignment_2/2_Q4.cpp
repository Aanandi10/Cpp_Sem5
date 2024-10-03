#include <iostream>
using namespace std;

/*
This is a valid function declaration in C++ where parameters are assigned default values.
If no arguments are provided when calling the function, the char parameter will default to '*'
and the int parameter will default to 45.
*/

void func(char = '*', int = 45);

/*
When the function is called without any arguments, both parameters take their default values.
If you pass only one argument, it will be assigned to the first parameter (char), and the second 
parameter (int) will retain its default value.
If both arguments are provided, the defaults are bypassed and the given values are used.
*/
void func(char c, int num) 
{
    cout << "Character: " << c << " | Number: " << num << endl;
}

int main() 
{
    func();          // Both parameters use their default values: '*', 45
    func('#');       // First parameter is '#', second uses default 45
    func('#', 10);   // Both parameters use provided values: '#', 10
    return 0;
}
