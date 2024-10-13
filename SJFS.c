#include <stdio.h>

int main() {
    // Matrix for storing Process Id, Arrival Time, Burst Time, Waiting Time, and Turn Around Time
    int A[100][5];  // 0: Process ID, 1: Arrival Time, 2: Burst Time, 3: Waiting Time, 4: Turn Around Time
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;
    
    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    // Input arrival time and burst time
    printf("Enter Arrival Time and Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &A[i][1]);  // Arrival Time
        printf("Burst Time: ");
        scanf("%d", &A[i][2]);  // Burst Time
        A[i][0] = i + 1;        // Process ID
    }
    
    // Sorting processes according to Arrival Time
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++) {
            if (A[j][1] < A[index][1])  // Sorting by Arrival Time
                index = j;
        }
        // Swapping elements
        for (j = 0; j < 5; j++) {
            temp = A[i][j];
            A[i][j] = A[index][j];
            A[index][j] = temp;
        }
    }

    // Waiting Time calculation
    A[0][3] = 0;  // First process has no waiting time
    total = 0;
    for (i = 1; i < n; i++) {
        A[i][3] = 0;
        for (j = 0; j < i; j++) {
            A[i][3] += A[j][2];  // Waiting time is the sum of previous burst times
        }
        A[i][3] -= A[i][1];  // Subtract the arrival time to get correct waiting time
        if (A[i][3] < 0) A[i][3] = 0;  // If waiting time is negative, set it to 0
        total += A[i][3];
    }
    avg_wt = (float)total / n;
    
    // Turnaround Time calculation and output
    total = 0;
    printf("P\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        A[i][4] = A[i][2] + A[i][3];  // Turnaround time = burst time + waiting time
        total += A[i][4];
        printf("P%d\t%d\t%d\t%d\t%d\n", A[i][0], A[i][1], A[i][2], A[i][3], A[i][4]);
    }
    avg_tat = (float)total / n;

    // Output average waiting and turnaround times
    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

