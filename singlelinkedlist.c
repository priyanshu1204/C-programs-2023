#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createNode() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    head = newNode;
}

void insertAtFirst() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void deleteAtFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void traverse() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(int value) {
    struct node *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            found = 1;
            printf("Value %d found in the list\n", value);
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Value %d not found in the list\n", value);
    }
}

int main() {
    int choice;
    int value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a node\n");
        printf("2. Insert a node at the beginning\n");
        printf("3. Delete a node from the beginning\n");
        printf("4. Traversal\n");
        printf("5. Search a node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createNode();
            break;
        case 2:
            insertAtFirst();
            break;
        case 3:
            deleteAtFirst();
            break;
        case 4:
            traverse();
            break;
        case 5:
            
            printf("Enter the value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}