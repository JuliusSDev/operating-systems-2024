#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * Check if a given string is a palindrome
 *
 * @return true if the string is a palindrome, false otherwise
 */
bool check_for_palindrome(const char* test) {
    if (test == NULL) {
        return false;
    }

    int len = strlen(test);
    int i = 0;
    int j = len - 1;

    // start at the beginning and end of the word and compare the corresponding
    // characters
    while (i < j) {
        if (test[i] != test[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(int argc, char** argv) {
    // Check if the user has entered the correct number of arguments and suggest
    // the correct usage
    if (argc <= 2) {
        printf("Usage: word,word,word,word start:end\n");
        return 1;
    }

    // Parse the start and end values to search for palindromes
    int start = 0;
    int end = 0;
    sscanf(argv[2], "%d:%d", &start, &end);
    if (start >= end || start < 0 || end < 0) {
        printf("Invalid range! start: %d, end: %d\n", start, end);
        return 1;
    }

    // Get the first word to check
    char* current_word = strtok(argv[1], ",");
    int counter = 0;  // Counter for the number of palindromes found

    while (current_word != NULL && end > start) {
        end--;

        // Check if the current word is a palindrome and increment the counter
        // if it is
        if (check_for_palindrome(current_word)) {
            counter++;
        }
        // get next word
        current_word = strtok(NULL, ",");
    }
    printf("Anzahl gefundener Palindrome: %d\n", counter);
    return 0;
}