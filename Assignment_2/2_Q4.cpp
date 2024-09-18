/*No the declaration "void func(char= '*', int =45);" is not valid in c++

in C++,when defining function paramter with default values, you must specify the 
data type for each paramter. The correct way to declare this fuction would be:*/

void func(char ch= '*', int=45);

/*If we declare this way the compiler wil generate a syntex error. The compiler will complain
that declaration is not valid because it expects a type before the parameter name. we will see
an error message indicating a "type name is not allowed"*/