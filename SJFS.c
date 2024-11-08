#include <stdio.h>

int main() {
    int A[100][5];  
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("Enter Arrival Time and Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &A[i][1]);  
        printf("Burst Time: ");
        scanf("%d", &A[i][2]);  
        A[i][0] = i + 1;       
    }
    
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++) {
            if (A[j][1] < A[index][1]) 
                index = j;
        }
        for (j = 0; j < 5; j++) {
            temp = A[i][j];
            A[i][j] = A[index][j];
            A[index][j] = temp;
        }
    }

    A[0][3] = 0;  
    total = 0;
    for (i = 1; i < n; i++) {
        A[i][3] = 0;
        for (j = 0; j < i; j++) {
            A[i][3] += A[j][2]; 
        }
        A[i][3] -= A[i][1];  
        if (A[i][3] < 0) A[i][3] = 0; 
        total += A[i][3];
    }
    avg_wt = (float)total / n;
    
    total = 0;
    printf("P\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        A[i][4] = A[i][2] + A[i][3];  
        total += A[i][4];
        printf("P%d\t%d\t%d\t%d\t%d\n", A[i][0], A[i][1], A[i][2], A[i][3], A[i][4]);
    }
    avg_tat = (float)total / n;

    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

