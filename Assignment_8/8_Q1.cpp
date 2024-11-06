#include <iostream>
#include <vector>
#include <list>

using namespace std;

class base 
{
    int x;
    vector<double> v;

protected:
    // Protected function to print base members
    void print_base() const 
    {
        cout << "x: " << x << endl;
        cout << "v: ";
        for (const auto &elem : v)
         {
            cout << elem << " ";
         }
        cout << endl;
    }

public:
    base(int y, vector<double> z) : x{y}, v{z} {}
};

class derived : public base {
    list<bool> l;

public:
    // Constructor that initializes an empty list
    derived(int y, vector<double> z) : base(y, z) {}

    // Constructor with list initialization
    derived(int y, vector<double> z, list<bool> el) : base(y, z), l{el} {}

    // Print function to display all members
    void print() {
        print_base();  // Call base class print function
        cout << "l: ";
        for (const auto &elem : l) {
            cout << (elem ? "true" : "false") << " ";
        }
        cout << endl;
    }
};

int main() {
    derived d{10, {1.5, 2.5, 3.5}, {true, false}};
    d.print();
    return 0;
}
