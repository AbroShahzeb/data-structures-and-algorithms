#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d", current->data);
        printf(" -> ");
        current = current->next;
    }

    printf("NULL\n");
}

struct Node* insert_at_beginning(struct Node* head, int val) {
    
    struct Node* new_node =  (struct Node*) malloc(sizeof(struct Node));
    new_node->data = val;

    new_node->next = head;
    return new_node;
}

int get_length(struct Node* head) {
    int len = 0;
    struct Node* current =head;

    while (current != NULL) {
        len++;
        current = current->next;
    }

    return len;
}

struct Node* insert_in_between(struct Node* head, int index, int val) {
    if (index < 0 || index > (get_length(head) - 1)) return head;

    if (index == 0) insert_at_beginning(head, val);

    else {

        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->data = val;

        struct Node* current = head;
        int i = 1;

        while (i < index) {
            current = current->next;
            i++;
        }

        new_node->next = current->next;
        current->next = new_node;

        return head;
    }
}

struct Node* insert_at_end(struct Node* head, int val) {
    struct Node *new_node, *current;
    current = head;
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;

    return head;
}

void insert_after_node(struct Node* node, int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = val;

    new_node->next = node->next;
    node->next = new_node;

}

int main() {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = NULL;

    head = insert_at_beginning(head, 9);
    head = insert_at_beginning(head, 19);

    head = insert_in_between(head, 2, 30);

    head = insert_at_end(head, 69);


    insert_after_node(head, 100);

    traverse(head);
    return 0;
}