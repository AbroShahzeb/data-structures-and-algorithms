#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to traverse the list
void traverse(struct Node* head) {
    struct Node* current = head;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != NULL);

    printf("NULL\n");
}


// Function to add the element at the beginning of a list
struct Node* insert_at_beginning(struct Node* head, int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->prev = NULL;
    new_node->next = head;
    head->prev = new_node;
    head = new_node;

    return head;
}

int main() {

    // Creating nodes
    struct Node *head, *second, *third, *fourth;


    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    // Linking nodes
    head->data = 1;
    head->next = second;
    head->prev = NULL;

    second->data = 2;
    second->next = third;
    second->prev = head;

    third->data = 3;
    third->next = fourth;
    third->prev = second;

    fourth->data = 4;
    fourth->next = NULL;
    fourth->prev = third;

    traverse(head);

    head = insert_at_beginning(head, 0);
    head = insert_at_beginning(head, -1);

    traverse(head);

    return 0;
}