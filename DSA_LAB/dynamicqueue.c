#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;  // The dynamic array
    int size;  // The physical array size
    int count;  // Number of items in queue
    int front;  // Location to dequeue from
    int rear;  // Location to enqueue to
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->array = (int*) malloc(size * sizeof(int));
    q->size = size;
    q->count = 0;
    q->front = 0;
    q->rear = -1;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->count == q->size) {
        q->size *= 2;
        q->array = (int*) realloc(q->array, q->size * sizeof(int));
    }
    q->rear = (q->rear + 1) % q->size;
    q->array[q->rear] = value;
    q->count++;
}

void dequeue(Queue* q) {
    if (q->count == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Removed %d from queue\n", q->array[q->front]);
    q->front = (q->front + 1) % q->size;
    q->count--;
    if (q->count <= q->size / 4) {
        q->size /= 2;
        q->array = (int*) realloc(q->array, q->size * sizeof(int));
    }
}

void display(Queue* q) {
    if (q->count == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->array[(q->front + i) % q->size]);
    }
    printf("\n");
}

int main() {
    int size = 5;
    Queue* q = createQueue(size);
    int choice, value;
    while(1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                free(q->array);
                free(q);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
