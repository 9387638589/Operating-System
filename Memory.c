//Write a program to report behavior of Linux kernel including information on configured memory, amount of free and used memory. (memory information)//
#include <stdio.h>

int main() {
    // Print memory information
    FILE *memInfoFile = fopen("/proc/meminfo", "r");
    if (memInfoFile != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), memInfoFile) != NULL) {
            printf("%s", line);
        }
        fclose(memInfoFile);
    } else {
        perror("Error opening /proc/meminfo");
        return 1;
    }
    return 0;
}