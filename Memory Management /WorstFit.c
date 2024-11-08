#include <stdio.h>

int main() {
    int nb, blockSize[100], n, jobSize[100], i, j, alloc[100], avail[100], max;

    printf("Enter the number of available memory blocks: ");
    scanf("%d", &nb);
    printf("Enter the size of each memory block: \n");
    for (i = 0; i < nb; i++) {
        printf("Size of block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the size of each process: \n");
    for (i = 0; i < n; i++) {
        printf("Size of process %d: ", i + 1);
        scanf("%d", &jobSize[i]);
    }

    for (i = 0; i < n; i++) {
        alloc[i] = -1;
    }

    for (i = 0; i < n; i++) {
        max = -1;  
        for (j = 0; j < nb; j++) {
            if (blockSize[j] >= jobSize[i]) {  
                int remainingSpace = blockSize[j] - jobSize[i];
                if (remainingSpace > max) {  
                    max = remainingSpace;
                    alloc[i] = j;  
                }
            }
        }
        
        if (alloc[i] != -1) {
            blockSize[alloc[i]] -= jobSize[i];
        }
    }

    printf("Process allocation:\n");
    for (i = 0; i < n; i++) {
        if (alloc[i] != -1) {
            printf("Process %d of size %d --> Block %d\n", i + 1, jobSize[i], alloc[i] + 1);
        } else {
            printf("Process %d of size %d --> is not allocated\n", i + 1, jobSize[i]);
        }
    }

    return 0;
}
