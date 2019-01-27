/*
 * Read strings from stdin using scanf 
 * until EOF is encountered.
 * 
 * Example:
 * gcc readstrings.c -o reads
 * ./reads < data/textlines.txt
 * 
 */

#include <stdio.h>

int main() {

    char s[1000];
    
    int n_elements;
    while ((n_elements = scanf("%s", s)) != EOF) {
        printf("Read (%d): %s\n", n_elements, s);
    }

    return 0;
}