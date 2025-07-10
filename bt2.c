//
// Created by Admin on 10/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *arr;
    int front;
    int rear;
    int maxSize;
}Queue;
Queue initQueue(int maxSize) {
    Queue q;
    q.arr = (int*)malloc(maxSize*sizeof(int));
    q.front = 0;
    q.rear = -1;
    q.maxSize = maxSize;
    return q;
}
int isEmpty(Queue* q) {
    return q->front > q->rear;
}
int isFull(Queue* q) {
    return q->rear == q->maxSize - 1;
}
void enQueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->arr[++q->rear] = value;
}
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
}
int main () {
    int maxSize;
    printf("Enter max size: ");
    scanf("%d", &maxSize);
    Queue q = initQueue(maxSize);

    for (int i = 0; i < maxSize; i++) {
        int temp;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &temp);
        enQueue(&q, temp);
    }

    printQueue(&q);
}
