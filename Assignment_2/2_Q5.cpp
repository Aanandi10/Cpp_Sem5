#include <iostream>

/*
The following program increments each element of the 2D array `m` by 2.
*/

/*
In C++, it is possible to pass a 2D array to a function without specifying the number of rows.
However, the number of columns must be defined to allow the compiler to correctly access
the elements of the array. When passing a 2D array to a function in C++, the size of the second dimension (number of columns)
must be specified because the compiler needs this information to compute the memory location of
each element correctly. The number of rows (first dimension) can remain unspecified, as the column size
is sufficient for the compiler to determine the position of each element.
*/





void f1(int m[][5], int dim1) {
    for(unsigned int i = 0; i < dim1; i++)
        for(unsigned int j = 0; j < 5; j++)
            m[i][j] = m[i][j] + 2;  // Increment each element by 2
}

int main() {
    // Initialize a 2D array.
    int m[3][5] = {{1, 2, 3, 4, 5}, {11, 12, 13, 14, 15}, {21, 22, 23, 34, 25}};
    
    // Call function f1 to modify the array.
    f1(m, 3);
    
    // Print the modified array.
    for(unsigned int i = 0; i < 3; i++) {
        for(unsigned int j = 0; j < 5; j++)
            std::cout << m[i][j] << " ";
        std::cout << "\n";
    }
}
