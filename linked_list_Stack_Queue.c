#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* push(struct Node *top, int value) {
    struct Node *newNode = createNode(value);
    newNode->next = top;
    return newNode;
}

struct Node* pop(struct Node *top, int *value) {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        *value = -1;
        return NULL;
    }

    struct Node *temp = top;
    *value = temp->data;
    top = top->next;

    free(temp);
    return top;
}

void displayStack(struct Node *top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}


void enqueue(struct Queue *q, int value) {
    struct Node *newNode = createNode(value);

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }

    struct Node *temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

void displayQueue(struct Queue *q) {
    struct Node *temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node *stack = NULL;
    int poppedVal;

    struct Queue q = {NULL, NULL};

    printf("\n--- STACK OPERATIONS ---\n");
    stack = push(stack, 10);
    stack = push(stack, 20);
    stack = push(stack, 30);
    displayStack(stack);

    stack = pop(stack, &poppedVal);
    printf("Popped: %d\n", poppedVal);
    displayStack(stack);

    printf("\n--- QUEUE OPERATIONS ---\n");
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    displayQueue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    displayQueue(&q);

    return 0;
}
