#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int b[n], p[n], index[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time and Priority Value for Process %d: ", i + 1);
        scanf("%d %d", &b[i], &p[i]);
        index[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        int max_priority = p[i];
        int max_index = i;

        for (int j = i; j < n; j++) {
            if (p[j] > max_priority) {
                max_priority = p[j];
                max_index = j;
            }
        }

        swap(&p[i], &p[max_index]);
        swap(&b[i], &b[max_index]);
        swap(&index[i], &index[max_index]);
    }

    int t = 0;

    printf("Order of process execution is:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d is executed from %d to %d\n", index[i], t, t + b[i]);
        t += b[i];
    }
    printf("\n");

    printf("Process ID     Burst Time   Wait Time    Turnaround Time\n");
    int wait_time = 0;
    int total_wait_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        int turnaround_time = wait_time + b[i];
        printf("P%d            %d           %d           %d\n", index[i], b[i], wait_time, turnaround_time);

        total_wait_time += wait_time;
        total_turnaround_time += turnaround_time;

        wait_time += b[i];
    }

    double avg_wait_time = (double)total_wait_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
