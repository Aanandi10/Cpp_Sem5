#include <iostream>
using namespace std;

// Struct foo with a constructor, destructor, and an integer member initialized to 5
struct foo
 {
    foo() { cout << "foo()\n"; }  // Constructor prints when a foo object is created
    ~foo() { cout << "~foo()\n"; }  // Destructor prints when a foo object is destroyed
    int i {5};  // Member variable initialized to 5
};

// Struct obj contains a foo object and a method to return a copy of foo
struct obj 
{
    // Returns a **copy** of my_foo, instead of a reference
    foo getFoo() { return my_foo; }

    foo my_foo;  // foo object as a member of obj
};

int main()
 {
    // Dynamically allocate an obj object on the heap
    obj *o = new obj();

    // Call getFoo() to get a **copy** of my_foo, not a reference
    foo val = o->getFoo();  // val is a copy of my_foo, so it's independent

    // Access the member `i` of val (which is a copy of my_foo)
    cout << "val.i=" << val.i << endl;  // This will print val.i = 5

    // Delete the dynamically allocated obj object (this destroys my_foo inside obj)
    delete o;  // The destructor of my_foo is called here, prints "~foo()"

    // Access val again after obj is deleted.
    // Since val is a copy, it's still valid even after deleting o
    cout << "val.i=" << val.i << endl;  // This will still print val.i = 5
/* Since val holds a reference to my_foo within o, and o has been deleted, 
   val now points to a memory location that has been freed.
   Accessing val.i at this stage results in undefined behavior,which could manifest in different ways such as a crash, random data, or incorrect values.As a result, the last line of the code produces an unpredictable outcome, often referred to as a junk value. */

    return 0;
}
