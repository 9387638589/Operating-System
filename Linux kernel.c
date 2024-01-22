//Write a program to report behavior of Linux kernel including kernel version, CPU type and model. (CPU information)//
#include <stdio.h>
#include <stdlib.h>
int main() {
    // Print Linux kernel version
    FILE *versionFile = fopen("/proc/version", "r");
    if (versionFile != NULL) {
        char versionInfo[256];
        fgets(versionInfo, sizeof(versionInfo), versionFile);
        printf("Linux Kernel Version: %s", versionInfo);
        fclose(versionFile);
    } else {
        perror("Error opening /proc/version");
        return 1;
    }

    // Print CPU information
    FILE *cpuInfoFile = fopen("/proc/cpuinfo", "r");
    if (cpuInfoFile != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), cpuInfoFile) != NULL) {
            printf("%s", line);
        }
        fclose(cpuInfoFile);
    } else {
        perror("Error opening /proc/cpuinfo");
        return 1;
    }

    return 0;
}