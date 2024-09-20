#include <ctype.h>
#include <string.h>
#include <iostream>
#include "revwords.h"
#include "revwords.cpp"

using namespace std;

int main() {
    char str[] = "University of Stolkholm!";
    reverse_words(str);
    cout << str << endl;
    return 0;
}
