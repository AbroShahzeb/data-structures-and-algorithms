#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to add the element at the beginning of a list
void traverse(struct Node* head) {
    struct Node* current = head;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("NULL\n");
}

// Function to add the element at the beginning of a list
struct Node* insert_at_beginning(struct Node* head, int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = val;

    struct Node* ptr = head->next;

    while (ptr->next != head) {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    new_node->next = head;
    head = new_node;
    return head;
}

int main() {

    // Creating Nodes
    struct Node *head, *second, *third, *fourth;


    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    // Linking nodes
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = head;

    traverse(head);

    head = insert_at_beginning(head, 0);
    head = insert_at_beginning(head, -1);
    head = insert_at_beginning(head, -2);
    head = insert_at_beginning(head, -3);

    traverse(head);

    return 0;
}