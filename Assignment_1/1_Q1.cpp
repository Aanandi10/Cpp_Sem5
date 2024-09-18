#include<iostream>

int main()
{
  int days , years, weeks,input_days,rem_days;
  std::cout << "Enter the number of days :";
  std::cin >> input_days;
  
   years=input_days/365;
   rem_days = input_days%365;
   weeks= rem_days/7;
   days=rem_days%7;
   
   std::cout << input_days<< "Days :";
   if(years>0)
    std::cout<< years << ( years>1 ? "years" : "year");
    if(weeks>0)
    std ::cout<<weeks << (weeks>1 ? "weeks:" : "week:");
    if(days>0)
    std::cout<< days <<(days>1 ? "days :" :"day:");
    std ::cout <<std::ends;
    return 0;
 }
