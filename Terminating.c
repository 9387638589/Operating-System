//Write a program (using fork() and/or exec() commands) where parent and child execute: c)    before terminating, the parent waits for the child to finish its task.//
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process executing its task.\n");
        // Add the code for the task the child process needs to perform

    } else if (pid > 0) {
        // Parent process
        printf("Parent process waiting for the child to finish.\n");
        wait(NULL); // Wait for the child to finish
        printf("Parent process exiting after child's task is completed.\n");
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }

    return 0;
}
