//Write program to implement FCFS scheduling algorithm.//
#include <stdio.h>

void calculateTimes(int n, int bt[], int wt[], int tat[]) {
    // Waiting time for the first process is 0
    wt[0] = 0;
    // Calculate waiting time for each process
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];
}

void display(int n, int bt[], int wt[], int tat[]) {
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burstTime[n], waitingTime[n], turnaroundTime[n];

    // Input burst time for each process
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    // Calculate waiting time and turnaround time
    calculateTimes(n, burstTime, waitingTime, turnaroundTime);

    // Display the results
    display(n, burstTime, waitingTime, turnaroundTime);

    return 0;
}