#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 10

int mutex = 1, n, empty, full = 0, item, item1;
int buffer[BUFFERSIZE];
int in = 0, out = 0;

void waitSemaphore(int *s) {
    while (*s <= 0) {
        printf("\nCannot proceed, waiting...\n");
        exit(0);
    }
    (*s)--;
}

void signalSemaphore(int *s) {
    (*s)++;
}

void producer() {
    do {
        waitSemaphore(&empty);
        waitSemaphore(&mutex);
        printf("\nEnter an item: ");
        scanf("%d", &item);
        buffer[in] = item;
        in = (in + 1) % BUFFERSIZE;  // Circular buffer handling
        signalSemaphore(&mutex);
        signalSemaphore(&full);
    } while (in < n);
}

void consumer() {
    do {
        waitSemaphore(&full);
        waitSemaphore(&mutex);
        item1 = buffer[out];
        printf("\nConsumed item = %d", item1);
        out = (out + 1) % BUFFERSIZE;  // Circular buffer handling
        signalSemaphore(&mutex);
        signalSemaphore(&empty);
    } while (out < n);
}

int main() {
    printf("Enter the value of n (number of items): ");
    scanf("%d", &n);
    empty = BUFFERSIZE;

    while (in < n)
        producer();
    
    while (out < n)
        consumer();

    return 0;
}
