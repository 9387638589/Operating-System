//Write a program (using fork() and/or exec() commands) where parent and child execute: b) same program, different code.//
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process executing same program, different code.\n");
    } else if (pid > 0) {
        // Parent process
        printf("Parent process executing same program, different code.\n");
        wait(NULL); // Wait for the child to finish
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }

    return 0;
}