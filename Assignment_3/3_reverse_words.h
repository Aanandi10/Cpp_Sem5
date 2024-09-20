#ifndef REVWORDS_H
#define REVWORDS_H 0

/*
 * The reverse_substring function takes a character array 'str',
 * along with two indices 'start' and 'end'. It reverses the characters
 * between these two indices (inclusive).
 *
 * Precondition: Both 'start' and 'end' are valid positions within the array.
 */
extern void reverse_substring(char str[], int start, int end);

/*
 * The find_next_start function scans the string 'str' of length 'len' starting
 * from index 'i'. It looks for the next alphabetic character, marking the 
 * beginning of the next word. Returns the index of this character, or -1 if no
 * such word exists.
 *
 * Precondition: i < len.
 */
extern int find_next_start(char str[], int len, int i);

/*
 * The find_next_end function scans the string 'str' of length 'len' starting 
 * from index 'i'. It finds the first non-alphabetic character after the start
 * of a word, returning its index. This index is considered to be just after 
 * the end of the current word.
 *
 * Precondition: i < len.
 */
extern int find_next_end(char str[], int len, int i);

/*
 * The reverse_words function takes a character array 'str', and reverses the 
 * letters of every word in the array. Words are defined as sequences of 
 * alphabetic characters that are delimited by non-alphabetic characters.
 */
extern void reverse_words(char s[]);

#endif /* REVWORDS_H */

