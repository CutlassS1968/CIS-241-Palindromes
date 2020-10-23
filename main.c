//
//  CIS 241 02, Professor Vijay Bhuse
//            Palindromes
//
//  Created by Evan Johns on 10/18/2020
//

#include <stdio.h>
#include <ctype.h>

#define SIZE 200 // Max size of the user's input

int testPalindrome(char*, int, int);
void format(char *);
void copy(char *s1, const char *s2);
size_t getSize(char *);

int main() {

    char str[SIZE];     // User's string input
    char cpyStr[SIZE];  // Copy of user's input for display

    printf("\nEnter a palindrome: ");
    scanf("%[^\n]%*c",str);

    copy(cpyStr, str);
    format(str);

     if (testPalindrome(str, 0, getSize(str))) {
         printf("\n\"%s\" is a palindrome!\n\n", cpyStr);
     } else {
         printf("\n\"%s\" is not a palindrome.\n\n", cpyStr);
     }
    return 0;
}

// Copies one string to another
void copy(char *s1, const char *s2) {
    for (; (*s1 = *s2) != '\0'; ++s1, ++s2);
}

// Recursively tests if a phrase is a palindrome and returns true or false
int testPalindrome(char str[], int start, int end) {
    if (start == end) {
        return 1;
    }
    if (str[start] != str[end - 1]) {
        return 0;
    }
    if (start < end + 1) {
        return testPalindrome(str, start + 1, end - 1);
    }
    return 1;
}

// Formats a string input to remove punctuation, spaces, and convert to lowercase
void format(char *str) {
    char *sta = str;   // starting string
    char *res = str;   // resulting string

    while (*sta) {
        if (ispunct((unsigned char)*sta)) {         // removing punctuation
            sta++;
        }
        else if (isblank((unsigned char)*sta)) {    // removing spaces
            sta++;
        }
        else if (isupper((unsigned char)*sta)) {    // converting to lowercase
            *res++ = tolower((unsigned char)*sta);
            sta++;
        }
        else if (sta == res) {
            sta++;
            res++;
        }
        else {
            *res++ = *sta++;
        }
    }
    *res = 0;
}

// Returns the size of a string
size_t getSize(char *ptr) {
    int c = 0;
    do {
        if (*ptr != '\0') {
            ++c;
        }
        ptr++;
    } while (*ptr != '\0');
    return c;
}