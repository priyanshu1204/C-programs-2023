#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

// Function to check if the dequeue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to insert an element at the front of the dequeue
void enqueueFront(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = front;
    front = newNode;

    if (rear == NULL) {
        rear = front;
    }
}

// Function to insert an element at the rear of the dequeue
void enqueueRear(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to delete an element from the front of the dequeue
int dequeueFront() {
    if (isEmpty()) {
        printf("Dequeue is empty!\n");
        return -1;
    }

    int data = front->data;
    Node *temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return data;
}

// Function to delete an element from the rear of the dequeue
int dequeueRear() {
    if (isEmpty()) {
        printf("Dequeue is empty!\n");
        return -1;
    }

    int data = rear->data;
    Node *temp = rear;

    if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        while (temp->next != rear) {
            temp = temp->next;
        }

        rear = temp;
        free(rear->next);
        rear->next = NULL;
    }

    return data;
}

// Function to display the elements of the dequeue
void display() {
    Node *temp = front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Enqueue at front\n2. Enqueue at rear\n3. Dequeue from front\n4. Dequeue from rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueueFront(data);
                break;
            case 2:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueueRear(data);
                break;
            case 3:
                data = dequeueFront();
                if (data != -1) {
                    printf("The dequeued element is: %d\n", data);
                }
                break;
            case 4:
                data = dequeueRear();
                if (data != -1) {
                    printf("The dequeued element is: %d\n", data);
                }
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}