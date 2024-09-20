#include <iostream>
using namespace std;

// Function to swap two integers using pointers
void exchange(int* first, int* second) {
    int tempVar = *first;
    *first = *second;
    *second = tempVar;
}

int main() {
    int num1, num2;

    // Taking input from the user
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Display numbers before the swap
    cout << "Before exchange: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    // Call the swap function
    exchange(&num1, &num2);  // Pass the addresses of num1 and num2
    
    // Display numbers after the swap
    cout << "After exchange: num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}
