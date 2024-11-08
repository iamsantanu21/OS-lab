#include <stdio.h>

void main() {
    int cl[10][10], al[10][10], av[10], ne[10][10];
    int finished[10] = {0}, safeSequence[10];
    int i, j, k, m, n, flag = 0, count = 0;

    printf("\nEnter the number of processes and resources (m and n): ");
    scanf("%d %d", &m, &n);

    printf("\nEnter the Claim (Maximum Need) Matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cl[i][j]);
        }
    }

    printf("\nEnter the Allocated Matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &al[i][j]);
        }
    }

    printf("\nEnter the Available Resources:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &av[i]);
    }

    printf("\nThe Need Matrix is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            ne[i][j] = cl[i][j] - al[i][j];
            printf("%d\t", ne[i][j]);
        }
        printf("\n");
    }

    // Banker's Algorithm for safety check
    while (count < m) {
        int found = 0;
        for (i = 0; i < m; i++) {
            if (!finished[i]) {  // Process i is not yet finished
                flag = 1;
                for (j = 0; j < n; j++) {
                    if (ne[i][j] > av[j]) {
                        flag = 0;  // Process i cannot be completed with available resources
                        break;
                    }
                }
                if (flag) {  // Process i can be completed
                    for (k = 0; k < n; k++) {
                        av[k] += al[i][k];  // Release resources
                    }
                    safeSequence[count++] = i;
                    finished[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {  // If no process can proceed, unsafe state
            printf("\nSystem is in an Unsafe State\n");
            return;
        }
    }

    // If we get here, all processes have been safely sequenced
    printf("\nSystem is in a Safe State.\nSafe Sequence: ");
    for (i = 0; i < count; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
}
