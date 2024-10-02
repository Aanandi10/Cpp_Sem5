#include <iostream>
#include "revwords.h"  // Assuming you have the prototypes here

int main() 
{
    char ss[] = "University of Cambridge!";
    reverse_words(ss);
    std::cout << ss << std::endl;  // The desired output is "ytisrevinU fo egdirbmaC!"
    return 0;
}
