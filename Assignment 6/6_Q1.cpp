#include <iostream>

class myvector
{
    int *p; // base pointer of the vector
    unsigned int size; // size of the vector
    bool shallow; // flag indicating whether this is a shallow copy

public:
    /* Create an empty vector */
    myvector() : p(nullptr), size(0), shallow(false) {}

    /* Create a vector of length n initialized to 0 */
    myvector(unsigned int n) : size(n), shallow(false)
    {
        p = new int[size];
        for (unsigned int i = 0; i < size; ++i) 
        {
            p[i] = 0;
        }
    }

    /* Copy constructor. Can be shallow or deep depending on the option */
    myvector(myvector& v, bool shallow = true) : size(v.size), shallow(shallow)
    {
        if (shallow) 
        {
            p = v.p; // just copy the pointer, shallow copy
        } 
        else 
        {
            p = new int[size]; // deep copy, allocate new memory
            for (unsigned int i = 0; i < size; ++i) 
            {
                p[i] = v.p[i];
            }
        }
    }

    /* Return the base pointer to the vector */
    int* get_ptr() const { return p; }

    /* Return the size of the vector */
    constexpr unsigned int get_size() const { return size; }

    /* Return the shallow flag */
    bool is_shallow() const { return shallow; }

    /* Update the element at index i with val */
    void update(unsigned int i, int val)
    {
        if (i < size) 
        {
            p[i] = val;
        }
    }

    /* Return the element at index i */
    constexpr int get(unsigned int i) const 
    {
        if (i < size)
        {
            return p[i];
        }
        return -1; // return an invalid value if out of bounds
    }

    /* Print the vector contents in the console */
    void print() const 
    {
        for (unsigned int i = 0; i < size; ++i) 
        {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }

    /* Expand the vector and insert a new value at the end */
    void push_back(int val)
    {
        int* new_p = new int[size + 1];
        for (unsigned int i = 0; i < size; ++i)
        {
            new_p[i] = p[i];
        }
        new_p[size] = val; // add new element
        if (!shallow) 
        {
            delete[] p; // free old memory for deep copies
        }
        p = new_p;
        ++size;
    }

    /* Destructor */
    ~myvector() 
    {
        if (!shallow)
        {
            delete[] p; // free memory only for deep copies
        }
    }
};

int main() 
{
    myvector x(7); /* create a vector of size 7 initialized all to 0 */
    for (unsigned int i = 0; i < 7; i++) 
    {
        x.update(i, 10 + 5 * i);
    }

    myvector v{x}; // shallow copy
    v.update(1, 100);
    v.print(); // prints 10 100 20 25 30 35 40
    x.print(); // prints 10 100 20 25 30 35 40 (since v is shallow copy)

    myvector y{x, false}; // deep copy
    y.update(1, 200);
    y.print(); // prints 10 200 20 25 30 35 40
    x.print(); // prints 10 100 20 25 30 35 40 (x unchanged after deep copy)

    // push_back 500 on y and verify
    y.push_back(500);
    y.print(); // prints 10 200 20 25 30 35 40 500

    return 0;
}
