#include <iostream>
using namespace std;

int main(){
    long double x, rounded;
    int k;
    cout << "Enter the real number: ";
    cin >> x;
    cout << "Enter the positive integer k: ";
    cin >> k;
    rounded = x*k;
    rounded = (long int) (rounded + 0.5f);
    rounded /=k;
    cout << "The rounded off number is: " << rounded << endl;
    return 0;
}

	
