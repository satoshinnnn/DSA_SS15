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
    printf("\n");
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
}
int main() {
    Queue qOld, qNormal;
    initQueue(&qOld);
    initQueue(&qNormal);
    int choice;
    char name[MAX_NAME];
    int age;
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

                printf("Nhap tuoi: ");
                scanf("%d", &age);
                getchar();
                if (age>= 60)  enQueue(&qOld, name);
                else enQueue(&qNormal, name);
                break;
            case 2:
                if (!isEmpty(&qOld)) deQueue(&qOld);
                else deQueue(&qNormal);
                break;
            case 3:
                printf("Hang doi nguoi gia: \n");
                displayQueue(&qOld);
                printf("\n");
                printf("Hang doi nguoi binh thuong: \n");
                displayQueue(&qNormal);
                printf("\n");
                break;
            case 4:
                printf("Thoat truong chinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                printf("\n");
                break;
        }
    } while (choice != 4);
}