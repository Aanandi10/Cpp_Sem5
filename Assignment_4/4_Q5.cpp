#include <iostream>
using namespace std;

// Swap function using pointers
void swapUsingPointers(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Swap function using references
void swapUsingReferences(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main() 
{
    int x = 10, y = 20;
    
    // Swap using pointers
    cout << "Before swap (using pointers): x = " << x << ", y = " << y << endl;
    swapUsingPointers(&x, &y);  // Pass the addresses of x and y
    cout << "After swap (using pointers): x = " << x << ", y = " << y << endl;

    // Reinitialize x and y for the next test
    x = 10;
    y = 20;

    // Swap using references
    cout << "\nBefore swap (using references): x = " << x << ", y = " << y << endl;
    swapUsingReferences(x, y);  // Pass x and y by reference
    cout << "After swap (using references): x = " << x << ", y = " << y << endl;

    return 0;
}
