#include <string.h>
#include <ctype.h>
#include <iostream> 

void reverse_substring(char ss[], int start, int end) 
{
    while (start < end)
        {
        // Swap characters at indices start and end
        char temporary = ss[start];
        ss[start] = ss[end];
        ss[end] = temporary;
            
        // Move towards the middle
        start++;
        end--;
    }
}
int find_next_start(char ss[], int len, int i) 
{
    // Move forward until we find an alphabetic character
    //The isalpha() function in C++ checks if the given character is an alphabet or not. It is defined in the cctype header file
    while (i < len && !isalpha(ss[i]))
        {
        i++;
        }
    
    // Return -1 if no alphabetic character is found
    return (i < len) ? i : -1;
}

int find_next_end(char ss[], int len, int i) 
{
    // Move forward until we find a non-alphabetic character
    while (i < len && isalpha(ss[i]))
        {
        i++;
        }
    // Return the index of the first non-alphabetic character after the word
    return i;
}
void reverse_words(char ss[])
{
    int len = strlen(ss);  // Get the length of the string
    int start = 0;

    // Iterate through the string and reverse each word
    while ((start = find_next_start(ss, len, start)) != -1)
        {
        int end = find_next_end(ss, len, start) - 1;
        reverse_substring(ss, start, end);
        // Move to the next part of the string after the current word
        start = end + 1;
       }
}



 
