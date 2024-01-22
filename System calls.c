//Write a program to copy files using system calls.//
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // Open the source file for reading
    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        return 1;
    }

    // Create or open the destination file for writing
    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(source_fd);
        return 1;
    }

    // Copy the contents from source to destination
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    while ((bytesRead = read(source_fd, buffer, sizeof(buffer))) > 0) {
        bytesWritten = write(dest_fd, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Error writing to destination file");
            close(source_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading from source file");
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    // Close the file descriptors
    close(source_fd);
    close(dest_fd);

    printf("File copy successful: %s -> %s\n", argv[1], argv[2]);

    return 0;
}