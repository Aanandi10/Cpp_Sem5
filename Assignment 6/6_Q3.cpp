#include<iostream>
using namespace std;

struct X 
{
    // Default constructor, called when an object is created
    X() { cout << "default constructor\n"; }

    // Move constructor, called when an object is moved
    X(X&& x) { cout << "move constructor\n"; }

    // Copy constructor, called when an object is copied
    X(const X& x) { cout << "copy constructor\n"; }

    // Copy assignment operator, called when an object is assigned the value of another object
    X& operator=(const X&) 
    {
        cout << "copy assignment\n";
        return *this;
    }

    // Destructor, called when an object is destroyed
    ~X() { cout << "Destructor\n"; }
};

// Function foo accepts an object by value and returns it
X foo(X x)
{
    return x;  // Returning the object involves move semantics if supported
}

int main() 
{
    // Create an object of type X using the default constructor
    X obj;
    /* Output: default constructor is triggered when `obj` is created */

    // Pass `obj` to foo by value
    obj = foo(obj);
    /* A copy of `obj` is made when passing it to foo, which invokes the copy constructor.
       So the Output is : copy constructor is invoked to copy `obj` into `x` 
     
      When foo returns `x` by value, the move constructor is utilized to transfer
       the object back from foo's local scope. 
       So the Output is : move constructor is invoked to return the object 

     The returned object from foo (a temporary) is assigned to `obj` via the copy assignment operator.
       So the Output is: copy assignment 

     The temporary object created when returning from foo is destroyed as it goes out of scope.
       So the Output: Destructor 

     The copy of `obj` that was passed as an argument to foo is destroyed when foo ends.
     So the Output is: Destructor 

     Finally, `obj` is destroyed at the end of `main`.
       So the Output is : Destructor */
}
