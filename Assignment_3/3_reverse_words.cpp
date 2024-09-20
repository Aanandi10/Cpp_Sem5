#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end) {
    for (int i = 0; i < (end - start + 1) / 2; ++i) {
        char temp = str[start + i];
        str[start + i] = str[end - i];
        str[end - i] = temp;
    }
}

int find_next_start(char str[], int len, int index) {
    for (; index < len; ++index) {
        if (isalpha(str[index])) return index;
    }
    return -1;
}

int find_next_end(char str[], int len, int index) {
    for (; index < len; ++index) {
        if (!isalpha(str[index])) return index;
    }
    return len;
}

void reverse_words(char s[]) {
    int len = strlen(s);
    int start = 0;
    while (start < len) {
        start = find_next_start(s, len, start);
        if (start == -1) break;
        int end = find_next_end(s, len, start) - 1;
        reverse_substring(s, start, end);
        start = end + 2; // Advance past the space or punctuation
    }
}

