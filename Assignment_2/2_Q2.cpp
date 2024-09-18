/*What does the following mean? What would it be good for?
typedef int (&rifii) (int, int);*/

/*The statement typedef int (&rifii)(int, int); defines rifii as an alias for a reference
to a function that takes two int parameters and returns an int. 

This alias makes it easier to refer to functions of this type. It’s useful for simplifying 
code, especially when passing or storing function references, and improves readability by 
avoiding repetitive function signatures. For example, you can use rifii to create a reference
to a function and call it using a simpler name.*/