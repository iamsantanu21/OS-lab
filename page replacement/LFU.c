#include <stdio.h>

void main() {
    int q[20], p[50], pageHits = 0, pageFaults = 0, c1, f, i, j, k = 0, n, r, c2[20];
    
    printf("Enter no of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    
    printf("Enter no of frames: ");
    scanf("%d", &f);
    
    q[k] = p[k];
    pageFaults++;
    k++;

    for (i = 1; i < n; i++) {
        c1 = 0;
        
        for (j = 0; j < f; j++) {
            if (p[i] == q[j]) {
                c1 = 1;
                break;
            }
        }

        if (c1 == 1) {
            pageHits++;
        }
        else {
            pageFaults++; 
            if (k < f) {
                q[k] = p[i];
                k++;
            } else {
                for (r = 0; r < f; r++) {
                    c2[r] = 0;
                    for (j = i + 1; j < n; j++) {
                        if (q[r] != p[j])
                            c2[r]++;
                        else
                            break; 
                    }
                }

                int maxDistance = c2[0], maxIndex = 0;
                for (r = 1; r < f; r++) {
                    if (c2[r] > maxDistance) {
                        maxDistance = c2[r];
                        maxIndex = r;
                    }
                }

                q[maxIndex] = p[i];
            }
        }
    }
    
    printf("\nTotal Page Hits: %d\n", pageHits);
    printf("Total Page Faults: %d\n", pageFaults);
}
