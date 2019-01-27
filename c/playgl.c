/*
 * Read lines from stdin or a file
 * using getline. 
 * 
 * Examples:
 * gcc playgl.c -o playgl
 * ./playgl 
 * ./playgl data/textlines.txt
 * 
 */

#include <stdio.h>

int main(int argc, char** argv) {

    size_t buff_size = 1000;
    char arr[buff_size];
    char* buff = arr;

    FILE* f;
    char *fname;

    if (argc == 1) { // No arguments
        printf("Reading from stdin\n");
        f = stdin;
    } else if (argc > 1) {
        fname = argv[1];
        printf("Reading from %s\n", fname);
        f = fopen(fname, "r");
    }

    int n_bytes;
    int counter = 0;
    while ( (n_bytes = getline(&buff, &buff_size, f)) != EOF ) {
        printf("Line %d (%d bytes): %s", counter++, n_bytes, buff);
    }

    return 0;
}