#include <iostream>
using namespace std;

int globalCounter = 0;  // Global variable to track call count

void trackGlobalCalls()
{
    globalCounter++;
    cout << "Global: I have been called " << globalCounter << " times" << endl;
}

void trackStaticCalls()
{
    static int staticCounter = 0;  // Static variable to track call count, limited to this function's scope
    staticCounter++;
    cout << "Static:  I have been called " << staticCounter << " times" << endl;
}

int main()
{
    cout << "Invoking the Global Call Tracker:" << endl;
    for (int i = 0; i < 10; i++)
    {
        trackGlobalCalls();
     }

    cout << "\nInvoking the Static Call Tracker:" << endl;
    for (int i = 0; i < 10; i++) 
    {
        trackStaticCalls();
    }

    return 0;
}

/*
Using a static local variable within a function is generally preferable. 
It restricts the variable's scope to the function itself, which helps to prevent unintended 
modifications elsewhere in the program. This approach also ensures that the function is self-contained 
and simpler to maintain.
*/

/*
A regular local variable would get reinitialized on every function call, meaning it would lose
its value after each execution. Consequently, it wouldn't be able to track how many times 
the function has been called as it would always reset to its initial value.
*/
