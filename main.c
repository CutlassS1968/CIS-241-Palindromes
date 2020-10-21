//
//  CIS 241 02, Professor Vijay Bhuse
//   Target-Heart-Rate Calculator
//
//  Created by Evan Johns on 9/13/20
//

#include <stdio.h>
#include <ctype.h>

#define SIZE 50 // Max size of the user's input

int testPalindrome(char*, int, int);
void formatString(char *);
void removeSpaces(char *);
void convertToLowercase(char *);
void copy(char *s1, const char *s2);
size_t getSize(char *);

int main() {

    char str[SIZE];     // User's string input
    char cpyStr[SIZE];  // Copy of user's input for display

    printf("Enter a phrase!\n");
    scanf("%[^\n]%*c",str);

    copy(cpyStr, str);
    formatString(str);

     if (testPalindrome(str, 0, getSize(str))) {
         printf("\"%s\" is a palindrome!", cpyStr);
     } else {
         printf("\"%s\" is not a palindrome.", cpyStr);
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

// Formats a string to be in lowercase and have no spaces
void formatString(char * str) {
    convertToLowercase(str);
    removeSpaces(str);
}

// Removes all spaces in a string
void removeSpaces(char* str) {
    const char* del = str;
    do {
        while (*del == ' ') {
            del++;
        }
    } while (*str++ = *del++);
}

// Converts a string input to lowercase
void convertToLowercase(char *str) {
    while (*str != '\0') {
        *str = tolower(*str);
        ++str;
    }
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
