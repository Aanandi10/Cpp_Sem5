#ifndef REVWORDS_H
#define REVWORDS_H

#include <string> //This includes the standard C++ string library so that std::string can be used in the function prototypes.

// Function is to reverse the characters of a word within a given range from start to end of the string.
void reverseWord(std::string &s, int start, int end);



// Function is to reverse each word within a given string while keeping the order of the words the same.
void reverseWordsInString(std::string &s);

#endif
