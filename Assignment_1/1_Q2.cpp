#include<iostream>

int main()
{
 double x ,y,z,w, result;
 std:: cout << "Enter the value of x :";
 std:: cin >> x;
 y=1/x;
 z=1/(x+y);
 w=1/(x+z);
 result =  x+w;
 std::cout<< result;
 return 0;
}
 
