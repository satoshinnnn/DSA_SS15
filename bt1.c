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
int main () {
    int maxSize;
    printf("Enter max size: ");
    scanf("%d", &maxSize);
    Queue q = initQueue(maxSize);

}
