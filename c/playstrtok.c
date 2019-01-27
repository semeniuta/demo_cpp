/*
 * Split a string using strtok.
 * Demonstrtes how the original string gets changed.
 */ 

#include <stdio.h>
#include <string.h>

/*
 * Print array of characters, even if it is delimited by \0's.
 * Special characters like \n, \t are visualized as C literals
 */
void print_char_array(char* arr, size_t len) {

    char c;

    for (unsigned int i = 0; i < len; i++) {

        c = arr[i];

        if (c == 0) {
            printf("%s", "\\0");
        } else if (c == '\n') {
            printf("%s", "\\n");
        } else if (c == '\t') {
            printf("%s", "\\t");
        } else {
            printf("%c", c);
        }

    }

    printf("%c", '\n');
}

int main() {

    char s[] = "one, two,three,\tfour, five\n";
    char delimiter[] = ",\t\n ";

    size_t len = sizeof(s); // size in bytes, each element of s is a byte

    printf("Original string: ");
    print_char_array(s, len);

    char *token_p;
    token_p = strtok(s, delimiter);

    while (token_p != NULL) {

        printf("Token: \"%s\"\n", token_p);

        printf("String: ");
        print_char_array(s, len);
    
        token_p = strtok(NULL, delimiter);
    }

    return 0;

}