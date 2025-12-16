#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* append(struct Node *head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct Node* insertLeft(struct Node *head, int target, int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found!\n", target);
        return head;
    }

    struct Node *newNode = createNode(value);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }

    temp->prev = newNode;

    return head;
}

struct Node* deleteValue(struct Node *head, int target) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found in list!\n", target);
        return head;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

void displayForward(struct Node *head) {
    printf("List (forward): ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void displayBackward(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    head = append(head, 10);
    head = append(head, 20);
    head = append(head, 30);

    displayForward(head);

    head = insertLeft(head, 20, 15);
    displayForward(head);

    head = insertLeft(head, 10, 5);
    displayForward(head);

    head = deleteValue(head, 30);
    displayForward(head);

    head = deleteValue(head, 5);
    displayForward(head);

    displayBackward(head);

    return 0;
}
