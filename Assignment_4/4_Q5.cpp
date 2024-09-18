#include <iostream>
using namespace std;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x,y;
    cout<<"Enter The First Integer: ";
    cin>>x;
    cout<<"Enter The Second Integer: ";
    cin>>y; 
    cout << "Before swap: x = " << x << ", y = " << y <<endl;
    
    swap(&x, &y);  // Pass addresses of x and y
    
    cout << "After swap: x = " << x << ", y = " << y <<endl;
    return 0;
}