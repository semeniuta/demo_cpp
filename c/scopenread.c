/*
 * A demostration of open, read, close system calls 
 * and error handling functionality 
 * (perror, strerror, errno, fprintf to stderr).
 * 
 * Tries to opes a file using the open system call. 
 * If successful, counts the file's size in bytes.
 * On error, prints the details to stderr
 * (different options are demonstrated).
 * 
 */

#include <stdio.h> // printf, fprintf, perror
#include <string.h> // strerror
#include <stdlib.h> // exit

#include <unistd.h> // read
#include <errno.h> // errno
#include <fcntl.h> // open, O_RDONLY

int main(int argc, char *argv[]) {

    char* fname;
    int input_fd;
    int n_bytes_read;
    const size_t buffer_size = 64;
    char buff[buffer_size];
    int file_size;
    int close_status;

    if (argc == 1) {
        fname = "nosuchfile.txt";
    } else if (argc == 2) {
        fname = argv[1];
    } else {
        printf("Wrong command format\n");
        exit(-1);
    }

    input_fd = open(fname, O_RDONLY);
    if (input_fd == -1) {
        
        perror("open");

        fprintf(stderr, "Error when opening %s: %s\n", fname, strerror(errno));

        fprintf(stderr, "errno: %d\n", errno);

        exit(-1); 

    }

    printf("File %s opened successfully (file descriptor: %d)\n", fname, input_fd);

    while ((n_bytes_read = read(input_fd, buff, buffer_size)) != 0) {
        file_size += n_bytes_read;
    }

    printf("Size of %s in bytes: %d\n", fname, file_size);

    close_status = close(input_fd);
    if (close_status == -1) {
        perror("close");
    }

    exit(0);

}