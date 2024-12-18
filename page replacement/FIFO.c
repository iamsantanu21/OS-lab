#include <stdio.h>
#include <string.h>

int main() {
    int n, l, i, j, count = 0, temp;
    char page[100] = {0};  
    char sent[100];

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the input string: ");
    scanf("%s", sent);

    l = strlen(sent);

    for (i = 0; i < l; i++) {
        temp = 1; 

        for (j = 0; j < n; j++) {
            if (sent[i] == page[j]) {
                temp = 0;  
                break;
            }
        }

        if (temp == 1) {
            page[count % n] = sent[i]; 
            count++;  
        }
    }

    printf("The number of page faults are: %d\n", count);
    printf("The number of page hits are: %d\n", l - count);

    return 0;
}
