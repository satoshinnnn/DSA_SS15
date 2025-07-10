//
// Created by Admin on 10/07/2025.
//
#include <stdio.h>
#include <string.h>
#define MAX 100
#define MAX_NAME 30
typedef struct {
    char arr[MAX][MAX_NAME];
    int front;
    int rear;
}Queue;
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}
int isEmpty(Queue* q) {
    return q->front > q->rear;
}
int isFull(Queue* q) {
    return q->rear == MAX -1;
}
// ham them khach hang vao hang doi
void enQueue(Queue* q, char* name) {
    if (isFull(q)) {
        printf("Khong them duoc khach hang moi\n");
        return;
    }
    if (strlen(name)>MAX_NAME) {
        printf("Ten khong duoc dai qua 30 ki tu\n");
        return;
    }
    strcpy(q->arr[++q->rear], name);
    printf("Them khach hang %s thanh cong!\n", name);
    printf("\n");
}
// ham xoa khach hang dau va tra ve gia ve ten (phuc vu)
void deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }
    char* frontV = q->arr[q->front];
    printf("Da phuc vu khach %s \n", frontV);
    q->front++;
}
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong \n");
        printf("\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s, ", q->arr[i]);
    }
    printf("\n");
}
int main() {
    Queue q;
    initQueue(&q);
    int choice;
    char name[100];
    do {
        printf("1. Them khach hang moi: \n");
        printf("2. Phuc vu\n");
        printf("3. Hien thi danh sach khach hang dang cho\n");
        printf("4. Thoat truong trinh\n");
        printf("Chon hanh dong: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Nhap ten khach hang: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                enQueue(&q, name);
                break;
            case 2:
                deQueue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Thoat truong chinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    } while (choice != 4);
}