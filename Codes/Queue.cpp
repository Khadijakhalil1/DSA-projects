#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    if(rear == MAX-1) printf("Overflow\n");
    else queue[++rear] = x;
}

int dequeue() {
    if(front > rear) {
        printf("Underflow\n");
        return -1;
    }
    return queue[front++];
}

int main() {
    enqueue(5); enqueue(10);
    printf("Dequeued: %d\n", dequeue());
    return 0;
}

