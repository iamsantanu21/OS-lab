#include <stdio.h>

struct Process {
    int pid;        // Process ID
    int bt;         // Burst Time
    int at;         // Arrival Time
};

void findWaitingTime(struct Process proc[], int n, int wt[]) {
    int service_time[n];
    service_time[0] = proc[0].at;  // Service time of first process is its arrival time
    wt[0] = 0;  // First process does not wait

    for (int i = 1; i < n; i++) {
        // Add burst time of previous processes
        service_time[i] = service_time[i - 1] + proc[i - 1].bt;
        // Calculate waiting time
        wt[i] = service_time[i] - proc[i].at;
        
        // If waiting time is negative, it means the process arrived after
        // the previous process completed, so set it to 0
        if (wt[i] < 0) {
            wt[i] = 0;
        }
    }
}

void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i];
    }
}

void findAverageTime(struct Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(proc, n, wt);

    // Function to find turn around time for all processes
    findTurnAroundTime(proc, n, wt, tat);

    // Display processes along with all details
    printf("\nProcesses   Arrival Time   Burst Time   Waiting Time   Turn-Around Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d ", proc[i].pid);
        printf("           %d ", proc[i].at);
        printf("           %d ", proc[i].bt);
        printf("           %d ", wt[i]);
        printf("              %d\n", tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", (float)total_wt / (float)n);
    printf("Average Turn-Around Time = %.2f\n", (float)total_tat / (float)n);
}

int main() {
    int n;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1; // Process ID
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &proc[i].at);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].bt);
    }

    // Sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].at > proc[j + 1].at) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    findAverageTime(proc, n);

    return 0;
}
